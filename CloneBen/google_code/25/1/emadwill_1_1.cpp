#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;
#define pb push_back

vector< vector<int> > v;
int ret,n,m,comp,vis[1001],x[1001];

void flood(int num)
{
	vis[num] = comp;
	
	for(int i=0;i<v[num].size();++i)
		if(!vis[v[num][i]]) flood(v[num][i]);
}

int main()
{
	int ts,t,i,a,b;
	
	scanf("%d",&ts);
	
	for(t=1;t<=ts;++t) {
		scanf("%d%d",&n,&m);
		
		ret=0;
		v.clear();
		v.resize(n);
		
		for(i=0;i<m;++i) {
			scanf("%d%d",&a,&b);
			v[a].pb(b);
			v[b].pb(a);
		}
		
		printf("Case #%d: ",t);
		
		memset(vis,0,sizeof(vis));
		comp = 0;
		
		for(i=0;i<n;++i) {
			if(!v[i].size()) continue;
			if(!vis[i]) {
				++comp;
				flood(i);
			} 
		}
		
		memset(x,0,sizeof(x));
		
		for(i=0;i<n;++i) {
			if(!v[i].size()) continue;
			if(v[i].size()%2)
				++x[vis[i]-1];
		}
	
		if(comp>1) 
		{
			ret = comp;
			int sum=0;
		
			for(i=0;i<comp;++i) {
				if(x[i] == 1) {
					x[i]=0;
					sum++;
				}
				else if(x[i]>1) {
					x[i]-=2;
					sum+=x[i];
				}
			}
		
			ret += sum/2;
		}
		else if(comp == 1) {
			ret = x[0]/2;
		}
		
		printf("%d\n",ret);
	}
}









