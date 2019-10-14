#define _hypot hypot

#include <vector>
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std; 


typedef float ld;
const ld eps = 1e-7;
const int maxn = 100000;
 
 
int main() {
    freopen ("A.in", "r", stdin);
    freopen ("A.out", "w", stdout);
    int t, n;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n;
        vector<double> p (2*n, 0);
        for (int j = 0; j < 2*n; j++) {
            cin >> p[j]; 
        }
        sort(p.begin(), p.end());
        double ans = 1;
        for (int k = 0; k < n; k++) {
            ans *= 1 - p[k] * p[2*n - 1 - k];
        }
        cout <<  "Case #" << i + 1 << ": " << std::setprecision(9) << ans << "\n";
    }
    
    return 0;
}