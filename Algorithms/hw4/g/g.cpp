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
#include <set>
 
#define INF 1000000009
#define ll long long
#define ui unsigned int

using namespace std;

#include <cstdio>



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
}


struct Event{
	int x;
	int type;
	int col;
	int num;
	Event(int xx, int ttype, int ccol, int nnum)
	{
		x = xx;
		type = ttype;
		col = ccol;
		num = nnum;
	}
	Event(){}

};
bool cmp(Event a, Event b)
{
	if (a.x == b.x){
		if (a.type == b.type) return a.num < b.num;
		return a.type < b.type;
	}
	return a.x < b.x;
}

int main() {

	//cin.tie(0);
	//ios_base::sync_with_stdio(0);
	freopen("paint.in", "r", stdin);
	freopen("paint.out", "w", stdout);

	int n = readInt(), k = readInt(), m = readInt();
	//cin >> n >> k >> m;

	if (m == 0){
		for (int i = 0; i < k; i++){
			writeInt(0);
			writeChar(' ');
		}
		writeChar('\n');
		flush();
		exit(0);
	}
	//ev_ch = event_checker
	set < pair <int, int> > ev_ch;
	vector< Event > ev;
	vector <int> ans;
	ans.assign(k, 0);

	for (int i = 0; i < m; i++){
		int pai = readInt(), a = readInt(), b = readInt();
		//cin >> pai >> a >> b;
		ev.push_back(Event(a, -1, pai - 1, i));
		ev.push_back(Event(b + 1, 1, pai - 1, i));
	}

	sort(ev.begin(), ev.end(), cmp);

	//for (int i = 0; i < ev.size(); i++) cout << ev[i].x << ' ' << ev[i].type << ' ' << ev[i].col << ' ' << ev[i].num << '\n';
	
	ev_ch.insert(make_pair(-ev[0].num, ev[0].col));

	if (m == 1){
		ans[ev_ch.begin() -> second] = 1;
		for (int i = 0; i < k; i++){
			writeInt(ans[i]);
			writeChar(' ');
		} //cout << ans[i] << ' ';
		//cout << '\n';
		writeChar('\n');
		flush();
		exit(0);
	}

	for (int i = 1; i < ev.size(); i++){

		if (ev_ch.size() != 0) ans[ev_ch.begin() -> second] += ev[i].x - ev[i - 1].x;
	

		if (ev[i].type == -1){
			//if (ev_ch.size() != 0) ans[ev_ch.begin() -> second] += ev[i].x - ev[i - 1].x;
			ev_ch.insert(make_pair(-ev[i].num, ev[i].col));
		}else{
			//if (ev_ch.size() != 0) ans[ev_ch.begin() -> second] += ev[i].x - ev[i - 1].x + 1;
			ev_ch.erase(make_pair(-ev[i].num, ev[i].col));
		}

	}

	/*for (set < pair <int, int> > :: iterator it = ev_ch.begin(); it != ev_ch.end(); it++){
		pair <int, int> tmp = *it;
		cout << tmp.first << ' ' << tmp.second << '\n';
	}*/


	for (int i = 0; i < k; i++){
		writeInt(ans[i]);
		writeChar(' ');
	} //cout << ans[i] << ' ';
	//cout << '\n';
	writeChar('\n');

	flush();

	return 0;
}








