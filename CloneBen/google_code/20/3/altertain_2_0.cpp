#include <vector>
#include <map>
#include <set>
#include <stack>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <cctype>
#include <cstring>
#include <queue>
#include <cassert>
#include <ctime>

using namespace std;

typedef long long LL;
typedef long double LD;
typedef vector<int> VI;
typedef pair<int,int> PII;
typedef vector<PII> VPII;

#define MP make_pair
#define ST first
#define ND second
#define PB push_back
#define FOR(i,a,b) for( int i=(a); i<(b); ++i)
#define FORD(i,a,b) for( int i=(a); i>(b); --i)
#define REP(i,n) for(int i=0; i<(n); ++i)
#define ALL(X) (X).begin(),(X).end()
#define SZ(X) (int)(X).size()
#define FORE(it,X) for(__typeof((X).begin()) it=(X).begin(); it!=(X).end();++it)

int n,p,m;
int st[101],w[101];
VPII dt[10001];
int dp[101][10001];

int main()
{
	int tn;
	cin>>tn;

	while (tn--) {
		cin>>n>>p>>m;
		REP(i,n) dt[i].clear();
		
		REP(i,p) {
			cin>>st[i]>>w[i];
			st[i]--;
		}
		REP(i,m) {
			int d,l;
			cin>>d>>l;
			int v1,v2;
			cin>>v1; v1--;
			REP(j,l-1) {
				cin>>v2; v2--;

//				cout<<v1<<"-"<<v2<<":"<<d<<endl;
				dt[v1].PB(MP(d,v2));
				dt[v2].PB(MP(d,v1));
				v1=v2;
			}
		}


		priority_queue<PII,VPII, greater<PII> > pq;
		REP(i,p) {
			memset(dp[i],63,sizeof(dp[i]));
			VI vst(n,0);
			int* dij = dp[i];

			dij[st[i]]=0;
			pq.push(MP(0,st[i]));

			while (pq.size()) {
				int v=pq.top().ND;
				int now = pq.top().ST;
				pq.pop();
				if (vst[v]) continue;
				vst[v]=true;

				REP(e,SZ(dt[v])) {
					int u=dt[v][e].ND;
					int d=dt[v][e].ST;
					if (dij[u]>now+d) {
						dij[u]=now+d;
						pq.push(MP(now+d,u));
					}
				}
			}

//			REP(j,n) cout<<dij[j]<<" "; cout<<endl;
		}
//		cout<<endl;

		LL prt=1e18;
		REP(i,n) {
			LL mx=0;
			REP(j,p)
				mx=max(mx, dp[j][i]*(LL)w[j]);
			prt=min(prt,mx);
		}

		static int qq=0;
		printf("Case #%d: ",++qq);
		if (prt<1061109567)
			cout<<prt<<endl;
		else
			cout<<-1<<endl;
	}
	return 0;
}
