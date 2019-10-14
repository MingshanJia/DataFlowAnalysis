#include <iostream>
#include <vector>
#include <cstring>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <map>
#include <math.h>

using namespace std;

int a[110];
int b[110];
int main() {
    freopen("../B-small-attempt0.in", "r", stdin);
    freopen("../out.txt", "w", stdout);
   
    int T;
    cin >> T;
    int C = 1;
    while (T --) {
        int n;
        scanf("%d", &n);
        long long cur = 0;
        long long max_rate = 0;
        for (int i = 0;i < n;i ++) {
            long long N,E;
            cin >> N >> E;
            long long votes = N * E;
            cur = max(0LL, cur - votes);
            cur += N;
            max_rate = E;
        }
        long long res = max(cur, max_rate + 1);
        printf("Case #%d: ", C++);
        cout << res << endl;

    }
}