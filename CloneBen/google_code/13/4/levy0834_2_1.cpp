#include<iostream>
#include<cmath>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
using namespace std;

#pragma comment(linker, "/STACK:36777216")
#define INF 0x7fffffff;
typedef long long LL;

int main()
{
	freopen("input.in","r",stdin);
	freopen("output.txt","w",stdout);
	int T,cs,n,i;
	scanf("%d",&T);
	for(cs=1;cs<=T;cs++)
	{
		printf("Case #%d: ",cs);
		
		string name[105];
		char s[1005];
		scanf("%d",&n);
		gets(s);
		for(i=0;i<n;i++)
		{
			gets(s);
			name[i]=s;
		}
		int ans=0;
		while(true)
		{
			bool flag=false;
			for(i=1;i<n;i++)
			{
				if(name[i]<name[i-1])
				{
					flag=true;
					break;
				}
			}
			if(flag)
			{
				ans++;
				sort(name,name+i+1);
			}
			else
				break;
		}
		printf("%d\n",ans);
	}
}