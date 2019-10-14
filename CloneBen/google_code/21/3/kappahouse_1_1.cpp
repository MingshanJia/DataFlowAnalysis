#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <numeric>

using namespace std;

// Å‚‚ÌƒR[ƒq[

int main()
{
	int cases;
	cin >> cases;

	for (int caseno = 1; caseno <= cases; caseno++) {
		int N;
		long long K;
		cin >> N >> K;
		vector <vector <long long> > c(N, vector <long long>(3));
		for (int i = 0; i < N; i++) {
			cin >> c[i][1] >> c[i][2] >> c[i][0];
		}
		sort(c.begin(), c.end());
		reverse(c.begin(), c.end());
		long long ret = 0;
		for (int i = 0; i < N; i++) {
			long long d = min(K, min(c[i][1], c[i][2]));
			ret += d * c[i][0];
			K -= d;
			for (int j = i + 1; j < N; j++) {
				if (c[j][2] >= c[i][2]) {
					c[j][2] -= d;
				} else if (c[j][2] >= c[i][2] - d) {
					c[j][2] = c[i][2] - d;
				}
			}
		}
		cout << "Case #" << caseno << ": " << ret << endl;
	}

	return 0;
}
