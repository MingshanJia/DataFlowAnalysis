#include <functional>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <numeric>
#include <cstring>
#include <climits>
#include <cassert>
#include <complex>
#include <cstdio>
#include <string>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <cmath>
#include <ctime>
#include <list>
#include <set>
#include <map>
using namespace std;
typedef long long LL;
const int N = 405;
const int MOD = 1000000007;
double dp[N][(N - 1) * N / 2];
int b , l , n;
int main(){
#ifndef ONLINE_JUDGE
    freopen ("input.txt" , "r" , stdin);
    freopen ("output.txt" , "w" , stdout);
#endif
    int t , cas = 0;
    scanf ("%d" , &t);
    while (t --) {
        scanf ("%d %d %d" , &b , &l , &n);
        memset (dp , 0 , sizeof (dp));
        dp[1][1] = b * 750.0;
        for (int i = 1 ; i < l ; i ++) {
            int k = 1;
            for (int j = 1 ; j <= i ; j ++) {
                for (int r = 0 ; r < j ; r ++ , k ++) {
                    double d = max (0.0 , dp[i][k] - 250.0) / 3.0;
                    dp[i + 1][k] += d;
                    dp[i + 1][k + j] += d;
                    dp[i + 1][k + j + 1] += d;
                }
            }
        }
        printf ("Case #%d: %.7f\n" , ++ cas , min (250.0 , dp[l][n]));
    }
    return 0;
}