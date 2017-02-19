#include <iostream>
#include "intersection.h"

using namespace std;

int CheckIntersection(Rectangle& s0, Rectangle& s1) {
	cout <<  "Rectangle Rectangle\n";
	return 1;
}

int CheckIntersection(Rectangle& s0, Triangle& s1) {
	cout <<  "Rectangle Triangle\n";
	return 1;
}

int CheckIntersection(Rectangle& s0, Circle& s1) {
	cout <<  "Rectangle Circle\n";
	return 1;
}

int CheckIntersection(Triangle& s0, Rectangle& s1) {
	cout <<  "Triangle Rectangle\n";
	return 1;
}

int CheckIntersection(Triangle& s0, Triangle& s1) {
	cout <<  "Triangle Triangle\n";
	return 1;
}

int CheckIntersection(Triangle& s0, Circle& s1) {
	cout <<  "Triangle Circle\n";
	return 1;
}

int CheckIntersection(Circle& s0, Rectangle& s1) {
	cout <<  "Circle Rectangle\n";
	return 1;
}

int CheckIntersection(Circle& s0, Triangle& s1) {
	cout <<  "Circle Triangle\n";
	return 1;
}

int CheckIntersection(Circle& s0, Circle& s1) {
	cout <<  "Circle Circle\n";	
	return 1;
}