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

int n;
int prev[maxn], a[maxn], b[maxn];
vector<int> g[maxn];
int inp[maxn];
int res[maxn];

void test() {
	scanf("%d", &n);
	FOR(i,n) scanf("%d", &a[i]);
	FOR(i,n) scanf("%d", &b[i]);
	FOR(i,n) g[i].clear();
	FOR(i,n+2) prev[i] = -1;
	FOR(i,n) {
		if (prev[a[i]] != -1) {
			g[i].push_back(prev[a[i]]);
		}
		if (prev[a[i]-1] != -1) {
			g[prev[a[i]-1]].push_back(i);
		}
		prev[a[i]] = i;
	}
	FOR(i,n+2) prev[i] = -1;
	for (int i = n-1; i >= 0; i--) {
		if (prev[b[i]] != -1) {
			g[i].push_back(prev[b[i]]);
		}
		if (prev[b[i]-1] != -1) {
			g[prev[b[i]-1]].push_back(i);
		}
		prev[b[i]] = i;
	}
	FOR(i,n) inp[i] = 0;
	FOR(i,n) {
		//printf("%d : ", i);
		FOREACH(j,g[i]) {
			//printf("%d ", *j);
			inp[*j]++;
		}
		//printf("\n");
	}
	set<int> Q;
	FOR(i,n) if (inp[i] == 0) {
		Q.insert(i);
	}
	int cur = 1;
	while (!Q.empty()) {
		int u = *Q.begin();
		res[u] = cur;
		cur++;
		Q.erase(u);
		FOREACH(i,g[u]) {
			int v = *i;
			inp[v]--;
			if (inp[v] == 0) {
				Q.insert(v);
			}
		}
	}
	FOR(i,n) printf(" %d", res[i]);
	printf("\n");
}

int main() {
	int T;
	scanf("%d", &T);
	for (int tt = 1; tt <= T; tt++) {
		printf("Case #%d:", tt);
		test();
	}
	return 0;
}