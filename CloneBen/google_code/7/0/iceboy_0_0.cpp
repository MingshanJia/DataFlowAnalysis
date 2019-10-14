#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int maze[1001][1001];
int cache[1001][1001];

int solve(int x, int y)
{
	if (cache[y][x] != -1)
		return cache[y][x];

	int up = (maze[y-1][x] == maze[y][x] + 1) ? solve(x, y-1) : 0;
	int dn = (maze[y+1][x] == maze[y][x] + 1) ? solve(x, y+1) : 0;
	int lf = (maze[y][x-1] == maze[y][x] + 1) ? solve(x-1, y) : 0;
	int rt = (maze[y][x+1] == maze[y][x] + 1) ? solve(x+1, y) : 0;

	int result = 1 + max(max(up, dn), max(lf, rt));
	cache[y][x] = result;
	return result;
}

int main()
{
	int T;
	cin >> T;

	for (int t = 0; t < T; ++t) {
		memset(maze, 0, sizeof(maze));
		memset(cache, 0xff, sizeof(cache));

		int S;
		cin >> S;
		for (int y = 1; y <= S; ++y) {
			for (int x = 1; x <= S; ++x) {
				cin >> maze[y][x];
			}
		}

		int r = 0, d = 0;
		for (int y = 1; y <= S; ++y) {
			for (int x = 1; x <= S; ++x) {
				int cur = solve(x, y);
				if (cur > d || (cur == d && maze[y][x] < r)) {
					r = maze[y][x];
					d = cur;
				}
			}
		}

		cout << "Case #" << (t + 1) << ": " << r << " " << d << endl;
	}
}