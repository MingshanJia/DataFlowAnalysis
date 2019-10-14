/*
*/

//#pragma comment(linker, "/STACK:16777216")
#define _CRT_SECURE_NO_WARNINGS

#include <fstream>
#include <iostream>
#include <string>
#include <complex>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <stack>
#include <algorithm>
#include <list>
#include <ctime>
#include <memory.h>
#include <assert.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash
#define norm asdfasdgasdgsd

#define eps 1e-9
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256

using namespace std;

const int INF = 1e9;
const int N = 100031;

int tests;
int board[20][20];

int cb(int x)
{
	if (x == 0)
		return 0;
	return cb(x / 2) + x % 2;
}

int n;
int ts;

int temp_board[20][20];

int found_shit;
int used1[100], used2[100];

void dfs()
{
	for (int i = 0; i < n; i++)
	{
		if (used1[i])
			continue;
		vector<int> cand;
		for (int j = 0; j < n; j++)
		{
			if (used2[j])
				continue;
			if (temp_board[i][j] == 0)
				continue;
			cand.push_back(j);
		}
		if (cand.size() == 0)
		{
			found_shit = 1;
			return;
		}
		for (int q = 0; q < cand.size(); q++)
		{
			int id = cand[q];
			used1[i] = 1;
			used2[id] = 1;
			dfs();
			used1[i] = 0;
			used2[id] = 0;
		}
	}
}
int solve(int mask)
{
	for (int i = n-1; i >= 0; --i)
	{
		for (int j = n-1; j >= 0; --j)
		{
			temp_board[i][j] = mask % 2;
			mask /= 2;
		}
	}
	
	found_shit = 0;
	for (int i = 0; i < n; i++)
		used1[i] = used2[i]=0;
	dfs();
	return found_shit;
}

int main(){
	//freopen("fabro.in","r",stdin);
	//freopen("fabro.out","w",stdout);
	freopen("F:/in.txt", "r", stdin);
	freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin >> tests;
	for (; tests; --tests)
	{
		cerr << ts << endl;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			string st;
			cin >> st;
			for (int j = 0; j < n; j++)
			{
				board[i][j] = st[j] - 48;
			}
		}
		
		int cur_mask = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cur_mask = cur_mask * 2 + board[i][j];
			}
		}

		int ans = 1e9;

		for (int mask = 0; mask < (1 << (n*n)); mask++)
		{
			if ((mask&cur_mask) != cur_mask)
				continue;
			if (solve(mask)==0)
				ans = min(ans, cb(mask - cur_mask));
		}
		++ts;
		cout << "Case #" << ts << ": " << ans << endl;
	}
	cin.get(); cin.get();
	return 0;
}