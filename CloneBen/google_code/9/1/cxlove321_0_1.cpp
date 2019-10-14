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
const int N = 105;
const int MOD = 1000000007;
int c[N][N];
int dp[N][N] , m , n;
inline int mut (int a , int b) {
    return 1LL * a * b % MOD;
}
int main(){
#ifndef ONLINE_JUDGE
    freopen ("input.txt" , "r" , stdin);
    freopen ("output.txt" , "w" , stdout);
#endif
    for (int i = 1 ; i < N ; i ++) {
        c[i][0] = c[i][i] = 1;
        for (int j = 1 ; j < i ; j ++) {
            c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % MOD;
        }
    }
    // cout << c[2][2] << endl;
    int t , cas = 0;
    scanf ("%d" , &t);
    while (t --) {
        scanf ("%d %d" , &m , &n);
        memset (dp , 0 , sizeof (dp));
        dp[0][0] = 1;
        for (int i = 0 ; i < m ; i ++) {
            for (int j = 0 ; j <= n ; j ++) {
                for (int k = 1 ; k + j <= n ; k ++) {
                    dp[i + 1][j + k] = (dp[i + 1][j + k] + mut (dp[i][j] , c[n - j][k])) % MOD;
                }
            }
        }
        printf ("Case #%d: %d\n" , ++ cas , dp[m][n]);
    }

    return 0;
}