#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <string>
#include <bitset>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <sstream>
#include <stack>
#include <iomanip>
using namespace std;
#define pb push_back
#define mp make_pair
typedef pair<int,int> pii;
typedef long long ll;
typedef double ld;
typedef vector<int> vi;
#define fi first
#define se second
#define fe first
#define FO(x) {freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);}
#define Edg int M=0,fst[SZ],vb[SZ],nxt[SZ];void ad_de(int a,int b){++M;nxt[M]=fst[a];fst[a]=M;vb[M]=b;}void adde(int a,int b){ad_de(a,b);ad_de(b,a);}
#define Edgc int M=0,fst[SZ],vb[SZ],nxt[SZ],vc[SZ];void ad_de(int a,int b,int c){++M;nxt[M]=fst[a];fst[a]=M;vb[M]=b;vc[M]=c;}void adde(int a,int b,int c){ad_de(a,b,c);ad_de(b,a,c);}
#define es(x,e) (int e=fst[x];e;e=nxt[e])
#define esb(x,e,b) (int e=fst[x],b=vb[e];e;e=nxt[e],b=vb[e])
#define VIZ {printf("digraph G{\n"); for(int i=1;i<=n;i++) for es(i,e) printf("%d->%d;\n",i,vb[e]); puts("}");}
#define VIZ2 {printf("graph G{\n"); for(int i=1;i<=n;i++) for es(i,e) if(vb[e]>=i)printf("%d--%d;\n",i,vb[e]); puts("}");}
#define SZ 666666
int T,n; ll l[SZ];
map<ll,ll> rec;
map<ll,bool> vis;
void sol()
{
	rec.clear();
	cin>>n;
	for(int i=1;i<=n;++i)
		cin>>l[i];
	ll cc=0;
	sort(l+1,l+1+n);
	for(int i=1;i<=n;++i)
	{
		for(int j=i+1;j<=n;++j)
		{
			if(l[i]!=l[j]) continue;
			//需要注意一个问题
			//有可能腰和底或顶相等
			//这时候会被算3次
			//需要额外容斥一下
			if(rec.count(l[i]))
			{
				cc+=rec[l[i]];
				continue;
			}
			ll cnt=0;
			for(int r=1;r<=n;++r)
			{
				if(r==i||r==j) continue;
				//r为顶
				//我们就要询问>l[r]且<l[r]+l[i]+l[j]的有几个
				cnt+=lower_bound(l+1,l+1+n,l[r]+l[i]*2)
				-upper_bound(l+1,l+1+n,l[r]);
				if(l[i]>l[r]) cnt-=2;
			}
			rec[l[i]]=cnt; cc+=cnt;
		}
	}
	vis.clear();
	//如果作为顶？(i,3i)
	//如果作为底？(0,i)
	for(int i=1;i<=n;++i)
	{
		if(vis[l[i]]) continue;
		vis[l[i]]=1;
		ll ceq=0,c1=0,c2=0;
		for(int j=1;j<=n;++j)
		{
			if(l[j]==l[i]) ++ceq;
			else if(l[j]<l[i]) ++c1;
			else if(l[j]<l[i]*3) ++c2;
		}
		ll cho=ceq*(ceq-1)*(ceq-2)/6;
		cc-=cho*(c1+c2)*2;
	}
	cout<<cc<<"\n";
}
int main()
{
	cin>>T;
	for(int i=1;i<=T;++i)
		printf("Case #%d: ",i),sol();
}
/*
假设腰为a，上底为x，下底为y
那么x<y,2a+x>y
*/
