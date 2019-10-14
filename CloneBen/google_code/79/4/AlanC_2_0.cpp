#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <string>
#include <map>
#include <ctime>
#define LL long long int
#define N 10005
using namespace std;

int n,TC,ok;
LL L,H,x,a[N];

int main(){
	scanf("%d",&TC);
	
	for (int C=1;C<=TC;C++){
		scanf("%d%lld%lld",&n,&L,&H);
		for (int i=0;i<n;i++) scanf("%lld",&a[i]);
		
		
		for (LL i=L;i<=H;i++){
			ok=1;
			for (int j=0;j<n;j++)
				if (i%a[j]!=0 && a[j]%i!=0) ok=0;
			if (ok){
				x=i;
				break;
			}
		}
		if (ok)
		printf("Case #%d: %lld\n",C,x);
		else printf("Case #%d: NO\n",C);
	}
	//scanf("\n");
	return 0;
}
