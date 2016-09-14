// Dragonfly - Program a Game Engine from Scratch
// Listing 4.19
#include <Windows.h>

// The clock, for timing (such as in the game loop)
namespace df {
	class Clock {

	private:
		double previous_time; // Previous time delta() called (in microsec).
		//long int convertTime(SYSTEMTIME st);
	public:
		// Sets previous_time to current time.
		Clock();

		// Return time elapsed since delta() was last called, -1 if error.
		// Units are microseconds.
		double delta();

		// Return time elapsed since delta() was called, -1 if error.
		// Units are microseconds.
		double split() const;
	};
}