/******************************************************************************\
*                         Author:  Dumbear                                     *
*                         Email:   dumbear[#at]163.com                         *
*                         Website: http://dumbear.com                          *
\******************************************************************************/
#include <algorithm>
#include <bitset>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <typeinfo>
#include <utility>
#include <vector>

using namespace std;

#define output(x) cout << #x << ": " << (x) << endl;

typedef long long LL;
typedef vector<int> VI;
typedef vector<long long> VL;
typedef vector<double> VD;
typedef vector<string> VS;

int t, n, board[32][32], buffer[32][32];
char direction[16];

void drop() {
    memset(buffer, 0, sizeof(buffer));
    for (int col = 0; col < n; ++col) {
        int p = n;
        for (int row = n - 1; row >= 0; --row) {
            if (board[row][col] == 0)
                continue;
            if (p < n && buffer[p][col] == board[row][col]) {
                buffer[p][col] *= 2;
                --p;
            } else {
                if (p == n || buffer[p][col] != 0)
                    --p;
                buffer[p][col] = board[row][col];
            }
        }
    }
    memcpy(board, buffer, sizeof(board));
}

void rotate() {
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            buffer[n - j - 1][i] = board[i][j];
    memcpy(board, buffer, sizeof(board));
}

void compute_state() {
    switch(direction[0]) {
        case 'u':
            rotate();
            rotate();
            drop();
            rotate();
            rotate();
            break;
        case 'd':
            drop();
            break;
        case 'l':
            rotate();
            drop();
            rotate();
            rotate();
            rotate();
            break;
        case 'r':
            rotate();
            rotate();
            rotate();
            drop();
            rotate();
            break;
    }
}

void solve() {
    scanf("%d%s", &n, direction);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            scanf("%d", &board[i][j]);
    compute_state();
    printf("Case #%d:\n", ++t);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            printf(j == n - 1 ? "%d\n" : "%d ", board[i][j]);
}

int main() {
    freopen("out.txt", "w", stdout);
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; ++i)
        solve();
    return 0;
}
