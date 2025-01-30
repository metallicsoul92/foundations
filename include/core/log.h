#ifndef FOUNDATIONS_CORE_LOG_H_
#define FOUNDATIONS_CORE_LOG_H_

#include <stdint.h>
#include <stdarg.h>

// =========================================
// Log Levels, I/O Options, and Format Flags
// =========================================

#define LOG_LEVEL_TRACE    1
#define LOG_LEVEL_INFO     2
#define LOG_LEVEL_WARN     4
#define LOG_LEVEL_ERROR    8
#define LOG_LEVEL_CRITICAL 16
#define LOG_LEVEL_ALL      (LOG_LEVEL_TRACE | LOG_LEVEL_INFO | LOG_LEVEL_WARN | \
                            LOG_LEVEL_ERROR | LOG_LEVEL_CRITICAL)

#define LOG_IO_STDOUT      1
#define LOG_IO_STDERR      2
#define LOG_IO_STD         (LOG_IO_STDOUT | LOG_IO_STDERR)
#define LOG_IO_FILE        4
#define LOG_IO_ALL         (LOG_IO_STD | LOG_IO_FILE)

#define LOG_FORMAT_UNSTRUCTURED 1
#define LOG_FORMAT_STRUCTURED   2

// =========================================
// Forward Declarations for Opaque Structures
// =========================================

typedef struct logger logger_t;
typedef struct logMessage logMessage_t;

// =========================================
// Logger Functions
// =========================================

// Initialize a pre-allocated logger
void logger_init(logger_t* out, uint8_t io, uint8_t format, const char* fp);

// Allocate and initialize a logger
logger_t* logger_malloc(uint8_t io, uint8_t format, const char* fp);

// Allocate a logger with default settings (e.g., LOG_IO_STDOUT, LOG_FORMAT_UNSTRUCTURED)
logger_t* logger_calloc();

// Close and deallocate a logger
void logger_close(logger_t* out);

// Log a message (no variadic args here; message formatting is done in logMessage_init)
void logger_log(logger_t* out, logMessage_t* message);

// Getter for log I/O configuration (simplified for example)
const char* logger_getIO(logger_t* out);

// Getter for log format
const char* logger_getFormat(logger_t* out);

// =========================================
// Log Message Functions
// =========================================

// Initialize a log message with variadic formatting
void logMessage_init(logMessage_t* out, uint8_t level, const char* format, ...);

// Allocate and initialize a log message with variadic formatting
logMessage_t* logMessage_malloc(uint8_t level, const char* format, ...);

// Allocate a log message with default settings
logMessage_t* logMessage_calloc();

// Deallocate a log message
void logMessage_free(logMessage_t* m);

#endif // FOUNDATIONS_CORE_LOG_H_
