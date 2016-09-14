#ifndef __LOG_MANAGER_H__
#define __LOG_MANAGER_H__

#include <stdio.h>

#include "Manager.h"

const std::string LOGFILE_NAME = "dragonfly.log";

namespace df {
	class LogManager : df::Manager
	{
	private:
		LogManager();
		LogManager(LogManager const&);
		void operator=(LogManager const&);
		bool do_flush;  // True if fflush after each write.
		FILE *p_f;      // Pointer to logfile structure.
		int log_level;

	public:
		// If logfile is open, close it.
		~LogManager();

		//Get the instance of LogManager, creates it if it hasn't already
		static LogManager &getInstance();

		// Start up the LogManager (open logfile "dragonfly.log").
		int startUp();

		// Shut down the LogManager (close logfile).
		void shutDown();

		// Set flush of logfile after each write.
		void setFlush(bool do_flush = true);

		// Write to logfile. Supports printf() formatting.
		// Return number of bytes written, -1 if error.
		int writeLog(const char *fmt, ...);

		// Write to logfile. Supports printf() formatting.
		// Return number of bytes written, -1 if error.
		// Also accepts logLevel to filter out logs
		int writeLog(int logLevel, const char *fmt, ...);

		int getLogLevel();

		void setLogLevel(int level);

	};	
}

#endif // !__LOG_MANAGER_H__
