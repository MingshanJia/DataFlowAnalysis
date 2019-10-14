#include <cstring>
#include <string.h>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <set>
#include <complex>
using namespace std;


#define SMALL
#define LARGE
int T;


void mergeL(vector<vector<int> > &B)
{
	for (int i = 0; i < B.size(); i++)
	{
		int ni = 0;
		for (int j = 0; j < B[0].size(); j++)
		{
			if (B[i][j] == 0)
				continue;
			else
				B[i][ni++] = B[i][j];
		}
		int ns = 0;
		for (int j = 0; j < ni; j++)
		{
			if (j < ni-1 && B[i][j] == B[i][j + 1])
				B[i][ns++] = 2 * B[i][j++];
			else
				B[i][ns++] = B[i][j];
		}
		for (int j = ns; j < B[0].size(); j++)
			B[i][j] = 0;
	}
}

void mergeR(vector<vector<int> > &B)
{
	for (int i = 0; i < B.size(); i++)
	{
		int ni = B.size()-1;
		for (int j = B.size()-1; j >=0; j--)
		{
			if (B[i][j] == 0)
				continue;
			else
				B[i][ni--] = B[i][j];
		}
		int ns = B.size()-1;
		for (int j = B.size()-1; j >ni; j--)
		{
			if (j > ni + 1 && B[i][j] == B[i][j - 1])
				B[i][ns--] = 2 * B[i][j--];
			else
				B[i][ns--] = B[i][j];
		}
		for (int j = ns; j >=0; j--)
			B[i][j] = 0;
	}
}

void mergeU(vector<vector<int> > &B)
{
	for (int i = 0; i < B.size(); i++)
	{
		int ni = 0;
		for (int j = 0; j < B.size(); j++)
		{
			if (B[j][i] == 0)
				continue;
			else
				B[ni++][i] = B[j][i];
		}
		int ns = 0;
		for (int j = 0; j < ni; j++)
		{
			if (j < ni - 1 && B[j][i] == B[j+1][i])
				B[ns++][i] = 2 * B[j++][i];
			else
				B[ns++][i] = B[j][i];
		}
		for (int j = ns; j < B[0].size(); j++)
			B[j][i] = 0;
	}
}

void mergeD(vector<vector<int> > &B)
{
	for (int i = 0; i < B.size(); i++)
	{
		int ni = B.size() - 1;
		for (int j = B.size() - 1; j >= 0; j--)
		{
			if (B[j][i] == 0)
				continue;
			else
				B[ni--][i] = B[j][i];
		}
		int ns = B.size() - 1;
		for (int j = B.size() - 1; j >ni; j--)
		{
			if (j > ni + 1 && B[j][i] == B[j - 1][i])
				B[ns--][i] = 2 * B[j--][i];
			else
				B[ns--][i] = B[j][i];
		}
		for (int j = ns; j >= 0; j--)
			B[j][i] = 0;
	}
}

void adjust(vector<vector<int> > &A, string dir)
{
	if (dir == "left")
		mergeL(A);
	else if (dir == "right")
		mergeR(A);
	else if (dir == "up")
		mergeU(A);
	else if (dir == "down")
		mergeD(A);
}

int main()
{
	freopen("a.txt", "rt", stdin);
#ifdef SMALL
	freopen("B-small-attempt0.in", "rt", stdin);
	freopen("B-small.out", "wt", stdout);
#endif
#ifdef LARGE
	freopen("B-large.in", "rt", stdin);
	freopen("B-large.out", "wt", stdout);
#endif
	cin >> T;
	for (int i = 1; i < T + 1; i++)
	{
		int N;
		string s;
		cin >> N >> s;
		vector<vector<int> > table(N, vector<int>(N, 0));
		for (int m = 0; m < N;m++)
		for (int n = 0; n < N; n++)
			cin >> table[m][n];

		adjust(table, s);
		printf("Case #%d:\n", i);
		for (int m = 0; m < N; m++)
		{
			for (int n = 0; n < N; n++)
				printf("%d\t", table[m][n]);
			cout << endl;
		}
	}

	return 0;
}