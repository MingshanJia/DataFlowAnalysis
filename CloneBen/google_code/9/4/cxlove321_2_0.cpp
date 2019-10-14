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
const int N = 10005;
const int MOD = 1000000007;
int n , k;
int main(){
#ifndef ONLINE_JUDGE
    freopen ("input.txt" , "r" , stdin);
    freopen ("output.txt" , "w" , stdout);
#endif
    
    int t , cas = 0;
    scanf ("%d" , &t);
    while (t --) {
        vector <int> a;
        scanf ("%d %d" , &n , &k);
        for (int i = 0 ; i < n ; i ++) {
            int p;
            scanf ("%d" , &p);
            a.push_back (p);
        }
        int ans = 0;
        for (int i = 0 ; i < (int)a.size () - 2 ; ) {
            // cout << i << " " << a.size () << endl;
            if (a[i] == a[i + 1] && a[i] == a[i + 2]) {
                a.erase (a.begin () + i);a.erase (a.begin () + i);a.erase (a.begin () + i);
                ans += 3;
                i = 0;
            }
            else i ++;
        }
        printf ("Case #%d: %d\n" , ++ cas , n - ans);
    }
    return 0;
}