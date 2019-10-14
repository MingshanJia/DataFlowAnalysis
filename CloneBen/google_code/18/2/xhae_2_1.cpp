#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>
#include <cmath>
#include <set>
#include <sstream>
#include <cstring>
#include <queue>
#include <stack>

#define EPS 1e-10
#define EQ(a,b) (abs(b)<EPS?abs(a-b)<EPS:abs(a/b-1)<EPS)

using namespace std;

int n, m, K;

vector <pair<int, int> > coord[50][200];
char field[50][20][21];
bool isVisit[50][20][20];
int roomCnt[50];

#define _M 5000
#define _N 5000

bool graph[_M][_N];
bool seen[_N];
int matchL[_M], matchR[_N];
int _n, _m;

bool bpm( int u )
{
    for( int v = 0; v < _n; v++ ) if( graph[u][v] )
    {
        if( seen[v] ) continue;
        seen[v] = true;

        if( matchR[v] < 0 || bpm( matchR[v] ) )
        {
            matchL[u] = v;
            matchR[v] = u;
            return true;
        }
    }
    return false;
}

bool isCross(int floor, int i1, int i2)
{
	for(int i=0;i<coord[floor][i1].size();i++) for(int j=0;j<coord[floor-1][i2].size();j++)
		if(coord[floor][i1][i]==coord[floor-1][i2][j]) return true;
	return false;
}

int main(void)
{
	int T;
	scanf("%d", &T);
	for(int caseN=1;caseN<=T;caseN++)
	{
		memset(isVisit, 0, sizeof(isVisit));
		for(int i=0;i<50;i++) for(int j=0;j<200;j++) coord[i][j].clear();
		memset(roomCnt, 0, sizeof(roomCnt));

		scanf("%d %d %d", &n, &m, &K);
		for(int i=0;i<K;i++) for(int j=0;j<n;j++) scanf("%s", field[i][j]);
		for(int i=0;i<K;i++)
		{
			for(int j=0;j<n;j++)
			{
				for(int k=0;k<m;k++)
				{
					if(!isVisit[i][j][k] && field[i][j][k]=='.')
					{
						queue <pair<int, int> > q;
						q.push(make_pair(j, k));
						isVisit[i][j][k]=true;
						coord[i][roomCnt[i]].push_back(make_pair(j, k));
						while(!q.empty())
						{
							pair <int, int> cur = q.front();
							q.pop();

							int mov[4][2]={{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
							for(int l=0;l<4;l++)
							{
								int ny=cur.first+mov[l][0];
								int nx=cur.second+mov[l][1];

								if(ny>=0 && ny<n && nx>=0 && nx<m && field[i][ny][nx]=='.' && !isVisit[i][ny][nx])
								{
									isVisit[i][ny][nx]=true;
									coord[i][roomCnt[i]].push_back(make_pair(ny, nx));
									q.push(make_pair(ny, nx));
								}
							}
						}

						roomCnt[i]++;
					}
				}
			}
		}

		memset(graph, 0, sizeof(graph));		
		memset(matchL, -1, sizeof(matchL));
		memset(matchR, -1, sizeof(matchR));

		_n = 0, _m = 0;
		for(int i=0;i<K;i+=2)
		{
			if(i-1>=0)
			{
				for(int j=0;j<roomCnt[i];j++) for(int k=0;k<roomCnt[i-1];k++)
				{
					if(isCross(i, j, k)) graph[_m+j][_n+k] = true;
				}
				_n += roomCnt[i-1];
			}

			if(i+1<K)
			{
				for(int j=0;j<roomCnt[i];j++) for(int k=0;k<roomCnt[i+1];k++)
				{
					if(isCross(i+1, k, j)) graph[_m+j][_n+k] = true;
				}				
			}

			_m += roomCnt[i];
		}

		_n=0, _m=0;
		for(int i=0;i<K;i++) if(i%2==0) _m+=roomCnt[i]; else _n+=roomCnt[i];
		
		int cnt=0;
		for(int i=0;i<_m;i++)
		{
			memset(seen, 0, sizeof(seen));
			if(bpm(i)) cnt++;
		}

//		printf("%d, %d, %d\n", _n, _m, cnt);
//		for(int i=0;i<_n;i++)
//		{
///			for(int j=0;j<_m;j++) printf("%d ", graph[i][j]);
//			printf("\n");
//		}

		printf("Case #%d: %d\n", caseN, _n+_m - cnt);
	}

	return 0;
}
