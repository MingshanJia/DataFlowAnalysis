#include <iostream>
#include <cstdio>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>
#include <climits>
#include <cmath>
#include <string>
#include <cstring>
using namespace std;

#define rep(i, n) for (int i = 0; i < n; i ++)
#define mem(s, v) memset(s, v, sizeof(s))
#define sz(v) (int)v.size()
#define pb push_back
#define mp make_pair

int main() {
    freopen("/Users/youhangtian/Downloads/C-small-attempt0.in.txt", "r", stdin);
    freopen("/Users/youhangtian/Downloads/output.txt", "w", stdout);
    
    int T;
    cin >> T;
    
    for (int ca = 1; ca <= T; ca ++) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        rep(i, n) cin >> arr[i];
        
        int res = 0;
        int arr2[105];
        
        rep(i, n) {
            arr2[res] = arr[i];
            if (res - 2 >= 0 && arr2[res] - arr2[res - 1] == k && arr2[res - 1] - arr2[res - 2] == k) res -= 2;
            else res ++;
        }
        
        cout << "Case #" << ca << ": " << res << endl;
    }
    
    return 0;
}