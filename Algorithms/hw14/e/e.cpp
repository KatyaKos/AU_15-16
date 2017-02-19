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
#include <queue>
#include <string.h>
#include <bitset>
 
#define INF 1000000009
#define ll long long
#define ui unsigned int
#define mp make_pair
#define pb push_back

using namespace std;

#include <cassert>

bool comp(string a, string b){
	return b + a < a + b;
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);

	vector <string> ans;
	char s[110];
	while (scanf("%s\n", s) == 1){
		ans.pb(s);
	}
	sort(ans.begin(), ans.end(), comp);
	for (int i = 0; i < ans.size(); i++){
		cout << ans[i];
	}
	cout << '\n';

	return 0;
}