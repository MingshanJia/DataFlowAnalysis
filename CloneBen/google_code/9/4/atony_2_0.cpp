#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>

using namespace std;

const int MAXN = 11001;
const int MAXM = 1000011;
const int MAXK = 101;
const int INF = 1000000005;
const double pi = acos(-1.0);

int K;

int cal(vector<vector<int> > &dp, vector<int> &a, int l,int r)
{
	if(l>r)
		return 0;
	if(dp[l][r]!=-1)
	return	dp[l][r];
	int &ans =dp[l][r];
	if(r-l+1<=2)
	{
		ans=r-l+1;
		return ans;
	}
	ans=INF;
	int j,k;
	for(j=l+1;j<r;j++)
		if(a[j]-a[l]==K&&cal(dp,a,l+1,j-1)==0)
		for(k=j+1;k<=r;k++)
			if(a[k]-a[j]==K&&cal(dp,a,j+1,k-1)==0)
			{
				ans=min(ans,cal(dp,a,k+1,r));
			}
	ans=min(ans,cal(dp,a,l+1,r)+1);
	return ans;
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int T,cas,n;
	scanf("%d",&T);
	for(cas=1;cas<=T;cas++)
	{
		scanf("%d%d",&n,&K);
		vector<int> a(n,0);
		for(int i=0;i<n;i++)
			scanf("%d",&a[i]);
		vector<vector<int> > dp(n,vector<int>(n,-1));
		printf("Case #%d: %d\n",cas,cal(dp,a,0,n-1));
	}
	return 0;
}