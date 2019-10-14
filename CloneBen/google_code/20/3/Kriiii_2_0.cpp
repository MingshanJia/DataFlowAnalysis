#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

struct edge{
	edge(int y_, int c_){y = y_; c = c_;}
	int y,c;
};
vector<edge> G[10101];

struct phase{
	phase(int x_, int c_){x = x_; c = c_;}
	int x,c;
	bool operator <(const phase t)const{return c > t.c;}
};
priority_queue<phase> Q;

vector<long long> PR[111];

int T,C,N,P,M,X[111],V[111];

vector<long long> shortest(int s, int v)
{
	int i,x,y,c;

	vector<long long> RET;
	RET.resize(N+1);
	for (i=0;i<RET.size();i++) RET[i] = 1000000000000ll;
	Q.push(phase(s,0));
	while (!Q.empty()){
		x = Q.top().x; c = Q.top().c; Q.pop();
		if (RET[x] <= c) continue;
		RET[x] = c;
		for (i=0;i<G[x].size();i++){
			y = G[x][i].y;
			if (RET[y] > c + G[x][i].c) Q.push(phase(y,c + G[x][i].c));
		}
	}

	for (i=0;i<RET.size();i++){
		if (RET[i] != 1000000000000ll) RET[i] *= v;
		else RET[i] = -1;
	}
	return RET;
}

int main()
{
	freopen ("input.txt","r",stdin);
	freopen ("output.txt","w",stdout);

	int i,j,d,l,x,y;

	scanf ("%d",&T); while (T--){
		scanf ("%d %d %d",&N,&P,&M);
		for (i=1;i<=N;i++) G[i].clear();
		for (i=1;i<=P;i++){
			PR[i].clear();
			scanf ("%d %d",&X[i],&V[i]);
		}
		for (i=1;i<=M;i++){
			scanf ("%d %d %d",&d,&l,&x);
			for (j=1;j<l;j++){
				scanf ("%d",&y);
				G[x].push_back(edge(y,d));
				G[y].push_back(edge(x,d));
				x = y;
			}
		}

		for (i=1;i<=P;i++) PR[i] = shortest(X[i],V[i]);
		vector<long long> ANS;
		ANS.resize(N+1);
		for (i=1;i<=N;i++){
			ANS[i] = 0;
			for (j=1;j<=P;j++){
				if (PR[j][i] != -1){
					if (ANS[i] < PR[j][i])
						ANS[i] = PR[j][i];
				}
				else {ANS[i] = -1; break;}
			}
		}
		
		long long R = 1000000000000ll;
		for (i=1;i<=N;i++){
			if (ANS[i] != -1){
				if (R > ANS[i]) R = ANS[i];
			}
		}
		if (R == 1000000000000ll) R = -1;
		printf ("Case #%d: %lld\n",++C,R);
	}

	return 0;
}