#include "Saucer.h"
#include "LogManager.h"
#include "WorldManager.h"
#include "GameManager.h"
#include "EventStep.h"
#include <stdlib.h>

//This is a class for testing the instantiation of objects. When 100 game steps have occured it sets game_over to true
Saucer::Saucer()
{
	// Set object type.
	setType("Saucer");
}

//Calls the out function if the saucer is off the map
int Saucer::eventHandler(const df::Event *p_e) {
	df::LogManager &log_manager = df::LogManager::getInstance();
	df::GameManager &game_manager = df::GameManager::getInstance();

	//If there has been 100 game steps then we will set the game to game over
	if (p_e->getType() == "EventStep") {
		log_manager.writeLog("Saucer EventStep");
		
		const df::EventStep *step = dynamic_cast<const df::EventStep*> (p_e);
		int step_count = step->getStepCount();

		std::string s = std::to_string(step_count);
		char const *pchar = s.c_str();
		log_manager.writeLog(0, pchar);
		
		if (step_count >= 100) {
			log_manager.writeLog("Game over set");
			game_manager.setGameOver(true);
		}
		return 1;
	}
	return 0;
}

Saucer::~Saucer() {
}

