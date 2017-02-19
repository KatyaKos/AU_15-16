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

 
#define INF 1000000009
#define ll long long
#define sort stable_sort

using namespace std;

//ios_base::sync_with_stdio(0);
//cin.tie(0);
ifstream in("check.in");
ofstream out("check.out");

  
int main() {

	string s;
	in >> s;
	stack <int> st;
	st.push(0);
	int bal1 = 0, bal2 = 0, bal3 = 0;
	for (int i = 0; i < s.length(); i++){
		if (s[i] == '('){ bal1++; st.push(1);}
		else if (s[i] == ')'){ 
			if (st.top() == 1){ bal1--; st.pop();}
			else{ out << "NO" << '\n'; return 0;}
		}
		if (s[i] == '['){ bal2++; st.push(2);}
		else if (s[i] == ']'){ 
			if (st.top() == 2){ bal2--; st.pop();}
			else{ out << "NO" << '\n'; return 0;}
		}
		if (s[i] == '{'){ bal3++; st.push(3);}
		else if (s[i] == '}'){ 
			if (st.top() == 3){ bal3--; st.pop();}
			else{ out << "NO" << '\n'; return 0;}
		}
 

		if (bal1 < 0 || bal2 < 0 || bal3 < 0){
			out << "NO" << '\n';
			return 0;
		}
	}

	if (bal1 + bal2 + bal3 == 0) out << "YES" << '\n';
	else out << "NO" << '\n';

	return 0;
}
