#include <bits/stdc++.h>

using namespace std;

/** Interface */

template <class T = int> inline T readInt();						
inline double readDouble();
inline int readUInt();					 
inline int readChar();					 
inline void readWord( char *s ); 
inline bool readLine( char *s ); // do not save '\n'
inline bool isEof();
inline int peekChar();
inline bool seekEof();

template <class T> inline void writeInt( T x, int len = -1 );
template <class T> inline void writeUInt( T x, int len = -1 );
inline void writeChar( int x ); 
inline void writeWord( const char *s );
inline void writeDouble( double x, int len = 0 );
inline void flush();

/** Read */

static const int buf_size = 4096;

static char buf[buf_size];
static int buf_len = 0, pos = 0;

inline bool isEof() {
	if (pos == buf_len) {
		pos = 0, buf_len = fread(buf, 1, buf_size, stdin);
		if (pos == buf_len)
			return 1;
	}
	return 0;
}

inline int getChar() { 
	return isEof() ? -1 : buf[pos++];
}

inline int peekChar() { 
	return isEof() ? -1 : buf[pos];
}

inline bool seekEof() { 
	int c;
	while ((c = peekChar()) != -1 && c <= 32)
		pos++;
	return c == -1;
}

inline int readChar() {
	int c = getChar();
	while (c != -1 && c <= 32)
		c = getChar();
	return c;
}

inline int readUInt() {
	int c = readChar(), x = 0;
	while ('0' <= c && c <= '9')
		x = x * 10 + c - '0', c = getChar();
	return x;
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

inline double readDouble() {
	int s = 1, c = readChar();
	double x = 0;
	if (c == '-')
		s = -1, c = getChar();
	while ('0' <= c && c <= '9')
		x = x * 10 + c - '0', c = getChar();
	if (c == '.') {
		c = getChar();
		double coef = 1;
		while ('0' <= c && c <= '9')
			x += (c - '0') * (coef *= 1e-1), c = getChar();
	}
	return s == 1 ? x : -x;
}

inline void readWord( char *s ) { 
	int c = readChar();
	while (c > 32)
		*s++ = c, c = getChar();
	*s = 0;
}

inline bool readLine( char *s ) { 
	int c = getChar();
	while (c != '\n' && c != -1)
		*s++ = c, c = getChar();
	*s = 0;
	return c != -1;
}

/** Write */

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
inline void writeInt( T x, int output_len ) {
	if (x < 0)
		writeChar('-'), x = -x;

	char s[24];
	int n = 0;
	while (x || !n)
		s[n++] = '0' + x % 10, x /= 10;
	while (n < output_len)
		s[n++] = '0';
	while (n--)
		writeChar(s[n]);
}

template <class T> 
inline void writeUInt( T x, int output_len ) {
	char s[24];
	int n = 0;
	while (x || !n)
		s[n++] = '0' + x % 10, x /= 10;
	while (n < output_len)
		s[n++] = '0';
	while (n--)
		writeChar(s[n]);
}

inline void writeWord( const char *s ) {
	while (*s)
		writeChar(*s++);
}

inline void writeDouble( double x, int output_len ) {
	if (x < 0)
		writeChar('-'), x = -x;
	int t = (int)x;
	writeUInt(t), x -= t;
	writeChar('.');
	for (int i = output_len - 1; i > 0; i--) {
		x *= 10;
		t = std::min(9, (int)x);
		writeChar('0' + t), x -= t;
	}
	x *= 10;
	t = std::min(9, (int)(x + 0.5));
	writeChar('0' + t);
}

#define mp make_pair
#define pb push_back
#define pi pair <int, int>
#define forn(i, n) for(int i = 0; i < (int)(n); i++)

typedef long long ll;
typedef long double ld;

const int INF = 1000000000;
const int MAXN = 50;
const int MAXM = 2000;
const ld EPS = 1e-10;
const ll MOD = 1500000001;
 
int c[MAXM], num[MAXM], ans;
ll a[MAXM][MAXN];

inline ll inv(ll x){
	ll in = 1, tmp = MOD - 2;

	while (tmp){
		if (tmp & 1)
			in = (in * x) % MOD, tmp--;
		else
			x = (x * x) % MOD, tmp >>= 1;
	}
	return in;
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	freopen("nikifor.in", "r", stdin);
	freopen("nikifor.out", "w", stdout);

	int n = readInt(), m = readInt();
	forn(i, n)
		forn(j, m)
			a[i][j] = readInt();

	forn(i, n){
		c[i] = readInt();
		num[i] = i;
	}

	forn(i, m){
		int tmp = -1;
		for (int j = i; j < n; j++)
			if (EPS < abs(a[j][i]) && (tmp == -1 || c[tmp] > c[j] || c[tmp] == c[j] && num[j] < num[tmp]))
				tmp = j;

		if (tmp == -1){
			writeWord("0\n");
			flush();
			return 0;
		}

		swap(a[i], a[tmp]);
		swap(c[i], c[tmp]);
		swap(num[i], num[tmp]);
		ans += c[i];

		for (int j = i + 1; j < n; j++)
            if (a[j][i] != 0) {
                ll delta = (a[j][i] * inv(a[i][i])) % MOD;
                for (int u = i; u < m; u++)
                    a[j][u] = (a[j][u] - delta * a[i][u]) % MOD;
            }
	}

	sort(num, num + m);
	writeInt(ans);
	writeChar('\n');

	forn(i, m){
		writeInt(num[i] + 1);
		writeChar('\n');
	}

	flush();
	
	return 0;
}