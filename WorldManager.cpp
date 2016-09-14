#include "WorldManager.h"

//The WorldManager class keeps a list of objects to be updated and deleted, and can update these lists
//WorldManager can also find specific objects from its list of all objects

df::WorldManager::WorldManager()
{
	setType("WorldManager");
	df::ObjectList *updates_ptr = new df::ObjectList();
	updates = *updates_ptr;
	df::ObjectList *deletions_ptr = new df::ObjectList();
	deletions = *deletions_ptr;
}

df::WorldManager &df::WorldManager::getInstance() {
	static WorldManager world_manager;
	return world_manager;
}

int df::WorldManager::startUp() {
	Manager::startUp();
	return true;
}

void df::WorldManager::shutDown() {
	ObjectList ol = updates;
	ObjectListIterator li((const ObjectList *) &ol);
	for (li.first(); !li.isDone(); li.next()){
		delete(li.currentObject());
	}
	Manager::shutDown();
}


int df::WorldManager::insertObject(df::Object *p_o) {
	if (updates.insert(p_o)) {
		return true;
	}
	else {
		return false;
	}
}

int df::WorldManager::removeObject(df::Object *p_o) {
	if (updates.remove(p_o)) {
		return true;
	}
	else {
		return false;
	}
}

df::ObjectList df::WorldManager::getAllObjects() const{
	return updates;
}

// Returns the matching objects from the list
df::ObjectList df::WorldManager::objectsOfType(std::string type) const {
	ObjectList *list = new ObjectList();
	ObjectListIterator *li = new ObjectListIterator((const ObjectList *)&updates);
	for (li->first(); !li->isDone(); li->next()) {
		if (li->currentObject()->getType() == type) {
			list->insert(li->currentObject());
		}
	}
	return *list;
}

void df::WorldManager::update() {
	// Object might already have been marked, so only add once.
	ObjectListIterator *li = new ObjectListIterator((const ObjectList *)&deletions);
	while (!li->isDone()) {
		delete(li->currentObject());
		li->next();
	}
	// Object not in list, so add.
	deletions.clear();
}

int df::WorldManager::markForDelete(Object *p_o) {
	// Object might already have been marked, so only add once.
	ObjectListIterator *li = new ObjectListIterator((const ObjectList *)&deletions);
	while (!li->isDone()){
		if (li->currentObject() == p_o) { // Object already in list.
			return 0;                // This is still "ok".
		}
		li->next();
	}
	// Object not in list, so add.
	deletions.insert(p_o);
	return 1;
}

//df::WorldManager::~WorldManager()
//{
//}
