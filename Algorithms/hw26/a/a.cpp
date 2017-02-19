#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define pi pair <int, int>
#define forn(i, n) for(int i = 0; i < (int)(n); i++)

typedef long long ll;

const int INF = 1000000000;
const int MAXN = 1000005;
const int MAXM = 100005;
const int S = 26;

string s, t;
int ans[MAXM];

struct Node {
	int next[S], go[S];
	int leaf, link, p, pch, end;
};

Node tree[MAXM];
int sz;

void init(){
	tree[0].p = tree[0].leaf = -1;
	tree[0].end = tree[0].link = 0;
	memset(tree[0].next, -1, sizeof(tree[0].next));
	memset(tree[0].go, -1, sizeof(tree[0].go));
	sz = 1;
}

void add_string(const string &s, int num) {
	int v = 0;
	for(char c : s) {
		c -= 'a';
		if (tree[v].next[c] == -1) {
			memset(tree[sz].next, -1, sizeof(tree[sz].next));
			memset(tree[sz].go, -1, sizeof(tree[sz].go));
			tree[sz].p = v;
			tree[sz].pch = c;
			tree[sz].link = -1;
			tree[sz].end = 0;
			tree[v].next[c] = sz++;
		} 
		v = tree[v].next[c];
	}
	tree[v].leaf = num;
}

int go(int v, int c);

int get_link(int v) {
	if (tree[v].link == -1) { 
		if (!v || !tree[v].p)
			tree[v].link = 0;
		else
			tree[v].link = go(get_link(tree[v].p), tree[v].pch);
	}
	return tree[v].link;
}

int go(int v, int c) {
	if (tree[v].go[c] == -1) {
		if (tree[v].next[c] != -1)
			tree[v].go[c] = tree[v].next[c];
		else
			tree[v].go[c] = !v ? 0 : go(get_link(v), c);
	}
	return tree[v].go[c];
}

void suf_link(int v) {
	if (!v) return;
	tree[v].end = 1;
	if (tree[v].leaf != -1) ans[tree[v].leaf] = 1;
	suf_link(get_link(v));
}

void solve(int n, int m){
	int v = 0;
	forn(i, n) {
		t[i] -= 'a';
		v = go(v, t[i]);
		tree[v].end = 1;
		if (tree[v].leaf != -1) ans[tree[v].leaf] = 1;
	}

	for (int i = sz - 1; i >= 0; i--){
		if (tree[i].end)
			suf_link(get_link(i));
	}

	forn(i, m) {
		if (ans[i + 1])
			cout << "Yes\n";
		else
			cout << "No\n";
	}
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	freopen("dictionary.in", "r", stdin);
	freopen("dictionary.out", "w", stdout);

	int n, m;
	getline(cin, t);
	n = int(t.size());
	cin >> m;
	getline(cin, s);

	init();
	forn(i, m) {
		getline(cin, s);
		add_string(s, i + 1);
	}

	solve(n, m);
	
	return 0;
}