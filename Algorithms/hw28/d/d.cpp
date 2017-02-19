#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define pi pair <int, int>
#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define PI M_PI

typedef long long ll;

const int INF = 1000000000;
const int MAXN = 1<<18 + 5;
const int MAXM = 100005;

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

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	freopen("real.in", "r", stdin);
	freopen("real.out", "w", stdout);

	long long n = readInt(), a = readInt(), b = readInt(), c = readInt(), d = readInt(), e = readInt(), f = readInt(), m = readInt();
	int k; complex<double> fa, fb, twi(0, 2), tw(2, 0);
	forn(i, m){
		k = readInt();
		complex<double> fc(((a + b * k) ^ (c * k)) * 0.001, ((d + e * k) ^ (f * k)) * 0.001);
		complex<double> fnc(((a + b * ((n - k) % n)) ^ (c * ((n - k) % n))) * 0.001, ((d + e * ((n - k) % n)) ^ (f * ((n - k) % n))) * 0.001);
		fa = (fc + conj(fnc)) / tw;
		fb = (fc - conj(fnc)) / twi;
		//cout.precision(4);
		//cout << fixed << real(fa) << ' ' << imag(fa) << ' ' << real(fb) << ' ' << imag(fb) << '\n';
		writeDouble(real(fa), 4); writeChar(' ');
		writeDouble(imag(fa), 4); writeChar(' ');
		writeDouble(real(fb), 4); writeChar(' ');
		writeDouble(imag(fb), 4); writeChar('\n');
	}
	flush();

	return 0;
}