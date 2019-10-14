// TwT514 {{{
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#define SZ(x) ((int)(x).size())
#define FOR(i,c) for (__typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)
#define REP(i,n) for (int i=0; i<(n); i++)
#define REP1(i,a,b) for (int i=(int)(a); i<=(int)(b); i++)
#define ALL(x) (x).begin(),(x).end()
#define MS0(x,n) memset((x),0,(n)*sizeof(*x))
#define MS1(x,n) memset((x),-1,(n)*sizeof(*x))
#define MP make_pair
#define PB push_back
#define RI(a) scanf("%d",&(a))
#define RII(a,b) scanf("%d%d",&(a),&(b))
#define RIII(a,b,c) scanf("%d%d%d",&(a),&(b),&(c))
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
// }}}
#define N 210
#define L 100
int m,n;
vector<int> e[N];
char name[N][L];
int find(char c[]){
	REP(i,n) if(strcmp(name[i],c)==0) return i;
	strcpy(name[n], c);
	return n++;
}

void input(){
	char c[L];
	int x,y;
	RI(m);
	n=0;
	REP(i,2*m) e[i].clear();
	REP(i,m){
		scanf("%s",&c); x = find(c);
		scanf("%s",&c); y = find(c);
		e[x].PB(y); e[y].PB(x);
	}
}

int vis[N];
bool dfs(int a, int t){
	vis[a] = t;
	FOR(it,e[a]){
		int b = *it;
		if(vis[b]==-t)continue;
		if(vis[b]==t || !dfs(b,-t)) return false;
	}
	return true;
}

bool good(){
	MS0(vis,N);
	REP(i,n){
		if(vis[i])continue;
		if(!dfs(i,1))return false;
	}
	return true;
}

int main() {
	int zn;
	RI(zn);
	REP(zi,zn){
		input();
		printf("Case #%d: %s\n", zi+1, good()?"Yes":"No");
	}
    return 0;
}


