//////////////////////////////////////////////////////////////////////////
//
// 
//
// Problem: 
//
// by Michael Rybak
//
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
///NOTE: THIS PROGRAM CONTAINS SOME COPY-PASTED CODE//////////////////////
///SEE BELOW FOR THE MARK WHERE ACTUALLY TYPED CODE STARTS////////////////
//////////////////////////////////////////////////////////////////////////


#define ASSERT(x) if (!(x)) while (1) cout << 1;else 1
#include <iostream>
#include "stdio.h"
#include <list>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <string>
#include <math.h>
#include <sstream>
#include <fcntl.h>
#include <set>
#include <cstring>
using namespace std;

typedef unsigned long ulong;
typedef unsigned char uchar;
typedef long long llong;
typedef long double ldouble;
typedef short int sint;
typedef unsigned short int usint;


//strings/////////////////////////////////////////////////////////////////
#define STR string
#define GETCOREOF(c, eof) c=0;eof=scanf("%c", &(c))==EOF;
#define SERASELAST(s) if (SIZE(s)) (s).erase(--(s).end(), (s).end())
template <class _T> STR TO_S(_T v)
{ostringstream o;o<<v;return o.str();}
template <class _T> _T FROM_S(STR& s)
{_T v;istringstream i(s);i>>v;return v;}

//vectors/////////////////////////////////////////////////////////////////
#define VE vector
#define SIZE(a) ((int)(a).size())
#define IT iterator
#define VI VE < int >
#define PB push_back
#define PPB pop_back
#define ALL(c) (c).begin(), (c).end()
#define UNIQ(c) sort(ALL(c)), (c).resize(unique(ALL(c)) - (c).begin());
#define VD VE < double >
#define VB VE < bool >
#define VS VE < STR >
#define REV(a) reverse((a).begin(), (a).end())
#define DECALL(_T,a) FOREACH(_T,_it,a)--(*_it);
#define INCALL(_T,a) FOREACH(_T,_it,a)++(*_it);
#define CINTO(_T,n,a) {REP(_i, n) {_T _v; cin >> _v; (a).PB(_v);}}
#define CINNTO(_T,n,a) cin>>n;{REP(_i, n) {_T v; cin >> v; (a).PB(v);}}
#define COUTALL(_T,a,d) {REP(_i,SIZE(a)) cout<<a[_i]<<(_i==_n-1?"\n":d);}
#define CINSTRTO(n,a){REP(_i,n){STR v;getline(cin,v);(a).PB(v);}}
#define CINNSTRTO(n,a)\
  cin>>n; {STR v;getline(cin,v);REP(_i,n){getline(cin,v);(a).PB(v);}}

//cycles//////////////////////////////////////////////////////////////////
#define FOR(i,a,b) for (int _n(b), i(a); i < _n; i++)
#define REP(i,n) FOR(i,0,n)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)
#define FOREACH01(T,it,it0,it1)\
  for(VE< T >::IT it(it0),_itn(it1);it!=_itn;++it)
#define FOREACH(T,it,c) FOREACH01(T,it,(c).begin(),(c).end())
#define FOREACHI01(T,it,it0,it1,i)\
  int i = 0;for(VE< T >::IT it=it0,_itn(it1);it!=_itn;++it,++i)
#define FOREACHI(T,it,i,c) FOREACHI01(T,it,(c).begin(),(c).end(),i)
#define FOREACHNEXT01(T,icur,inext,it0,it1,c)for(VE< T >::IT\
  icur=it0,inext=it0+1;icur!=it1&&inext!=it1;++icur,++inext)
#define FOREACHNEXT(T,icur,inext,c)\
  FOREACHNEXT01(T,icur,inext,(c).begin(),(c).end(),c) 
#define FINDI01(i,i0,i1,v,pre) bool found_ = false;\
  FOR(i_, i0, i1)if (pre){i = i_;found_ = true; break;}
#define FINDI(i,v,pre) FINDI_(i,0,SIZE(v),v,pre)

//misc////////////////////////////////////////////////////////////////////
#define TWO(x) (1<<(x))
#define MSET(a, v) memset(a, v, sizeof(a))
#define MSET0(a) MSET(a, 0)
#define FMIN(a, b) ((a) < (b) ? (a) : (b))
#define FMAX(a, b) ((a) > (b) ? (a) : (b))
#define INF 1000000000
#define ABS(a) ((a) >= 0 ? (a) : -(a))
#define SIGN(a) ((a) > 0 ? 1 : (a) < 0 ? -1 : 0)
#define SQR(a) ((a) * (a))
template <class _T> void SWP(_T& a, _T& b) {_T c=a;a=b;b=c;}
template <class _T> void SWP3(_T& a, _T& b, _T& c) {_T d=a;a=b;b=c;c=d;}
template <class _T> void SWP4(_T&a,_T&b,_T&c,_T&d){_T e=a;a=b;b=c;c=d;d=e;}
template <class _T> void ORDER(_T& a, _T& b) {if(a>b)SWP(a,b);}
template <class _T> void RORDER(_T& a, _T& b) {if(a<b)SWP(a,b);}
template <class _T> bool BTW(const _T&a, const _T&a0, const _T&a1)
{return a0<a&&a<a1;}
template <class _T> bool BTWE(const _T&a, const _T&a0, const _T&a1)
{return a0<=a&&a<=a1;}

//maps////////////////////////////////////////////////////////////////////
#define MM multimap
#define MMII MM <int, int>
#define INS insert
#define LOWB lower_bound
#define UPB upper_bound
#define HASKEY(m, k) ((m).LOWB(k) != (m).UPB(k))
#define FORKEYVALS(TK,TV,it,m,k)\
  for(MM<TK,TV>::IT it=m.LOWB(k),_iend=m.UPB(k);it!=_iend;++it)

//pairs///////////////////////////////////////////////////////////////////
typedef pair<int, int> PII;
#define MP(a, b) make_pair((a), (b))
#define X first
#define Y second

inline int TrOrder(const PII& a, const PII& b, const PII& c)
{return SIGN((b.X - a.X) * (c.Y - a.Y) - (b.Y - a.Y) * (c.X - a.X));}

inline int TrS(const PII& a, const PII& b, const PII& c)
{return (b.X - a.X) * (c.Y - a.Y) - (b.Y - a.Y) * (c.X - a.X);}

template <class _T1, class _T2>
istream& operator >> (istream& cin, pair <_T1, _T2> &p)
{return cin >> p.X >> p.Y;}

template <class _T1, class _T2>
ostream& operator << (ostream& cout, const pair <_T1, _T2> &p)
{return cout << p.X << " " << p.Y;}
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
//floats
//////////////////////////////////////////////////////////////////////////
#define PI 3.14159265358979323846
#define M_PI D_(PI)
#define M_2PI D_(2.0*PI)


typedef double D_;
#define D_0 D_(0)
#define D_1 D_(1)
#define D_2 D_(2)
#define VD_ VE < D_ >


typedef int L_;
#define VI_ VE < L_ >
#define L_0 L_(0)
#define L_1 L_(1)
#define L_2 L_(2)


#ifdef INT_ONLY
typedef L_ type;
#else
typedef D_ type;
#endif 

#define DBL_EPSILON 1e-8
long czero(D_ a)
{return (((a) > DBL_EPSILON)?1:((-(a)) > DBL_EPSILON) ? -1 : 0);}
bool aEb(D_ a, D_ b) 
{return (czero(a - b) == 0);}
bool aSb(D_ a, D_ b) 
{return (czero(a - b) < 0);}
bool aSEb(D_ a, D_ b)
{return (czero(a - b) <= 0);}
bool aGb(D_ a, D_ b)
{return (czero(a - b) > 0);}
bool aGEb(D_ a, D_ b)
{return (czero(a - b) >= 0);}
bool aBTWbc(D_ a, D_ b, D_ c)
{return (aSb(b, a) && aSb(a, c));}
bool aBTWEbc(D_ a, D_ b, D_ c)
{return (aSEb(b, a) && aSEb(a, c));}
void swp(D_ &a, D_ &b)
{D_ c = a; a = b; b = c;}
void order(D_ &a, D_ &b)
{if (aGb(a, b)) swp(a, b);}


long czero(L_ a)
{return ((a > 0 ? 1 : (a < 0 ? -1 : 0)));}
bool aEb(L_ a, L_ b) 
{return a == b;}
bool aSb(L_ a, L_ b) 
{return a < b;}
bool aSEb(L_ a, L_ b)
{return a <= b;}
bool aGb(L_ a, L_ b)
{return a > b;}
bool aGEb(L_ a, L_ b)
{return a >= b;}
bool aBTWbc(L_ a, L_ b, L_ c)
{return (b < a && a < c);}
bool aBTWEbc(L_ a, L_ b, L_ c)
{return (b <= a && a <= c);}
void swp(L_ &a, L_ &b)
{L_ c = a; a = b; b = c;}
void order(L_ &a, L_ &b)
{if (a > b) swp(a, b);}



L_ to_long_(D_ a) 
//to nearest integer; (1.2) -> 1, (1.9) -> 2, (-1.9) -> -2, (-1.2) -> -1
{
  L_ sg = 1;
  if (aSb(a, 0.0)) {
    sg = -1;
    a = -a;
  }

  L_ r = L_(a);
  if (aEb(a, D_(r + 1)))
    ++r;
  return r * sg;
}

type  min(type a, type b)
{return (aSb(a, b)?a:b);}
type  max(type a, type b)
{return (aGb(a, b)?a:b);}
type  min3(type a, type b, type c)
{return min(min(a, b), c);}
type  max3(type a, type b, type c)
{return max(max(a, b), c);}

type abs_(type a){
  return aGEb(a, type(0)) ? a : -a;
}

template <class _T> _T sqr(_T x){return x * x;};

D_ sqrt_(D_ x){
  return (aGb(x, D_0) ? (sqrt(x + D_0)) : 0);
}

L_ pwr(L_ a, L_ p)
{
  L_ r = 1;
  for (; p > 0; a *= a, p /= 2)
    if (p % 2)
      r *= a;
  return r;
}

template <class _T>
_T pwrmod(_T a, _T p, _T m)
//a^p mod m
{
  _T r = 1;
  for (; p > 0; a = (a * a) % m, p /= 2)
    if (p % 2)
      r = (r * a) % m;
  return r;
}

template <class _T1, class _T2>
D_ fmod_(_T1 a, _T2 b) 
//b must be > 0
//result always in [0; b)
{
  ASSERT(aGb(b, _T2(0.0)));
  if (aSb(a, _T1(0.0)))
    a += (to_long_((-a) / b) + 2) * b;
  return a - b * to_long_(a / b);
}

D_ fsubmod_(type a, type b) {
  return a - fmod_(a, b);
}

//////////////////////////////////////////////////////////////////////////
namespace NAngle
{ 
  D_ In2PI(D_ ang_a){
    return fmod_(ang_a, M_2PI);
  }

  void To2PI(D_ &ang_a) {
    ang_a = In2PI(ang_a);
  }
  D_ ReducedDistByCircle(D_ dist)
  {
    To2PI(dist);
    ASSERT(aGEb(dist, 0.0));
    return min(dist, M_2PI - dist);
  }

  void DoReduceDistByCircle(D_ &dist)
  {
    dist = ReducedDistByCircle(dist);
  }

  void OrderForBTWCheck(D_& ang_a, D_& ang_b, D_& ang_c) {
    To2PI(ang_a); To2PI(ang_b); To2PI(ang_c);
    while (aSb(ang_c, ang_b)) ang_c += M_2PI;
    while (aSb(ang_a, ang_b)) ang_a += M_2PI;
  }

  bool aBTWbc_(D_ ang_a, D_ ang_b, D_ ang_c) {
    OrderForBTWCheck(ang_a, ang_b, ang_c);
    return aBTWbc(ang_a, ang_b, ang_c);
  }

  bool aBTWEbc_(D_ ang_a, D_ ang_b, D_ ang_c) {
    OrderForBTWCheck(ang_a, ang_b, ang_c);
    return aBTWEbc(ang_a, ang_b, ang_c);
  }

  D_ acos_(D_ x, D_ low_bound = 0.0)
    //return angle in [low_bound; low_bound + M_PI)
  {
    return 
      ReducedDistByCircle(
      aGEb(x, D_1) ? D_0 : (aSEb(x, -D_1) ? M_PI : D_(acos(x))))
      + low_bound;
  }

  D_ asin_(D_ x) {
    return (aGEb(x, D_1)
      ? M_PI / D_2
      : (aSEb(x, -D_1)
      ? - M_PI / D_2
      : asin(x)));

  }

  D_ atan2_(D_ y, D_ x) 
    //0 <= result < 2 PI
  {
    if (aEb(y, 0.0))
      return (aGEb(x, 0.0) ? 0 : M_PI);
    else if (aEb(x, 0.0))
      return (aGEb(y, 0.0) ? M_PI / 2.0 : 3.0 * M_PI / 2.0);
    else {
      D_ r = atan2(y, x);
      D_ vmin = (aGb(y, 0.0) ? 0 : M_PI);
      D_ vmax = vmin + M_PI;
      while (aSb(r, vmin))
        r += M_PI;
      while (aGEb(r, vmax))
        r -= M_PI;

      return r;
    }
  }
}

D_ CosABySides(D_ a, D_ b, D_ c)
{
  if (aEb(b, 0.0) || aEb(c, 0.0))
    return 1.0;
  return (b * b + c * c - a * a) / 2.0 / b / c;
}

D_ AngleABySides(D_ a, D_ b, D_ c)
{
  return NAngle::acos_(CosABySides(a, b, c));
}
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////
//CPoint
////////////////////////////////////////////////////////////
template <class _T>
struct CPoint
{
  _T x, y;
  CPoint(_T i_x = 0, _T i_y = 0):
  x(i_x), y(i_y)
  {
  }

  CPoint(const CPoint &other):
  x(other.x), y(other.y)
  {
  }

  bool operator<( const CPoint &other ) const
  {
    return aSb(x, other.x) ? true : aGb(x, other.x) ? false : aSb(y, other.y);
  }

  bool operator<=( const CPoint &other ) const
  {
    return aSb(x, other.x) ? true : aGb(x, other.x) ? false : aSEb(y, other.y);
  }

  bool operator>( const CPoint &other ) const
  {
    return aGb(x, other.x) ? true : aSb(x, other.x) ? false : aGb(y, other.y);
  }

  bool operator>=( const CPoint &other ) const
  {
    return aGb(x, other.x) ? true : aSb(x, other.x) ? false : aGEb(y, other.y);
  }

  bool operator==( const CPoint &other ) const
  {
    return (aEb(x, other.x) && aEb(y, other.y));
  }

  bool operator!=( const CPoint &other ) const
  {
    return !(*this == other);
  }

  CPoint& operator = ( const CPoint &other )
  {
    Set(other);
    return *this;
  }

  CPoint operator + (const CPoint &other) const{
    return CPoint(x + other.x, y + other.y);
  }

  CPoint operator - (const CPoint &other) const{
    return CPoint(x - other.x, y - other.y);
  }

  CPoint operator - () const{
    return CPoint(-x, -y);
  }

  CPoint operator * (_T alpha) const{
    return CPoint(x * alpha, y * alpha);
  }

  CPoint operator / (_T alpha) const{
    return CPoint(x / alpha, y / alpha);
  }

  inline D_ Dist( const CPoint &other) const  {
    return sqrt_(sqr(other.x - x) + sqr(other.y - y));
  }

  inline D_ Dist00() const  {
    return sqrt_(sqr(x) + sqr(y));
  }

  inline _T sqdist( const CPoint &other) const  {
    return sqr(other.x - x) + sqr(other.y - y);
  }

  inline _T sqdist00( ) const  {
    return sqr(x) + sqr(y);
  }

  bool Normalize()
    //false if zero point
  {
    D_ dist = Dist(CPoint(0, 0));
    if (aEb(dist, 0.0))
      return false;
    x /= dist;
    y /= dist;
    return true;
  }

  inline _T rectdist( const CPoint &other) const  {
    return abs_(other.x - x) + abs_(other.y - y);
  }

  bool InRect( const CPoint &wh) const
  {return (aBTWbc(x, _T(0), wh.x) && aBTWbc(y, _T(0), wh.y));}

  bool InRectE( const CPoint &wh) const
  {return (aBTWEbc(x, _T(0), wh.x) && aBTWEbc(y, _T(0), wh.y));}

  inline void Shift(_T dx, _T dy) {
    x += dx; y += dy;
  };

  inline void Rotate(CPoint &b, D_ ang) const
  {
    D_ sn = sin(ang), cs = cos(ang);
    D_ dx = b.x - x, dy = b.y - y;
    b.Set(dx * cs - dy * sn + x,
      dy * cs + dx * sn + y);
  }

  inline void RotateSinCos(CPoint &b, D_ sn, D_ cs) const
  {
    D_ dx = b.x - x, dy = b.y - y;
    b.Set(dx * cs - dy * sn + x,
      dy * cs + dx * sn + y);
  }

  inline CPoint& operator += (const CPoint &other) {
    Shift(other.x, other.y);
    return *this;
  }

  inline CPoint& operator -= (const CPoint &other) {
    Shift(-other.x, -other.y);
    return *this;
  }

  inline CPoint& operator *= (_T alpha) {
    *this = *this * alpha;
    return *this;
  }

  inline CPoint& operator /= (_T alpha) {
    *this = *this / alpha;
    return *this;
  }

  inline CPoint<_T> Shifted(_T dx, _T dy) const{
    return CPoint<_T>(x + dx, y + dy);
  };

  inline void Set(_T vx, _T vy) {
    x = vx; y = vy;
  };

  inline void Set( const CPoint& other) {
    x = other.x; y = other.y;
  };

  inline void Swap()
  {SWP(x, y);}

  inline D_ Angle(const CPoint<_T> &p1, const CPoint<_T> &p2) const {
    _T a(sqdist(p1)), b(sqdist(p2)), c(p1.sqdist(p2));
    if (aEb(a, D_0) || aEb (b, D_0))
      return 0;
    else
      return NAngle::acos_((a + b - c ) / 2 / sqrt_(a) / sqrt_(b) + 0.0);
  };

  inline D_ Atan(const CPoint& p) const
  {
    return NAngle::atan2_(p.y - y, p.x - x);
  }

  inline bool InTriangle( const CPoint &a, const CPoint &b, const CPoint &c);
};
typedef CPoint<L_> CPointL_;
typedef CPoint<D_> CPointD_;
typedef VE <CPointL_> VPL_;
typedef VE <CPointD_> VPD_;

const CPointD_ PD_00(D_0, D_0);
const CPointD_ PD_10(D_1, D_0);
const CPointD_ PD_01(D_0, D_1);

const CPointL_ PL_00(L_0, L_0);
const CPointL_ PL_11(L_1, L_1);
const CPointL_ PL_10(L_1, L_0);
const CPointL_ PL_01(L_0, L_1);

//////////////////////////////////////////////////////////////////////////
template <class _T>
istream& operator >> (istream& inp, CPoint<_T> &p) {
  return inp >> p.x >> p.y;
}

//////////////////////////////////////////////////////////////////////////
template <class _T>
ostream& operator << (ostream& out, const CPoint<_T> &p) {
  return out << p.x << " " << p.y;
}

//////////////////////////////////////////////////////////////////////////
bool TriangleBySides(
                     D_ ab, D_ bc, D_ ca,
                     const CPointD_ &pa, CPointD_ &pb, 
                     CPointD_ &pc0, CPointD_ &pc1,
                     bool pb_already_set = false)
{
  if (!pb_already_set)
    pb = pa.Shifted(ab, 0);
  else
    ASSERT(aEb(pa.Dist(pb), ab));

  if (aEb(ab, 0.0))
  {
    pc0 = pc1 = pa.Shifted(0, ca);
    return aEb(ca, bc);
  }
  else if (aEb(ca, 0.0))
  {
    pc0 = pc1 = pa;
    return aEb(ab, bc);
  }
  else
  {
    CPointD_ dir = pb - pa;
    dir.Normalize();
    dir *= ca;

    D_ cs = (sqr(ab) + sqr(ca) - sqr(bc)) / 2.0 / ab / ca;
    if (!aBTWEbc(cs, -D_1, D_1))
      return false;

    D_ sn = sqrt_(1.0 - cs * cs);

    pc0 = pc1 = pa + dir;
    pa.RotateSinCos(pc0, sn, cs);
    pa.RotateSinCos(pc1, -sn, cs);
    return true;
  }
}

//////////////////////////////////////////////////////////////////////////
template <class _T>
type OrSTr(const CPoint<_T> &a, const CPoint<_T> &b, const CPoint<_T> &c)
{return 0.5 * ((b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y));}

//////////////////////////////////////////////////////////////////////////
D_ HeronS(D_ a, D_ b, D_ c) 
{
  D_ p = (a + b + c) / 2.0;
  return sqrt(p) * sqrt(p - a) * sqrt(p - b) * sqrt(p - c);
}

//////////////////////////////////////////////////////////////////////////
template<class _T> 
void Symmetry(CPoint<_T> &a, const CPoint<_T> &center)
{
  a = center + (center - a);
}

//////////////////////////////////////////////////////////////////////////
template<class _T> 
CPoint<_T> Symmetried(CPoint<_T> &a, const CPoint<_T> &center)
{
  CPoint<_T> r(a);
  Symmetry(r, center);
  return r;
}

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////
//CLine
//////////////////////////////////////////////////////////////////////////
template <class _T>
struct CLine
{
  CPoint<_T> p1, p2;

  CLine ()
  {
  };

  CLine (const CPoint<_T> &i_p1, const CPoint<_T> &i_p2)
    : p1(i_p1)
    , p2(i_p2)
  {
  }

  CLine (_T x1, _T y1, _T x2, _T y2):
  p1(CPoint<_T>(x1, y1)),
    p2(CPoint<_T>(x2, y2))
  {
  }

#ifdef INT_ONLY
  CLine (const D_ &x1, const D_ &y1, 
    const D_ &x2, const D_ &y2):
  p1(CPoint<_T>(type(x1), type(y1))),
    p2(CPoint<_T>(type(x2), type(y2)))
  {
  }
#endif

  bool IsPoint() const {return (p1 == p2);}
  type DX() const  {return p2.x - p1.x;}
  type DY() const {return p2.y - p1.y;}
  type DX1(type x) const {return x - p1.x;}
  type DY1(type y) const {return y - p1.y;}
  D_ Len() const {return p1.Dist(p2);}
  type SqLen() const {return p1.sqdist(p2);}


  bool Passes(const CPoint<_T> &p) const
  {
    if (IsPoint())
      return (p1 == p);
    else
      return aEb(DX1(p.x) * DY(), DX() * DY1(p.y));
  }

  bool Contains(const CPoint<_T> &p) const
  {
    if (!Passes(p))
      return false;
    else
    {
      bool t1 = p1 <= p;
      return ((p1 <= p && p <= p2) ||
        (p2 <= p && p <= p1));
    }
  }

#ifndef INT_ONLY
  D_ OrDist(const CPoint<_T> &p) const
  {
    return OrSTr(p1, p2, p) * 2.0 / Len();
  }

  D_ Dist(const CPoint<_T> &p) const
  {
    return abs(OrDist(p));
  }

  void Project(CPointD_ &projected, const CPointD_ &p) const
  {
    D_ d = OrDist(p);
    CPointD_ dir(p2.y - p1.y, p1.x - p2.x);
    ASSERT(dir.Normalize());
    dir *= d;
    projected = p + dir;
  }

  void Project(CPointD_ &p) const
  {
    CPointD_ r;
    Project(r, p);
    p = r;
  }

  void FindPointClosestTo(CPointD_& o_closest, CPointD_ to_what)
  {
    if (IsPoint())
    {
      o_closest = p1;
      return;
    }

    Project(o_closest, to_what);
    if (!Contains(o_closest))
      if (p1.sqdist(to_what) < p2.sqdist(to_what))
        o_closest = p1;
      else
        o_closest = p2;
  }


  CPointD_ Projected(const CPointD_ &p) const
  {
    CPointD_ r;
    Project(r, p);
    return r;
  }
#endif

  void SwapPoints()
  {
    CPoint<_T> p(p1);
    p1 = p2;
    p2 = p;
  };

  void Order()
  {if (p1 > p2) SwapPoints();}

  bool IsSameAngle(const CLine& other) {
    return aEb(DX() * other.DY(), DY() * other.DX());
  }

  bool IsSameLine(const CLine& other) {
    return other.Passes(p1) && other.Passes(p2);
  }
};
typedef CLine<L_> CLineL_;
typedef CLine<D_> CLineD_;

//////////////////////////////////////////////////////////////////////////
template <class _T>
istream& operator >> (istream& cin, CLine<_T> &line)
{
  return cin >> line.p1 >> line.p2;
}


//////////////////////////////////////////////////////////////////////////
template <class _T>
bool CPoint<_T>::InTriangle( const CPoint<_T> &a, const CPoint<_T> &b, const CPoint<_T> &c)
{
  if (a == b)
    return CLine<_T>(a, c).Contains(*this);
  else if (CLine<_T>(a, b).Passes(c))
    return (CLine<_T>(a, c).Contains(*this) ||
    CLine<_T>(a, b).Contains(*this) ||
    CLine<_T>(b, c).Contains(*this));
  else
    return aEb(abs_(OrSTr(a, b, c)),
    abs_(OrSTr(*this, a, b)) + 
    abs_(OrSTr(*this, b, c)) + 
    abs_(OrSTr(*this, c, a)));
}

//////////////////////////////////////////////////////////////////////////
template <class _T>
bool IntersectLines(CLine<_T> &o_e, const CLine<_T> &e1, const CLine<_T> &e2, 
                    bool is_edge_1 = false, bool is_edge_2 = false)
                    //true if at least one common point
{
  if (aEb(e1.DX() * e2.DY(), e2.DX() * e1.DY())) //parallel or coincide
    if (!e1.Passes(e2.p1) && !e2.Passes(e1.p1))
      return false; //parallel
    else
    {
      if (!is_edge_2)
      {
        o_e = e1;
        return true;
      }

      if (!is_edge_1)
      {
        o_e = e2;
        return true;
      }

      //both are edges
      CLine<_T> ce1(e1), ce2(e2);

      ce1.Order();
      ce2.Order();
      if (ce2.p1 > ce1.p2 || ce2.p2 < ce1.p1)
        return false;

      o_e.p1 = CPoint<_T>((ce1.p1 > ce2.p1) ? ce1.p1 : ce2.p1);
      o_e.p2 = CPoint<_T>((ce1.p2 < ce2.p2) ? ce1.p2 : ce2.p2);
      return true;
    }
  else
  {
    type z = e1.DX() * e2.DY() - e2.DX() * e1.DY();
    type x = ((e2.p1.y - e1.p1.y) * e1.DX() * e2.DX() 
      + e1.DY() * e2.DX() * e1.p1.x 
      - e2.DY() * e1.DX() * e2.p1.x) / -z;
    type y = ((e2.p1.x - e1.p1.x) * e1.DY() * e2.DY()
      + e1.DX() * e2.DY() * e1.p1.y 
      - e2.DX() * e1.DY() * e2.p1.y) / z;
    o_e.p1 = CPoint<_T>(x, y);
    o_e.p2 = CPoint<_T>(x, y);

    bool toret = true;

    if (is_edge_1)
      toret &= e1.Contains(o_e.p1);
    if (is_edge_2)
      toret &= e2.Contains(o_e.p1);

    return toret;
  }


}

//////////////////////////////////////////////////////////////////////////
template <class _T>
bool IntersectEdges(CLine<_T> &o_e, const CLine<_T> &e1, const CLine<_T> &e2, 
                    bool is_edge_1 = true, bool is_edge_2 = true)
{return IntersectLines(o_e, e1, e2, is_edge_1, is_edge_2);} 


//////////////////////////////////////////////////////////////////////////
void Symmetry(CPointD_ &p, const CLineD_& line)
{
  if (line.IsPoint())
    Symmetry(p, line.p1);
  else
  {
    CPointD_ center(p);
    line.Project(center);
    Symmetry(p, center);
  }
}

CPointD_ Symmetried(const CPointD_& p, const CLineD_& line)
{
  CPointD_ r(p);
  Symmetry(r, line);
  return r;
}

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////
//CCircle
////////////////////////////////////////////////////////////

template <class _T>
struct CCircle:
  public CPoint<_T>
{
  _T r;
  CCircle(_T i_x = 0.0, _T i_y = 0.0, _T i_r = 1.0)
    : CPoint<_T>(i_x, i_y)
    , r(i_r)
  {};

  CPoint<_T>& AsP()
  {return (CPoint<_T>&) *this;}

  bool ContainsInside(const CPoint<_T> &p) const 
  {return aSb(sqdist(p), r * r);}
  bool Contains(const CPoint<_T> &p) const 
  {return aSEb(sqdist(p), r * r);}

  bool ContainsInside(const CCircle &b) const
  {return aSb(Dist(b) + b.r, r);}
  bool Contains(const CCircle &b) const
  {return aSEb(Dist(b) + b.r, r);}

  bool Coincide(const CCircle &b) const
  {return *this == b && aEb(r, b.r);}

  bool CirInRect( const CPoint<_T> &wh) const
  {return (aBTWbc(this->x, r, wh.x - r) && aBTWbc(this->y, r, wh.y - r));}

  bool CirInRectE( const CPoint<_T> &wh) const
  {return (aBTWEbc(this->x, r, wh.x - r) && aBTWEbc(this->y, r, wh.y - r));}


  void Set(type vx, type vy, type vr) {
    this->x = vx; this->y = vy; r = vr;
  };

  D_ CalcArea() { return M_PI * r * r;};

#ifndef INT_ONLY
  bool CalcTangents(const CPoint<_T> &p, CPoint<_T>& o_t1, CPoint<_T>& o_t2) 
    //false if strictly inside
  {
    if (Contains(p))
    {
      o_t1 = p;
      o_t2 = p;
      return !(ContainsInside(p));
    }

    Shift(-p.x, -p.y);

    type vx, vy;
    type q(this->x * this->x + this->y * this->y - r * r);

    if (aEb(this->y, 0)){
      vx = q / this->x;
      vy = sqrt_(q - vx * vx);
      o_t1 = CPoint<_T>(vx, vy);
      o_t2 = CPoint<_T>(vx, -vy);
    } else {
      type a(this->x * this->x + this->y * this->y), 
        b( -2 * q * this->x), c(q * q - q * this->y * this->y);
      type d(b * b - 4 * a * c);
      ASSERT(aGEb(d, 0.0));
      d = sqrt_(d);
      vx = (- b + d) / 2 / a;
      o_t1 = CPoint<_T>(vx, (q - this->x * vx) / this->y);
      vx = (- b - d) / 2 / a;
      o_t2 = CPoint<_T>(vx, (q - this->x * vx) / this->y);
    }

    Shift(p.x, p.y);
    o_t1.Shift(p.x, p.y);
    o_t2.Shift(p.x, p.y);

    return true;
  }
#endif

  bool IntersectLine(CLine<_T> &o_inside, const CLine<_T> &line) 
    // in INT_ONLY mode should only be used to
    // check whether there's an intersection;
    // values for o_inside are rounded
  {
    _T dx0 = -line.DX1(this->x),
      dy0 = -line.DY1(this->y),
      dx1 = line.DX(),
      dy1 = line.DY();
    _T a = sqr(dx1) + sqr(dy1),
      b = 2 * (dx1 * dx0 + dy1 * dy0),
      c = sqr(dx0) + sqr(dy0) - sqr(r),
      d = b * b - 4 * a * c;

    if (aSb(d, (_T)0))
      return false;
    D_ sq_d = sqrt_(d);
    D_ t0 = (-b + sq_d) / 2.0 / a,
      t1 = (-b - sq_d) / 2.0 / a;
    o_inside = CLine<_T>(line.p1.x + t0 * dx1, line.p1.y + t0 * dy1,
      line.p1.x + t1 * dx1, line.p1.y + t1 * dy1);
    return true;
  }

  bool IntersectsLine(const CLine<_T> &line) 
  {
    CLine <_T> unused;
    return IntersectLine(unused, line);
  }

  bool IntersectEdge(CLine<_T> &o_inside, const CLine<_T> &line) {
    if (line.IsPoint())
    {
      o_inside.p1 = o_inside.p2 = line.p1;
      return Contains(line.p1);
    }
    else
    {

      if (!IntersectLine(o_inside, line))
        return false;
      return IntersectEdges(o_inside, CLine<_T>(o_inside), line);
    }
  }

  bool IntersectsEdge(const CLine<_T> &line) 
  {
    CLine <_T> unused;
    return IntersectEdge(unused, line);
  }

  CPoint<_T> PntAtAngle(D_ a) {
    return ((CPoint<_T>&)(*this)).Shifted(r * cos(a), r * sin(a));
  }

  D_ ShortcutOutside(const CLine<_T>& way)
    //find optimal route from way.p1 to way.p2 that doesn't run inside circle
  {
    ASSERT(!ContainsInside(way.p1) && !ContainsInside(way.p2));

    D_ ans;

    if (!IntersectsEdge(way))
      ans = way.Len();
    else
    {
#define DistViaTangentPoints(t0, t1) \
  way.p1.Dist(t0) + \
  r * this->Angle(t0, t1) + \
  t1.Dist(way.p2)

      CPointD_ t00, t01, t10, t11;
      (CalcTangents(way.p1, t00, t01));
      (CalcTangents(way.p2, t10, t11));

      ans = min(min(DistViaTangentPoints(t00, t10), 
        DistViaTangentPoints(t00, t11)),
        min(DistViaTangentPoints(t01, t10), 
        DistViaTangentPoints(t01, t11)));
    }

    return ans;
  }

  D_ SegmentArea(D_ chord)
  {
    ASSERT(aSEb(chord, 2 * r));
    ASSERT(aSEb(0.0, chord));
    D_ ca = 1.0 - sqr(chord) / 2.0 / r / r;
    D_ sa = sqrt_(1 - ca * ca);

    return r * r * NAngle::acos_(ca) / 2.0 - 0.5 * r * r * sa;
  }
};
typedef CCircle<L_> CCircleL_;
typedef CCircle<D_> CCircleD_;

//////////////////////////////////////////////////////////////////////////
template <class _T>
istream& operator >> (istream& cin, CCircle<_T> &c)
{ 
  return cin >> ((CPoint<_T>&)c) >> c.r;
}
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//geo3d
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
//CPoint3d
//////////////////////////////////////////////////////////////////////////
struct CPoint3d
{
  type x, y, z;
  CPoint3d(type i_x = 0, type i_y = 0, type i_z = 0):
  x(i_x), y(i_y), z(i_z)
  {
  }

  CPoint3d(const CPoint3d &other):
  x(other.x), y(other.y), z(other.z)
  {
  }

  bool operator<( const CPoint3d &other ) const
  {
    if (!aEb(x, other.x))
      return aSb(x, other.x);
    else if (!aEb(y, other.y))
      return aSb(y, other.y);
    else
      return aSb(z, other.z);
  }

  CPoint3d operator - (const CPoint3d &b) const
  {
    return CPoint3d(x - b.x, y - b.y, z - b.z);
  }

  CPoint3d& operator += (const CPoint3d &b) 
  {
    x += b.x;
    y += b.y;
    z += b.z;
    return *this;
  }


  CPoint3d& operator /= (type alpha) 
  {
    x /= alpha;
    y /= alpha;
    z /= alpha;
    return *this;
  }

  //bool operator<=( const CPoint &other ) const
  //{
  //  return aSb(x, other.x) ? true : aGb(x, other.x) ? false : aSEb(y, other.y);
  //}

  //bool operator>( const CPoint &other ) const
  //{
  //  return aGb(x, other.x) ? true : aSb(x, other.x) ? false : aGb(y, other.y);
  //}

  //bool operator>=( const CPoint &other ) const
  //{
  //  return aGb(x, other.x) ? true : aSb(x, other.x) ? false : aGEb(y, other.y);
  //}

  bool operator==( const CPoint3d &other ) const
  {
    return (aEb(x, other.x) && aEb(y, other.y) && aEb(z, other.z));
  }

  //bool operator!=( const CPoint &other ) const
  //{
  //  return !(*this == other);
  //}

  CPoint3d& operator = ( const CPoint3d &other )
  {
    Set(other);
    return *this;
  }

  inline D_ Dist( const CPoint3d &other) const  {
    return sqrt_(sqr(other.x - x) + sqr(other.y - y) + sqr(other.z - z));
  }

  inline type sqdist( const CPoint3d &other) const  {
    return sqr(other.x - x) + sqr(other.y - y) + sqr(other.z - z);
  }

  //inline type rectdist( const CPoint3d &other) const  {
  //  return abs(other.x - x) + abs(other.y - y);
  //}

  //inline void Shift(type dx, type dy) {
  //  x += dx; y += dy;
  //};

  inline void Set(type vx, type vy, type vz) {
    x = vx; y = vy; z = vz;
  };

  inline void Set( const CPoint3d& other) {
    x = other.x; y = other.y; z = other.z;
  };

  //inline double_ Angle(const CPoint3d &p1, const CPoint3d &p2) const {
  //  type a(sqdist(p1)), b(sqdist(p2)), c(p1.sqdist(p2));
  //  if (aEb(a, 0) || aEb (b, 0))
  //    return 0;
  //  else
  //    return acos_((a + b - c ) / 2 / sqrt_(a) / sqrt_(b) + 0.0);
  //};

  //inline bool InTriangle( const CPoint3d &a, const CPoint3d &b, const CPoint3d &c);
};

istream& operator >> (istream& inp, CPoint3d &p) {
  return inp >> p.x >> p.y >> p.z;
}


//////////////////////////////////////////////////////////////////////////
//CLine3d
//////////////////////////////////////////////////////////////////////////
struct CLine3d
{
  CPoint3d p1, p2;

  CLine3d ()
  {
  };

  CLine3d (const CPoint3d &i_p1, const CPoint3d &i_p2)
    : p1(i_p1)
    , p2(i_p2)
  {
  }

  //CLine (const type &x1, const type &y1, 
  //  const type &x2, const type &y2):
  //p1(CPoint(x1, y1)),
  //  p2(CPoint(x2, y2))
  //{
  //}

  //CLine(const CLine &other):
  //p1(other.p1),
  //  p2(other.p2)
  //{
  //}

  void Set(const CPoint3d& i_p1, const CPoint3d& i_p2) 
  {
    p1 = i_p1;
    p2 = i_p2;
  }

  bool IsPoint() const {return (p1 == p2);}
  type DX() const {return p2.x - p1.x;}
  type DY() const {return p2.y - p1.y;}
  type DZ() const {return p2.z - p1.z;}
  type DX1(type x) const {return x - p1.x;}
  type DY1(type y) const {return y - p1.y;}
  type DZ1(type z) const {return z - p1.z;}
  D_ Len() const {return p1.Dist(p2);}
  type SqLen() const {return p1.sqdist(p2);}


  bool Passes(const CPoint3d &p) const
  {
    if (IsPoint())
      return (p1 == p);
    else
      return aEb(DX1(p.x) * DY(), DX() * DY1(p.y)) &&
      aEb(DX1(p.x) * DZ(), DX() * DZ1(p.z));
  }

  //bool Contains(const CPoint &p) const
  //{
  //  if (!Passes(p))
  //    return false;
  //  else
  //  {
  //    bool t1 = p1 <= p;
  //    return ((p1 <= p && p <= p2) ||
  //      (p2 <= p && p <= p1));
  //  }
  //}

  void SwapPoints()
  {
    CPoint3d p(p1);
    p1 = p2;
    p2 = p;
  };

  //void Order()
  //  {if (p1 > p2) SwapPoints();}

  bool IsSameAngle(const CLine3d& other) {
    return aEb(DX() * other.DY(), DY() * other.DX()) && 
      aEb(DX() * other.DZ(), DZ() * other.DX());
  }

  bool IsSameLine(const CLine3d& other) {
    return other.Passes(p1) && other.Passes(p2);
  }

  bool LineIntersectXPlane(CLine3d& o_e, type x) {
    if (aEb(x, p1.x) && aEb(x, p2.x)) {
      o_e = *this;
      return true;
    }
    else if (aEb(p1.x, p2.x))
      return false;
    else {
      CPoint3d p(x, 
        p1.y + DX1(x) * DY() / DX(), 
        p1.z + DX1(x) * DZ() / DX());
      o_e.Set(p, p);
      return true;
    }
  }

  //bool EdgeIntersectXPlane(CLine3d& o_e, type x) {
  //  return LineIntersectXPlane(o_e, x)  && Contains
  //  else
  //}
};



//////////////////////////////////////////////////////////////////////////
///////CODE THAT WAS ACTUALLY TYPED FOR THIS PROBLEM STARTS HERE//////////
//////////////////////////////////////////////////////////////////////////

int ntest;

int main()
{ 
  cin >> ntest;
  REP(ctest, ntest)
  {
    int n;
    cin >> n;

    CPoint3d center3d, velocity3d;
    REP(i, n)
    {
      CPoint3d cur_center, cur_velocity;
      cin >> cur_center >> cur_velocity;
      center3d += cur_center;
      velocity3d += cur_velocity;
    }

    center3d /= double(n);
    velocity3d /= double(n);

    // turn to 2d
    CPointD_ center, velocity, p00_here;
    {      
      CPoint3d P3D_00(0, 0, 0);
      double ab = center3d.Dist(P3D_00);
      double bc = velocity3d.Dist(center3d);
      double ca = velocity3d.Dist(P3D_00);


      CPointD_ unused;
      ASSERT(TriangleBySides(ab, bc, ca, p00_here, center, velocity, unused));
    }

    double ans;
    double time;

    if (velocity == PD_00)
    {
      ans = center.Dist00();
      time = 0;
    }
    else
    {
      CPointD_ p1 = center;
      CPointD_ p2 = center + velocity;
      for (int k = 2; p1.Dist(p2) < 10000; k++)
        p2 = center + velocity * k;

      CLineD_ line(p1, p2);
      CPointD_ closest;
      line.FindPointClosestTo(closest, PD_00);

      ans = closest.Dist00();
      time = p1.Dist(closest) / velocity.Dist00();
    }

    printf("Case #%d: %.8lf %.8lf\n", ctest + 1, ans, time);
  }

  return 0;
}
