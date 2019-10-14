#include <iostream>
#include <algorithm>
using namespace std;

const int MAXS = 110;
bool seat[MAXS][MAXS];
int rownum[MAXS];

int main() {
	int t;
	cin >> t;
	for (int tc = 0; tc < t; tc++) {
		int f,s;
		cin >> f >> s;
		// clear seat and rownum
		for (int i = 0; i < MAXS; i++) {
			memset(seat[i], 0, MAXS);
		}
		memset(rownum, 0, MAXS*sizeof(int));
		// fill in seats
		for (int i = 0; i < f; i++) {
			int a, b;
			cin >> a >> b;
			a--; b--;
			if (!seat[a][b]) {
				rownum[a]++;
			}
			seat[a][b] = true;
			if (!seat[b][a]) {
				rownum[b]++;
			}
			seat[b][a] = true;
		}
		// find max number in any row
		int res = 0;
		for (int i = 0; i < s; i++) {
			res = max(rownum[i], res);
		}
		cout << "Case #" << tc+1 << ": " << res << endl;
	}
}