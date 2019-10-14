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
int dp[305][305][305];
int match[305][305];
string s;
int DP(int a,int b,int c){
	//printf("%d %d %d\n",a,b,c);
	if(c>a)
	return 1e9;
	if(a==0)
	return 1;
	if(dp[a][b][c]!=-1)
	return dp[a][b][c];
	dp[a][b][c]=1e9;
	if(c==0){
		dp[a][b][c]=a+1;
		for(int i=0;i<a;i++)
			for(int j=i+1;j<a;j++){
				if(match[j][a]>=j-i+1)
				dp[a][b][c]=min(dp[a][b][c],DP(a-j+i-1,i,j)+1);
				dp[a][b][c]=min(dp[a][b][c],DP(a-1,i,j)+1);
			}
		return dp[a][b][c];
	}
	dp[a][b][c]=DP(a-1,b,c)+1;
	if(match[c][a]>=c-b+1){
		dp[a][b][c]=min(dp[a][b][c],DP(a-c+b-1,b,c)+1);
	}
	dp[a][b][c]=min(dp[a][b][c],DP(a,0,0)+1);
	return dp[a][b][c];
}
int main(){
	int t;
	scanf("%d",&t);
	for(int T=1;T<=t;T++){ 
		cin>>s;
		for(int i=0;i<s.size();i++)
			for(int j=i;j<s.size();j++){
				int k=0;
				while(k<=i&&k<=j&&s[i-k]==s[j-k]){
					k++;
				}
				match[i][j]=k;
			}
		MEMS(dp);
		dp[0][0][0]=0;
		int len=s.size();
		int ans=DP(len-1,0,0);
		for(int i=0;i<s.size();i++)
			for(int j=i+1;j<s.size();j++)
				ans=min(ans,DP(len-1,i,j));
		//printf("%d\n",DP(len-1,0,5));
		printf("Case #%d: %d\n",T,ans);
	} 
}
