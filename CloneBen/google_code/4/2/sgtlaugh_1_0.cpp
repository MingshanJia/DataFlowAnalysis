#include <bits/stdtr1c++.h>

#define MAX 222
#define clr(ar) memset(ar, 0, sizeof(ar))
#define read() freopen("lol.txt", "r", stdin)
#define write() freopen("out.txt", "w", stdout)
#define dbg(x) cout << #x << " = " << x << endl
#define ran(a, b) ((((rand() << 15) ^ rand()) % ((b) - (a) + 1)) + (a))

using namespace std;

int n, m, res = 0, board[15][15], dp[MAX + 10][MAX + 10], seq[MAX + 10];

void backtrack(int i, int j, int counter){
    res = max(res, counter);
    if (j == m) return backtrack(i + 1, 0, counter);
    if (i == n) return;

    int flag = 1;
    backtrack(i, j + 1, counter);

    board[i][j] = 1;
    if ((j - 2) >= 0 && board[i][j - 1] == board[i][j] && board[i][j - 2] == board[i][j]) flag = 0;
    if ((i - 2) >= 0 && board[i - 1][j] == board[i][j] && board[i - 2][j] == board[i][j]) flag = 0;
    if (flag) backtrack(i, j + 1, counter + 1);

    board[i][j] = 0;
}

int brute(int a, int b){
    clr(board);
    n = a, m = b, res = 0;
    backtrack(0, 0, 0);
    return res;
}

void Generate(){
    int n, m, i, j;

    seq[1] = 1, seq[2] = 2, seq[3] = 2;
    for (i = 4; i < MAX; i += 3){
        seq[i] = seq[i - 3] + 2;
        seq[i + 1] = seq[i - 2] + 2;
        seq[i + 2] = seq[i - 1] + 2;
    }

    clr(dp);
    for (m = 1; m < MAX; m++){
        for (n = 1; n < MAX; n++){
            if (m % 3 == 0){
                int s = (m / 3) * 2;
                dp[n][m] = s * n;
            }
            else dp[n][m] = dp[n][m - 1] + seq[n];
            if ((n % 5 == 0) && (m % 5 == 0)) dp[n][m]--;
        }
    }
}

int main(){
    read();
    write();
    Generate();
    int T = 0, t, i, j, k, x;

//    for (n = 1; n <= 7; n++){
//        for (m = 1; m <= 7; m++){
//            if (n == 7 && m == 7) continue;
//            if (n == 7 && m == 6) continue;
//            if (n == 6 && m == 7) continue;
//            if (brute(n, m) != dp[n][m]){
//                printf("%d %d = %d %d\n", n, m, dp[n][m], brute(n, m));
//            }
//
//            assert(dp[n][m] == brute(n, m));
//
//            //printf("%d %d = %d\n", n, m, brute(n, m));
//        }
//    }
//    return 0;

    scanf("%d", &t);
    while (t--){
        scanf("%d %d", &n, &m);
        printf("Case #%d: %d\n", ++T, brute(n, m));
    }
    return 0;
}
