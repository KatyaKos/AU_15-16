#include "autotest.h"
#include <cstdio>

using namespace std;

Testing::Testing(){
	result = 0;
	num = 1;
	state = wait;
}

void Testing::start_test(){
	if (state != wait) {
		cerr << "This test is not ready yet." << endl;
		throw;
	}
	state = run;
	cout << "Start test " << num << endl;
}

void Testing::finish_test(){
	if (state != run) {
		cerr << "You can't finish this test, it's still running." << endl;
		throw;
	}
	cout << "Test " << num << " is finished. Verdict is " << (verd == AC ? "AC" : "WA") << endl;
	
	if (verd == AC){
		++result;
	}
	state = wait;
	num++;
}

void Testing::show(){
	cout << "What we got: " << result << " AC out of " << num - 1 << endl;
}

void Testing::run_test(bool (*test)()){
	start_test();
	verd = (test() ? AC : WA);
	finish_test();
}
