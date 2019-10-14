#include <algorithm>
#include <vector>
using namespace std;
#include <stdio.h>
#include <string.h>

FILE *Fin = fopen("B-large.in","r");
FILE *Fou = fopen("b.out","w");
//FILE *Fin = stdin;
//FILE *Fou = stdout;

int n,m;

vector<pair<int, int> > user[3000];
vector<pair<int, int> > anti[3000];
int deg[3000];
int ans[3000];

int main()
{
	int i,j,k,caseN,t;
	fscanf(Fin,"%d",&caseN);
	for (t=0; t<caseN; t++)
	{
		fprintf(Fou,"Case #%d:",t+1);
		if (t+1==85)
			t = 84;
		fscanf(Fin,"%d%d",&n,&m);
		for (i=1; i<=n; i++)
			anti[i].clear();
		for (i=1; i<=m; i++)
			user[i].clear();
		for (i=1; i<=m; i++)
		{
			int a;
			fscanf(Fin,"%d",&a);
			for (j=0; j<a; j++)
			{
				int b,c;
				fscanf(Fin,"%d%d",&b,&c);
				user[i].push_back(make_pair(b,c));
				anti[b].push_back(make_pair(i,c));
			}
		}
		bool done[3000];
		memset(done,false,sizeof(done));
		vector<int> lst;
		for (i=1; i<=m; i++)
		{
			deg[i] = user[i].size();
			if (deg[i]==1)
			{
				lst.push_back(i);
				done[i] = true;
			}
		}
		memset(ans,0xFF,sizeof(ans));
		bool nosol=false;
		for (i=0; i<lst.size()&&!nosol; i++)
		{
			int u = lst[i];
			int dir=-1, col;
			bool okay = false;
			for (j=0; j<user[u].size(); j++)
				if ( ans[user[u][j].first]!=-1 && ans[user[u][j].first]==user[u][j].second ) okay = true;
			for (j=0; j<user[u].size(); j++)
				if ( ans[user[u][j].first]==-1 )
				{
					dir = user[u][j].first;
					col = user[u][j].second;
					break;
				}
			if (dir==-1 && !okay)
			{
				nosol = true;
				break;
			}
			if (dir==-1) continue;
			deg[u] = 0;
			ans[dir] = col;
			for (j=0; j<anti[dir].size(); j++) if (!done[anti[dir][j].first] && deg[anti[dir][j].first]>=1)
			{
				int v = anti[dir][j].first, dcol = anti[dir][j].second;
				if (col==dcol)
					deg[v] = 0;
				else
				{
					if (deg[v]==1)
					{
						nosol = true;break;
					}
					deg[v]--;
					if (deg[v]==1)
					{
						lst.push_back(v);
						done[v] = true;
					}
				}
			}
		}
		if (nosol)
			fprintf(Fou," IMPOSSIBLE\n");
		else
		{
			for (i=1; i<=n; i++)
				fprintf(Fou," %d",ans[i]==1 ? 1 : 0);
			fprintf(Fou,"\n");
		}
	}
	return 0;
}

