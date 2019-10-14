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

int dynamic[5][1<<13];
int n, m, K;

vector <pair<int, int> > coord[5][13];
char field[5][5][6];
bool isVisit[5][5][5];
int roomCnt[5];

bool isCross(int floor, int bef, int cur);
int getAns(int floor, int stat);

int main(void)
{
	int T;
	scanf("%d", &T);
	for(int caseN=1;caseN<=T;caseN++)
	{
		memset(isVisit, 0, sizeof(isVisit));
		for(int i=0;i<5;i++) for(int j=0;j<13;j++) coord[i][j].clear();
		memset(dynamic, -1, sizeof(dynamic));
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

		printf("Case #%d: %d\n", caseN, getAns(0, 0));
	}

	return 0;
}

int getAns(int floor, int stat)
{
	if(floor==K) return 0;
	int &ret=dynamic[floor][stat];
	if(ret!=-1) return ret;

	ret=0;

	for(int i=0;i<(1<<roomCnt[floor]);i++)
	{
		if(isCross(floor, stat, i)) continue;
		int cnt=0;
		for(int j=0;j<roomCnt[floor];j++) if(i & (1<<j)) cnt++;
		ret=max(ret, getAns(floor+1, i)+cnt);
	}

	return ret;
}

bool isCross(int floor, int bef, int cur)
{
	if(floor==0) return false;

	for(int i=0;i<roomCnt[floor-1];i++)
	{
		if((bef & (1<<i)) == false) continue;
		for(int j=0;j<roomCnt[floor];j++)
		{
			if((cur & (1<<j)) == false) continue;

			for(int q=0;q<coord[floor-1][i].size();q++) for(int w=0;w<coord[floor][j].size();w++) if(coord[floor-1][i][q] == coord[floor][j][w]) return true;
		}
	}

	return false;
}
