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
#include <bitset>

using namespace std;

// ƒrƒbƒg”

int main()
{
	int cases;
	cin >> cases;

	for (int caseno = 1; caseno <= cases; caseno++) {
		long long N;
		cin >> N;
		int ret = 0;
		while (N > 0) {
			if (N & 1) {
				ret += 1;
			} else {
				ret += 2;
			}
			N = (N - 1) >> 1;
		}
		cout << "Case #" << caseno << ": " << ret << endl;
	}

	return 0;
}
