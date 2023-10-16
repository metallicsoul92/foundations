#ifndef FOUNDATIONS_CORE_LOG_H_
#define FOUNDATIONS_CORE_LOG_H_


//forward declare the fixed data types
#ifndef STDINT_DEFINED
#include <stdint.h>
#define STDINT_DEFINED 1
#endif

//forward declare the stdargs header
#ifndef STDARG_DEFINED
#include <stdarg.h>
#define STDARG_DEFINED 1
#endif


//Levels of logging that can occur
#define LOG_LEVEL_TRACE 1
#define LOG_LEVEL_INFO 2
#define LOG_LEVEL_WARN 4
#define LOG_LEVEL_ERROR 8
#define LOG_LEVEL_CRITICAL 16
#define LOG_LEVEL_ALL LOG_LEVEL_TRACE | LOG_LEVEL_INFO | LOG_LEVEL_WARN | \
					  LOG_LEVEL_ERROR | LOG_LEVEL_CRITICAL

//Where should the log messages go? Directly to a file or the stdout/stderr?
#define LOG_IO_STDOUT 1
#define LOG_IO_STDERR 2
#define LOG_IO_STD LOG_IO_STDOUT | LOG_IO_STDERR
#define LOG_IO_FILE 4
#define LOG_IO_FILE_AND_STDOUT LOG_IO_STDOUT | LOG_IO_FILE
#define LOG_IO_FILE_AND_STDERR LOG_IO_STDERR | LOG_IO_FILE
#define LOG_IO_FILE_AND_STD LOG_IO_STD | LOG_IO_FILE
#define LOG_IO_ALL LOG_IO_FILE_AND_STD


//Is this a formatted log?
#define LOG_FORMAT_UNSTRUCTURED 1
#define LOG_FORMAT_STRUCTURED 2


#ifndef LOGMESSAGE_DEFINED
typedef struct logMessage logMessage_t;
#define LOGMESSAGE_DEFINED 1
#endif

#ifndef LOGGER_DEFINED
typedef struct logger logger_t;
#define LOGGER_DEFINED 1
#endif

//initialize an already allocated logger)
void logger_init(logger_t * out,uint8_t io, uint8_t format,const char * fp);
logger_t * logger_malloc(uint8_t io, uint8_t format, const char * fp);
logger_t * logger_calloc();
//Needs to be done on every logger to close the file pointer.
void logger_close(logger_t * out);
void logger_log(logger_t * out, logMessage_t * message, ...);
const char * logger_getIO(logger_t * out);
const char * logger_getFormat(logger_t * out);

//LogMessage API

void logMessage_init(logMessage_t * out , uint8_t level, const char * message);
logMessage_t * logMessage_malloc(uint8_t level, const char * message);
logMessage_t * logMessage_calloc();
void logMessage_free(logMessage_t * m);

#endif
