#include <cstdio>
#include <cstring>
using namespace std;
long long a[7700];
const int N=2e5+100;
long long as[N];
int main(){
	int t;
	scanf("%d",&t);
	int id=0;
	while(t--){
		memset(as,0,sizeof as);
		int n;
		scanf("%d",&n);
		long long ds[3]={0,0,0};
		for(int i=0;i<n;i++)scanf("%d",a+i),as[a[i]]++;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++)if(i!=j){
				long long mul=1ll*a[i]*a[j];
				long long cur=0;
				if(mul<N)cur+=as[mul]; 
				if(mul==a[i])cur--;
				if(mul==a[j])cur--;
				if(cur!=0){
					int cc=0;
					if(a[i]==1||a[j]==0)cc++;
					if(a[j]==1||a[i]==0)cc++;
					ds[cc]+=cur;
				}
			}
		}
		printf("Case #%d: %lld\n",++id,ds[0]/2+ds[1]/4+ds[2]/6);
	}
}
