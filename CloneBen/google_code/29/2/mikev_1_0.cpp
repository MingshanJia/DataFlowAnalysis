#include <iostream>
#include <string>
#include <algorithm>
#include <bitset>
#include <vector>

using namespace std;

const int mx = 10000;
bitset<4> maze[mx][2*mx];

int main()
{
	int N;
	cin >> N;

	for (int i=1; i<=N; ++i)
	{
		string fw, bk;
		cin >> fw >> bk;

//		vector<vector<bitset<4> > > maze(mx, vector<bitset<4> >(2*mx));
		memset(maze, 0, sizeof(maze));
		int x0 = 0, x1 = 0, y0 = 0, y1 = 0, x = 0, y = 0, dir = 2;
		int dx[] = {  0, 1, 0, -1},
			dy[] = { -1, 0, 1,  0};

		for (int i=1; i<fw.length(); ++i)
		{
			switch (fw[i])
			{
			case 'W':  if (fw[i-1]=='W')  maze[y][x+mx].set((dir+3)%4);
				       x += dx[dir];  y += dy[dir];
					   break;
			case 'L':  dir = (dir+3)%4;
					   break;
			case 'R':  maze[y][x+mx].set((dir+3)%4);
					   maze[y][x+mx].set(dir);
					   dir = (dir+1)%4;
			}
			if (i+1<fw.length())
			{
				x0 = min(x0, x);
				x1 = max(x1, x);
				y0 = min(y0, y);
				y1 = max(y1, y);
			}
			dir %= 4;
		}
		dir = (dir+2)%4;
		x += dx[dir];  y += dy[dir];
		for (int i=1; i<bk.length(); ++i)
		{
			switch (bk[i])
			{
			case 'W':  if (bk[i-1]=='W')  maze[y][x+mx].set((dir+3)%4);
				       x += dx[dir];  y += dy[dir];
					   break;
			case 'L':  dir = (dir+3)%4;
					   break;
			case 'R':  maze[y][x+mx].set((dir+3)%4);
					   maze[y][x+mx].set(dir);
					   dir = (dir+1)%4;
			}
			if (i+1<bk.length())
			{
				x0 = min(x0, x);
				x1 = max(x1, x);
				y0 = min(y0, y);
				y1 = max(y1, y);
			}
			dir %= 4;
		}

		cout << "Case #" << i << ":" << endl;
		for (int y=y0; y<=y1; ++y)
		{
			for (int x=x0; x<=x1; ++x)
			{
				bitset<4> tmp = maze[y][x+mx];
				maze[y][x+mx].set(1, tmp[2]);
				maze[y][x+mx].set(2, tmp[3]);
				maze[y][x+mx].set(3, tmp[1]);
				maze[y][x+mx].flip();
				cout << "0123456789abcdef"[maze[y][x+mx].to_ulong()];
			}
			cout << endl;
		}
	}

	return 0;
}