#include "Vector.h"
#include <math.h>  

//This the the vector class. It holds the x and y coordinates for a point. 
//It has getters and setters for the x,y coordinates.
//It has functions for getting the magnitute, scaling, normalizing, and performings operations on two vectors.
df::Vector::Vector()
{
	this->x = 0;
	this->y = 0;
}

df::Vector::Vector(float init_x, float init_y)
{
	this->x = init_x;
	this->y = init_y;
}

void df::Vector::setX(float new_x) {
	this->x = new_x;
}

void df::Vector::setY(float new_y) {
	this->y = new_y;
}

float df::Vector::getX() const{
	return this->x;
}

float df::Vector::getY() const {
	return this->y;
}

void  df::Vector::setXY(float new_x, float new_y) {
	x = new_x;
	y = new_y;
}

float df::Vector::getMagnitude() const{
	float mag = sqrt(x*x + y*y);
	return mag;
}

void df::Vector::normalize() {
	int length = getMagnitude();
	if (length > 0) {
		x = x / length;
		y = y / length;
	}
}

void df::Vector::scale(float s) {
	x = x * s;
	y = y * s;
}

df::Vector df::Vector::operator+(const Vector &other) const {
	Vector *v = new Vector();
	v->x = x + other.x;
	v->y = y + other.y;
	return *v;
}

df::Vector df::Vector::operator-(const Vector &other) const {
	Vector *v = new Vector();
	v->x = x - other.x;
	v->y = y - other.y;
	return *v;
}

df::Vector df::Vector::operator/(const Vector &other) const {
	Vector *v = new Vector();
	v->x = x / other.x;
	v->y = y / other.y;
	return *v;
}

df::Vector df::Vector::operator*(const Vector &other) const {
	Vector *v = new Vector();
	v->x = x * other.x;
	v->y = y * other.y;
	return *v;
}

bool df::Vector::operator==(const Vector &other) const {
	Vector *v = new Vector();
	if (x == other.x && y == other.y)
		return true;
	else {
		return false;
	}
}

bool df::Vector::operator!=(const Vector &other) const {
	Vector *v = new Vector();
	if (x != other.x || y != other.y)
		return true;
	else {
		return false;
	}
}