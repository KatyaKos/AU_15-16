#ifndef IDISPATCHER_H
#define IDISPATCHER_H

class Circle;
class Rectangle;
class Triangle;

class IDispatcher {
public:
    virtual void dispatch(Rectangle& shape) = 0;
    virtual void dispatch(Triangle& shape) = 0;
    virtual void dispatch(Circle& shape) = 0;
};

#endif
