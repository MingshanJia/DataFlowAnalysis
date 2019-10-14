#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstdio>
#include <map>
#include <vector>
#include <memory.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
int T,N,P[1005],S[1005];
int Dp[1024],Vs[1024];
int solve(int now)
{
	if (Vs[now]) return Dp[now];
	Vs[now]=1;
	int curTime = 0;
	for (int q=0;q<N;++q)
		if (now&(1<<q))
			curTime += S[q];
	Dp[now] = curTime;
	for (int q=0;q<N;++q)
		if (~now&(1<<q))
			if (P[q]>=curTime)
				Dp[now] = max(Dp[now],solve(now|(1<<q)));
	return Dp[now];
}
int main()
{
	scanf("%d",&T);
	for (int kase=1;kase<=T;++kase)
	{
		memset(Vs,0,sizeof(Vs));
		scanf("%d",&N);
		for (int q=0;q<N;++q)
			scanf("%d %d",P+q,S+q);
		printf("Case #%d: %d\n",kase,solve(0));
	}
	return 0;
}