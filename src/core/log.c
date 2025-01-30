#include "../../include/core/log.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <errno.h>

// =====================
// Internal Declarations
// =====================

#define MAX_MESSAGE_LEN 1024
#define TIMESTAMP_LEN 64

typedef enum {
    LOG_SOURCE_STDOUT,
    LOG_SOURCE_STDERR,
    LOG_SOURCE_FILE
} log_source_type_t;

typedef struct {
    FILE* fp;
    log_source_type_t type;
} log_output_t;

struct logger {
    log_output_t* outputs;
    uint8_t output_count;
    uint8_t format;
    char* file_path;
};

struct logMessage {
    uint8_t level;
    time_t timestamp;
    char message[MAX_MESSAGE_LEN];
};

// =====================
// Static Data
// =====================

static const char* LEVEL_STRINGS[] = {
    [LOG_LEVEL_TRACE] = "TRACE",
    [LOG_LEVEL_INFO] = "INFO",
    [LOG_LEVEL_WARN] = "WARN",
    [LOG_LEVEL_ERROR] = "ERROR",
    [LOG_LEVEL_CRITICAL] = "CRITICAL"
};

static const char* IO_STRINGS[] = {
    "STDOUT", "STDERR", "STDOUT/STDERR", "FILE",
    "FILE/STDOUT", "FILE/STDERR", "ALL"
};

static const char* FORMAT_STRINGS[] = {
    "UNSTRUCTURED", "STRUCTURED"
};

// =====================
// Utility Functions
// =====================

static const char* level_to_string(uint8_t level) {
    switch(level) {
        case LOG_LEVEL_TRACE:   return LEVEL_STRINGS[0];
        case LOG_LEVEL_INFO:    return LEVEL_STRINGS[1];
        case LOG_LEVEL_WARN:    return LEVEL_STRINGS[2];
        case LOG_LEVEL_ERROR:   return LEVEL_STRINGS[3];
        case LOG_LEVEL_CRITICAL:return LEVEL_STRINGS[4];
        default:                return "UNKNOWN";
    }
}

static void format_timestamp(time_t t, char* buffer, size_t len) {
    struct tm tm_info;
    localtime_r(&t, &tm_info);
    strftime(buffer, len, "%Y-%m-%d %H:%M:%S", &tm_info);
}

// =====================
// Logger Implementation
// =====================

void logger_init(logger_t* out, uint8_t io, uint8_t format, const char* fp) {
    if (!out) return;

    // Initialize basic fields
    out->format = format;
    out->output_count = 0;
    out->outputs = NULL;
    out->file_path = NULL;

    // Determine output count
    uint8_t count = 0;
    if (io & LOG_IO_STDOUT) count++;
    if (io & LOG_IO_STDERR) count++;
    if (io & LOG_IO_FILE) count++;

    if (count == 0) return;

    // Allocate outputs
    out->outputs = calloc(count, sizeof(log_output_t));
    if (!out->outputs) return;

    // Configure outputs
    uint8_t index = 0;
    if (io & LOG_IO_STDOUT) {
        out->outputs[index++] = (log_output_t){stdout, LOG_SOURCE_STDOUT};
    }
    if (io & LOG_IO_STDERR) {
        out->outputs[index++] = (log_output_t){stderr, LOG_SOURCE_STDERR};
    }
    if (io & LOG_IO_FILE) {
        if (fp) {
            FILE* f = fopen(fp, "a+");
            if (f) {
                out->file_path = strdup(fp);
                out->outputs[index++] = (log_output_t){f, LOG_SOURCE_FILE};
            }
        }
    }

    out->output_count = index;
}

logger_t* logger_malloc(uint8_t io, uint8_t format, const char* fp) {
    logger_t* logger = malloc(sizeof(logger_t));
    if (logger) {
        logger_init(logger, io, format, fp);
    }
    return logger;
}

void logger_close(logger_t* out) {
    if (!out) return;

    for (uint8_t i = 0; i < out->output_count; i++) {
        if (out->outputs[i].type == LOG_SOURCE_FILE) {
            fclose(out->outputs[i].fp);
        }
    }

    free(out->outputs);
    free(out->file_path);
    free(out);
}

// =====================
// Log Message Implementation
// =====================

void logMessage_init(logMessage_t* out, uint8_t level, const char* format, ...) {
    if (!out) return;

    va_list args;
    va_start(args, format);
    vsnprintf(out->message, MAX_MESSAGE_LEN, format, args);
    va_end(args);

    out->level = level;
    out->timestamp = time(NULL);
}

logMessage_t* logMessage_malloc(uint8_t level, const char* format, ...) {
    logMessage_t* msg = malloc(sizeof(logMessage_t));
    if (msg) {
        va_list args;
        va_start(args, format);
        vsnprintf(msg->message, MAX_MESSAGE_LEN, format, args);
        va_end(args);
        msg->level = level;
        msg->timestamp = time(NULL);
    }
    return msg;
}

void logMessage_free(logMessage_t* m) {
    free(m);
}

// =====================
// Core Logging Function
// =====================

void logger_log(logger_t* out, logMessage_t* message) {
    if (!out || !message) return;

    char timestamp[TIMESTAMP_LEN];
    format_timestamp(message->timestamp, timestamp, sizeof(timestamp));

    for (uint8_t i = 0; i < out->output_count; i++) {
        switch(out->format) {
            case LOG_FORMAT_STRUCTURED:
                fprintf(out->outputs[i].fp,
                    "[%s] [%s] %s\n",
                    timestamp,
                    level_to_string(message->level),
                    message->message);
                break;

            case LOG_FORMAT_UNSTRUCTURED:
            default:
                fprintf(out->outputs[i].fp,
                    "%s - %s: %s\n",
                    timestamp,
                    level_to_string(message->level),
                    message->message);
                break;
        }
        fflush(out->outputs[i].fp);
    }
}

// =====================
// Getters
// =====================

const char* logger_getIO(logger_t* out) {
    if (!out) return "INVALID";
    return IO_STRINGS[out->output_count - 1]; // Simplified for example
}

const char* logger_getFormat(logger_t* out) {
    if (!out) return "INVALID";
    return FORMAT_STRINGS[out->format - 1];
}
