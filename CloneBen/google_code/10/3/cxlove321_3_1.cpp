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
struct Node {
    int w , h;
    Node () {}
    Node (int _w , int _h) {
        w = _w;
        h = _h;
        if (w > h) swap (w , h);
    }
    bool operator < (const Node &n) const {
        return w != n.w ? w < n.w : h < n.h;
    }
};
int n , m , a[N];
int main () {
#ifndef ONLINE_JUDGE
    freopen ("input.txt" , "r" , stdin);
    freopen ("output.txt" , "w" , stdout);
#endif
    int t , cas = 0;
    scanf ("%d" , &t);
    while (t --) {
        scanf ("%d %d" , &n , &m);
        for (int i = 0 ; i < n ; i ++) {
            scanf ("%d" , &a[i]);
            a[i] = 1 << a[i];
        }
        sort (a , a + n);
        reverse (a , a + n);
        int ans = 0;
        multiset <Node> s;
        for (int i = 0 ; i < n ; i ++) {
            int ok = false;
            for (set <Node> :: iterator it = s.begin () ; it != s.end () ; it ++){
                if (it -> w >= a[i]) {
                    ok = true;
                    Node p = *it;
                    if ((p.h - a[i]) && (p.w - a[i]))
                        s.insert (Node (p.w - a[i] , p.h - a[i]));
                    if (p.w - a[i]) 
                        s.insert (Node (p.w - a[i] , a[i]));
                    if (p.h - a[i])
                        s.insert (Node (p.h - a[i] , a[i]));
                    s.erase (it);
                    break;
                }
            }
            if (!ok) {
                ans ++;
                if (m - a[i])  {
                    s.insert (Node (a[i] , m - a[i]));
                    s.insert (Node (a[i] , m - a[i]));
                    s.insert (Node (m - a[i] , m - a[i]));
                }
            }
        }
        printf ("Case #%d: %d\n" , ++ cas , ans);
    }
    return 0;
}
