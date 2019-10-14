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
const int N = 25;
int n , a[N][N] , b[N][N];
char str[10];
int main () {
#ifndef ONLINE_JUDGE
    freopen ("input.txt" , "r" , stdin);
    freopen ("output.txt" , "w" , stdout);
#endif
    int t , cas = 0;scanf ("%d" , &t);
    while (t --) {
        memset (b , 0 , sizeof (b));
        scanf ("%d %s" , &n , str);
        for (int i = 0 ; i < n ; i ++) {
            for (int j = 0 ; j < n ; j ++) {
                scanf ("%d" , &a[i][j]);
            }
        }
        if (str[0] == 'r') {
            for (int i = 0 ; i < n ; i ++) {
                vector <int> v;
                for (int j = 0 ; j < n ; j ++) {
                    if (a[i][j])
                        v.push_back (a[i][j]);
                }
                for (int j = n - 1 , k = v.size () - 1 ; j >= 0 ; j --) {
                    if (k < 0) {
                        b[i][j] = 0;
                    }
                    else if (k == 0) {
                        b[i][j] = v[k];
                        k --;
                    }
                    else if (v[k] == v[k - 1]) {
                        b[i][j] = v[k] * 2;
                        k -= 2;
                    }
                    else {
                        b[i][j] = v[k];
                        k --;
                    }
                }
            }
        }
        else if (str[0] == 'l') {
            for (int i = 0 ; i < n ; i ++) {
                vector <int> v;
                for (int j = n - 1 ; j >= 0 ; j --) {
                    if (a[i][j])
                        v.push_back (a[i][j]);
                }
                for (int j = 0 , k = v.size () - 1 ; j < n ; j ++) {
                    if (k < 0) {
                        b[i][j] = 0;
                    }
                    else if (k == 0) {
                        b[i][j] = v[k];
                        k --;
                    }
                    else if (v[k] == v[k - 1]) {
                        b[i][j] = v[k] * 2;
                        k -= 2;
                    }
                    else {
                        b[i][j] = v[k];
                        k --;
                    }
                }
            }
        }
        else if (str[0] == 'd') {
            for (int i = 0 ; i < n ; i ++) {
                vector <int> v;
                for (int j = 0 ; j < n ; j ++) {
                    if (a[j][i])
                        v.push_back (a[j][i]);
                }
                for (int j = n - 1 , k = v.size () - 1 ; j >= 0 ; j --) {
                    if (k < 0) {
                        b[j][i] = 0;
                    }
                    else if (k == 0) {
                        b[j][i] = v[k];
                        k --;
                    }
                    else if (v[k] == v[k - 1]) {
                        b[j][i] = v[k] * 2;
                        k -= 2;
                    }
                    else {
                        b[j][i] = v[k];
                        k --;
                    }
                }
            }
        }
        else if (str[0] == 'u') {
            for (int i = 0 ; i < n ; i ++) {
                vector <int> v;
                for (int j = n - 1 ; j >= 0 ; j --) {
                    if (a[j][i])
                        v.push_back (a[j][i]);
                }
                for (int j = 0 , k = v.size () - 1 ; j < n ; j ++) {
                    if (k < 0) {
                        b[j][i] = 0;
                    }
                    else if (k == 0) {
                        b[j][i] = v[k];
                        k --;
                    }
                    else if (v[k] == v[k - 1]) {
                        b[j][i] = v[k] * 2;
                        k -= 2;
                    }
                    else {
                        b[j][i] = v[k];
                        k --;
                    }
                }
            }
        }
        printf ("Case #%d:\n" , ++ cas);
        for (int i = 0 ; i < n ; i ++) {
            for (int j = 0 ; j < n - 1 ; j ++)
                printf ("%d " , b[i][j]);
            printf ("%d\n" , b[i][n - 1]);
        }
    }
    return 0;
}
