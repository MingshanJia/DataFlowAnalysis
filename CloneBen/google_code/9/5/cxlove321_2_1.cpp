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
int a[N] , b[N][N] , n , k , ans[N];
int dp[N][N];
int main(){
#ifndef ONLINE_JUDGE
    freopen ("input.txt" , "r" , stdin);
    freopen ("output.txt" , "w" , stdout);
#endif
    int t , cas = 0;
    scanf ("%d" , &t);
    while (t --) {
        scanf ("%d %d" , &n , &k);
        for (int i = 0 ; i < n ; i ++) {
            scanf ("%d" , &a[i]);
            for (int j = 0 ; j < i ; j ++) {
                b[j][i] = a[i] - a[j];
            }
        }
        memset (dp , 0 , sizeof (dp));
        for (int i = 0 ; i < n - 2 ; i ++) {
            if (b[i][i + 1] == k && b[i + 1][i + 2] == k) {
                dp[i][i + 2] = 1;
            }
        }
        for (int i = 0 ; i < n - 5 ; i ++) {
            if (dp[i][i + 2] && dp[i + 3][i + 5]) {
                dp[i][i + 5] = 1;
            }
            else {
                if (dp[i + 1][i + 1 + 2] && b[i][i + 4] == k && b[i + 4][i + 5] == k) {
                    dp[i][i + 5] = 1;
                }
                if (dp[i + 2][i + 2 + 2] && b[i][i + 1] == k && b[i + 1][i + 5] == k) {
                    dp[i][i + 5] = 1;
                }
            }
        }
        for (int len = 9 ; len <= n ; len += 3) {
            for (int l = 0 ; l + len - 1 < n ; l ++) {
                int r = l + len - 1;
                if (dp[l + 1][r - 2] && b[l][r - 1] == k && b[r - 1][r] == k) {
                    dp[l][r] = 1;
                }
                if (dp[l + 2][r - 1] && b[l][l + 1] == k && b[l + 1][r] == k) {
                    dp[l][r] = 1;
                }
                for (int x = l + 1 ; x < r ; x ++) {
                    if (dp[l + 1][x - 1] && dp[x + 1][r - 1] && b[l][x] == k && b[x][r] == k) {
                        dp[l][r] = 1;
                    }
                    if (dp[l][x] && dp[x + 1][r]) {
                        dp[l][r] = 1;
                    }
                }
            }
        }
        memset (ans , 0x11 , sizeof (ans));
        ans[0] = 0;
        for (int i = 1 ; i <= n ; i ++) {
            ans[i]= ans[i - 1] + 1;
            for (int j = 0 ; j * 3 <= i ; j ++) {
                if (dp[i - 3 * j][i - 1]) {
                    ans[i] = min (ans[i] , ans[i - 3 * j]);
                }
            }
        }
        printf ("Case #%d: %d\n" , ++ cas , ans[n]);
    }
    return 0;
}