#include "../../include/core/log.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

const char * LEVEL_STRINGS[6] = {"TRACE","INFO","WARN","ERROR","CRITICAL","ALL"};

const char * levelToString(uint8_t level){
	switch(level){
	case LOG_LEVEL_TRACE : return LEVEL_STRINGS[0]; break;
	case LOG_LEVEL_INFO : return LEVEL_STRINGS[1]; break;
	case LOG_LEVEL_WARN : return LEVEL_STRINGS[2]; break;
	case LOG_LEVEL_ERROR : return LEVEL_STRINGS[3]; break;
	case LOG_LEVEL_CRITICAL :  return LEVEL_STRINGS[4]; break;
	case LOG_LEVEL_ALL: return LEVEL_STRINGS[5]; break;

	}
	return "ERR";
}


const char * IO_STRINGS[7] = {"STDOUT","STDERR","STDOUT/STDERR","FILE"
							"FILE/STDOUT","FILE/STDERR","ALL"};

const char * FORMAT_STRINGS[2] = {"UNSTRUCTURED","STRUCTURED"};

#define DEFAULT_FILE_DIR "../log"
#define DEFAULT_FILE_NAME "default.log"
#define DEFAULT_FILE_PATH "../log/default.log"


static char * logFilepath = DEFAULT_FILE_PATH;


struct logger{
	FILE ** _fp;
	char ** _logpaths;
	//LOG_IO_ flags
	uint8_t _io;
	//LOG_FORMAT flags
	uint8_t _format;
	uint8_t _handles;
};

struct logMessage{
	va_list _va;
	//LOG_LEVEL flags
	uint8_t _level;
	time_t _time;
	//actual message to be written
	char * _message;
};

//initialize an already allocated logger)
void logger_init(logger_t * out,uint8_t io, uint8_t format,const char * fp)
{
	char * lfp;
	out->_io = io;
	out->_format = format;
	if(fp == NULL){
	lfp = malloc(strlen(logFilepath) * sizeof(char)+1);
	strcpy(lfp,logFilepath);
	}else{
	lfp = malloc(strlen(fp) * sizeof(char) + 1);
	strcpy(lfp,fp);
	}
	switch(io){
	//Will handle this within the log function itself if it is
	//only logging to the standard input/output
	case LOG_IO_STDOUT:
	out->_fp = malloc(sizeof(FILE*));
	out->_fp[0] = stdout;
	out->_handles = 1;
	break;
	case LOG_IO_STDERR:
	out->_fp = malloc(sizeof(FILE*));
	out->_fp[0] = stderr;
	out->_handles = 1;
	break;
	case LOG_IO_STD:
	out->_fp = malloc(sizeof(FILE*)*2);
	out->_fp[0] = stdout;
	out->_fp[1] = stderr;
	out->_handles = 2;
	break;
	case LOG_IO_FILE:
	out->_fp = malloc(sizeof(FILE*));
	out->_fp[0] = fopen(lfp,"a+");
	out->_handles = 1;
	break;
	case LOG_IO_FILE_AND_STDOUT:
	out->_fp = malloc(sizeof(FILE*) * 2);
	out->_fp[0] = stdout;
	out->_fp[1] = fopen(lfp,"a+");
	out->_handles = 2;
	break;
	case LOG_IO_FILE_AND_STDERR:
	out->_fp = malloc(sizeof(FILE*) * 2);
	out->_fp[0] = stderr;
	out->_fp[1] = fopen(lfp,"a+");
	out->_handles = 2;
	break;
	case LOG_IO_FILE_AND_STD:
	out->_fp = malloc(sizeof(FILE*) * 2);
	out->_fp[0] = stdout;
	out->_fp[1] = stderr;
	out->_fp[2] = fopen(lfp,"a+");
	out->_handles = 3;
	break;
	default:
		out->_fp = NULL;
		out->_handles = 0;
	}
	// at this point , the logger is created and to be used?
	free(lfp);

}
logger_t * logger_malloc(uint8_t io, uint8_t format, const char * fp){
	logger_t * out = malloc(sizeof(logger_t));
	logger_init(out, io, format, fp);
	return out;
	}

logger_t * logger_calloc(){
	logger_t * out = calloc(1,sizeof(logger_t));
	return out;
	}

//Needs to be done on every logger to close the file pointer.
void logger_close(logger_t * out){
	for(int i = 0;i < out->_handles; i++){
	fclose(out->_fp[i]);
	}
	free(out->_fp);
}


logMessage_t * logMessage_malloc(uint8_t level, const char * message){
	logMessage_t * out = malloc(sizeof(logMessage_t));
	logMessage_init(out,level, message);
	return out;
}

logMessage_t * logMessage_calloc(){
	logMessage_t * out = calloc(1,sizeof(logMessage_t));
	return out;
}

void logMessage_free(logMessage_t * m){
	free(m->_message);
	free(m);
}


void logMessage_init(logMessage_t * out , uint8_t level, const char * message){
	out->_level = level;
	//this just gets the current time of the initialization
	out->_time = time(NULL);
	out->_message = malloc(sizeof(char)* strlen(message)+1);
	strcpy(out->_message,message);
	strcat(out->_message,"\n");
}

void logger_log(logger_t * out, logMessage_t * message, ...){
	va_start( message->_va, message);
	switch(out->_format){
	case LOG_FORMAT_UNSTRUCTURED:
	for(int h = 0; h < out->_handles; h++){
	fprintf(out->_fp[h],"%s%s:", asctime(localtime(&message->_time)),
				     levelToString(message->_level));
	vfprintf(out->_fp[h], message->_message,message->_va);
	}
	va_end(message->_va);
	break;
	case LOG_FORMAT_STRUCTURED:
	for(int h = 0; h < out->_handles; h++){
	fprintf(out->_fp[h],"%s%s:\n\t", asctime(localtime(&message->_time)),
					 levelToString(message->_level));
	vfprintf(out->_fp[h], message->_message,message->_va);
	fprintf(out->_fp[h],"\n");
	}
	va_end(message->_va);
	break;
	}
	logMessage_free(message);
}



const char * logger_getIO(logger_t * out){
	return IO_STRINGS[out->_io -1];
}

const char * logger_getFormat(logger_t * out){
	return FORMAT_STRINGS[out->_format - 1];
}
