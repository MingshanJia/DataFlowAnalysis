//	GCJ Practice - AlwaysTurnLeft.cpp

#include <string>
#include <vector>
#include <iostream>
using namespace std;

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

// S, E, N, W
int bit[4] = { 2, 8, 1, 4 };
const char* hexch = "0123456789abcdef";

int minx, maxx, miny, maxy;
int x, y, dir;
vector <string> maze;

void walk(string w)
{
	for (int i = 0; i < w.size(); i++) {
		switch (w[i])
		{
		case 'W':
			if (i > 0 && !maze.empty()) {
				maze[y][x] |= bit[dir];
			}
			x += dx[dir];
			y += dy[dir];
			if (i < w.size() - 1) {
				if (maze.empty()) {
					if (x < minx) minx = x;
					if (x > maxx) maxx = x;
					if (y < miny) miny = y;
					if (y > maxy) maxy = y;
				}
				else {
					maze[y][x] |= bit[(dir + 2) & 3];
				}
			}
			break;
		case 'L':
			dir = (dir + 1) & 3;
			break;
		case 'R':
			dir = (dir - 1) & 3;
			break;
		}
	}
}

int main()
{
	int N = 0;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		string w1, w2;
		cin >> w1 >> w2;
		maze.clear();
		minx = 0; maxx = 0; miny = 0; maxy = 0;
		x = 0; y = -1; dir = 0;
		walk(w1);
		dir = (dir + 2) & 3;
		walk(w2);
		int xx = maxx - minx + 1;
		int yy = maxy - miny + 1;
		maze.resize(yy, string(xx, 0));
		x -= minx; y -= miny; dir = 0;
		walk(w1);
		dir = (dir + 2) & 3;
		walk(w2);
		cout << "Case #" << i << ":" << endl;
		for (int j = 0; j < yy; j++) {
			for (int k = 0; k < xx; k++) {
				maze[j][k] = hexch[maze[j][k]];
			}
			cout << maze[j] << endl;
		}
	}
	return 0;
}
