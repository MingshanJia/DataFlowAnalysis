#pragma warning(disable:4786)
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<functional>
#include<string>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<utility>
#include<fstream>
#include<sstream>
#include<cmath>
#include<stack>
#include<cstdio>
#include <iomanip>


using namespace std;

#define MEM(a,b) memset(a,(b),sizeof(a))
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b)  ((a) < (b) ? (a) : (b))
#define istr(S) istringstream sin(S)
#define MP make_pair
#define pb push_back
#define inf 1000000000

typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;
typedef vector<pi> vpi;

#define inf 1000000000
//typedef long long LL;
//typedef __int64 LL;

int dr[]={-1,0,0,+1};
int dc[]={0,-1,+1,0};

int sink[105][105][2],grid[105][105],label[105][105],R,C;
vector<pi> all[105][105];

void go(int r,int c)
{
	int i,k=-1,min=inf;

	if(sink[r][c][0]!=-1) return ;

	//printf("%d %d\n",r,c);

	for(i=0;i<4;i++)
	{
		int nr=r+dr[i],nc=c+dc[i];
		if(nr<0 || nc<0 || nr>=R || nc>=C) continue;
		if(grid[r][c]>grid[nr][nc] && grid[nr][nc]<min)
			k=i,min=grid[nr][nc];
	}

	if(k<0)
	{
		sink[r][c][0]=r;
		sink[r][c][1]=c;
		return;
	}

	go(r+dr[k],c+dc[k]);
	sink[r][c][0]=sink[r+dr[k]][c+dc[k]][0];
	sink[r][c][1]=sink[r+dr[k]][c+dc[k]][1];
}

int main()
{
	int i,j,k,tests,cs=0;
	
	freopen("D:\\gcj\\B-large.in","r",stdin);
	freopen("D:\\gcj\\B-large.out","w",stdout);

	scanf("%d",&tests);

	while(tests--)
	{
		scanf("%d%d",&R,&C);

		for(i=0;i<R;i++)
			for(j=0;j<C;j++)
			{
				scanf("%d",&grid[i][j]);
				all[i][j].clear();
			}

		MEM(sink,-1);
		

		for(i=0;i<R;i++)
			for(j=0;j<C;j++)
			{
				if(sink[i][j][0]!=-1) continue;
				go(i,j);
			}


		for(i=0;i<R;i++)
			for(j=0;j<C;j++)
				all[sink[i][j][0]][sink[i][j][1]].push_back(MP(i,j));

		MEM(label,-1);
		int now=0;

		for(i=0;i<R;i++)
			for(j=0;j<C;j++)
			{
				if(label[i][j]!=-1) continue;

				int r=sink[i][j][0],c=sink[i][j][1];
				int sz=all[r][c].size();

				for(k=0;k<sz;k++)
					label[all[r][c][k].first][all[r][c][k].second]=now;
				++now;
			}

		printf("Case #%d:\n",++cs);
		for(i=0;i<R;i++)
		{
			for(j=0;j<C;j++)
			{
				if(j) printf(" ");
				printf("%c",label[i][j]+'a');
			}
			printf("\n");
		}


	}


	return 0;
} 


