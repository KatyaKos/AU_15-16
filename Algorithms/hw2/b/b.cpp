#define _CRT_SECURE_NO_WARNINGS

#include <vector>
#include <fstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <algorithm>
#include <numeric>
#include <stack>
#include <stdlib.h>

 
#define INF 1000000009
#define ll long long
#define sort stable_sort

using namespace std;

//ios_base::sync_with_stdio(0);
//cin.tie(0);
ifstream in("postfix.in");
ofstream out("postfix.out");

  
int main() {

	stack <int> st;
	
	char a;
	in >> a;
	st.push((int)a - (int)'0');
	in >> a;
	st.push((int)a - (int)'0');

	while (!st.empty()){
		in >> a;
		int t = (int)a;

		if (t <= '9' && t >= '0') st.push((int)a - (int)'0');
		else if (st.size() > 1){
			if (t == '+'){ int b = st.top(); st.pop(); int c = st.top(); st.pop(); st.push(b + c);}
			else if (t == '-'){ int b = st.top(); st.pop(); int c = st.top(); st.pop(); st.push(c - b);}
			else if (t == '*'){ int b = st.top(); st.pop(); int c = st.top(); st.pop(); st.push(b * c);}
		}else break;
	}

	out << st.top() << '\n';

	return 0;
}
