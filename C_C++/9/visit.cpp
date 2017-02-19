#include <cstdio>
#include <iostream>
#include <stdlib.h>

using namespace std;

class BinOp;
class Number;

class Visitor{
public:
	virtual void visit(BinOp* tree) = 0;
	virtual void visit(Number* n) = 0;
};

class Node{
public:
	virtual void accept(Visitor*) = 0;
};

class Number: public Node{
public:
	double val;

	Number(double vval){
		val = vval;
	}
	void accept(Visitor* v){
		v -> visit(this);
	}
};

class BinOp: public Node{
public:
	Node* val1;
	Node* val2;
	char op;

	BinOp(Node* vval1, Node* vval2, char oop){
		val1 = vval1;
		val2 = vval2;
		op = oop;
	}
	void accept(Visitor* v){
		v -> visit(this);
	}
};

class Printer: public Visitor{
public:
	void visit(Number* n){
		cout << (*n).val;
	}
	void visit(BinOp* tree){
		Visitor* p = new Printer;
		cout << '(';
		(*tree).val1->accept(p);
		cout << ' ' << (*tree).op << ' ';
		(*tree).val2->accept(p);
		cout << ')';
	}
};

class Evaluate: public Visitor{
public:
	double res;
	void visit(Number* n){
		res = (*n).val;
	}
	void visit(BinOp* tree){
		//Visitor* e = new Evaluate;
		(*tree).val1->accept(this);
		double rest = res;
		(*tree).val2->accept(this);
		if ((*tree).op == '+'){
			res += rest;
		} else if ((*tree).op == '-'){
			res = rest - res;
		} else if ((*tree).op == '*'){
			res *= rest;
		} else if ((*tree).op == '/'){
			res = rest / res;
		}
	}
};

int main(){

	Node* v1 = new Number(5);
	Node* v2 = new Number(10);
	Node* s1 = new BinOp(v1, v2, '+');
	Node* s2 = new BinOp(v1, s1, '*');
	Node* s3 = new BinOp(s2, s1, '-');
	Visitor* p = new Printer;
	s3->accept(p);
	cout << '\n';
	Evaluate* e = new Evaluate;
	s3->accept(e);
	cout << (*e).res << '\n';


	return 0;
}