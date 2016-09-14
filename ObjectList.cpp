#include "ObjectList.h"

//A class that acts as a list of objects. It can insert, remove, clear, and get specific objects
df::ObjectList::ObjectList()
{
	count = 0;
}

int df::ObjectList::insert(df::Object *p_o) {
	if (count == MAX_OBJECTS)  // Check if room.
		return false;
	p_obj[count] = p_o;
	count++;
	return true;
}

int df::ObjectList::remove(df::Object *p_o) {
	for (int i = 0; i<count; i++) {
		if (*p_obj[i] == *p_o) {           // Found...
			for (int j = i; j<count - 1; j++) // ...so scoot over
				*p_obj[j] = *p_obj[j + 1];
			count--;
			return true; // Found.
		}
	}
	return false; // Not found.
}

void df::ObjectList::clear() {
	count = 0;
}

int df::ObjectList::getCount() const {
	return count;
}

df::Object* df::ObjectList::getObj(int index) const {
	return p_obj[index];
}


bool df::ObjectList::isEmpty() const {
	if (count == 0) {
		return true;
	}
	else {
		return false;
	}
}

bool df::ObjectList::isFull() const {
	if (count == MAX_OBJECTS) {
		return true;
	}
	else {
		return false;
	}
}





//df::ObjectList::~ObjectList()
//{
//}
