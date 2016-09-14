#include "GameManager.h"
#include "LogManager.h"
#include "WorldManager.h"
#include "EventStep.h"
#include "Clock.h"
#include <Windows.h>
#include <mmsystem.h>
#include <TimeAPI.h>

#pragma comment(lib, "winmm.lib")

//GameManager runs the game loop, and keeps track of whether or not the game is over.
//It is also in charge of running the startUp() functions for the other Managers

df::GameManager::GameManager()
{
	setType("GameManager");
	game_over = false;
	frame_time = FRAME_TIME_DEFAULT;
}

df::GameManager &df::GameManager::getInstance() {
	static GameManager game_manager;
	//game_manager.startUp();
	return game_manager;
}

//Starts the other managers, and begins the timing period for Sleep calls
int df::GameManager::startUp() {
	Manager::startUp();
	df::LogManager &log_manager = df::LogManager::getInstance();
	log_manager.startUp();
	df::WorldManager &world_manager = df::WorldManager::getInstance();
	world_manager.startUp();
	timeBeginPeriod(1);
	return 1;
}
void df::GameManager::shutDown() {
	Manager::shutDown();
	setGameOver(true);
	timeEndPeriod(1);
}

//Runs the main game loop.
//Deletes objects that are marked for deletion, as well as sends events to all objects to be updated
void df::GameManager::run() {
	df::WorldManager &world_manager = df::WorldManager::getInstance();
	df::Clock *clock = new df::Clock();
	int adjust_time = 0;
	int game_loop_count = 0;
	while (!game_over) {
		clock->delta();//get initial time

		//This loop is for sending the event step to all objects in the object list
		df::ObjectList all_objects = world_manager.getAllObjects();
		df::EventStep *s = new df::EventStep(game_loop_count);
		df::ObjectListIterator *li = new df::ObjectListIterator(&all_objects);
		while (!li->isDone()) {
			li->currentObject()->eventHandler(s);
			li->next();
		}

		//Continue with calculations for sleep time
		long int loop_time = clock->split();
		int intended_sleep_time = frame_time - loop_time - adjust_time;
		clock->delta();
		if (intended_sleep_time > 0) {
			Sleep(intended_sleep_time);
		}
		int actual_sleep_time = clock->split();
		adjust_time = actual_sleep_time - intended_sleep_time;

		game_loop_count++;//Increment game loop count
	}
}

void df::GameManager::setGameOver(bool is_gameover) {
	game_over = is_gameover;
}

bool df::GameManager::getGameOver() const {
	return game_over;
}

int df::GameManager::getFrameTime() const {
	return frame_time;
}

df::GameManager::~GameManager(){
	this->shutDown();
}

