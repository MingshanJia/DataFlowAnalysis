#include <iostream>
#include <stdio.h>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cmath>
#include <memory.h>
#include <unordered_set>
#include <unordered_map>
using namespace std;

int xd[8] = {-1,-1,-1,0,1,1,1,0};
int yd[8] = {-1,0,1,1,1,0,-1,-1};

int n;
char b[301][301];
int num[301][301];
bool v[301][301];

void go(int i, int j) {
    if(b[i][j] == '*')
        return;
    if(v[i][j])
        return;
    v[i][j] = true;
    if(num[i][j] == 0) {
        for(int k = 0; k < 8; k ++) {
            int x = i+xd[k];
            int y = j+yd[k];
            if(x >= 0 && x < n && y >= 0 && y < n)
                go(x, y);
        }
    }
}

int main() {
    int caseNum = 0;
    cin >> caseNum;
    for(int c = 1; c <= caseNum; c ++) {
        cin >> n;
        for(int i = 0; i < n; i ++)
        for(int j = 0; j < n; j ++) {
            cin >> b[i][j];
            v[i][j] = false;
        }
        for(int i = 0; i < n; i ++)
        for(int j = 0; j < n; j ++) {
            if(b[i][j] == '*')
                continue;
            int t = 0;
            for(int k = 0; k < 8; k ++) {
                int x = i+xd[k];
                int y = j+yd[k];
                if(x >= 0 && x < n && y >= 0 && y < n && b[x][y] == '*')
                    t ++;
            }
            num[i][j] = t;
        }

        int ans = 0;
        for(int i = 0; i < n; i ++)
        for(int j = 0; j < n; j ++) {
            if(b[i][j] != '*' && num[i][j] == 0 && v[i][j] == false) {
                ans ++;
                go(i, j);
            }
        }
        for(int i = 0; i < n; i ++)
        for(int j = 0; j < n; j ++) {
            if(b[i][j] != '*' && num[i][j] != 0 && v[i][j] == false) {
                ans ++;
            }
        }
        printf("Case #%d: %d\n", c, ans);
    }
}

