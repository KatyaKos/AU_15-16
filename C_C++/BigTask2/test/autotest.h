#ifndef AUTOTEST_H
#define AUTOTEST_H
#include <iostream>

using namespace std;

enum Verdict {AC, WA};
enum State {run, wait};

class Testing{
private:
	int result, num;
protected:
	Verdict verd;
	State state;
public:
	Testing();
	void start_test();
	void finish_test();
	void show();
	void run_test(bool (*test)());
};

#endif
