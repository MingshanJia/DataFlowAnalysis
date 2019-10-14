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

int side[3], bot[3];
int n;
int field[3][3];
long long ans;

void backtr(int y, int x, long long val);

int main(void)
{
	int T;
	scanf("%d", &T);
	for(int caseN=1;caseN<=T;caseN++)
	{
		scanf("%d %d %d %d %d %d %d", &n, side, side+1, side+2, bot, bot+1, bot+2);
		for(int i=0;i<3;i++) for(int j=0;j<3;j++) scanf("%d", field[i]+j);

		ans = -100000LL*100000*11000;
		backtr(0, 0, 0);
		printf("Case #%d: %lld\n", caseN, ans);
	}

	return 0;
}

void backtr(int y, int x, long long val)
{
//	printf("called: %d %d %lld\n", y, x, val);
	if(x==3) 
	{
		backtr(y+1, 0, val);
		return;
	}

	if(x==0 && y && side[y-1]) return;

	if(y==3) ans=max(ans, val);
	else if (y==2)
	{
		long long used=bot[x];		
		
		side[y]-=used;
		bot[x]-=used;

		backtr(y, x+1, val+used*field[y][x]);

		side[y]+=used;
		bot[x]+=used;
	}
	else
	{
		int lim=min(side[y], bot[x]);
		for(long long i=0;i<=lim;i++)
		{
			side[y]-=i;
			bot[x]-=i;

			backtr(y, x+1, val+i*field[y][x]);

			side[y]+=i;
			bot[x]+=i;
		}
	}

	return;
}
