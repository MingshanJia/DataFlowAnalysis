#include <vector>
#include<cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <deque>
#include <set>
#ifdef __GXX_EXPERIMENTAL_CXX0X__
#include <unordered_map>
#include <cassert>
#endif
#include <ctime>
#include <queue>
#include <stack>
#include<iomanip>
#include <sstream>
#include <cmath>
using namespace std;
typedef pair<int, int> PII;
typedef unsigned long long ll;

void change(string& dir, vector<vector<int>>& board) {
    int n = board.size();
    if (dir == "right") {
        for(int i = 0; i < n; i ++) {
            vector<int> tmp(n, 0);
            int cnt = n - 1;
            for(int j = n - 1; j >= 0; j --) {
                if (board[i][j] == 0) continue;
                int k = j - 1;
                while(k >= 0 && board[i][k] == 0) k --;
                if (k >= 0 && board[i][k] == board[i][j]) {
                    tmp[cnt --] = board[i][j] * 2;
                    k --;
                } else {
                    tmp[cnt --] = board[i][j];
                }
                j = k + 1;
            }
            for(int j = 0; j < n; j ++) {
                board[i][j] = tmp[j];
            }
        }
    }
    if (dir == "left") {
        for(int i = 0; i < n; i ++) {
            vector<int> tmp(n, 0);
            int cnt = 0;
            for(int j = 0; j < n; j ++) {
                if (board[i][j] == 0) continue;
                int k = j + 1;
                while(k < n && board[i][k] == 0) k ++;
                if (k < n && board[i][k] == board[i][j]) {
                    tmp[cnt ++] = board[i][j] * 2;
                    k ++;
                } else {
                    tmp[cnt ++] = board[i][j];
                }
                j = k - 1;
            }
            for(int j = 0; j < n; j ++) {
                board[i][j] = tmp[j];
            }
        }
    }
    if (dir == "down") {
        for(int j = 0; j < n; j ++) {
            vector<int> tmp(n, 0);
            int cnt = n - 1;
            for(int i = n - 1; i >= 0; i --) {
                if (board[i][j] == 0) continue;
                int k = i - 1;
                while(k >= 0 && board[k][j] == 0) k --;
                if (k >= 0 && board[i][j] == board[k][j]) {
                    tmp[cnt --] = board[i][j] * 2;
                    k --;
                } else {
                    tmp[cnt --] = board[i][j];
                }
                i = k + 1;
            }
            for(int i = 0; i < n; i ++) {
                board[i][j] = tmp[i];
            }
        }
    }
    if (dir == "up") {
        for(int j = 0; j < n; j ++) {
            vector<int> tmp(n, 0);
            int cnt = 0;
            for(int i = 0; i < n; i ++) {
                if (board[i][j] == 0) continue;
                int k = i + 1;
                while(k < n && board[k][j] == 0) k ++;
                if (k < n && board[i][j] == board[k][j]) {
                    tmp[cnt ++] = board[i][j] * 2;
                    k ++;
                } else {
                    tmp[cnt ++] = board[i][j];
                }
                i = k - 1;
            }
            for(int i = 0; i < n; i ++) {
                board[i][j] = tmp[i];
            }
        }
    }
}

void solve(int ncase) {
    int n;
    string dir;
    cin >> n >> dir;
    vector<vector<int>> board(n, vector<int>(n));
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < n; j ++) {
            cin >> board[i][j];
        }
    }
    change(dir, board);
    cout << "Case #" << ncase << ":" << endl;
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < n; j ++) {
            cout << board[i][j] << (j < n - 1 ? ' ' : '\n');
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    //cout << setprecision(16) << endl;
#ifdef _zzz_
   freopen("B-large.in", "r", stdin);
   freopen("out.txt", "w", stdout);
#endif
    int T = 1;
    //scanf("%d", &T);
    cin >> T;
    int ncase = 0;
    while(T --) {
        solve(++ ncase);
    }
}
