#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<list>
#include<stack>
#include<map>

#define FOR(i,a,b) for(int i=(a); i<(int)(b); ++i)
#define FORD(i,a,b) for(int i=(a)-1; i>=(int)(b); --i)
#define FORE(i,C) for(__typeof(C.begin()) i=C.begin(); i!=C.end(); ++i)
#define MP make_pair
#define FI first
#define SE second
#define PB push_back

using namespace std;

typedef long long LL;

const int P = 9901;
const int kMax = 16;
const int nMax = 302;

//	Rozszerzony Euklides
//	ax + by = d, gdzie d=gcd(a,b)
//	a >= b!  a,b >= 0 (wpp. bardzo uwazaj)
int egcd(int a, int b, int &x, int &y) {
	stack<int> S;
	while(b) {S.push(a/b); swap(a,b); b%=a;}
	x=1, y=0;
	while(!S.empty()) {swap(x,y); y-=S.top()*x; S.pop();}
	return a;
}

int inv(int a) {
	int x,y;
	egcd(P,a,y,x);
	while(x<0) x+=P;
	return x;
}

pair<int,int> tabK[kMax];
int K,N;
vector<int> tabN[nMax];
int fact[nMax+4];
bool vis[nMax];

void dfs(int v) {
	if(vis[v]) return;
	vis[v] = true;
	FORE(it,tabN[v]) dfs(*it);
}

int count(int mask) {
	FOR(i,0,N) {tabN[i].clear(); vis[i]=false;}
	
	int nK=0;
	
	FOR(i,0,K) if(mask&(1<<i)) {
		int a=tabK[i].FI, b=tabK[i].SE;
		tabN[a].PB(b); tabN[b].PB(a);
		nK++;
	}
	
	if(nK==N) {
		dfs(0);
		FOR(i,0,N) if(!vis[i]) return 0;
		FOR(i,0,N) if(tabN[i].size()!=2) return 0;
		return 1;
	}
	
	FOR(i,0,N) if(tabN[i].size()>2) return 0;
	int n1=0;
	FOR(i,0,N) if(tabN[i].size()==1) n1++;
	
	int nP=0;
	
	FOR(i,0,N) if(!tabN[i].empty() && !vis[i]) {
		dfs(i);
		nP++;
	}
	
	if(nP*2!=n1) return 0;
	
	int res = ((1<<nP)*fact[N-nK-1])%P;
	int den = 2;
	res = (res*inv(den))%P;
	
	FOR(i,0,N) tabN[i].clear();
	
	return res;
}

int bitCount(int k) {
	int res = 0;
	while(k) {
		res += k&1;
		k >>= 1;
	}
	return res;
}

void testcase(int tNum) {
	scanf("%d %d",&N,&K);
	FOR(i,0,K) {
		int a,b;
		scanf("%d %d",&a,&b); --a; --b;
		tabK[i] = MP(a,b);
	}
	int res = 0;
	FOR(mask,0,(1<<K)) {
		int num = count(mask);
		if(bitCount(mask)%2==0)
			res = (res+num)%P; else
			res = (res+P-num)%P;
	}
	printf("Case #%d: %d\n",tNum,res);
}

int main() {

	fact[0] = 1;
	FOR(i,1,nMax+2) fact[i] = (fact[i-1]*i)%P;

	int t;
	scanf("%d",&t);
	FOR(i,0,t) testcase(i+1);
	
	return 0;
}
