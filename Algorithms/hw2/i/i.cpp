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
#define pb push_back

using namespace std; 
  
int main() { 

	freopen("isgood.in", "r", stdin); 
	freopen("isgood.out", "w", stdout); 
	ios_base::sync_with_stdio(0); 
	cin.tie(0);

	vector <int> pref;
	string s;
	getline(cin, s);
	pref.pb(0);
	for (int i = 0; i < s.size(); i++){
		if (s[i] == '(') pref.pb(pref.back() + 1);
		else pref.pb(pref.back());
	}
	int n;
	cin >> n;
	int l, r;
	for (int i = 0; i < n; i++){
		cin >> l >> r;
		if ((pref[r] - pref[l - 1]) * 2 == r - l + 1) cout << 1;
		else cout << 0;
	}

	cout << '\n';

	return 0; 
}
