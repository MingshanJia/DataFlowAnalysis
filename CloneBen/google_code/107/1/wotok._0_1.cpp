#include <iostream>
#include <vector>
#include <cstring>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

int a[110];
int b[110];
int main() {
    freopen("../A-large.in", "r", stdin);
    freopen("../out.txt", "w", stdout);
   
    int T;
    cin >> T;
    int C = 1;
    while (T --) {
        int n;
        scanf("%d", &n);
        for (int i = 0;i < n;i ++) {
            a[i] = i / 2;
        }
        for (int i = 0;i < n;i ++) {
            cin >> b[i];
        }
        sort(b, b+n);
        long long res = 0;
        for (int i = 0;i < n;i ++) {
            res += (a[i] - b[i]) * (a[i] - b[i]);
        }

        printf("Case #%d: ", C++);
        cout << res << endl;

    }
}