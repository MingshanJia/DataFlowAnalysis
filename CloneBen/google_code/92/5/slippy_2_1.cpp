#include <iostream>
#include <sstream>
#include <cstring>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <map>
#include <deque>
#include <set>
#include <algorithm>

using namespace std;

bool G[105][105];

int N1;
int leftP[105], rightP[105];
int v[1000];

int dfs(int a)
{
	if(a < 0) return 1;
	if(v[a]) return 0;
	v[a] = 1;
	for(int i = 0; i < N1; i++)
	if(G[a][i] && dfs(rightP[i]))
	{ 		
		leftP[a] = i, rightP[i] = a; 
		return 1; 	
	}
	return 0;
}

int match()
{
	int ans = 0;
	for(int i = 0; i < N1; i++)
		leftP[i] = rightP[i] = -1;
	for(int i = 0; i < N1; i++)
	if(leftP[i] < 0)
	{
		for(int k = 0; k < N1; k++) 
			v[k] = 0;
		ans += dfs(i);
	}
	return ans; 
}



int main()
{
	ofstream fout("C-large.out");
	ifstream fin("C-large.in");
	
	int T;
	fin >> T;
	for(int tt = 0; tt < T; tt++)
	{
		int n, k;
		fin >> n >> k;
		int nums[100][25];
		for(int p = 0; p < n; p++)
		for(int q = 0; q < k; q++)
			fin >> nums[p][q];
		memset(G,0,sizeof G);
		
		for(int p = 0; p < n; p++)
		for(int q = 0; q < n; q++)
		{
			int lessthan = 1;
			for(int r = 0; r < k; r++)
				if(nums[p][r] >= nums[q][r])
				{
					lessthan = 0;
					break;
				}
			if(lessthan == 1)
				G[p][q] = 1;
			else G[p][q] = 0;
		}
		
		N1 = n;
		
		int ans = n-match();
		fout << "Case #" << tt+1 << ": " << ans << endl;
	}
		

	return 0;
}
		
