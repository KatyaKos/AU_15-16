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
#include <unordered_map>
#include <queue>
#include <set>
#include <iomanip>
#include <cassert>
 
#define INF 1000000009
#define ll long long
#define ui unsigned int
#define mp make_pair

using namespace std;

/*

inline int readChar();
template <class T = int> inline T readInt(); 
template <class T> inline void writeInt( T x );
inline void writeChar( int x ); 
inline void writeWord( const char *s );
inline void flush();


static const int buf_size = 4096;

inline int getChar() {
  static char buf[buf_size];
  static int len = 0, pos = 0;
  if (pos == len)
    pos = 0, len = fread(buf, 1, buf_size, stdin);
  if (pos == len)
    return -1;
  return buf[pos++];
}

inline int readChar() {
  int c = getChar();
  while (c <= 32)
    c = getChar();
  return c;
}

template <class T>
inline T readInt() {
  int s = 1, c = readChar();
  T x = 0;
  if (c == '-')
    s = -1, c = getChar();
  while ('0' <= c && c <= '9')
    x = x * 10 + c - '0', c = getChar();
  return s == 1 ? x : -x;
}

static int write_pos = 0;
static char write_buf[buf_size];

inline void writeChar( int x ) {
  if (write_pos == buf_size)
    fwrite(write_buf, 1, buf_size, stdout), write_pos = 0;
  write_buf[write_pos++] = x;
}

inline void flush() {
  if (write_pos)
    fwrite(write_buf, 1, write_pos, stdout), write_pos = 0;
}

template <class T> 
inline void writeInt( T x ) {
  if (x < 0)
    writeChar('-'), x = -x;

  char s[24];
  int n = 0;
  while (x || !n)
    s[n++] = '0' + x % 10, x /= 10;
  while (n--)
    writeChar(s[n]);
}*/

const int MAX_MEM = 1e8;
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

int main() {

	cin.tie(0);
	ios_base::sync_with_stdio(0);
	freopen("milliarder.in", "r", stdin);
	freopen("milliarder.out", "w", stdout);

  map<string, pair<int, ll> > map1;
  unordered_map<string, pair<ll, string> > map2;
  priority_queue<pair<ll, string> > qu;

  int n, m, k, day, lday;
  ll tmp;
  string name, town_f, town_m1, town_m2, town_to;
  ll sum, m1, m2;

  cin >> n;
  for (int i = 0; i < n; i++){
    cin >> name >> town_f >> sum;
    map1[town_f].second += sum;
    map2[name].first = sum;
    map2[name].second = town_f;
    //qu.push(mp(map1[town_f].second, town_f));
  }
  for (auto it = map1.begin(); it != map1.end(); it++){
    qu.push(mp(it->second.second, it->first));
  }

  cin >> m >> k;
  lday = 0;
  for (int i = 0; i < k; i++){
    //Prepare
    cin >> day >> name >> town_to;
    town_f = map2[name].second;
    sum = map2[name].first;
    town_m1 = qu.top().second;
    m1 = qu.top().first;
    while(m1 != map1[town_m1].second){
      qu.pop();
      town_m1 = qu.top().second;
      m1 = qu.top().first; 
    }
    if (qu.size() == 1){
      map1[town_m1].first += day - lday;
    }else{
      qu.pop();
      town_m2 = qu.top().second;
      m2 = qu.top().first;
      while((m2 != map1[town_m2].second || town_m1 == town_m2) && qu.size() != 0){
        qu.pop();
        town_m2 = qu.top().second;
        m2 = qu.top().first; 
      }
      qu.push(mp(m1, town_m1));
      if (m1 != m2 || qu.size() == 1){
        map1[town_m1].first += day - lday;
      } 
    }

    //Operations
    map1[town_f].second -= sum;
    map1[town_to].second += sum;
    map2[name].second = town_to;
    if (town_f == town_m1 || town_to == town_m1){
      qu.pop();
    }
    qu.push(mp(map1[town_to].second, town_to));
    qu.push(mp(map1[town_f].second, town_f));
    lday = day;

  }

  day = m;
  town_m1 = qu.top().second;
  m1 = qu.top().first;
  while(m1 != map1[town_m1].second){
    qu.pop();
    town_m1 = qu.top().second;
    m1 = qu.top().first; 
  }
  if (qu.size() == 1){
    map1[town_m1].first += day - lday;
  }else{
    qu.pop();
    town_m2 = qu.top().second;
    m2 = qu.top().first;
    while((m2 != map1[town_m2].second || town_m1 == town_m2) && qu.size() != 0){
      qu.pop();
      town_m2 = qu.top().second;
      m2 = qu.top().first; 
    }
    qu.push(mp(m1, town_m1));
    if (m1 != m2 || qu.size() == 1){
      map1[town_m1].first += day - lday;
    } 
  }

  for (auto it = map1.begin(); it != map1.end(); it++){
    if (it->second.first != 0){
      cout << it->first << ' ' << it->second.first << '\n';
    }
  }
  //flush();

	return 0;
}

//Check
    /*cout << "map2:\n";
    for (auto it = map2.begin(); it != map2.end(); it++){
      cout << it->first << ' ' << it->second.first << ' ' << it->second.second << '\n';
    }
    cout << "map1:\n";
    for (auto it = map1.begin(); it != map1.end(); it++){
      cout << it->first << ' ' << it->second.first << ' ' << it->second.second << '\n';
    }
    cout<<"qu:\n";
    cout << qu.top().first << ' ' << qu.top().second << '\n';
    pair<double, string> tmp = qu.top();
    qu.pop();
    cout << qu.top().first << ' ' << qu.top().second << '\n';
    qu.push(tmp);
    cout << '\n';*/