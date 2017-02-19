#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define pi pair <int, int>
#define forn(i, n) for(int i = 0; i < (int)(n); i++)

typedef long long ll;

const int INF = 1000000000;
const int MAXN = 100000;
const int MAXM = 300005;

string s;
int n;
bool comp(int a, int b){
	while (s[a] == s[b]){
		a++; b++;
	}
	return s[a] < s[b];
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	freopen("suffarray.in", "r", stdin);
	freopen("suffarray.out", "w", stdout);

	getline(cin, s);
	n = s.size();
	vector<int> arr;
	forn(i, n) arr.pb(i);

	sort(arr.begin(), arr.end(), comp);
	forn(i, n) cout << arr[i] + 1 << ' ';
	cout << '\n';

	return 0;
}