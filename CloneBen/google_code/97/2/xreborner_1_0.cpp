#define _CRT_SECURE_NO_DEPRECATE
#ifdef NDEBUG
	#define _SECURE_SCL 0
#endif
#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <functional>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>

using namespace std;

int NN, TT;
int W, H;
int OX1, OY1, OX2, OY2;
bool Marks[100][100];
int Total;

bool check(int X, int Y)
{
	return X >= 0 && X < W && Y >= 0 && Y < H;
}

bool outof(int X, int Y)
{
	return X < -100 || X >= W + 100 || Y < -100 || Y >= H + 100;
}

void dfs(int X, int Y)
{
	if (!check(X, Y)) return;
	if (Marks[X][Y]) return;
	Total++;
	Marks[X][Y] = true;
	dfs(X + OX1, Y + OY1);
	dfs(X + OX2, Y + OY2);
}

int main()
{
	cin >> NN;
	for (TT = 1; TT <= NN; TT++)
	{
		int SX, SY;
		int Len = 0;
		cin >> W >> H >> OX1 >> OY1 >> OX2 >> OY2 >> SX >> SY;
		memset(Marks, 0, sizeof(Marks));
		Total = 0;
		dfs(SX, SY);
		printf("Case #%d: %d\n", TT, Total);
	}
	return 0;
}