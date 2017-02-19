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
#include <set>
#include <string>
 
#define INF 1000000009
#define ll long long
#define ui unsigned int

using namespace std;


const int H_c = 12 * 60 * 60;

int main() {

	cin.tie(0);
	ios_base::sync_with_stdio(0);
	freopen("watches.in", "r", stdin);
	freopen("watches.out", "w", stdout);

	int n;
	//n = readInt();
	cin >> n;
	vector <int> h;
	h.resize(n);

	for (int i = 0; i < n; i++){
		int a, b, c;
		char ch;
		cin >> a >> ch >> b >> ch >> c;
		h[i] = (a - 1) * 60 * 60 + b * 60 + c;
		//cout << h[i] << '\n';
	}

	sort(h.begin(), h.end());
	vector <int> ans;
	ans.assign(n, 0);
	for (int i = 1; i < n; i++){
		ans[0] += H_c - (h[i] - h[0]);
	}

	int ans_min = ans[0];
	int ans_hour = h[0];
	//cout << ans_min;
	for (int i = 1; i < n; i++){
		ans[i] = ans[i - 1] + (n - 1) * (h[i] - h[i - 1]) - (H_c - (h[i] - h[i - 1]));
		if (ans[i] < ans_min){
			ans_min = ans[i];
			ans_hour = h[i];
		}
	}

	int sec = ans_hour % 60;
	ans_hour = ans_hour / 60;
	int min = ans_hour % 60;
	int hour = 1 + ans_hour / 60;

	//cout << ans_hour << '\n';

	cout << hour << ':';
	if (min < 10) cout << '0';
	cout << min << ':';
	if (sec < 10) cout << '0';
	cout << sec << '\n';

	
	//cout << '\n';
	//writeChar('\n');

	//flush();

	return 0;
}








