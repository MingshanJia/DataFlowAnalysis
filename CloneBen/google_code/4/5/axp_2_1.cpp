/* ***********************************************
Author        :axp
Created Time  :2016/10/16 13:24:56
TASK		  :C.cpp
LANG          :C++
************************************************ */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

typedef long long ll;
const int inf = 1<<30;
const int md = 1e9+7;
const int N = 4000+10;
int n,m;
int T;
bool vis[N];
int dp[N];
char ch[N];
char tmp[N];

struct Point
{
	int v[26];
	Point(){memset(v,0,sizeof v);}
};

bool operator<(Point a,Point b)
{
	for(int i=0;i<26;i++)
		if(a.v[i]!=b.v[i])
			return a.v[i]<b.v[i];
	return 0;
}

map<Point,int> mp;

int f(int now)
{
	int &re=dp[now];
	if(vis[now])return re;
	vis[now]=1;
	if(now==n)return re=1;
	Point p;
	re=0;
	for(int i=now;i<n;i++)
	{
		p.v[ch[i]-'a']++;
		int t=mp[p];
		if(t)re=(re+1ll*t*f(i+1))%md;
	}
	return re;
}

int main()
{
    freopen("C-large.in","r",stdin);
    freopen("large-out.txt","w",stdout);
    scanf("%d",&T);
	for(int kase=1;kase<=T;kase++)
	{
		printf("Case #%d:",kase);
		int v,s;
		scanf("%d%d",&v,&s);
		mp.clear();
		for(int i=0;i<v;i++)
		{
			scanf("%s",tmp);
			Point p;
			for(int j=0;tmp[j];j++)p.v[tmp[j]-'a']++;
			mp[p]++;
		}
		for(int i=0;i<s;i++)
		{
			scanf("%s",ch);
			memset(vis,0,sizeof vis);
			n=strlen(ch);
			int ans=f(0);
			printf(" %d",ans);
		}
		putchar(10);
	}
    return 0;
}
