#pragma comment (linker, "/STACK:10000000000")

#include <vector>
#include <fstream>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <cstring>
//#include <algorithm>
#include <numeric>
#include <stack>
#include <map>
#include <queue>
#include <string.h>
#include <bitset>
 
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

int randnum(){
	return (rand() << 16) ^ rand();
}
              
struct Node{
	Node *l, *r;
	int key, x;
	ll sum;

	Node(){}
	Node(int xx): l(NULL), r(NULL), x(xx), key(randnum()), sum(x) {}
};

typedef Node* pNode;
const int M = 1e9;

void upd_sum(pNode& v){
	v->sum = v->x;
	if (v->l) v->sum += v->l->sum;
	if (v->r) v->sum += v->r->sum;
}

bool find(pNode t, int x) {
	if (!t) return false;
	if (t->x < x) return find(t->r, x);
	if (t->x > x) return find(t->l, x);
	return true;
}

void split(pNode t, pNode& l, pNode& r, int x){
	if (!t){
		l = NULL; r = NULL;
	}else if (t->x < x){
		split(t->r, t->r, r, x);
		l = t;
		upd_sum(l);		
	}else{
		split(t->l, l, t->l, x);
		r = t;
		upd_sum(r);
	}
}

void merge(pNode& t, pNode l, pNode r){
	if (!r) t = l;
	else if (!l) t = r;
	else if (r->key > l->key){
		merge(l->r, l->r, r);
		t = l;
	}else{
		merge(r->l, l, r->l);
		t = r;
	}

	if (t) upd_sum(t);
}

void insert(pNode& v, int x){
	if (find(v, x)) return;
	pNode t, l, r;
	pNode tmp = new Node(x);

	split(v, l, r, x);
	merge(t, l, tmp);
	merge(v, t, r);	
}

ll getsum(pNode& v, int lx, int rx){
	ll ans;
	pNode l, r, t1, t2; 

	split(v, l, r, lx);
	split(r, t1, t2, rx + 1);
	if (t1) ans = t1->sum;
	else ans = 0;

	merge(r, t1, t2);
	merge(v, l, r);
	return ans;
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	freopen("sum2.in", "r", stdin);
	freopen("sum2.out", "w", stdout);

	pNode t = NULL;
	int n;
	cin >> n;

	char s; int l, r, k;
	ll ans = 0;
	for (int i = 0; i < n; i++){
		cin >> s;
		if (s == '+'){
			cin >> k;
			insert(t, (k + ans) % M);
			ans = 0;
		}else{
			cin >> l >> r;
			ans = getsum(t, l, r);
			cout << ans << '\n';
		}
	}

	return 0;
}