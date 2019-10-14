#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<map>
using namespace std;

bool b[105][257];
int f[105][257];
int a[105];
int N,D,I,M,T;

int abs(int x)
{
	return x>0?x:-x;
}

int dp(int now,int last)
{
	if(now==N)
		return 0;
	if(!b[now][last])
	{
		b[now][last]=true;
		f[now][last]=dp(now+1,last)+D;
		for(int i=0;i<=255;i++)
			if(abs(last-i)<=M||last==256)
				f[now][last]=min(f[now][last],dp(now+1,i)+abs(a[now]-i));
		for(int i=0;i<=255;i++)
			if(abs(last-i)<=M||last==256&&i!=last)
				f[now][last]=min(f[now][last],dp(now,i)+I);
	}
	return f[now][last];
}

int main()
{
	freopen("B-large.in","r",stdin);
	freopen("B-large.out","w",stdout);
	scanf("%d",&T);
	for(int test=1;test<=T;test++)
	{
		memset(b,0,sizeof(b));
		memset(f,0,sizeof(f));
		scanf("%d%d%d%d",&D,&I,&M,&N);
		for(int i=0;i<N;i++)
			scanf("%d",&a[i]);
		printf("Case #%d: %d\n",test,dp(0,256));
	}
	return 0;
}

