#include <stdio.h>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

typedef pair<long long, int> ppair;

#define P 105
#define N 10005
#define INF 10000000000
#define Max(x,y) ((x)>(y)?(x):(y))

FILE *in=fopen("C-small-attempt1.in","rt");
FILE *out=fopen("output.txt","wt");

int n,p,m;
vector<ppair> edge[N];
long long dist[P][N],ans;
priority_queue<ppair,vector<ppair>,greater<ppair> > q;

struct data
{
	int start,speed;
}a[P];

void input()
{
	int i,j,d,x,y,cnt;
	fscanf(in,"%d %d %d",&n,&p,&m);
	for(i=1;i<=p;i++) fscanf(in,"%d %d",&a[i].start,&a[i].speed);
	for(i=1;i<=n;i++) edge[i].clear();
	for(i=1;i<=m;i++)
	{
		x=0;
		fscanf(in,"%d %d",&d,&cnt);
		for(j=1;j<=cnt;j++)
		{
			fscanf(in,"%d",&y);
			if(j>1){
				edge[x].push_back(make_pair(d,y));
				edge[y].push_back(make_pair(d,x));
			}
			x=y;
		}
	}
}

void dijkstra(int x, int speed, long long dist[])
{
	int i,k,y;
	ppair t;
	for(i=1;i<=n;i++) dist[i]=INF;
	dist[x]=0;
	q.push(make_pair(0,x));
	while(!q.empty())
	{
		t=q.top();
		q.pop();
		x=t.second;
		if(dist[x]<t.first) continue;
		k=edge[x].size();
		for(i=0;i<k;i++)
		{
			y=edge[x][i].second;
			if(dist[y]>t.first+edge[x][i].first*speed){
				dist[y]=t.first+edge[x][i].first*speed;
				q.push(make_pair(dist[y],y));
			}
		}
	}
}

void process()
{
	int i,j;
	long long tmp;
	ans=INF;
	for(i=1;i<=p;i++) dijkstra(a[i].start,a[i].speed,dist[i]);
	for(i=1;i<=n;i++)
	{
		tmp=0;
		for(j=1;j<=p;j++) tmp=Max(tmp,dist[j][i]);
		if(tmp<ans) ans=tmp;
	}
}

int main()
{
	int i,t;
	fscanf(in,"%d",&t);
	for(i=1;i<=t;i++)
	{
		input();
		process();
		if(ans==INF) fprintf(out,"Case #%d: -1\n",i);
		else fprintf(out,"Case #%d: %lld\n",i,ans);
	}
	fclose(in);
	fclose(out);
	return 0;
}