#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int G[100][100];
char ans[100][100];

int dx[] = {-1,0,0,1};
int dy[] = {0,-1,1,0};

int H, W;

char curr;

char dfs(int i, int j)
{
	if(ans[i][j] != '.') return ans[i][j];
	
	int dir = -1;
	int lowest = 9999999;
		
	for(int p = 0; p < 4; p++)
		if(i+dx[p] >= 0 && i+dx[p] < H && j+dy[p] >= 0 && j+dy[p] < W && G[i+dx[p]][j+dy[p]] < G[i][j])
		{
			if(G[i+dx[p]][j+dy[p]] < lowest)
				dir = p, lowest = G[i+dx[p]][j+dy[p]];
		}
		
	if(dir == -1)
	{
		ans[i][j] = curr, curr++;
		return ans[i][j];
	}
	
	ans[i][j] = dfs(i+dx[dir], j+dy[dir]);
	return ans[i][j];
}
			

int main()
{
	ofstream fout("B-large.out");
	ifstream fin("B-large.in");
	
	int T;
	fin >> T;
	
	for(int tt = 0; tt < T; tt++)
	{
		fin >> H >> W;
		for(int i = 0; i < H; i++)
		for(int j = 0; j < W; j++)
		{
			fin >> G[i][j];
			ans[i][j] = '.';
		}
		
		curr = 'a';
			
		for(int i = 0; i < H; i++)
		for(int j = 0; j < W; j++)
			if(ans[i][j] == '.')
				ans[i][j] = dfs(i,j);

		fout << "Case #" << tt+1 << ":\n";
		for(int i = 0; i < H; i++)
		{
			fout << ans[i][0];
			for(int j = 1; j < W; j++)
				fout << " " << ans[i][j];
			fout << endl;
		}
	
	}
	return 0;
}
		
