#include "autotest.h"
#include "huffman_test.h"
#include "../src/huffman.h"
#include <fstream>
#include <cstring>
#include <ctime>

using namespace std;

const char* test = "test.txt";
const char* encoded = "encoded.txt";
const char* decoded = "decoded.txt";

HuffTest::HuffTest(): Testing(){
	run_test(&test1);
	run_test(&test2);
}

HuffTest::~HuffTest(){
	remove(test);
	remove(encoded);
	remove(decoded);
}

void HuffTest::save_test(string& buf){
	ofstream fout(test, ofstream::binary);
	fout << buf;
	fout.close();
}

const int MAXSZ = 1<<25;
bool HuffTest::is_equal(){
	ifstream f(test, ifstream::binary);
	ifstream ff(decoded, ifstream::binary);

	char* buf = new char[MAXSZ];
	char* buff = new char[MAXSZ];
	bool ans = memcmp(buf, buff, MAXSZ) == 0;
	delete[] buf;
	delete[] buff;

	f.close();
	ff.close();

	return ans;
}

bool HuffTest::check(string& buf){
	Encode hf(test, encoded);
	hf.Encoding();
	Decode dhf(encoded, decoded);
	dhf.Decoding();
	bool ans = is_equal();

	return ans;
}

bool HuffTest::test1(){
	string buf;
	srand(time(0));
	forn(i, SZ){
		buf += char(65 + rand() % 60);
	}
	save_test(buf);
	return check(buf);
}

bool HuffTest::test2() {
	string buf;
	srand(time(0));
	forn(i, SZ){
		buf += char(rand() % 256);
	}
	save_test(buf);
	return check(buf);
}