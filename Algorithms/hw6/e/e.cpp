#include <cmath>
#include <cassert>
#include <cstdio>
#include <cstring>

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define sz(a) (int)(a).size()

typedef double dbl;
typedef long long ll;

struct pnt
{
  int x, y;

  pnt( int _x = 0, int _y = 0 ) : x(_x), y(_y) { }

  inline pnt operator + ( const pnt &p ) const { return pnt(x + p.x, y + p.y); }
  inline pnt operator - ( const pnt &p ) const { return pnt(x - p.x, y - p.y); }

  inline ll operator * ( const pnt &p ) const { return (ll)x * p.y - (ll)y * p.x; }

  inline bool operator < ( const pnt &p ) const { return x < p.x || (x == p.x && y < p.y); }

  inline ll d2() const { return (ll)x * x + (ll)y * y; }
  inline dbl ang() const { return atan2((dbl)y, (dbl)x); }
};

typedef vector <pnt> vpnt;

inline bool pless( const pnt &a, const pnt &b )
{
  ll x = a * b;
  return x != 0 ? x < 0 : a.d2() < b.d2();
}

vpnt ConvexHull( vpnt p )
{
  int n = sz(p), mi = 0;
  assert(n > 0);
  forn(i, n)
    if (p[mi] < p[i])
      mi = i;
  swap(p[0], p[mi]);
  for (int i = 1; i < n; i++)
    p[i] = p[i] - p[0];
  sort(p.begin() + 1, p.end(), pless);

  int rn = 0;
  vpnt r(n);
  r[rn++] = p[0];
  for (int i = 1; i < n; i++)
  {
    pnt q = p[i] + p[0];
    while (rn >= 2 && (r[rn - 1] - r[rn - 2]) * (q - r[rn - 2]) >= 0)
      rn--;
    r[rn++] = q;
  }
  r.resize(rn);
  return r;
}

struct MagicStructure
{
  int N;
  pnt st;
  vector <pnt> p;
  vector <dbl> ang;

  void Build( int n, int *x, int *y ) // O(NlogN)
  {
    assert(n > 0);
    p.resize(N = n);
    forn(i, N)
      p[i].x = x[i], p[i].y = y[i];
    p = ConvexHull(p);
    N = sz(p);
    reverse(p.begin(), p.end());
 
    ang.resize(N);
    forn(i, N)
      ang[i] = (p[(i + 1) % N] - p[i]).ang();
    forn(i, N)
      if (i && ang[i] < ang[i - 1])
        ang[i] += 2 * M_PI;
  }

  ll GetMax( int a, int b ) // O(logK)
  {
    if (N < 3)
    {
      ll ma = -(ll)8e18;
      forn(l, N)
        ma = max(ma, (ll)a * p[l].x + (ll)b * p[l].y);
      return ma;
    }

    int l = 0, r = N - 1;
    dbl x = atan2(a, -b);
    while (x < ang[0])
      x += 2 * M_PI;
    while (l != r)
    {
      int m = (l + r + 1) / 2;
      if (ang[m] < x)
        l = m;
      else
        r = m - 1;
    }
    l = (l + 1) % N;
    return (ll)a * p[l].x + (ll)b * p[l].y;
  }
};

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  freopen("mostfar.in", "r", stdin);
  freopen("mostfar.out", "w", stdout);

  MagicStructure str;
  cin >> str.N;
  

  return 0;
}

