#include <iostream>
#include <map>
#include <utility>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define REP(i,n) FOR(i,0,n)
#define SIZE(c) (int((c).size()))
#define MP make_pair

const int inf = 1000000000;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int mask[4] = {2, 8, 1, 4};

map<pair<int,int>,int> maze;
int x, y;
int minx, maxx;
int miny, maxy;
string path;
int k;

void go() {
	int n = SIZE(path);
	REP(i,n) {
		if (i) {
			minx <?= x;
			maxx >?= x;
			miny <?= y;
			maxy >?= y;
		}
		switch (path[i]) {
			case 'L':
				k++;
				if (k == 4)
					k = 0;
				break;
			case 'R':
				k--;
				if (k == -1)
					k = 3;
				break;
			default:
				maze[MP(x,y)] |= mask[k];
				x += dx[k];
				y += dy[k];
				maze[MP(x,y)] |= mask[k^2];
				break;
		}
	}
}

int main() {
	int cc;
	cin >> cc;
	REP(c,cc) {
		maze.clear();
		x = y = 0;
		minx = miny = inf;
		maxx = maxy = -inf;
		cin >> path;
		k = 0;
		go();
		cin >> path;
		k ^= 2;
		go();
		cout << dec << "Case #" << c+1 << ":" << endl;
		cout << dec;
		//cout << minx << "-" << maxx << " " << miny << "-" << maxy << endl;
		cout << hex;
		FOR(i,minx,maxx+1) {
			FOR(j,miny,maxy+1)
				cout << hex << maze[MP(i,j)];
			cout << endl;
		}
	}
}
