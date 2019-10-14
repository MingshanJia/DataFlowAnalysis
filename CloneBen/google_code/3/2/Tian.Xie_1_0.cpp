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

const int MAXN = 5000 + 10;

int N;
int L[MAXN];
int Len[MAXN], nLen;
long long Dup[MAXN];
long long Sum[MAXN];

void Work()
{
	scanf("%d", &N);
	map <int, int> Map;
	for (int i = 0; i < N; i ++)
	{
		scanf("%d", &L[i]);
		Map[L[i]] ++;
	}

	nLen = 0;
	for (auto it : Map)
	{
		Len[nLen] = it.first;
		Dup[nLen] = it.second;
		nLen ++;
	}
	Sum[nLen] = 0;
	for (int i = nLen - 1; i >= 0; i --)
		Sum[i] = Dup[i] * (Dup[i] - 1) / 2LL + Sum[i + 1];

	sort(L, L + N);
	long long Ans = 0;
	for (int i = 0; i < nLen; i ++) // upper
		for (int j = i + 1; j < nLen; j ++) // lower
		{
			int Least = (Len[j] - Len[i]) / 2 + 1;
			int Pos = lower_bound(Len, Len + nLen, Least) - Len;
			
			long long Cur = Sum[Pos];
			if (i >= Pos) Cur -= Dup[i] * (Dup[i] - 1) / 2LL;
			if (j >= Pos) Cur -= Dup[j] * (Dup[j] - 1) / 2LL;
			Ans += Cur * Dup[i] * Dup[j];

			if (i >= Pos) Ans += (Dup[i] * (Dup[i] - 1) * (Dup[i] - 2)) / 6LL * Dup[j];
			if (j >= Pos) Ans += (Dup[j] * (Dup[j] - 1) * (Dup[j] - 2)) / 6LL * Dup[i];
		}

	cout << Ans << endl;
}

int main()
{
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("B-small-attempt0.out", "w", stdout);
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
