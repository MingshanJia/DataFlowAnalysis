#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second

const int iters = 100;

int main () {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int tc;
    cin >> tc;

    for (int tnum = 0; tnum < tc; tnum++) {
    	int n, k;
    	cin >> n >> k;
    	double u;
    	cin >> u;
    	vector <double> p(n);
    	for (int i = 0; i < n; i++)
    		cin >> p[i];

    	double lb = 0.0;
    	double rb = 1.0;
    	for (int it = 0; it < iters; it++) {
    		double mid = (lb + rb) / 2.0;
    		double sum = 0.0;
    		for (int i = 0; i < n; i++)
    			sum += max(0.0, mid - p[i]);
    		if (sum > u)
    			rb = mid;
    		else
    			lb = mid;
    	}

    	double res = (lb + rb) / 2.0;
		double ans = 1.0;
		for (int i = 0; i < n; i++)
			ans *= max(p[i], res);
		cout.precision(20);
		cout << "Case #" << tnum + 1 << ": " << ans << endl;
    }

    return 0;
}