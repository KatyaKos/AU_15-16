#ifndef HUFFMAN_TEST_H
#define HUFFMAN_TEST_H
#include "autotest.h"
#include <string>

using namespace std;

const int SZ = 1<<10;

class HuffTest: public Testing{
private:
	int sz;
	static void save_test(string& buf);
	static bool is_equal();
public:
	HuffTest();
	~HuffTest();
	static bool check(string& buf);
	static bool test1();
	static bool test2();
};
#endif
