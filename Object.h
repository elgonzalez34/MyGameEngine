
#ifndef __OBJECT_H__
#define __OBJECT_H__

#include <string>
#include "Vector.h"
#include "Event.h"

namespace df {
	class Object {

	private:
		int id;            // Unique Object identifier.
		std::string type;  // User-defined identification.
		df::Vector position;   // Position in game world.

	public:
		// Construct Object. Set default parameters and
		// add to game world (WorldManager).
		Object();

		// Destroy Object.
		// Remove from game world (WorldManager).
		virtual ~Object();

		// Set Object id.
		void setId(int new_id);

		// Get Object id.
		int getId() const;

		// Set type identifier of Object.
		void setType(std::string new_type);

		// Get type identifier of Object.
		std::string getType() const;

		// Set position of Object.
		void setPosition(df::Vector new_pos);

		// Get position of Object.
		df::Vector getPosition() const;

		//Handle and event, returns 0 if ignored, else 1
		virtual int eventHandler(const Event *p_e);

		//Comparator for object equality
		bool operator==(const Object &other) const;
	};

}

#endif // !__OBJECT_H__
