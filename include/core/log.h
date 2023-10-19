/**
 * @file log.h
 * @brief A logging library for C with different log levels and output options.
 *
 * This library provides functionality for logging messages at different levels
 * (e.g., trace, info, warn, error, and critical). It allows users to direct log
 * messages to various output sources, such as standard output (stdout), standard
 * error (stderr), or log files. Users can choose between structured and unstructured
 * log formats.
 *
 * @author Clim Jark
 * @version 1.0
 */

#ifndef FOUNDATIONS_CORE_LOG_H_
#define FOUNDATIONS_CORE_LOG_H_

// Include necessary standard headers and forward declarations.

// Forward declare fixed data types if not already defined.
#ifndef STDINT_DEFINED
#include <stdint.h>
#define STDINT_DEFINED 1
#endif

// Forward declare the stdargs header if not already defined.
#ifndef STDARG_DEFINED
#include <stdarg.h>
#define STDARG_DEFINED 1
#endif

/** @def LOG_LEVEL_TRACE
 *  The log level for trace messages.
 */
#define LOG_LEVEL_TRACE 1

/** @def LOG_LEVEL_INFO
 *  The log level for informational messages.
 */
#define LOG_LEVEL_INFO 2

/** @def LOG_LEVEL_WARN
 *  The log level for warning messages.
 */
#define LOG_LEVEL_WARN 4

/** @def LOG_LEVEL_ERROR
 *  The log level for error messages.
 */
#define LOG_LEVEL_ERROR 8

/** @def LOG_LEVEL_CRITICAL
 *  The log level for critical messages.
 */
#define LOG_LEVEL_CRITICAL 16

/** @def LOG_LEVEL_ALL
 *  A combination of all log levels (trace, info, warn, error, and critical).
 */
#define LOG_LEVEL_ALL LOG_LEVEL_TRACE | LOG_LEVEL_INFO | LOG_LEVEL_WARN | \
                      LOG_LEVEL_ERROR | LOG_LEVEL_CRITICAL

/** @def LOG_IO_STDOUT
 *  Log messages to standard output (stdout).
 */
#define LOG_IO_STDOUT 1

/** @def LOG_IO_STDERR
 *  Log messages to standard error (stderr).
 */
#define LOG_IO_STDERR 2

/** @def LOG_IO_STD
 *  Log messages to both standard output (stdout) and standard error (stderr).
 */
#define LOG_IO_STD LOG_IO_STDOUT | LOG_IO_STDERR

/** @def LOG_IO_FILE
 *  Log messages to a log file.
 */
#define LOG_IO_FILE 4

/** @def LOG_IO_FILE_AND_STDOUT
 *  Log messages to both a log file and standard output (stdout).
 */
#define LOG_IO_FILE_AND_STDOUT LOG_IO_STDOUT | LOG_IO_FILE

/** @def LOG_IO_FILE_AND_STDERR
 *  Log messages to both a log file and standard error (stderr).
 */
#define LOG_IO_FILE_AND_STDERR LOG_IO_STDERR | LOG_IO_FILE

/** @def LOG_IO_FILE_AND_STD
 *  Log messages to both a log file, standard output (stdout), and standard error (stderr).
 */
#define LOG_IO_FILE_AND_STD LOG_IO_STD | LOG_IO_FILE

/** @def LOG_IO_ALL
 *  Log messages to all available output options (stdout, stderr, and log file).
 */
#define LOG_IO_ALL LOG_IO_FILE_AND_STD

/** @def LOG_FORMAT_UNSTRUCTURED
 *  Unstructured log message format.
 */
#define LOG_FORMAT_UNSTRUCTURED 1

/** @def LOG_FORMAT_STRUCTURED
 *  Structured log message format.
 */
#define LOG_FORMAT_STRUCTURED 2

// Forward declarations of custom types for logger and log message.

#ifndef LOGMESSAGE_DEFINED
typedef struct logMessage logMessage_t;
#define LOGMESSAGE_DEFINED 1
#endif

#ifndef LOGGER_DEFINED
typedef struct logger logger_t;
#define LOGGER_DEFINED 1
#endif

/**
 * @brief Initializes an already allocated logger with specified options.
 *
 * @param out     Pointer to the logger to be initialized.
 * @param io      Log output options (e.g., LOG_IO_STDOUT, LOG_IO_FILE).
 * @param format  Log message format (e.g., LOG_FORMAT_UNSTRUCTURED, LOG_FORMAT_STRUCTURED).
 * @param fp      File path for log output (only applicable if io includes LOG_IO_FILE).
 */
void logger_init(logger_t * out, uint8_t io, uint8_t format, const char * fp);

/**
 * @brief Allocates and initializes a logger with specified options.
 *
 * @param io      Log output options (e.g., LOG_IO_STDOUT, LOG_IO_FILE).
 * @param format  Log message format (e.g., LOG_FORMAT_UNSTRUCTURED, LOG_FORMAT_STRUCTURED).
 * @param fp      File path for log output (only applicable if io includes LOG_IO_FILE).
 * @return A pointer to the allocated and initialized logger.
 */
logger_t * logger_malloc(uint8_t io, uint8_t format, const char * fp);

/**
 * @brief Allocates and initializes a logger with default options.
 *
 * @return A pointer to the allocated and initialized logger.
 */
logger_t * logger_calloc();

/**
 * @brief Closes the logger, releasing associated resources (e.g., file pointer).
 *
 * @param out Pointer to the logger to be closed.
 */
void logger_close(logger_t * out);

/**
 * @brief Logs a message to the specified logger.
 *
 * @param out     Pointer to the logger where the message will be logged.
 * @param message The log message format.
 * @param ...     Additional arguments to format the log message.
 */
void logger_log(logger_t * out, logMessage_t * message, ...);

/**
 * @brief Returns the current log output options as a string.
 *
 * @param out Pointer to the logger.
 * @return A string describing the current log output options.
 */
const char * logger_getIO(logger_t * out);

/**
 * @brief Returns the current log message format as a string.
 *
 * @param out Pointer to the logger.
 * @return A string describing the current log message format.
 */
const char * logger_getFormat(logger_t * out);

/**
 * @brief Initializes a log message structure with the specified log level and message.
 *
 * @param out     Pointer to the log message to be initialized.
 * @param level   The log level (e.g., LOG_LEVEL_INFO, LOG_LEVEL_WARN).
 * @param message The log message.
 */
void logMessage_init(logMessage_t * out, uint8_t level, const char * message);

/**
 * @brief Allocates and initializes a log message structure with the specified log level and message.
 *
 * @param level   The log level (e.g., LOG_LEVEL_INFO, LOG_LEVEL_WARN).
 * @param message The log message.
 * @return A pointer to the allocated and initialized log message.
 */
logMessage_t * logMessage_malloc(uint8_t level, const char * message);

/**
 * @brief Allocates and initializes a log message structure with default options.
 *
 * @return A pointer to the allocated and initialized log message.
 */
logMessage_t * logMessage_calloc();

/**
 * @brief Deallocates the memory associated with a log message structure.
 *
 * @param m Pointer to the log message to be deallocated.
 */
void logMessage_free(logMessage_t * m);

#endif
