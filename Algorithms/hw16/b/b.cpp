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
	int size;

	Node(){}
	Node(int xx): l(NULL), r(NULL), x(xx), key(randnum()), size(1) {}
};

typedef Node* pNode;

void upd_size(pNode& v){
	v->size = 1;
	if (v->l) v->size += v->l->size;
	if (v->r) v->size += v->r->size;
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
		upd_size(l);		
	}else{
		split(t->l, l, t->l, x);
		r = t;
		upd_size(r);
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

	if (t) upd_size(t);
}

void insert(pNode& v, int x){
	//if (find(v, x)) return;
	pNode t, l, r;
	pNode tmp = new Node(x);

	split(v, l, r, x);
	merge(t, l, tmp);
	merge(v, t, r);	
}

void erase(pNode& v, int x){
	pNode l, r, t1, t2;

	split(v, l, r, x);
	split(r, t1, t2, x + 1);
	merge(v, l, t2);
}

int kth(pNode v, int k){
	int sl = 0, sr = 0;
	if (v->r) sr = v->r->size;

	if (sr > k - 1) return kth(v->r, k);
	else if (sr < k - 1) return kth(v->l, k - sr - 1);
	else return v->x;
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	freopen("kthmax.in", "r", stdin);
	freopen("kthmax.out", "w", stdout);

	pNode t = NULL;
	int n = 0, m;
	cin >> m;

	int s, k;
	for (int i = 0; i < m; i++){
		cin >> s >> k;
		if (s == 1){
			n++;
			insert(t, k);
		}else if (s == -1){
			n--;
			erase(t, k);
		}else{
			cout << kth(t, k) << '\n';
		}
	}

	return 0;
}