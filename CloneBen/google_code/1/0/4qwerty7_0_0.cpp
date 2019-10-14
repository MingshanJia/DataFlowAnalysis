#include <cstdio>
#include <cstring>
using namespace std;
int a[7700];
const int N=2e5+100;
int as[N];
int main(){
	int t;
	scanf("%d",&t);
	int id=0;
	while(t--){
		memset(as,0,sizeof as);
		int n;
		scanf("%d",&n);
		int cnt=0;
		for(int i=0;i<n;i++)scanf("%d",a+i),as[a[i]]++;
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				for(int k=j+1;k<n;k++){
					if(1ll*a[i]*a[j]==a[k]||1ll*a[k]*a[j]==a[i]||1ll*a[i]*a[k]==a[j])
					cnt++;
				}
			}
		}
		printf("Case #%d: %d\n",++id,cnt);
	}
}
