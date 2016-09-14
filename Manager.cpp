#include "Manager.h"

//This is the Manager parent class
df::Manager::Manager()
{
	is_started = true;
}

bool df::Manager::isStarted() const{
	return(is_started);
}

void df::Manager::setType(std::string type) {
	type = type;
}

std::string df::Manager::getType() const {
	return type;
}

int df::Manager::startUp() {
	is_started = true;
	return 1;
}

void df::Manager::shutDown() {
	is_started = false;
}

df::Manager::~Manager()
{
	shutDown();
}

