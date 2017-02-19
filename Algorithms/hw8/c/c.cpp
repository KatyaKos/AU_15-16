#include <vector>
#include <fstream>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <math.h>
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
#define ld long double

using namespace std;
int k;
int n, m, l;
char s[110];
char t[110];
vector <vector <int> > d;

void answer(int i, int j){
	if (i == -1 || j == -1){
		return;
	}
	if (s[i] == '*' && t[j] != '*'){

		if (d[i + 1][j + 1] == d[i][j] + 1){
			answer(i - 1, j - 1);
			if (t[j] == '?') cout << 'a';
			else cout << t[j];
		}
		else if (d[i + 1][j + 1] == d[i][j + 1]){
			answer(i - 1, j);
		}
		else{
			answer(i, j - 1);
			if (t[j] == '?') cout << 'a';
			else cout << t[j];
		}

	}else if (t[j] == '*' && s[i] != '*'){

		if (d[i + 1][j + 1] == d[i][j] + 1){
			answer(i - 1, j - 1);
			if (s[i] == '?') cout << 'a';
			else cout << s[i];
		}
		else if (d[i + 1][j + 1] == d[i + 1][j]){
			answer(i, j - 1);
		}
		else{
			answer(i - 1, j);
			if (s[i] == '?') cout << 'a';
			else cout << s[i];
		}

	}else if (s[i] == '*' && t[j] == '*'){

		if (d[i + 1][j + 1] == d[i][j]) answer(i - 1, j - 1);
		else if (d[i + 1][j + 1] == d[i][j + 1]) answer(i - 1, j);
		else answer(i, j - 1);

	}else if (s[i] == t[j] || s[i] == '?' || t[j] == '?'){

		answer(i - 1, j - 1);
		if (s[i] == '?' && t[j] == '?') cout << 'a';
		else if (s[i] == '?') cout << t[j];
		else cout << s[i];

	}
}

int main(){
	//cin.tie(0);
	//ios_base::sync_with_stdio(0);
	freopen("patterns2.in", "r", stdin);
	//freopen("patterns2.out", "w", stdout);

	cin >> k;
	gets(s);
	for (int u = 0; u < k; u++){
		gets(s);
		gets(t);
		n = strlen(s); m = strlen(t);
		if (n == 0 && m == 0){
			cout << '\n';
			continue;
		}else if (n == 0){
			int flag = 0;
			for (int i = 0; i < m; i++){
				if (t[i] != '*') flag = 1;
			}
			if (flag == 0) cout << '\n';
			else cout << "NO\n";
			continue;
		}else if (m == 0){
			int flag = 0;
			for (int i = 0; i < n; i++){
				if (s[i] != '*') flag = 1;
			}
			if (flag == 0) cout << '\n';
			else cout << "NO\n";
			continue;
		}
		d.resize(n + 1);
		for (int i = 0; i <= n; i++) d[i].assign(m + 1, INF);
		d[0][0] = 0;

		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				if (s[i] == '*' && t[j] != '*'){
					
					d[i + 1][j + 1] = min(d[i + 1][j + 1], d[i][j] + 1);
					d[i + 1][j + 1] = min(d[i + 1][j + 1], d[i][j + 1]);
					d[i + 1][j + 1] = min(d[i + 1][j + 1], d[i + 1][j] + 1);

				}else if (s[i] != '*' && t[j] == '*'){
					
					d[i + 1][j + 1] = min(d[i + 1][j + 1], d[i][j] + 1);
					d[i + 1][j + 1] = min(d[i + 1][j + 1], d[i + 1][j]);
					d[i + 1][j + 1] = min(d[i + 1][j + 1], d[i][j + 1] + 1);

				}else if (s[i] == '*' && t[j] == '*'){
					
					d[i + 1][j + 1] = min(d[i + 1][j + 1], d[i][j]);
					d[i + 1][j + 1] = min(d[i + 1][j + 1], d[i + 1][j]);
					d[i + 1][j + 1] = min(d[i + 1][j + 1], d[i][j + 1]);

				} else if (s[i] == t[j] || s[i] == '?' || t[j] == '?'){

					d[i + 1][j + 1] = min(d[i + 1][j + 1], 1 + d[i][j]);

				}
			}
		}

		/*for (int i = 0; i <= n; i++){
			for (int j = 0; j <= m; j++){
				cout << d[i][j] << ' ';
			}
			cout << '\n';
		}*/

		l = d[n][m];
		if (l == INF){
			cout << "NO" << '\n';
			continue;
		}
		answer(n - 1, m - 1);
		cout << '\n';

	}

	return 0;
}