#include <iostream>
#include <vector>
#include "idispatcher.h"
#include "ishape.h"
#include "intersection.h"

using namespace std;

template <typename T>
class Dispatcher: public IDispatcher {
private:
	T& step;
	int ans;
public:
	Dispatcher(T& step): step(step) {}

	void dispatch(Circle &shape){
		ans = step.Intersect(shape);
	}
	void dispatch(Triangle& shape){
		ans = step.Intersect(shape);
	}
	void dispatch(Rectangle &shape){
		ans = step.Intersect(shape);
	}

	int get_ans() {
		return ans;
	}
};

template <typename T1, typename T2, int Arity>
struct ThirdStep{
	vector<IShape*> args;
	T1& arg1;
	T2& arg2;
	ThirdStep(T1& arg1, T2& arg2): arg1(arg1), arg2(arg2) {}

	template <typename T3>
	int Intersect(T3& arg3);

	void add_arg(IShape* s) {
		args.push_back(s);
	}
};

template <typename T1, int Arity>
struct ParentSecondStep{
	vector<IShape*> args;
	T1& arg1;
	ParentSecondStep(T1& arg1): arg1(arg1){}

	void add_arg(IShape* s){
		args.push_back(s);
	}
};

template <typename T1, int Arity>
struct SecondStep: public ParentSecondStep<T1, Arity>{
	SecondStep(T1& aarg1): ParentSecondStep<T1, Arity>(aarg1){}

	template <typename T2>
	int Intersect(T2& arg2) {
		ThirdStep<T1, T2, Arity> step(this->arg1, arg2);

		for(int i = 1; i < this->args.size(); i++) step.add_arg(this->args[i]);
		Dispatcher<ThirdStep<T1, T2, Arity>> dsp(step);
		this->args[0]->visit(dsp);

		return dsp.get_ans();
	}
};

template <typename T1>
struct SecondStep<T1, 2>: public ParentSecondStep<T1, 2>{

	SecondStep(T1& aarg1): ParentSecondStep<T1, 2>(aarg1){}

	template <typename T2>
	int Intersect(T2& arg2) {
		return CheckIntersection(this->arg1, arg2);
	}
};

template <int Arity>
struct FirstStep{
	vector<IShape*> args;
	FirstStep(){}

	void add_arg(IShape* s){
		args.push_back(s);
	}

	template <typename T1>
	int Intersect(T1& arg1) {
		SecondStep<T1, Arity> step(arg1);
		for(int i = 1; i < args.size(); i++) step.add_arg(args[i]);

		Dispatcher<SecondStep<T1, Arity>> dsp(step);
		args[0]->visit(dsp);
		return dsp.get_ans();
	}
};

int CheckIntersection(IShape* s0, IShape* s1) {
	FirstStep<2> step;
	step.add_arg(s1);
	Dispatcher<FirstStep<2>> dsp(step);
	s0->visit(dsp);
	return dsp.get_ans();
}

int main() {
	IShape* s0 = new Circle;
	IShape* s1 = new Rectangle;
	IShape* s2 = new Triangle;

	CheckIntersection(s0, s2);
	return 0;
}
