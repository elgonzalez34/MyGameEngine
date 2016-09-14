#include "EventStep.h"

//Event steps occur every in game step. They retain the current step count
df::EventStep::EventStep()
{
	df::Event Event();
	setType("EventStep");
	step_count = 0;
}

df::EventStep::EventStep(int init_step_count)
{
	df::Event Event();
	setType("EventStep");
	step_count = init_step_count;
}

void df::EventStep::setStepCount(int new_step_count) {
	step_count = new_step_count;
}

int df::EventStep::getStepCount() const {
	return step_count;
}

//df::EventStep::~EventStep()
//{
//}
