#include <cstdio>
#include <algorithm>
#include <string>
#include <cassert>
#include <vector>
using namespace std;

#define PB push_back
#define SZ(v) ((int)(v).size())
#define MP make_pair
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define FORE(i,a,b) for(int i=(a);i<=(b);++i)
#define REPE(i,n) FORE(i,0,n)

typedef long long ll;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<VVI> VVVI;
typedef vector<ll> VLL;
typedef vector<VLL> VVLL;

const ll INF=1LL<<32;

int floors,drops,breaks;

VVLL maxfloors; //maxfloors[drops][breaks]
ll get(ll drops,ll breaks) {
	breaks<?=drops;
	if(breaks==0) return 0;
	if(breaks==1) return drops;
	if(breaks==2) return min(drops*(drops+1)/2,INF);
	int i=min(drops,(ll)SZ(maxfloors)-1),j=min(breaks,(ll)SZ(maxfloors[i])-1);
	if(!(i==drops&&j==breaks||maxfloors[i][j]==INF)) {
		printf("%d(%lld) %d(%lld) %lld\n",i,drops,j,breaks,maxfloors[i][j]);
	}
	assert(i==drops&&j==breaks||maxfloors[i][j]==INF);
	return maxfloors[i][j];
}

void run(int casenr) {
	scanf("%d%d%d",&floors,&drops,&breaks);
	
	ll a=get(drops,breaks),b,c;
	if(a==INF) a=-1;
	{
		ll l=0,h=drops;
		while(l+1<h) {
			ll m=(l+h)/2;
			if(get(m,breaks)>=floors) h=m; else l=m;
		}
		b=h;
	}
	{
		ll l=0,h=breaks;
		while(l+1<h) {
			ll m=(l+h)/2;
			if(get(drops,m)>=floors) h=m; else l=m;
		}
		c=h;
	}
	printf("Case #%d: %lld %lld %lld\n",casenr,a,b,c);	
}


int main() {
	maxfloors=VVLL(1,VLL(1,0));
	while(SZ(maxfloors)<10000) {
		maxfloors.PB(VLL(1,0));
		while(SZ(maxfloors.back())<SZ(maxfloors)&&maxfloors.back().back()<INF) {
			int i=SZ(maxfloors)-1,j=SZ(maxfloors[i]);
			maxfloors.back().PB(min(1+get(i-1,j-1)+get(i-1,j),INF));
		}
	}
	
	int n; scanf("%d",&n); FORE(i,1,n) run(i);
}
