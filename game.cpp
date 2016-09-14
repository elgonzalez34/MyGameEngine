#include "LogManager.h"
#include "GameManager.h"
#include "Clock.h"
#include "Vector.h"
#include "Object.h"
#include "ObjectList.h"
#include "ObjectListIterator.h"
#include "WorldManager.h"
#include "Event.h"
#include "EventStep.h"
#include "Saucer.h"

//This is a test game meant to create output through log manager to confirm that the engine is working properly

int main(int argc, char *argv[]) {
	df::GameManager &game_manager = df::GameManager::getInstance();
	game_manager.startUp();
	df::LogManager &log_manager = df::LogManager::getInstance();
	df::WorldManager &world_manager = df::WorldManager::getInstance();

	// Start up log manager.
	log_manager.setFlush(true);

	log_manager.writeLog(0, "Log Manager started! \n");

	//Clock Testing
	df::Clock *test_clock = new df::Clock();
	double clockStart = test_clock->delta();
	std::string s = std::to_string(clockStart);
	char const *pchar = s.c_str();
	log_manager.writeLog(0, pchar);
	Sleep(100);
	double clockEnd = test_clock->split();
	s = std::to_string(clockEnd);
	pchar = s.c_str();
	log_manager.writeLog(0, pchar);
	log_manager.writeLog(0, "Clock test end \n");


	//Vector Testing
	df::Vector *v = new df::Vector(1,5);
	float x = v->getX();
	float y = v->getY();
	//TestX
	s = std::to_string(x);
	pchar = s.c_str();
	log_manager.writeLog(0, pchar);
	//TestY
	s = std::to_string(y);
	pchar = s.c_str();
	log_manager.writeLog(0, pchar);
	log_manager.writeLog(0, "Vector test end \n");


	//World Manager, ObjectList, Iterator, and Object testing
	Saucer *saucer = new Saucer();
	Saucer *saucer2 = new Saucer();
	//We will insert two saucers into world_managers list, and then print out their ids
	world_manager.insertObject(saucer);
	world_manager.insertObject(saucer2);
	df::ObjectList *objs = new df::ObjectList();
	*objs = world_manager.getAllObjects();
	df::Object *saucerptr = objs->getObj(0);
	df::Object *saucerptr2 = objs->getObj(1);

	int id = saucerptr->getId();
	int id2 = saucerptr2->getId();
	s = std::to_string(id);
	pchar = s.c_str();
	log_manager.writeLog(0, pchar);
	s = std::to_string(id2);
	pchar = s.c_str();
	log_manager.writeLog(0, pchar);

	//Now we will delete one saucer from the list
	world_manager.markForDelete(saucer2);

	log_manager.writeLog(0, "World Manager, ObjectList, Iterator, and Object testing end \n");

	//GameManager and Step testing
	//We will print out a message every time a step event is sent to our saucer with the step count
	log_manager.writeLog(0, "Game Manager testing spam about to begin \n");
	game_manager.run();
	log_manager.writeLog(0, "Game Manager testing end \n");


	//Get rid of LogManager
	log_manager.~LogManager();
}

