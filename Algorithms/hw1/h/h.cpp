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

ifstream in("refrator.in");
ofstream out("refrator.out");
  
int main() {

	ll n;
	in >> n;
	vector<ll> ans;
	ans.assign(3, 0);
	vector<ll> mass;
	ll s = 10000000000000;
	for (ll i = 1; i * i <= n; i++){
		if (n % i == 0){
			mass.push_back(i);
			mass.push_back(n / i);
		}
	}
	

	for (ll i = 0; i < mass.size(); i++){
		ll a = mass[i];
		for (ll j = 0; j < mass.size(); j++){
			ll b = mass[j];
			if (n % (a * b) == 0){
				ll c = n / (a * b);

				if ((b + c) * a + b * c < s){
					ans[0] = a; ans[1] = b; ans[2] = c;
					s = (b + c) * a + b * c;
				}
			} 
		}
	}
	out << 2 * s << ' ' << ans[0] << ' ' << ans[1] << ' ' << ans[2] << '\n';
	return 0;
} 
