#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
//#define pdd pair<double,double>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-8
#define mii map<int,int>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define N 500005
//#define M 1000005
#define pi 3.14159265359
#define cpdd const pdd
#define hash Hash
#define list List
using namespace std;
typedef long long LL;
using namespace std;
int main(){
	int t;
	scanf("%d",&t);
	for(int T=1;T<=t;T++){ 
		int x[3],y[3],z[3];
		for(int i=0;i<3;i++)
		scanf("%d %d %d",&x[i],&y[i],&z[i]);
		sort(x,x+3);
		printf("Case #%d: %.12lf\n",T,(double)(x[2]-x[0])/6);
	} 
}
