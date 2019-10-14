#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <set>
#include <queue>
#include <map>

using namespace std;

#define W while
#define all(v) v.begin(), v.end()
#define sz(v) int((v).size())
#define pb push_back
#define mp make_pair
#define md 1000000007
#define P pair<int, int>
#define ll long long
#define vi vector <int>
#define vs vector <string>
#define f(i, n) for(int i=0; i<(n); i++)
#define F(i, n, m) for(int i=(n); i<=(m); i++)
#define d(i, n) for(int i=(n)-1; i>=0; i--)
#define D(i, n, m) for(int i=(n); i>=(m); i--)

inline ll sqr(ll x) { return x*x; }
inline ll gcd(ll x, ll y) { return y ? gcd(y, x%y) : x; }
inline ll lcm(ll x, ll y) { return x/gcd(x, y)*y; }

const double eps = 1e-11;
const int z = 1001;
const int inf = 1324162729;
const ll lnf =  653556257326348742LL;
const int dx[]={-1, 0, 1,  0, -1, -1,  1, 1};
const int dy[]={ 0, 1, 0, -1, -1,  1, -1, 1};

int i, j, k, l, n, m, u, y, res, ntst, tall;
ll X, Y, Z, a[z], g[z], h[z], ans;
vi v;

int main()
{
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
     scanf("%d", &tall);
   for(ntst=1; ntst<=tall; ntst++) {
      scanf("%d%d%d%d%d", &n, &m, &X, &Y, &Z);
    f(i, m) scanf("%d", &g[i]); ans=0;
     for(ll i=0; i<n; i++) {
         a[i]=g[i%m]; h[i]=1; g[i%m]=(X*g[i%m]+Y*(i+1))%Z;
        for(ll j=0; j<i; j++)
          if (a[i]>a[j]) h[i]=(h[i]+h[j])%md; ans=(ans+h[i])%md;
     }

       printf("Case #%d: %I64d\n", ntst, ans);
       
   }
      return 0;
} 
