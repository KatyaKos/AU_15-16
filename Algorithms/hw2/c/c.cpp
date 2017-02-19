#define _CRT_SECURE_NO_WARNINGS

#include <vector>
#include <fstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <algorithm>
#include <numeric>

 
#define INF 1000000009
#define ll long long
#define sort stable_sort

using namespace std;

//ios_base::sync_with_stdio(0);
//cin.tie(0);
ifstream in("erase.in");
ofstream out("erase.out");

  
int main() {

	string s;
	in >> s;
	int ans = 0, bal = 0;
	for (int i = 0; i < s.length(); i++){
		if (s[i] == '(') bal++;
		if (s[i] == ')') bal--;
		if (bal < 0){ ans++; bal = 0;}
	}

	ans += bal;
	out << ans << '\n';

	return 0;
}
