#include<iostream>
#include<cmath>
#include<vector>
#include<string>
#include<map>
using namespace std;

#pragma comment(linker, "/STACK:36777216")
#define INF 0x7fffffff;
typedef long long LL;

vector<vector<int> > vt;
int f[10005];
bool flag;

void dfs(int k,bool c)
{
	if(f[k]!=-1&&f[k]!=c)
		flag=1;
	if(flag||f[k]!=-1)
		return;
	f[k]=c;
	for(int i=0;i<vt[k].size();i++)
	{
		int p=vt[k][i];
		dfs(p,!c);
	}
}

int main()
{
	freopen("input.in","r",stdin);
	freopen("output.txt","w",stdout);
	int T,cs,n,i;
	char p[10005],q[10005];
	scanf("%d",&T);
	for(cs=1;cs<=T;cs++)
	{
		map<string,int> mp;
		int k=0;
		scanf("%d",&n);
		vt.clear();
		vt.resize(n*2);
		for(i=0;i<n;i++)
		{
			scanf("%s%s",p,q);
			if(mp.find(p)==mp.end())
				mp[p]=k++;
			if(mp.find(q)==mp.end())
				mp[q]=k++;
			vt[mp[p]].push_back(mp[q]);
			vt[mp[q]].push_back(mp[p]);
		}
		memset(f,-1,sizeof(f));
		flag=0;
		dfs(0,0);
		printf("Case #%d: ",cs);
		if(flag)
			printf("No\n");
		else
			printf("Yes\n");
	}
}