#include "Object.h"
#include "WorldManager.h"

//This is the Object parent class.
//It keeps track of the object number, id, its type, its x,y position, and inserts itself
df::Object::Object()
{
	static int object_num;
	object_num++;
	setId(object_num);
	setType("Object");
	Vector *initialPos = new Vector();
	setPosition(*initialPos);
	
	df::WorldManager &world_manager = df::WorldManager::getInstance();
	world_manager.insertObject(this);
}

void df::Object::setId(int new_id) {
	id = new_id;
}

int df::Object::getId() const {
	return id;
}

void df::Object::setType(std::string new_type) {
	type = new_type;
}

std::string df::Object::getType() const {
	return type;
}

void df::Object::setPosition(df::Vector new_pos) {
	position = new_pos;
}

df::Vector df::Object::getPosition() const {
	return position;
}

bool df::Object::operator==(const Object &other) const {
	if (getId() == other.getId()) {
		return true;
	}
	else {
		return false;
	}
}

int df::Object::eventHandler(const Event *p_e) {
	return 0;
}


df::Object::~Object()
{
	df::WorldManager &world_manager = df::WorldManager::getInstance();
	world_manager.removeObject(this);
}
