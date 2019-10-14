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

double table[405][90000];

int main() {
    freopen("/Users/youhangtian/Downloads/B-large.in.txt", "r", stdin);
    freopen("/Users/youhangtian/Downloads/output.txt", "w", stdout);
    
    int T;
    cin >> T;
    
    int leve[90000];
    int l = 1;
    int count = 0;
    for (int i = 1; i < 90000; i ++) {
        if (count + l >= i) leve[i] = l;
        else {
            leve[i] = l + 1;
            count += l;
            l ++;
        }
    }
    
    int num[90000][2];
    for (int i = 1; i < 90000; i ++) {
        int l = leve[i];
        num[i][0] = i + l;
        num[i][1] = i + l + 1;
    }
    
    for (int ca = 1; ca <= T; ca ++) {
        int b, l, n;
        cin >> b >> l >> n;
        rep(i, 405) rep(j, 90000) table[i][j] = 0;
        
        table[1][1] = b * 750;
        for (int i = 1; i <= l; i ++) {
            for (int j = 1; j <= i * (i + 1) / 2; j ++) {
                if (table[i][j] > 250) {
                    double d = (table[i][j] - 250) / 3;
                    table[i + 1][j] += d;
                    table[i + 1][num[j][0]] += d;
                    table[i + 1][num[j][1]] += d;
                    
                    table[i][j] = 250;
                }
            }
        }
        
        printf("Case #%d: %.7f\n", ca, table[l][n]);
    }
    
    return 0;
}