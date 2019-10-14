#include<bits/stdc++.h>
#include <unistd.h>
using namespace std;

#define sd(a) scanf("%d",&a)
#define ss(a) scanf("%s",a)
#define sl(a) scanf("%lld",&a)
#define clr(a) memset(a,0,sizeof(a))
#define debug(a) printf("check%d\n",a)
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define ll long long
#define N 10010
#define INF 100000

int s[N];
int main()
{
	// freopen("B.in","r",stdin);
	// freopen("B.out","w",stdout);
	int t;
	sd(t);
	for(int tt=1;tt<=t;tt++)
	{
		int n,e,i;
		sd(e);sd(n);
		for(i=0;i<n;i++)
			sd(s[i]);
		sort(s,s+n);
		int p=n, maxx=0, honor=0;
		for(i=0;i<p;i++)
		{
			while(p-1>i && honor)
			{
				if(e>s[i])	break;
				e+=s[--p];
				honor--;
			}
			if(e>s[i] && i<p)
			{
				honor++;
				e-=s[i];
			}
			maxx=max(maxx,honor);
		}
		printf("Case #%d: %d\n",tt,maxx);
	}
}