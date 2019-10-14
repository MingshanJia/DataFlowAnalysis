#include <stdio.h>
#include <string.h>
#define mod 1000000007
int wd[404][26],le[404];
int sen[26][4004];
char str[4004];
long long dp[4004];
int main()
{
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
	int T,cas=0;
	scanf("%d",&T);
	while(T--)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
		{
			char ch[25];
			memset(wd[i],0,sizeof(wd[i]));
			scanf("%s",ch);
			le[i]=strlen(ch);
			for(int j=0;ch[j]!='\0';j++)
			{
				wd[i][ch[j]-'a']++;
			}
		}
		printf("Case #%d: ",++cas);
		while(m--)
		{
			scanf("%s",str+1);
			int len=strlen(str+1);
			for(int i=0;i<26;i++)
			{
				for(int j=0;j<=len;j++)
				sen[i][j]=0;
			}
			for(int i=1;i<=len;i++)
			{
				dp[i]=0;
				for(int j=0;j<26;j++)
				{
					sen[j][i]=sen[j][i-1];
				}
				sen[str[i]-'a'][i]++;
			}
			dp[0]=1;
			for(int i=1;i<=len;i++)
			{
				if(dp[i-1])
				{
					for(int j=1;j<=n;j++)
					{
						if(i+le[j]-1>len)continue;
						bool key=true;
						for(int l=0;l<26;l++)
						{
							if(sen[l][i+le[j]-1]-sen[l][i-1]!=wd[j][l])
							{
								key=false;
								break;
							}
							
						}
						if(key)
						{
							dp[i+le[j]-1]+=dp[i-1];
							dp[i+le[j]-1]%=mod;
						}
					}
				}
			}
			printf("%lld",dp[len]);
			if(m==0)printf("\n");
			else printf(" ");
		}
	}
}