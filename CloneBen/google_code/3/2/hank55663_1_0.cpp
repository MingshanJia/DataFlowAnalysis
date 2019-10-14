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
		int n;
		scanf("%d",&n);
		int a[5005];
		for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
		sort(a,a+n);
		pii cnt[5005];
		int index=0;
		MEM(cnt);
		cnt[0].y=1;
		cnt[0].x=a[0];
		for(int i=1;i<n;i++){
			if(a[i]==a[i-1]){
				cnt[index].y++;
			}
			else{
				cnt[++index].y++;
				cnt[index].x=a[i];
			}
		}
		LL ans=0;
		for(int i=0;i<=index;i++){
			LL hi=0;
			LL now=0;
			for(int j=0;j<=index;j++){
				if(j==i)
				continue;
				while(now<=index&&(LL)cnt[now].x<(LL)2*cnt[i].x+cnt[j].x){
					if(now!=i)
					hi+=cnt[now].y;
			//		printf("%d\n",hi);
					now++;
				}
				hi-=cnt[j].y;
			//	printf("%d %d %d %d\n",i,j,hi,now);
				ans+=(LL)hi*cnt[i].y*(cnt[i].y-1)/2*cnt[j].y;
			//	printf("%d %d %lld\n",cnt[i].x,cnt[j].x,(LL)hi*cnt[i].y*(cnt[i].y-1)/2);
			}
		}
//		printf("Case #%d: %lld\n",T,ans);
		for(int i=0;i<=index;i++){
			LL sum=0;
			for(int j=0;j<=index;j++){
				if(i==j)
				continue;
				if((LL)cnt[j].x>=(LL)3*cnt[i].x)
				break;
				sum+=cnt[j].y;
			}
			ans+=(LL)cnt[i].y*(cnt[i].y-1)*(cnt[i].y-2)*sum/6; 
		}
		printf("Case #%d: %lld\n",T,ans);
	} 
}
