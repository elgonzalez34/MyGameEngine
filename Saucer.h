#include "Object.h"

#define POINTS_STRING "Points"

class Saucer : public df::Object {

public:
	Saucer();
	int eventHandler(const df::Event *p_e);
	~Saucer();
};