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


ifstream in("spaces.in");
ofstream out("spaces.out");
//ios_base::sync_with_stdio(0);
//cin.tie(0);

  
int main() {

	string s;
	getline(in, s);
	int i = 0;

	while (s[i]==' ') i++;

	for(int j = i; j < s.length() - 1; j++){
		if (s[j] == ' ' && s[j + 1] == ' ') continue;
		else{
			out << s[j];
		}
	}

	if (s[s.length() - 1] != ' ') out << s[s.length() - 1];
	out << '\n';

	return 0;
}
