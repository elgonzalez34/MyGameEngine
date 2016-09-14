#include "Event.h"

//This is the superclass for events
df::Event::Event()
{
	event_type = UNDEFINED_EVENT;
}

void df::Event::setType(std::string new_type) {
	event_type = new_type;
}

std::string df::Event::getType() const{
	return event_type;
}

df::Event::~Event()
{
}
