#include <cstdio>
#include <algorithm>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)
#define FORE(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
typedef long long ll;

const int N=11000;
int _,n;
ll l,h,a[N],ans,minans;

ll mnoz(ll a, ll b) {
   a *= b;
   if (a > h) return h+1;
   return a;
}

int main() {
   scanf("%d",&_);
   REP(test,_) {
      printf("Case #%d: ",test+1);
      scanf("%d%lld%lld",&n,&l,&h);
      REP(i,n) scanf("%lld",&a[i]);
      sort(a,a+n);
      ans = 1;
      minans = h+1;
      for(int i=-1;i<n;++i) {
	 if (i>=0) ans = mnoz(ans, (a[i] / __gcd(ans,a[i])));

	 ll g = -1;
	 if (i+1 < n) {
	    g = a[i+1];
	    for(int j=i+1;j<n;++j) g = __gcd(g,a[j]);
	 }
	 ll tans = ans;
	 if (g!=-1 && g % tans) continue;
	 if (tans > h) continue;
	 else if (tans < l) {
	    int ok=0;
//	    printf("t=%lld\n",tans);
	    for(int k=(l+tans-1)/tans; k*tans <= h; ++k)
	       if (g==-1 || g % (k*tans) == 0) { ok=1; tans = k*tans; break; }
	    if (!ok) continue;
	 }
//	 printf("tans=%lld\n",tans);
	 if (tans < minans) minans = tans;
      }
ret:
      if (minans > h) puts("NO");
      else printf("%lld\n",minans);
   }
}
