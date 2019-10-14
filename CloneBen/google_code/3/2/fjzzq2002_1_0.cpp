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
int T,n,l[SZ];
void sol()
{
	cin>>n;
	for(int i=1;i<=n;++i)
		cin>>l[i];
	int cc=0;
	for(int i=1;i<=n;++i)
	{
		for(int j=i+1;j<=n;++j)
		{
			for(int r=j+1;r<=n;++r)
			{
				for(int s=r+1;s<=n;++s)
				{
					int g[]={l[i],l[j],l[r],l[s]};
					sort(g,g+4);
					int ans=0;
					do
					{
						if(g[0]==g[1]&&g[2]<g[3]);
						else continue;
						if(g[0]+g[1]+(ll)g[2]>g[3])
							++ans;
					}while(next_permutation(g,g+4));
					if(ans) ++cc;
				}
			}
		}
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
