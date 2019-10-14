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

int w, h, n;
bool b[101][101];
bool full = false;

bool tet[7][4][4][4] =
{
    {
        { {1,0,0,0}, {1,1,0,0}, {0,1,0,0}, {0,0,0,0}, },
        { {0,1,1,0}, {1,1,0,0}, {0,0,0,0}, {0,0,0,0}, },
        { {1,0,0,0}, {1,1,0,0}, {0,1,0,0}, {0,0,0,0}, },
        { {0,1,1,0}, {1,1,0,0}, {0,0,0,0}, {0,0,0,0}, },
    },
    {
        { {0,1,0,0}, {1,1,0,0}, {1,0,0,0}, {0,0,0,0}, },
        { {1,1,0,0}, {0,1,1,0}, {0,0,0,0}, {0,0,0,0}, },
        { {0,1,0,0}, {1,1,0,0}, {1,0,0,0}, {0,0,0,0}, },
        { {1,1,0,0}, {0,1,1,0}, {0,0,0,0}, {0,0,0,0}, },
    },
    {
        { {1,0,0,0}, {1,0,0,0}, {1,1,0,0}, {0,0,0,0}, },
        { {0,0,1,0}, {1,1,1,0}, {0,0,0,0}, {0,0,0,0}, },
        { {1,1,0,0}, {0,1,0,0}, {0,1,0,0}, {0,0,0,0}, },
        { {1,1,1,0}, {1,0,0,0}, {0,0,0,0}, {0,0,0,0}, },
    },
    {
        { {0,1,0,0}, {0,1,0,0}, {1,1,0,0}, {0,0,0,0}, },
        { {1,1,1,0}, {0,0,1,0}, {0,0,0,0}, {0,0,0,0}, },
        { {1,1,0,0}, {1,0,0,0}, {1,0,0,0}, {0,0,0,0}, },
        { {1,0,0,0}, {1,1,1,0}, {0,0,0,0}, {0,0,0,0}, },
    },
    {
        { {1,1,0,0}, {1,1,0,0}, {0,0,0,0}, {0,0,0,0}, },
        { {1,1,0,0}, {1,1,0,0}, {0,0,0,0}, {0,0,0,0}, },
        { {1,1,0,0}, {1,1,0,0}, {0,0,0,0}, {0,0,0,0}, },
        { {1,1,0,0}, {1,1,0,0}, {0,0,0,0}, {0,0,0,0}, },
    },
    {
        { {1,0,0,0}, {1,0,0,0}, {1,0,0,0}, {1,0,0,0}, },
        { {1,1,1,1}, {0,0,0,0}, {0,0,0,0}, {0,0,0,0}, },
        { {1,0,0,0}, {1,0,0,0}, {1,0,0,0}, {1,0,0,0}, },
        { {1,1,1,1}, {0,0,0,0}, {0,0,0,0}, {0,0,0,0}, },
    },
    {
        { {0,1,0,0}, {1,1,1,0}, {0,0,0,0}, {0,0,0,0}, },
        { {0,1,0,0}, {1,1,0,0}, {0,1,0,0}, {0,0,0,0}, },
        { {1,1,1,0}, {0,1,0,0}, {0,0,0,0}, {0,0,0,0}, },
        { {1,0,0,0}, {1,1,0,0}, {1,0,0,0}, {0,0,0,0}, },
    }
};

void check() {
    for(int i = h-1; i >= 0; i --) {
        bool f = true;
        for(int j = 0; j < w; j ++) {
            if(!b[i][j]) {
                f = false;
                break;
            }
        }
        if(f) {
            for(int k = i; k >= 1; k --)
                for(int j = 0; j < w; j ++)
                    b[k][j] = b[k-1][j];
            for(int j = 0; j < w; j ++)
                b[0][j] = false;
            i ++;
        }
    }
}

void put(int t, int r, int x) {
    for(int row = 0; row <= h; row ++) {
        bool ok = true;
        for(int i = 0; i < 4; i ++) {
            for(int j = 0; j < 4; j ++) {
                if(tet[t][r][i][j]) {
                    int bi = row+i;
                    int bj = x+j;
                    if(bi < 0 || bi >= h || bj < 0 || bj >= w) {
                        ok = false;
                        break;
                    }
                    if(b[bi][bj]) {
                        ok = false;
                        break;
                    }
                }
            }
            if(ok == false)
                break;
        }
        if(ok == false) {
            if(row == 0) {
                full = true;
                break;
            }
            for(int i = 0; i < 4; i ++) {
                for(int j = 0; j < 4; j ++) {
                    if(tet[t][r][i][j]) {
                        int bi = row+i-1;
                        int bj = x+j;
                        b[bi][bj] = true;
                    }
                }
            }
            check();
            break;
        }
    }
}

int main() {
    int caseNum = 0;

/*
    for(int i = 0; i < 7;i ++)
    for(int j = 0; j < 4; j ++) {
        for(int x = 0; x < 4; x ++) {
        for(int y = 0; y < 4; y ++)
            if(tet[i][j][x][y])
                cout << 'x';
            else
                cout << '.';
        cout << endl;
        }
        cout << endl;
    }
*/

    cin >> caseNum;
    for(int c = 1; c <= caseNum; c ++) {
        cin >> w >> h >> n;
        full = false;
        memset(b, 0, sizeof(b));
        for(int i = 0; i < n; i ++) {
            int t, r, x;
            cin >> t >> r >> x;
            t --;
            if(!full)
                put(t, r, x);
        }
        printf("Case #%d:\n", c);
        if(full)
            cout << "Game Over!\n";
        else
        for(int i = 0; i < h; i ++) {
            for(int j = 0; j < w; j ++) {
                if(b[i][j])
                    cout << 'x';
                else
                    cout << '.';
            }
            cout << endl;
        }
    }
}

