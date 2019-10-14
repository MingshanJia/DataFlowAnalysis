#include <cstdio>
#include <cstdlib> 
#include <cstring> 
#include <cmath> 
#include <cctype> 
#include <vector> 
#include <string> 
#include <queue> 
#include <deque> 
#include <stack> 
#include <set> 
#include <map> 
#include <utility> 
#include <algorithm> 
#include <iostream> 
#include <sstream> 
using namespace std; 

#define size(x) int((x).size()) 
#define foreach(i,c) for(typeof((c).begin()) i=(c).begin();i!=(c).end();i++) 
typedef long long I64; typedef unsigned long long U64; 
const double EPS=1e-12; 
const int INF=999999999; 
typedef vector<int> VI; 
typedef vector<string> VS;

const int MAXN=10;

int n0,n1,m;
int a0[MAXN][2],a1[MAXN][2];
char buf[100];
int ans[MAXN];
int Q[MAXN][2];

VI hList,wList;

bool check(int lh,int rh,int lw,int rw)
{
	for(int i=0;i<n0;i++) {
		if(a0[i][0]>=lh && a0[i][0]<=rh && a0[i][1]>=lw && a0[i][1]<=rw) return 0;
	}
	for(int i=0;i<n1;i++) {
		if(a1[i][0]<lh || a1[i][0]>rh || a1[i][1]<lw || a1[i][1]>rw) return 0;
	}
	return 1;
}

void solve()
{
	int n;

	scanf("%d",&n);	
	hList.clear();
	wList.clear();
	
	n0=n1=0;
	for(int i=0;i<n;i++) {
		int x,y;
		scanf("%d%d",&x,&y);
		hList.push_back(x-1);hList.push_back(x);hList.push_back(x+1);
		wList.push_back(y-1);wList.push_back(y);wList.push_back(y+1);
		scanf("%s",buf);
		if(buf[0]=='N') {
			a0[n0][0]=x,a0[n0][1]=y;
			n0++;
			scanf("%s",buf);
		}
		else {
			a1[n1][0]=x,a1[n1][1]=y;
			n1++;
		}
	}

	hList.push_back(-1);
	hList.push_back(1000002);
	wList.push_back(-1);
	wList.push_back(1000002);

	sort(hList.begin(),hList.end());
	sort(wList.begin(),wList.end());
	
	scanf("%d",&m);
	for(int i=0;i<m;i++) scanf("%d%d",&Q[i][0],&Q[i][1]);
	memset(ans,-1,sizeof(ans));

		
	for(int i1=0;i1<size(hList);i1++)
		for(int i2=i1;i2<size(hList);i2++)
			for(int j1=0;j1<size(wList);j1++)
				for(int j2=j1;j2<size(wList);j2++) {
					if(!check(hList[i1],hList[i2],wList[j1],wList[j2])) continue;

					//printf("%d %d , %d %d\n",hList[i1],hList[i2],wList[j1],wList[j2]);
					for(int i=0;i<m;i++) if(ans[i]!=-2) {
						int ok=(Q[i][0]>=hList[i1] && Q[i][0]<=hList[i2] && Q[i][1]>=wList[j1] && Q[i][1]<=wList[j2]);
						if(ans[i]==-1) ans[i]=ok;
						else if(ans[i]!=ok) ans[i]=-2;
					}
				}

	for(int i=0;i<m;i++) {
		if(ans[i]==0) printf("NOT BIRD\n");
		else if(ans[i]==1) printf("BIRD\n");
		else printf("UNKNOWN\n");
	}
}

int main()
{
	int T;

	scanf("%d",&T);
	for(int i=1;i<=T;i++) {
		printf("Case #%d:\n",i);
		solve();
	}

	return 0;
}
