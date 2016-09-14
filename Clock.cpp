#include "Clock.h"

//The clock class will keep track of time passed since the time was last checked. 
//Delta() will reset the previous_time to the current time and return elapsed time. 
//Split() will return the elapsed time without reseting previous_time
df::Clock::Clock()
{
	SYSTEMTIME current_st;
	GetSystemTime(&current_st);
	previous_time = 0;
	previous_time = (current_st.wMinute * 60 * 1000000) + (current_st.wSecond * 1000000) + (current_st.wMilliseconds * 1000);
}

double df::Clock::delta() {
	SYSTEMTIME current_st;
	GetSystemTime(&current_st);
	double current_time = 0;
	current_time = (current_st.wMinute * 60 * 1000000) + (current_st.wSecond * 1000000) + (current_st.wMilliseconds * 1000);
	double elapsed_time = current_time - previous_time;
	previous_time = current_time;
	return elapsed_time;
}

double df::Clock::split() const {
	SYSTEMTIME current_st;
	GetSystemTime(&current_st);
	long int current_time = 0;
	current_time = (current_st.wMinute * 60 * 1000000) + (current_st.wSecond * 1000000) + (current_st.wMilliseconds * 1000);
	long int elapsed_time = current_time - previous_time;
	return elapsed_time;
}
