#pragma comment (linker, "/STACK:10000000000")

#include <vector>
#include <fstream>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <stack>
#include <map>
#include <queue>
 
#define INF 10000000
#define ll long long
#define ui unsigned int
#define mp make_pair
#define pb push_back
#define pi pair <int, int>

using namespace std;

#include <cassert>

const int MAX_MEM = 1e9;
int mpos = 0;
char mem[MAX_MEM];
inline void * operator new ( size_t n ) {
  char *res = mem + mpos;
  mpos += n;
  assert(mpos <= MAX_MEM);
  return (void *)res;
}
inline void operator delete ( void * ) { }

inline void * operator new [] ( size_t ) { assert(0); }
inline void operator delete [] ( void * ) { assert(0); }

int n, k;
vector <int> rnk;
vector <int> par;
vector <int> mass;
 
int find_set (int v) {
	if (v != par[v]) {
		return find_set(par[v]);
	}
	return v;
}
 
void merge(int a, int b) {
 
	if (a != b){
		if (rnk[a] < rnk[b])
			swap (a, b);
		par[b] = a;
		if (rnk[a] == rnk[b]) ++rnk[a];
	}
}

struct Ask{
	int a, b;
	int i;
	Ask(int aa, int bb, int ii): a(aa), b(bb), i(ii) {};
};

struct Node{
	int a, b;
	vector <Node*> ch;
	vector <Ask*> m;
	Node(): a(0), b(0) {};
	Node(int aa, int bb): a(aa), b(bb) {};
};

vector <Node*> root;
vector <int> ans;

inline void add(Node* v, int a, int b, int i){
	Node* u = new Node(a, b);
	v->ch.pb(u);
	root[i] = u;
}

inline void get(Node* v, int a, int b, int i){
	Ask* u = new Ask(a, b, i);
	v->m.pb(u);
}

void answer(Node* v){
	//merge and remembering
	int a, b, j;
	a = v->a; b = v->b;
	int pa = find_set(a), pb = find_set(b);
	int ppa = par[pa], rpa = rnk[pa], ppb = par[pb], rpb = rnk[pb];
	merge(pa, pb);

	//answering
	for(int i = 0; i < v->m.size(); i++){
		a = v->m[i]->a; b = v->m[i]->b; j = v->m[i]->i;
		a = find_set(a); b = find_set(b);
		if (a == b) ans[j] = 1;
		else ans[j] = 0;
	}
	//go down
	for (int i = 0; i < v->ch.size(); i++){
		answer(v->ch[i]);
	}
	//return
	par[pa] = ppa; par[pb] = ppb; rnk[pa] = rpa; rnk[pb] = rpb;
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	freopen("snm.in", "r", stdin);
	freopen("snm.out", "w", stdout);

	cin >> n >> k;
	par.resize(n); rnk.resize(n);
	root.resize(k + 1);
	root[0] = new Node;
	for (int i = 0; i < n; i++){
		par[i] = i;
		rnk[i] = 0;
	}

	char c;
	int sz = 0;
	int j, a, b;
	for (int i = 0; i < k; i++){
		cin >> c >> j >> a >> b;
		a--; b--;
		if (c == '+'){
			add(root[j], a, b, i + 1);
		}else{
			get(root[j], a, b, sz);
			sz++;
		}
	}

	ans.resize(sz);
	answer(root[0]);

	for (int i = 0; i < sz; i++){
		if (ans[i]) cout << "YES\n";
		else cout << "NO\n";
	}

	return 0;
}