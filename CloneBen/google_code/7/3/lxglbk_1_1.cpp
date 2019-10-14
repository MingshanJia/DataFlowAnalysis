#include<queue>
#include<vector>
#include<cstdio>
#include<cstring>
#include<cassert>
#include<iostream>
#include<algorithm>

using namespace std;
typedef long long ll;
const int N = 5005;

int a[N];
int main()
{
	int T,CAS=0;
	int n,m;

	for(scanf("%d",&T);CAS<T;CAS++)
	{
		memset(a,0,sizeof(a));
		scanf("%d",&n);
		for(int i=1,l,r;i<=n;i++)
		{
			scanf("%d %d",&l,&r);
			if(l>r) swap(l,r);
			a[l]++;
			a[r+1]--;
		}
		for(int i=1;i<=5000;i++) a[i]+=a[i-1];
		scanf("%d",&m);
		printf("Case #%d:",CAS+1);
		for(int k=0,p=0;k<m;k++)
		{
			scanf("%d",&p);
			printf(" %d",a[p]);
		}
		puts("");
	}
	return 0;
}
