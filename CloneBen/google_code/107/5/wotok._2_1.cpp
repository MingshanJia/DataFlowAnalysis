#include <iostream>
#include <vector>
#include <cstring>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <map>
#include <math.h>

using namespace std;

//int a[110];
//int b[110];
int n;
bool check(string A, string B, string C) {
    map<string,int> mp;
    for (int i = 0; i < n;i ++) {
        if (A[i] != B[i]) {
            string tmp = "";
            tmp = tmp + A[i];
            tmp = tmp + B[i];
            mp[tmp] = 1;
            break;
        }
    }
    for (int i = 0;i < n;i ++) {
        if (B[i] != C[i]) {
            string tmp = "";
            tmp = tmp + C[i];
            tmp = tmp + B[i];
            if (mp[tmp] == 1) {
                return false;
            }
            else {
                return true;
            }
        }
    }
}
int main() {
    freopen("../C-large.in", "r", stdin);
    freopen("../out.txt", "w", stdout);
   
    int T;
    cin >> T;
    int Case = 1;
    while (T --) {
        cin >> n;
        string A, B, C;
        cin >> A >> B >> C;
        int res[3];
        res[0] = res[1] = res[2] = 0;
        res[0] = check(B, A, C) || check(C, A, B);
        res[1] = check(A, B, C) || check(C, B, A);
        res[2] = check(A, C, B) || check(B, C, A);
        printf("Case #%d:", Case++);
        for (int i = 0;i < 3;i ++) {
            printf(" %s", res[i] == 1 ? "YES" : "NO");
        }
        puts("");
    }
}