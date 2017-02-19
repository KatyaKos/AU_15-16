#ifndef SHAPE_H
#define SHAPE_H

#include "idispatcher.h"

class IShape{
public:
	virtual void visit(IDispatcher& d) = 0;
};

class Circle: public IShape {
public:
	virtual void visit(IDispatcher& d){
		d.dispatch(*this);
	}
};

class Rectangle: public IShape {
public:
	virtual void visit(IDispatcher& d){
		d.dispatch(*this);
	}
};

class Triangle: public IShape {
public:
	virtual void visit(IDispatcher& d){
		d.dispatch(*this);
	}
};

#endif
