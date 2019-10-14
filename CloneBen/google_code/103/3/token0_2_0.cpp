#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <set>
#include <cmath>

using namespace std;

typedef vector<int> VI;
typedef long long LL;
typedef pair<int,int> PI;
#define MP make_pair
#define REP(x,n) for(int x=0; x<(int)(n); ++x)
#define REB(b,x,n) for(int x=b; x<(int)(n); ++x)
#define REPD(x,n) for(int x=(n)-1; x>=0; --x)
#define PB push_back
#define ST first
#define ND second
const int INF = 1000000001;
const double EPS = 10e-9;

int inp[500002];
int a[101];
int dyn[500002];

const LL MOD = 1000000007;

int doit(int n) {
	//REP(i,n+1) cout<<inp[i]<<endl;
	int result=0;
	dyn[0]=1;
	REP(i,n) {
		dyn[i+1]=0;
		REP(j,i+1)
			if(inp[j]<inp[i+1])
				dyn[i+1] = ((LL)dyn[i+1] + dyn[j]) % MOD;
		result = ((LL)result + (LL)dyn[i+1]) % MOD;
	}
	return result;
}

int main()
{
	ios_base::sync_with_stdio(0);
	int NCase;
	cin>>NCase;
	REP(ncase,NCase) {
		int n,m,X,Y,Z;
		cin>>n>>m>>X>>Y>>Z;
		REP(i,m) cin>>a[i];
		inp[0]=-1;
		REP(i,n) {
			inp[i+1]=a[i%m];
			a[i%m]=((LL)X*(LL)a[i%m] + (LL)Y*(LL)(i+1))%(LL)Z;
		}

		cout<<"Case #"<<ncase+1<<": "<<doit(n)<<endl;
	}

  return 0;
}
