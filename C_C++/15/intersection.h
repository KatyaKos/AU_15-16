#ifndef INTERSECTION_H
#define INTERSECTION_H

#include "ishape.h"

int CheckIntersection(Rectangle& s0, Rectangle& s1);
int CheckIntersection(Rectangle& s0, Triangle& s1);
int CheckIntersection(Rectangle& s0, Circle& s1);
int CheckIntersection(Triangle& s0, Rectangle& s1);
int CheckIntersection(Triangle& s0, Triangle& s1);
int CheckIntersection(Triangle& s0, Circle& s1);
int CheckIntersection(Circle& s0, Rectangle& s1);
int CheckIntersection(Circle& s0, Triangle& s1);
int CheckIntersection(Circle& s0, Circle& s1);
#endif
