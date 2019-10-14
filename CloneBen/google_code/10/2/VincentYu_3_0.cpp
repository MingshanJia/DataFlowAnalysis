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
//#define LARGE
int T;

class Matrix {
	int M;
	std::vector<int> tiles;

	// Find max k that: 2^k <= m
	int getK(int m) {
		int k = 0;
		while (m > 1) {
			m >>= 1;
			++k;
		}
		return k;
	}

	void incTiles(int a, int b, std::vector<int>& tiles) {
		if (a > b) {
			std::swap(a, b);
		}
		if (a == 0) {
			return;
		}
		if (a == 1) {
			tiles[0] += b;
			return;
		}
		int ak = getK(a), sa = 1 << ak;
		int ac = a / sa, bc = b / sa;
		tiles[ak] += ac * bc;
		incTiles(b - sa * bc, a, tiles);
		incTiles(a - sa * ac, sa * bc, tiles);
	}

public:
	Matrix(int _M) {
		M = _M;
		tiles.resize(32);
		incTiles(M, M, tiles);
	}
	void print() {
		for (int i = 0; i < 32; ++i) {
			if (tiles[i] > 0) {
				std::cout << i << " " << (1 << i) << " " << tiles[i] << std::endl;
			}
		}
	}
	bool add(int s) {
		for (int i = s; i < 31; ++i) {
			if (tiles[i] > 0) {
				--tiles[i];
				incTiles((1 << i) - (1 << s), 1 << i, tiles);
				incTiles(1 << s, (1 << i) - (1 << s), tiles);
				return true;
			}
		}
		return false;
	}
};


int main()
{
	freopen("a.txt", "rt", stdin);
#ifdef SMALL
	freopen("D-small.in", "rt", stdin);
	freopen("D-small.out", "wt", stdout);
#endif
#ifdef LARGE
	freopen("B-large.in", "rt", stdin);
	freopen("B-large.out", "wt", stdout);
#endif
	cin >> T;
	for (int i = 1; i < T + 1; i++)
	{
		int N, M;
		cin >> N >> M;
		vector<int> table(N);
		for (int j = 0; j < N; j++)
			cin >> table[j];
		sort(table.begin(), table.end());

		vector<Matrix> res;
		for (auto it = table.rbegin(); it != table.rend(); ++it) 
		{
			bool flag = false;
			int t = 0;
			for (; t < res.size();++t)
			{
				if (res[t].add(*it)) 
				{
					flag = true;
					break;
				}
			}
			if (!flag) 
			{
				res.push_back(Matrix(M));
				res.back().add(*it);
			}
		}
		printf("Case #%d: ", i);
		cout << res.size() << endl;
	}

	return 0;
}