#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <algorithm>
#include <sstream>
#include <stack>
#include <cstring>
#include <iomanip>
#include <ctime>
using namespace std;
#define pb push_back
#define INF 1000000000
#define FOR(i,n) for(int (i)=0;(i)<(n);++(i))
#define FORI(i,n) for(int (i)=1;(i)<=(n);++(i))
#define mp make_pair
#define pii pair<int,int>
#define ll long long
#define vi vector<int>
#define SZ(x) ((int)(x.size()))
#define fi first
#define se second
#define wez(n) int (n); scanf("%d",&(n));
#define wez2(n,m) int (n),(m); scanf("%d %d",&(n),&(m));
#define wez3(n,m,k) int (n),(m),(k); scanf("%d %d %d",&(n),&(m),&(k));
inline void pisz(int n) { printf("%d\n",n); }
template<typename T,typename TT> ostream& operator<<(ostream &s,pair<T,TT> t) {return s<<"("<<t.first<<","<<t.second<<")";}
template<typename T> ostream& operator<<(ostream &s,vector<T> t){FOR(i,SZ(t))s<<t[i]<<" ";return s; }
#define IN(x,y) ((y).find((x))!=(y).end())
#define DBG(vari) cerr<<#vari<<" = "<<(vari)<<endl;
#define ALL(t) t.begin(),t.end()
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define TESTS wez(testow)while(testow--)
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define REPD(i,a,b) for(int (i)=(a); (i)>=(b);--i)
#define REMAX(a,b) (a)=max((a),(b));
#define REMIN(a,b) (a)=min((a),(b));
#define IOS ios_base::sync_with_stdio(0);

const int maxn = 2222;

int n,m;
long long val[maxn];
int pos[maxn];
pair<pair<int,int>, int> t[maxn];

inline long long f(long long x) {
	return x * n - x * (x-1) / 2;
}

long long test() {
	long long res = 0;
	scanf("%d%d", &n, &m);
	FOR(i,m) {
		int ee,oo,pp;
		scanf("%d%d%d", &oo, &ee, &pp);
		t[2*i] = mp(mp(oo, 1), pp);
		t[2*i+1] = mp(mp(ee, -1), pp);
		res += f(ee-oo)*pp;
	}
	sort(t,t+2*m);
	long long cnt = 0;
	int q = 0;
	FOR(i,2*m) {
		if (i > 0 && t[i].fi.fi != t[i-1].fi.fi) {
			pos[q] = t[i-1].fi.fi;
			val[q] = cnt;
			q++;
		}
		cnt += t[i].fi.se * t[i].se;
	}
	pos[q] = t[2*m-1].fi.fi;
	val[q] = 0;
	bool fnd = true;
	while (fnd) {
		fnd = false;
		int j = 0;
		FOR(i,q) if (val[i] > 0) {
			j = i;
			fnd = true;
			break;
		}
		long long cur = val[j];
		int j0 = j;
		while (val[j] > 0) {
			cur = min(cur, val[j]);
			j++;
		}
		for (int i = j0; i < j; i++) {
			val[i] -= cur;
		}
		res -= cur * f(pos[j]-pos[j0]);
	}
	return res;
}

int main() {
	int T;
	scanf("%d", &T);
	for (int tt = 1; tt <= T; tt++) {
		printf("Case #%d: %lld\n", tt, test());
	}
	return 0;
}