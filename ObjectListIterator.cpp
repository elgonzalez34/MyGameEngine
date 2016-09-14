#include "ObjectListIterator.h"

//The iterator class for the object list.
df::ObjectListIterator::ObjectListIterator(const ObjectList *p_l)
{
	p_list = p_l;
	first();
}

void df::ObjectListIterator::first() {
	index = 0;
}

void df::ObjectListIterator::next() {
	if (index < p_list->getCount()) {
		index++;
	}
}

bool df::ObjectListIterator::isDone() const{
	return(index == p_list->getCount());
}

df::Object* df::ObjectListIterator::currentObject() const {
	return p_list->getObj(index);
}


//df::ObjectListIterator::~ObjectListIterator()
//{
//}
