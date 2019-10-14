//#include <bits/stdc++.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<vector>
#include<algorithm>

using namespace std;

#define CLR(a, b) memset(a, b, sizeof(a))

const int mod = 20007;

struct node {
    int x, y;
} a[1005];

int main() {
    int n;
    while(scanf("%d", &n), n) {
        vector<int> query[20008];
        int i, j, ans = 0, key;
        int x1, y1, x2, y2;
        for(i = 0; i < n; i++) {
            scanf("%d%d", &a[i].x, &a[i].y);
            key = (a[i].x * a[i].x + a[i].y * a[i].y) % mod;
            query[key].push_back(i);
        }
        for(i = 0; i < n; i++) {
            for(j = 0; j < n; j++) if(i != j) {
                x1 = a[i].x - (a[j].y - a[i].y);
                y1 = a[i].y + a[j].x - a[i].x;
                key = (x1 * x1 + y1 * y1) % mod;
                int fg = 0;
                for(int k = 0; k < query[key].size(); k++) {
                    int tp = query[key][k];
                    if(x1 == a[tp].x && y1 == a[tp].y) {
                        fg = 1;
                        break;
                    }
                }
                if(!fg)continue;
//                printf("%d -- %d  %d %d %d %d\n", i, j, x1, y1, x2, y2);
                x2 = a[j].x + a[i].y - a[j].y;
                y2 = a[j].y + a[j].x - a[i].x;
                key = (x2 * x2 + y2 * y2) % mod;
                for(int k = 0; k < query[key].size(); k++) {
                    int tp = query[key][k];
                    if(x2 == a[tp].x && y2 == a[tp].y) {
                        ans++;
                        break;
                    }
                }
            }
        }
        printf("%d\n", ans / 4);
    }
    return 0;
}
