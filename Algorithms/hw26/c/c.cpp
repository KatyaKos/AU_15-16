#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define pi pair <int, int>
#define forn(i, n) for(int i = 0; i < (int)(n); i++)

typedef long long ll;

const int INF = 1000000000;
const int MAX_N = 100005;
const int MAXM = 1005;
const int S = 26;
 
struct Node {
	int next[26], size, end;
 
	Node() : size(0), end(0) {
		memset(next, -1, sizeof(next));
	}
};
 
char str[MAX_N];
Node trie[MAX_N];
int last = 1;

void add(){
	int v = 0;

	for (char* c = str; *c != '\0'; c++){
		int i = *c - 'a';

		if (trie[v].next[i] == -1) trie[v].next[i] = last++;

		v = trie[v].next[i];
		trie[v].size++;
	}

	trie[v].end++;
}
 
void print_kth(int k){
	int v = 0;

	while (k >= trie[v].end){

		int down = 0;
		k -= trie[v].end;   
		for (int i = 0; i < 26; i++) {
			int nxt = trie[v].next[i];

			if (nxt == -1)
				continue;
			int sz = trie[nxt].size;
			down = 1;

			if (k < sz){
				cout << (char)(i + 'a');
				v = nxt;
				break;
			}else k -= sz;
		}

		if (!down) break;
	}

	cout << '\n';
}


int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	freopen("kthstr.in", "r", stdin);
	freopen("kthstr.out", "w", stdout);

	int n; cin >> n;

	forn(i, n){
		cin >> str;

		if (isdigit(str[0])){
			int k = atoi(str) - 1;
			print_kth(k);
		} else {
			add();
		}
	}
	
	return 0;
}