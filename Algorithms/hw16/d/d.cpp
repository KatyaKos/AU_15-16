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
	int min, size;

	Node(){}
	Node(int xx): l(NULL), r(NULL), x(xx), key(randnum()), min(xx), size(1) {}
};

typedef Node* pNode;

void upd(pNode& v){
	v->min = v->x; v->size = 1;
	if (v->l){
		v->min = min(v->l->min, v->min);
		v->size += v->l->size;
	}
	if (v->r){
		v->min = min(v->r->min, v->min);
		v->size += v->r->size;
	}
}

void split(pNode t, pNode& l, pNode& r, int x){
	if (!t){
		l = NULL; r = NULL;
		return;
	}
	int sl = 0;
	if (t->l) sl = t->l->size;

	if (sl <= x - 1){
		split(t->r, t->r, r, x - sl - 1);
		l = t;
		upd(l);
	}else{
		split(t->l, l, t->l, x);
		r = t;
		upd(r);
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

	if (t) upd(t);
}

void insert(pNode& v, int x, int i){
	pNode t, l, r;
	pNode tmp = new Node(x);

	split(v, l, r, i);
	merge(t, l, tmp);
	merge(v, t, r);	
}

int getmin(pNode v, int li, int ri){
	pNode l, r, t1, t2;
	int ans;

	split(v, l, r, ri);
	split(l, t1, t2, li - 1);
	ans = t2->min;
	merge(l, t1, t2);
	merge(v, l, r);

	return ans;
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	freopen("rmq.in", "r", stdin);
	freopen("rmq.out", "w", stdout);

	pNode t = NULL;
	int n;
	cin >> n;
	int k, j, l, r;

	char c;
	for (int i = 0; i < n; i++){
		cin >> c;
		if (c == '+'){
			cin >> j >> k;
			insert(t, k, j);
		}else{
			cin >> l >> r;
			cout << getmin(t, l, r) << '\n';
		}
	}

	return 0;
}