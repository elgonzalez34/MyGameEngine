#include "Event.h"

#ifndef __STEP_EVENT_H__
#define __STEP_EVENT_H__

const std::string STEP_EVENT = "df::step";

namespace df{

	class EventStep : public df::Event {

	private:
		int step_count; // Iteration number of game loop.

	public:
		// Default constructor.
		EventStep();

		// Constructor with initial step count.
		EventStep(int init_step_count);

		// Set step count.
		void setStepCount(int new_step_count);

		// Get step count.
		int getStepCount() const;
	};
}

#endif