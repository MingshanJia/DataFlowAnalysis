#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

long long cc[1000],vv[1000];
long long MOD=1000000007;

int main(){
	int T;
	scanf("%d",&T);
	for(int tt=1;tt<=T;++tt){
		long long C, V;
		int L;
		scanf("%lld%lld%d", &C,&V,&L);
		cc[1]=0;
		vv[1]=V;
		for(int i=2;i<=L;++i){
			vv[i] = (V * vv[i-1] + V * cc[i-1]) % MOD;
			cc[i] = (C * vv[i-1]) % MOD;
		}
		printf("Case #%d: %lld\n", tt, (vv[L] + cc[L]) % MOD);
	}
}
