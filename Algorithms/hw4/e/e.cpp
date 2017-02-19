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
#define ui unsigned int

using namespace std;

#include <cstdio>

int main() {

	cin.tie(0);
	ios_base::sync_with_stdio(0);
	freopen("cover.in", "r", stdin);
	freopen("cover.out", "w", stdout);

	int m;
	cin >> m;
	vector < pair<int, int> > seg;
	vector < pair<int, int> > ans;
	int a = 9, b = 0;
	while (a != 0 || b != 0){
		cin >> a >> b;
		seg.push_back(make_pair(a, b));
	}
	seg.pop_back();
	sort(seg.begin(), seg.end());
	//for (int j = 0; j < seg.size(); j++) cout << seg[j].first << ' ' << seg[j].second << '\n';

	int tmp_b = -1, tmp_i = -1, i = 0;
	while (seg[i].first <= 0 && i < seg.size()){
		if (seg[i].second > tmp_b){
			tmp_b = seg[i].second;
			tmp_i = i;
		}
		i++;
	}

	int r = 0;
	if (tmp_b == -1){
		cout << "No solution" << '\n';
		return 0;
	}else{
		ans.push_back(seg[tmp_i]);
		r = tmp_b;
	}

	//cout << ans[0].first << ' ' << ans[0].second << '\n';

	while (r < m && i < seg.size()){
		tmp_b = -60000, tmp_i = -1;

		while (seg[i].first <= r && i < seg.size()){
			if (seg[i].second > tmp_b){
				tmp_b = seg[i].second;
				tmp_i = i;
			}
			i++;
		}

		if (tmp_b == -60000){
			cout << "No solution" << '\n';
			return 0;
		}else{
			ans.push_back(seg[tmp_i]);
			r = tmp_b;
		}
	}

	if (r < m) cout << "No solution" << '\n';
	else{
		cout << ans.size() << '\n';
		for (int j = 0; j < ans.size(); j++) cout << ans[j].first << ' ' << ans[j].second << '\n';
	}

	return 0;
}








