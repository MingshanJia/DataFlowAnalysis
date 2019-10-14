#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>

using namespace std;

const int MAXN = 100 + 10;
const int MAXP = 200 + 10;
const int INF = 1000000000;

int N, M, P;
int Dist[MAXN][MAXN];

void Work()
{
	scanf("%d%d%d", &N, &M, &P);
	for (int i = 0; i < N; i ++)
		for (int j = 0; j < N; j ++)
			Dist[i][j] = ((i == j) ? 0 : INF);
	for (int i = 0; i < M; i ++)
	{
		int u, v, d;
		scanf("%d%d%d", &u, &v, &d);
		u --;
		v --;
		Dist[v][u] = Dist[u][v] = min(Dist[u][v], d);
	}

	for (int k = 0; k < N; k ++)
		for (int i = 0; i < N; i ++)
			for (int j = 0; j < N; j ++)
				Dist[i][j] = min(Dist[i][j], Dist[i][k] + Dist[k][j]);

	if (N == 2)
	{
		printf("%.8lf\n", (double) Dist[0][1] * (double) P);
		return;
	}

	double DistA = 0, DistB = 0;
	for (int i = 0; i < N; i ++)
		for (int j = 0; j < N; j ++)
			if (i == 0)
				DistA += Dist[i][j];
			else
				DistB += Dist[i][j];
	
	double FacA = 1 / (double) (N - 1), FacB = 0, Incre = 0, Base = 1 / (double) (N - 1);
	for (int p = 1; p < P; p ++)
	{
		FacA += Incre;
		Base *= 1 / (double) (N - 1);
		Incre += ((p % 2 == 1) ? 1 : -1) * Base;
		FacB += Incre;
	}
	
	double Ans = DistA * FacA + DistB * FacB;
	printf("%.8lf\n", Ans);
}

int main()
{
	freopen("C-small-attempt2.in", "r", stdin);
	freopen("C-small-attempt2.out", "w", stdout);
	int Cases;
	scanf("%d", &Cases);
	for (int Case = 1; Case <= Cases; Case ++)
	{
		printf("Case #%d: ", Case);
		fprintf(stderr, "Case #%d: \n", Case);
		Work();
		fflush(stdout);
	}
	return 0;
}
