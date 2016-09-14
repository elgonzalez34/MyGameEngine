#include "LogManager.h"
#include "utility.h"
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

#define NULL nullptr

//LogManager sends output to the file dragonfly.log
//Sets the file to null, flush to false, and sets the type
df::LogManager::LogManager()
{
	p_f = NULL;
	do_flush = false;
	setType("LogManager");
	log_level = 0;
}

//Singleton getInstance() function, also class startUp() 
df::LogManager &df::LogManager::getInstance() {
	static LogManager log_manager;
	//log_manager.startUp();
	return log_manager;
}

//Opens the file for log writing.
int df::LogManager::startUp() {
	Manager::startUp();
	try {
		p_f = fopen("dragonfly.log", "w");
		return 1;
	}
	catch (int e) {
		return e;
	}
}

//Closes the file
void df::LogManager::shutDown() {
	Manager::shutDown();
	if (p_f != NULL) {
		fclose(p_f);
	}
}

//First gets the current time. After this it prints the current time to the file. Then it prints the contents of the message to the file.
//If do_flush is true then it flushes the output to the file immediately. Returns the number of characters(same as bytes)
int df::LogManager::writeLog(const char *fmt, ...) {
	try {
		char* time = utility::getTimeString();
		fprintf(p_f, strcat(time, "Message: "));
		va_list args;
		va_start(args, fmt);
		vfprintf(p_f, fmt, args);
		va_end(args);
		if (do_flush) {
			fflush(p_f);
		}
		return strlen(fmt);
	}
	catch (int e) {
		return -1;
	}
}

//First gets the current time. After this it prints the current time to the file. Then it prints the contents of the message to the file.
//If do_flush is true then it flushes the output to the file immediately. Returns the number of characters(same as bytes)
//Also has notion of logLevel, ie importance level for message
int df::LogManager::writeLog(int logLevel, const char *fmt, ...) {
	if (logLevel >= this->log_level) {
		try {
			char* time = utility::getTimeString();
			fprintf(p_f, strcat(time, "Message: "));
			//fprintf(p_f, "Message: ");
			va_list args;
			va_start(args, fmt);
			vfprintf(p_f, fmt, args);
			va_end(args);
			if (do_flush) {
				fflush(p_f);
			}
		
			return strlen(fmt);
		}
		catch(int e){
			return -1;
		}
	}
}

void df::LogManager::setFlush(bool doFlush) {
	this->do_flush = doFlush;
}

//Represents the importance level of a message
void df::LogManager::setLogLevel(int level) {
	this->log_level = level;
}

int df::LogManager::getLogLevel() {
	return this->log_level;
}

df::LogManager::~LogManager()
{
	this->shutDown();
}
