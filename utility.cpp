#include "utility.h"
#include <time.h> 
#include <stdio.h>

//This class is for utility functions that do not belong in specific classes

utility::utility()
{
}

//Returns the current time in a string
char* utility::getTimeString() {
	// String to return, made `static' so persists.
	static char time_str[30];

	// System calls to get time.
	time_t now;
	time(&now);
	struct tm *p_time = localtime(&now);

	// `02' gives two digits, `%d' for integers.
	sprintf(time_str, "[%02d:%02d:%02d]",
		p_time->tm_hour,
		p_time->tm_min,
		p_time->tm_sec);

	return time_str;
}

utility::~utility()
{
}
