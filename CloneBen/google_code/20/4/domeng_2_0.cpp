#include <cstdio>
#include <memory.h>
#include <vector>
#include <map>
#include <queue>
using namespace std;
typedef pair<int,int> pii;
int N,P,M,X[105],V[105];
//int E[10000][10000];
int Latest[10000];
int Reach[10000];

int Cur[10000];
int State[10000];

vector<pii> Adj[10000];
int main()
{
	int T;
	scanf("%d",&T);
	for (int kase=1;kase<=T;++kase)
	{
		memset(Latest,0,sizeof(Latest));
		memset(Reach,0,sizeof(Reach));

		scanf("%d %d %d",&N,&P,&M);
		for (int q=0;q<N;++q) Adj[q].clear();
		for (int q=0;q<P;++q)
		{
			scanf("%d %d",&X[q],&V[q]);
			X[q]--;
		}

		for (int q=0;q<M;++q)
		{
			int k,l;
			scanf("%d %d",&l,&k);	
			int last = -1,x;
			for (int w=0;w<k;++w) 
			{
				scanf("%d",&x);
				x--;
				if (last>=0)
				{
					Adj[last].push_back(pii(x,l));
					Adj[x].push_back(pii(last,l));
				}
				last = x;
			}
		}
		
		for (int q=0;q<P;++q)
		{
			memset(Cur,0,sizeof(Cur));
			memset(State,0,sizeof(State));

			priority_queue<pii> sd;
			sd.push( pii(0,X[q]) );

			State[X[q]] = 1;

			while (!sd.empty())
			{
				pii io = sd.top(); sd.pop();
				const int time  = -io.first;
				const int city = io.second;

				//printf("%d reached %d(adj=%d) @ %d\n",q,city,Adj[city].size(),time);
				if (State[city]==2) continue;
				
				State[city] = 2;
				Reach[city]++;
				Latest[city] = max(Latest[city],Cur[city]);

				for (int e=0;e<Adj[city].size();++e) 
				{
					const int& next = Adj[city][e].first;
					const int& dist = Adj[city][e].second;
					int pr = time + dist * V[q];
					if (State[next] == 0 || Cur[next] > pr)
					{
						State[next] = 1;
						Cur[next] = pr;
						sd.push( pii(-pr,next));
					}
				}
			}
		}

		int ans = -1;
		for (int q=0;q<N;++q)
			if (Reach[q] == P && (Latest[q] < ans || ans < 0))
				ans = Latest[q];
		printf("Case #%d: %d\n",kase,ans);
	}
	return 0;
}
