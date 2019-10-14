#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

#define maxn 200
#define mod 1000000007
#define LL long long
int C[maxn][maxn];

LL pow(LL a,int n){
	LL t=a;LL ret=1;
	while(n){
		if(n&1)	ret=ret*t%mod;
		t=t*t%mod;
		n>>=1;
	}
	return ret;
}

void init(){
	for(int i=0;i<maxn;i++)
		for(int j=0;j<=i;j++){
			if(j==0)	C[j][i]=1;
			else if(j==i)	C[j][i]=1;
			else C[j][i]=(C[j-1][i-1]+C[j][i-1])%mod;
		}
}

int main(){
	freopen("A-small-attempt1 (1).in","r",stdin);
	freopen("2.txt","w",stdout);
	int cs,t=0;init();int n,m;
	scanf("%d",&cs);
	while(cs--){
		scanf("%d%d",&m,&n);
		LL ans=0;
		int flag=-1;LL tmp;
		for(int i=m;i>0;i--){
			flag=-flag;
			ans = (ans + flag*C[m-i][m]*pow(i,n))%mod;
			//cout<<ans<<endl;
		}
		ans = (ans%mod + mod)%mod;
		cout<<"Case #"<<++t<<": "<<ans<<endl;
	}
//	system("pause");
	return 0;
}
