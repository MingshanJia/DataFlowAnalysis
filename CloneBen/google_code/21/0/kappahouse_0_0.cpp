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

// Card Shuffle

int main()
{
	int cases;
	cin >> cases;

	for (int caseno = 1; caseno <= cases; caseno++) {
		int M, C, W;
		cin >> M >> C >> W;
		vector <int> A(C);
		vector <int> B(C);
		for (int i = 0; i < C; i++) {
			cin >> A[i] >> B[i];
		}
		for (int i = C - 1; i >= 0; i--) {
			if (W <= B[i]) {
				W += A[i] - 1;
			} else if (W <= B[i] + A[i] - 1) {
				W -= B[i];
			}
		}
		cout << "Case #" << caseno << ": " << W << endl;
	}

	return 0;
}
