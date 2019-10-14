#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>

#include <cmath>
#include <algorithm>
#include <vector>
#include <utility>
#include <map>
#include <set>

#define REP(a,b) for (int a = 0; a < b; a++)
#define FOR(a,b,c) for (int a = b; a <= c; a++)
#define RESET(a,b) memset(a,b,sizeof a)

#define PB push_back
#define PII pair<int,int>
#define MP make_pair
#define F first
#define S second

#define EPS 1e-8
#define INF 1023123123
#define LL long long
#define __ puts("")

#define MAXN 5005

using namespace std;

int T, N, Q;
map<string, int> alias;
int sum[MAXN][MAXN];
bool ada[MAXN][MAXN];
vector<int> adlis[MAXN];
char sc[1000];
int p;

bool reachable[MAXN][2];
int dist[MAXN][2];
int sig[] = {-1, 1};

void addAlias(string s){
	if (alias.count(s) == 0){
		alias[s] = p;
		p++;
	}
}

void rek(int x, int d, int cur){
	REP(i,adlis[x].size()){
		int v = adlis[x][i];

		if (!reachable[v][1-d]){
			// visit it
			reachable[v][1-d] = 1;
			dist[v][1-d] = cur + sig[d]*sum[x][v];
			rek(v, 1-d, dist[v][1-d]);
		}
	}
}

int main(){
	scanf("%d", &T);
	REP(jt,T){
		RESET(sum,0);
		RESET(ada,0);
		REP(i,MAXN){
			adlis[i].clear();
		}
		alias.clear();
		p = 0;

		scanf("%d", &N);
		gets(sc); // thaw	
		REP(i,N){
			char s1[15], s2[15];
			int val;
			scanf("%[^+]+%[^=]=%d", s1, s2, &val);

			string ss1 = s1;
			string ss2 = s2;
			addAlias(ss1);
			addAlias(ss2);

			int u = alias[ss1];
			int v = alias[ss2];
			sum[u][v] = val;
			sum[v][u] = val;

			adlis[u].PB(v);
			adlis[v].PB(u);

			ada[u][v] = 1;
			ada[v][u] = 1;

			gets(sc); // thaw	
		}

		printf("Case #%d:\n", jt+1);

		scanf("%d", &Q);
		gets(sc); // thaw
		REP(i,Q){
			char s1[15], s2[15];
			scanf("%[^+]+%[^\n]", s1, s2);

			string ss1 = s1;
			string ss2 = s2;

			int ans;
			bool valid = 0;
			if (alias.count(ss1) && alias.count(ss2)){
				int st = alias[ss1];
				int ed = alias[ss2];

				RESET(reachable, 0);
				RESET(dist, 0);
				REP(j,adlis[st].size()){
					int u = adlis[st][j];

					rek(u, 0, sum[st][u]);
					dist[u][0] = sum[st][u];
					reachable[u][0] = 1;
				}

				if (st == ed){
					if (ada[st][st]){
						ans = sum[st][st];
						valid = 1;
					}else if (reachable[st][0]){
						ans = dist[st][0];
						valid = 1;
					}
				}else{
					if (reachable[ed][0]){
						valid = 1;
						ans = dist[ed][0];
					}
				}
			}

			if (valid){
				printf("%s+%s=%d\n", s1, s2, ans);
			}


			gets(sc); // thaw
		}


	}	
}
