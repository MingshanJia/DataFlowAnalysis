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
///////CODE THAT WAS ACTUALLY TYPED FOR THIS PROBLEM STARTS HERE//////////
//////////////////////////////////////////////////////////////////////////

int ntest;

int f[128][128];
VI xx;

int F(int p1, int p2)
{
  int& res(f[p1][p2]);

  if (res == -1)
  {
    if (p1 + 1 == p2)
    {
      res = 0;
    }
    else
    {
      res = INF;
      FOR(p, p1 + 1, p2)
        res = FMIN(res, 
          xx[p] - xx[p1] - 1 + xx[p2] - xx[p] - 1 + 
          F(p1, p) + F(p, p2));
    }
  }

  return res;
}

int main()
{ 
  cin >> ntest;  
  REP(ctest, ntest)
  {
    int n_all, n_release;
    cin >> n_all >> n_release;
    
    VI r;
    CINTO(int, n_release, r);
    r.PB(0);
    r.PB(n_all + 1);
    sort(ALL(r));

    xx = r;

    MSET(f, -1);
    printf("Case #%d: %d\n", ctest + 1, F(0, SIZE(xx) - 1));
  }

  return 0;
}
