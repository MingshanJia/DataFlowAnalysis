#include <stdio.h>
#include <algorithm>
#include <queue>
using namespace std;

__int64 min(__int64 a, __int64 b){return a<b?a:b;}

int T,C;
__int64 N,A[3],D[3],ANS,X;
__int64 cap[8][8],cos[8][8];

priority_queue<pair<int, pair<int, int> >, vector<pair<int, pair<int, int> > >, greater<pair<int, pair<int, int> > > > Q;

bool go()
{
	int i,x,y,c; __int64 d[8],v[8],m[8];

	for (i=0;i<8;i++) d[i] = 0x7fffffff;

	Q.push(make_pair(0,make_pair(0,-1)));
	while (!Q.empty()){
		x = Q.top().second.first; y = Q.top().second.second; c = Q.top().first; Q.pop();

		if (d[x] < c) continue;
		d[x] = c; v[x] = y;
		if (y != -1) m[x] = min(cap[y][x],m[y]);
		else m[x] = 1000000000000000i64;

		for (y=1;y<8;y++){
			if (cap[x][y] && c + cos[x][y] < d[y]) Q.push(make_pair(c+cos[x][y],make_pair(y,x)));
		}
	}

	if (d[7] == 0x7fffffff) return false;

	x = 7;
	while (1){
		y = v[x];
		if (y == -1) break;
		
		cap[y][x] -= m[7];
		cap[x][y] += m[7];
		x = y;
	}
	return true;
}

int main()
{
	freopen ("input.txt","r",stdin);
	freopen ("output.txt","w",stdout);
	int i,j,v;
	
	scanf ("%d",&T); while (T--){
		scanf ("%I64d %I64d %I64d %I64d %I64d %I64d %I64d",&N,&A[0],&A[1],&A[2],&D[0],&D[1],&D[2]);
		cap[0][1] = A[0];
		cap[0][2] = A[1];
		cap[0][3] = A[2];
		cap[4][7] = D[0];
		cap[5][7] = D[1];
		cap[6][7] = D[2];
		for (i=0;i<3;i++) for (j=0;j<3;j++){
			scanf ("%d",&v);
			cap[i+1][j+4] = 1000000000000000i64;
			cap[j+4][i+1] = 0;
			cos[i+1][j+4] = -v;
			cos[j+4][i+1] = v;
		}
		
		while (go());

		ANS = 0;
		for (i=0;i<3;i++) for (j=0;j<3;j++){
			ANS += cos[j+4][i+1] * cap[j+4][i+1];
		}
		printf ("Case #%d: %I64d\n",++C,ANS);
	}
	
	return 0;
}