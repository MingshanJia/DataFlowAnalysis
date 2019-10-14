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

int n,n2;
int a[40][40];

void input(){
	RI(n);
	n2=n*n;
	REP(i,n2)REP(j,n2) RI(a[i][j]);
}

int c[40],flg;
bool solve(){
	REP(i,n2)REP(j,n2) if(a[i][j]<1 || a[i][j]>n2) return false;
	memset(c,0,sizeof(c));
	flg=0;
	REP(i,n2){
		flg++;
		REP(j,n2){
			if(c[a[i][j]]==flg)return false;
			c[a[i][j]]=flg;
		}
	}
	REP(j,n2){
		flg++;
		REP(i,n2){
			if(c[a[i][j]]==flg)return false;
			c[a[i][j]]=flg;
		}
	}
	REP(ii,n){
		REP(jj,n){
			flg++;
			REP(i,n)REP(j,n){
				if(c[a[ii*n+i][jj*n+j]]==flg) return false;
				c[a[ii*n+i][jj*n+j]]=flg;
			}
		}
	}
	return true;
}

int main() {
	int zn;
	RI(zn);
	REP(zi,zn){
		input();
		printf("Case #%d: ",zi+1);
		puts(solve()?"Yes":"No");
	}
	return 0;
}


