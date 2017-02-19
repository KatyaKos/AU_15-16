#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define pi pair <int, int>
#define forn(i, n) for(int i = 0; i < (int)(n); i++)

typedef long long ll;

const int INF = 1000000000;
const int MAXN = 10000000;
const int A = 4;

struct Node {
	int next[A];
	Node(){
		memset(next, -1, sizeof(next));
	} 
};

string s;
int n;

vector<Node> tree;
vector<int> type, pr, pch;
int sz;

void init(){
	pr.pb(-1);
	pch.pb(-1);
	tree.pb(Node());
	sz = 1;
}

void add_string1(int st) {
	int v = 0;
	for (int i = st; i < n; i++){
		int c = s[i] - '.';
		if (tree[v].next[c] == -1){
			pr.pb(v);
			pch.pb(c);
			tree.pb(Node());
			tree[v].next[c] = sz++;
		} 
		v = tree[v].next[c];
	}
}

void add_string2(int st) {
	int v = 0;
	for (int i = st; i < n; i++){
		int c = s[i] - '.';
		if (tree[v].next[c] == -1){
			pr.pb(v);
			pch.pb(1);
			tree.pb(Node());
			tree[v].next[1] = sz++;
			break;
		}
		v = tree[v].next[c];
	}
}


int dfs1(int v){
	int c = pch[v];
	if (v && c < 2){
		type[v] = c + 1;
		return c + 1;
	}
	forn(i, A)
		if (tree[v].next[i] != -1){
			int newy = dfs1(tree[v].next[i]);
			if (type[v] == 0) type[v] = newy;
			else if (type[v] != newy) type[v] = 3;
		}
	return type[v];
}

int tmpk = 0, k;
int dfs2(int v){
	if (type[v] == 3){
		if (v) tmpk++;
		if (tmpk == k) return v;
	
		forn(i, A){
			int u = tree[v].next[i];
			if (u != -1){
				int tans = dfs2(u);
				if (tans != -1) return tans;
			}
		}
	}
	return -1;
}


int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	freopen("common.in", "r", stdin);
	freopen("common.out", "w", stdout);

	init();
	getline(cin, s);
	s = s + '.';
	n = s.size();

	for (int i = n - 1; i >= 0; i--){
		add_string1(i);
	}
	
	getline(cin, s);
	s = s + '/';
	n = s.size();
	for (int i = n - 1; i >= 0; i--){
		add_string2(i);
	}

	cin >> k;
	if (!k){
		cout << '\n';
		return 0;
	}
	
	type.assign(sz, 0);

	dfs1(0);
	int v = dfs2(0);
	vector<char> answ;
	while (v != 0){
		answ.pb(pch[v] + '.');
		v = pr[v];
	}
	for (int i = answ.size() - 1; i >= 0; i--) cout << answ[i];
	cout << '\n';

	return 0;
}