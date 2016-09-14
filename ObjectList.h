
#ifndef __OBJECT_LIST_H__
#define __OBJECT_LIST_H__

const int MAX_OBJECTS = 5000;

#include "Object.h"
#include "ObjectListIterator.h"


namespace df {
	class ObjectListIterator;

	class ObjectList {

	private:
		int count;                    // Count of objects in list.
		df::Object *p_obj[MAX_OBJECTS];    // Array of pointers to objects.
	public:
		friend class ObjectListIterator;

		// Default constructor.
		ObjectList();

		// Insert object pointer in list.
		// Return 0 if ok, else -1.
		int insert(df::Object *p_o);

		// Remove object pointer from list.
		// Return 0 if found, else -1.
		int remove(df::Object *p_o);

		// Clear list (setting count to 0).
		void clear();

		// Return count of number of objects in list.
		int getCount() const;

		df::Object* df::ObjectList::getObj(int index) const;

		// Return true if list is empty, else false.
		bool isEmpty() const;

		// Return true if list is full, else false.
		bool isFull() const;
	};
}
#endif // !__OBJECT_LIST_H__
