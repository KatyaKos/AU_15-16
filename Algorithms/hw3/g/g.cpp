#define _CRT_SECURE_NO_WARNINGS
#pragma comment (linker, "/STACK:10000000000")

#include <vector>
#include <fstream>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <stack>
#include <map>
 
#define INF 1000000009
#define ll long long
#define sort stable_sort

using namespace std;

stack <int> val;
stack <char> oper;

int Make(char op){
	//cout << val.top();
	int n1 = val.top(); val.pop();
	int n2 = val.top(); val.pop();
	//cout << n1 << ' ' << n2 << '\n';
	if (op == '+') val.push(n1 + n2);
	else val.push(n2 - n1);
}

int main() {

	freopen("evalpm.in", "r", stdin);
	freopen("evalpm.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	map <char, int> prior;
	prior.insert(make_pair('+', 1));
	prior.insert(make_pair('-', 1));
	prior.insert(make_pair('(', INF));
	prior.insert(make_pair(')', 0));

	string s;
	getline(cin, s);
	s += ")";
	int n = s.size();
	int num = 0;
	oper.push('(');
	int flag = 0;
	
	for (int i = 0; i < n; i++){

		if (s[i] >= '0'){
			num = num * 10 + (s[i] - '0');
			flag = 1;
		}else{
			if (flag == 1){
				val.push(num);
				flag = 0;
			}
			num = 0;
			char op = s[i];

			while (oper.top() != '(' && prior[oper.top()] >= prior[op]){
				Make(oper.top());
				oper.pop();
			}
			//cout << val.top();
			//cout << oper.top();
			
			if (op == ')') oper.pop();
			else oper.push(op);
			//return 0;		
		}

	}
	
	
	cout << val.top() << '\n';

	return 0;
}


