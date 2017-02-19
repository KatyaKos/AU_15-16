#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define pi pair <int, int>
#define forn(i, n) for(int i = 0; i < (int)(n); i++)

typedef long long ll;

const int INF = 1000000000;
const int MAXN = 80005;
const int MAXM = 255;
const int S = 26;
 
struct Node{

	map<char, int> next;
	int p, suf, ok;
	char pch;
 
	Node() : ok(0) {}
};
 
Node trie[MAXN];
int root = 0, size = 1, q[MAXN];
string str;
 
inline void add() {
	int v = root;
	forn(i, str.size()){
		char c = str[i];

		if (trie[v].next.find(c) == trie[v].next.end()) {
			trie[v].next[c] = size;
			trie[size].p = v;
			trie[size].pch = c;
			v = size++;
		} else
			v = trie[v].next[c];
	}
	trie[v].ok = 1;
}
 
inline int go(int v, char c){

	if (trie[v].next.find(c) == trie[v].next.end())
		trie[v].next[c] = v == root ? root : go(trie[v].suf, c);
	return trie[v].next[c];
}
 
inline void set_suf(int v){

	if (v == root || trie[v].p == root)
		trie[v].suf = root;
	else
		trie[v].suf = go(trie[trie[v].p].suf, trie[v].pch);
}
 
void set_sufs(){
	int head = 0, tail = 0;
	q[head++] = root;
	while (head > tail) {
		int v = q[tail++];
		for (auto e : trie[v].next)
			q[head++] = e.second;
		set_suf(v);
		if (trie[trie[v].suf].ok)
			trie[v].ok = 1;
	}
}


int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	freopen("console.in", "r", stdin);
	freopen("console.out", "w", stdout);

	int n;
	cin >> n;
	getline(cin, str);

	forn(i, n){
		getline(cin, str);
		add();
	}

	set_sufs();
	while (getline(cin, str)){

		int found = 0, v = root;
		forn(i, str.size()){
			char c = str[i];
			v = go(v, c);
			if (trie[v].ok){
				found = 1;
				break;
			}
		}
		if (found) cout << str << '\n';
	}
	
	return 0;
}