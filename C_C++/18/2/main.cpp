#include <iostream>
#include <algorithm>
#include <iterator>
#include <string>
#include <vector>

using namespace std;

typedef string::iterator si;
typedef vector<char>::iterator vci;
typedef ostream_iterator<char> ois;

struct spaces{
	int flag = 1;
	char operator() (char s){
		//cout << flag << ' ';
		if (s == ' ' && flag) return '\0';
		else{
			flag = 0;
			return s;
		}
	}
};

struct printed{
	char operator() (char s){
		return s;
	}
};


int main(){

	string s = "                   I've been gone for so long now                                ";
	vector<char> t; t.resize(s.size());
	vector<char> tt; tt.resize(t.size());
	ois it = ois (cout);
	spaces sp, sp1;
	printed p;

	transform(s.begin(), s.end(), t.begin(), sp);
	reverse(t.begin(), t.end());
	transform(t.begin(), t.end(), tt.begin(), sp1);
	reverse(tt.begin(), tt.end());
	transform(tt.begin(), tt.end(), it, p);
	cout << " *stop*\n";

	return 0;
}