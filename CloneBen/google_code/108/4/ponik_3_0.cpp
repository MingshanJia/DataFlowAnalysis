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
const long long INF = 1e18;

long long solveTheProblem(vector<long long> const& d1, vector<long long> const& d2, int dist)
{
    long long bestMaxDist = INF;
    for (int pos = 0; pos <= dist; pos++)
    {
        long long maxDist = 0;
        for (int i = 0; i < (int)d1.size(); i++)
        {
            long long curDist = min(d1[i] + pos, d2[i] + dist - pos);
            maxDist = max(maxDist, curDist);
        }
        bestMaxDist = min(bestMaxDist, maxDist);
    }
    return bestMaxDist;
}
  
int main() {
    freopen ("A.in", "r", stdin);
    freopen ("A.out", "w", stdout);
    int t, b; 
    cin >> t;
    for (int test_number = 0; test_number < t; test_number++) {
        cin >> b;
        vector<vector<int>> mat (b, vector<int>(b, 0));
        for (int i = 0; i < b; i++) {
            for (int j = 0; j < i; j++) {
                cin >> mat[i][j];
                mat[i][j] *= 2;
            }
        }
        vector<vector<long long>> fl (b, vector<long long>(b, 0));
        for (int i = 0; i < b; i++)
        {
            for (int j = 0; j < i; j++) {
                fl[i][j] = mat[i][j];
                fl[j][i] = mat[i][j];
                if (mat[i][j] < 0) {
                    fl[i][j] = INF;
                    fl[j][i] = INF;
                }
            }
        }
        for (int k = 0; k < b; k++) {
            for (int i = 0; i < b; i++) {
                for (int j = 0; j < b; j++) {
                    fl[i][j] = min(fl[i][j], fl[i][k] + fl[k][j]);
                }
            }
        }
        long long best = INF;
        for (int i = 0; i < b; i++) {
            for (int j = 0; j < i; j++) {
                if (mat[i][j] < 0) {
                    continue;
                }
                long long cur = solveTheProblem(fl[i], fl[j], mat[i][j]);
                best = min(best, cur);
            }
        }
        double precision = best * 0.5;
        cout <<  "Case #" << test_number + 1 << ": " << precision << "\n";
    }
    
    return 0;
}