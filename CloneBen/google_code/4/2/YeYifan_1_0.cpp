#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int T,ans;
void solve(int m,int n){
		int cnt=0;
		for(int i=1;i<=m;i++){
			if(i%3==1)
			{
				for(int j=1;j<=n;j++)if(j%3)cnt++;
					
			}
			if(i%3==2){
				for(int j=1;j<=n;j++)if(j%3!=2)cnt++;
			}
			if(i%3==0){
				for(int j=1;j<=n;j++)if(j%3!=1)cnt++;
			}
		
		}
		if(cnt>ans)ans=cnt;
}
int main(){
	freopen("out.out","w",stdout);
	scanf("%d",&T);
	int m,n;
	for(int cas=1;cas<=T;cas++){
		ans=0;
		scanf("%d%d",&m,&n);
		solve(m,n);
		solve(n,m);
		if(m<=2&&n<=2)ans=m*n;
		else if(m==2)ans=n/3*4+n%3*2;
		else if(n==2)ans=m/3*4+m%3*2;
		printf("Case #%d: %d\n",cas,ans);
	}
return 0;
}