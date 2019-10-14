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

struct state
{
	int x,y,left,right;
	int val;
	state(int xx, int yy, int ll, int rr, int v): x(xx),y(yy),left(ll),right(rr),val(v) { }
	bool operator==(const state &a) const
	{
		return (x == a.x && y == a.y && val == a.val && left == a.left && right == a.right);
	}
   bool operator<(const state &a) const
   {
		return (a.val > val
		 || (a.val == val && a.x < x) || (a.val == val && a.x == x && a.y < y)
	|| (a.val == val && a.x == x && a.y == y && a.left < left)
		|| (a.val == val && a.x == x && a.y == y && a.left == left && a.right < right));
	} 
};


int dp[50][50][50][50];

set<state> S;

int main()
{
	ofstream fout("B-large.out");
	ifstream fin("B-large.in");
	
	int T;
	fin >> T;
	for(int tt = 0; tt < T; tt++)
	{
		S.clear();
		int N,M,F;
		fin >> N >> M >> F;

		char G[50][50];
		for(int p = 0; p < N; p++)
		for(int q = 0; q < M; q++)
			fin >> G[p][q];
		
		for(int p = 0; p < N; p++)
		for(int q = 0; q < M; q++)
		for(int r = 0; r < 50; r++)
		for(int s = 0; s < 50; s++)
			dp[p][q][r][s] = 9999999;
		
		int rr = 0;
		for(int p = 0; p < M; p++)
			if(G[0][p] == '.' && (N == 1 || G[1][p] == '#'))
				rr = p;
			else break;
		
		state newState(0,0,0,rr,0);
		dp[0][0][0][rr] = 0;		
		S.insert(newState);
		
		int best = 9999999;
		
		while(S.empty() == 0)
		{
			state k = *S.begin();
			S.erase(k);
			
			int row = k.x, col = k.y, v = k.val, l = k.left, r = k.right;
			
	//		if(v <= 5)
	//		fout << row << " " << col << "    " << l << " " << r << "    " << v << endl;
			
			if(row == N-1)
			{
				best = min(best, v);
				break;
				continue;
			}
			
			if(col > 0 && (G[row][col-1] == '.' || col-1 >= l))
			{
				//walk left
				int newx = row, newy = col-1;
				while(newx+1 < N && G[newx+1][newy] == '.')
					newx++;
		
				int newleft, newright;		
				if(newx == row) newleft = l, newright = r;
				else
				{
					newleft = newy, newright = newy;
					while(newleft > 0 && G[newx][newleft-1] == '.' && (newx+1 == N || G[newx+1][newleft-1] == '#')) newleft--;
					while(newright < M-1 && G[newx][newright+1] == '.' && (newx+1 == N || G[newx+1][newright+1] == '#')) newright++;
				}

				
				if(newx - row <= F && dp[newx][newy][newleft][newright] > v)
				{
					dp[newx][newy][newleft][newright] = v;
					state newState(newx,newy,newleft,newright,v);
					S.insert(newState);
				}
			}
			if(col < M-1 && (G[row][col+1] == '.' || col+1 <= r))
			{
				//walk right
				int newx = row, newy = col+1;
				while(newx+1 < N && G[newx+1][newy] == '.')
					newx++;
				
				int newleft, newright;		
				if(newx == row) newleft = l, newright = r;
				else
				{
					newleft = newy, newright = newy;
					while(newleft > 0 && G[newx][newleft-1] == '.' && (newx+1 == N || G[newx+1][newleft-1] == '#')) newleft--;
					while(newright < M-1 && G[newx][newright+1] == '.' && (newx+1 == N || G[newx+1][newright+1] == '#')) newright++;
				}
				
				if(newx - row <= F && dp[newx][newy][newleft][newright] > v)
				{
					dp[newx][newy][newleft][newright] = v;
					state newState(newx,newy,newleft,newright,v);
					S.insert(newState);
				}
			}
			
			//dig left some number of cells, then drop
			
			if(col > 0)
			{
				for(int p = 1; col-1+p < M; p++)
				{	
					//dig p cells (row+1,col-1), (row+1,col), (row+1,col+1), etc.
					if((G[row][col-2+p] != '.' && (col-2+p > r || col-2+p < l)) || G[row+1][col-2+p] != '#') break;
					if((G[row][col-1+p] != '.' && (col-1+p > r || col-1+p < l)) || G[row+1][col-1+p] != '#') break;
					
					int newx = row+1, newy = col-2+p;
					while(newx+1 < N && G[newx+1][newy] == '.')
						newx++;
					
					int newleft, newright;
					if(newx - row == 1)
						newleft = col-1, newright = col-2+p;
					else newleft = newy, newright = newy;

					while(newleft > 0 && G[newx][newleft-1] == '.' && (newx+1 == N || G[newx+1][newleft-1] == '#')) newleft--;
					while(newright < M-1 && G[newx][newright+1] == '.' && (newx+1 == N || G[newx+1][newright+1] == '#')) newright++;

					if(newx - row <= F && dp[newx][newy][newleft][newright] > v+p)
					{
						dp[newx][newy][newleft][newright] = v+p;
	//					if(newx == 2 && newy == 3 && newleft == 2 && newright == 3 && v+p == 4)
	//						fout << row << " " << col << " " << l << " " << r << " "  << v << " " << "LEFT" << endl;
						state newState(newx,newy,newleft,newright,v+p);
						S.insert(newState);
					}
				}
			}


			if(col < M-1)
			{
				for(int p = 1; col+1-p >= 0; p++)
				{	
					//dig p cells (row+1,col+1), (row+1,col), (row+1,col-1), etc.
					if((G[row][col+2-p] != '.' && (col+2-p < l || col+2-p > r)) || G[row+1][col+2-p] != '#') break;
					if((G[row][col+1-p] != '.' && (col+1-p < l || col+1-p > r)) || G[row+1][col+1-p] != '#') break;					
					
					int newx = row+1, newy = col+2-p;
					while(newx+1 < N && G[newx+1][newy] == '.')
						newx++;
					
					int newleft, newright;
					if(newx - row == 1)
						newleft = col+2-p, newright = col+1;
					else newleft = newy, newright = newy;

					while(newleft > 0 && G[newx][newleft-1] == '.' && (newx+1 == N || G[newx+1][newleft-1] == '#')) newleft--;
					while(newright < M-1 && G[newx][newright+1] == '.' && (newx+1 == N || G[newx+1][newright+1] == '#')) newright++;

					if(newx - row <= F && dp[newx][newy][newleft][newright] > v+p)
					{
						dp[newx][newy][newleft][newright] = v+p;
	//											if(newx == 2 && newy == 3 && newleft == 2 && newright == 3 && v+p == 4)
	//						cout << row << " " << col << " " << l << " " << r << " "  << v << " " << "RIGHT" << endl;
						state newState(newx,newy,newleft,newright,v+p);
						S.insert(newState);
					}
				}
			}
			
			
		}
		
		if(best == 9999999)
			fout << "Case #" << tt+1 << ": No" << endl;
		else fout << "Case #" << tt+1 << ": Yes " << best << endl;
		
	}
		
		

	return 0;
}
		
