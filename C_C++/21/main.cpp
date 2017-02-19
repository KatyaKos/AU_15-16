#include <bits/stdc++.h>

using namespace std;

struct IDispatcher;

struct IShape{
	virtual void visit(IDispatcher* d) = 0;
};

struct Circle{
	virtual void visit(IDispatcher* d);
};

struct Rectangle{
	virtual void visit(IDispatcher* d);
};

struct Triangle{
	virtual void visit(IDispatcher* d);
};


int CheckIntersection(Rectangle* s0, Rectangle* s1){
	cout <<  "Rectangle Rectangle\n";
	return 1;
}

int CheckIntersection(Rectangle* s0, Triangle* s1){
	cout <<  "Rectangle Triangle\n";
	return 1;
}

int CheckIntersection(Rectangle* s0, Circle* s1){
	cout <<  "Rectangle Circle\n";
	return 1;
}

int CheckIntersection(Triangle* s0, Rectangle* s1){
	cout <<  "Triangle Rectangle\n";
	return 1;
}

int CheckIntersection(Triangle* s0, Triangle* s1){
	cout <<  "Triangle Triangle\n";
	return 1;
}

int CheckIntersection(Triangle* s0, Circle* s1){
	cout <<  "Triangle Circle\n";
	return 1;
}

int CheckIntersection(Circle* s0, Rectangle* s1){
	cout <<  "Circle Rectangle\n";
	return 1;
}

int CheckIntersection(Circle* s0, Triangle* s1){
	cout <<  "Circle Triangle\n";
	return 1;
}

int CheckIntersection(Circle* s0, Circle* s1){
	cout <<  "Circle Circle\n";	
	return 1;
}

struct ListEnd {};

template <class TItem> 
struct IDispatchPart{
	virtual void Dispatch(TItem &item) = 0;
};

template <class TItem>
struct IDispatcherStep: IDispatchPart<typename TItem::item>, IDispatcherStep<typename TItem::next> {};

template<>
struct IDispatcherStep<ListEnd> {};

template <class TItem1, class TItem2 = ListEnd>
struct TypeList{
	typedef TItem1 item;
	typedef TItem2 next;
};

typedef TypeList<Circle, TypeList<Rectangle, TypeList<Triangle> > > Shapes;
struct IDispatcher : IDispatcherStep<Shapes> {};

template <class Step>
struct SoMuchDispatcher: IDispatcher{
	Step step;
};

template <class TItem, class Step>
struct Dispatcher: Dispatcher<typename TItem::next, Step>{
	using SoMuchDispatcher<Step>::step;
	int ans;

	virtual void Dispatch(typename TItem::item &shape){
		step.Intersect(&shape);
		ans = step.ans;
	}
};

template <class Step>
struct Dispatcher<ListEnd, Step>: SoMuchDispatcher<Step> {};

template <class TItem, class TDisp>
void VisitMe(TItem &self, TDisp *d){
	((IDispatchPart<TItem>*) d)->Dispatch(self);
}

void Circle::visit(IDispatcher *d){
	VisitMe(*this, d);
}

void Rectangle::visit(IDispatcher *d){
	VisitMe(*this, d);
}

void Triangle::visit(IDispatcher *d){
	VisitMe(*this, d);
}


template <class s0>
struct SecondStep{
	int ans;
	s0* arg0;
	vector<IShape*> mass;

	template <class s1>
	void Intersect(s1* arg1){
		ans = CheckIntersection(arg0, arg1);
	}
};

struct FirstStep{
	int ans;
	vector<IShape*> mass;

	template <class s0>
	void Intersect(s0* arg0){
		SecondStep<s0> step;

		step.arg0 = arg0;
		for (int i = 1; i < (int) mass.size(); i++)
			step.mass.push_back(mass[i]);

		Dispatcher<Shapes, SecondStep<s0> > d;
		d.step = step;
		mass[0]->visit(&d);
		ans = d.ans;
	}
};


bool CheckIntersection(IShape* s0, IShape* s1){  
	FirstStep step; 
	step.mass.push_back(s1);
	Dispatcher<Shapes, FirstStep> d;  
	d.step = step;
	s0->visit(&d);
	return d.ans;
}

int main(){
	IShape *c, *r, *t;
	c = (IShape*) new Circle;
	r = (IShape*) new Rectangle;
	t = (IShape*) new Triangle;
	CheckIntersection(c, r);
	CheckIntersection(t, r);
	CheckIntersection(c, c);
	return 0;
}
