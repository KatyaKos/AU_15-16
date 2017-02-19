#include <cstdio>
#include <iostream>
#include <stdlib.h>

using namespace std;

class OutputStream {
public:
  virtual void print(int t){}
  virtual void print(double d){}
  virtual void print(const char* s){}
  void flush(){}
};

class ConsolOutputStream:public OutputStream{
public:
	void print(int t){
		cout << t <<'\n';
	}
	void print(double d){
		cout << d << '\n';
	}
	void print(const char* s){
		cout << s << '\n';
	}
    void flush(){
        cout.flush();
    }
};

class ErrorOutputStream:public OutputStream{
public:
	void print(int t){
		cerr << t <<'\n';
	}
	void print(double d){
		cerr << d << '\n';
	}
	void print(const char* s){
		cerr << s << '\n';
	}
    void flush(){
        cerr.flush();
    }
};

class FileOutputStream:public OutputStream{
private:
	char* name;
	FILE* fout;
public:
	FileOutputStream(char* nname){
		name = nname;
		fout = fopen(nname, "w");
	}
	~FileOutputStream(){
		fclose(fout);
	}
	void print(int t){
		fprintf(fout, "%i\n", t);
	}
	void print(double d){
		fprintf(fout, "%f\n", d);
	}
	void print(const char* s){
		fprintf(fout, "%s\n", s);
	}
    void flush(){
        fflush(fout);
    }
};

int main(){

	int a = 4;
	double b = 1.4;
	const char* c = "Hi";
	OutputStream base;
	OutputStream* p;

	ConsolOutputStream cons;
	p = &cons;
	cout << "Consol:\n";
	p->print(a);
	p->print(b);
	p->print(c);
    p->flush();

	ErrorOutputStream err;
	p = &err;
	cout << "Error:\n";
	p->print(c);

	char name[] = "out.txt";
	FileOutputStream fil(name);
	p = &fil;
	cout << "Check out.txt\n";
	p->print(b);
	return 0;
}