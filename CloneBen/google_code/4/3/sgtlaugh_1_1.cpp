#include <bits/stdtr1c++.h>

#define MAX 222
#define clr(ar) memset(ar, 0, sizeof(ar))
#define read() freopen("lol.txt", "r", stdin)
#define write() freopen("out.txt", "w", stdout)
#define dbg(x) cout << #x << " = " << x << endl
#define ran(a, b) ((((rand() << 15) ^ rand()) % ((b) - (a) + 1)) + (a))

using namespace std;

int n, m, res = 0, board[MAX][MAX], dp[MAX + 10][MAX + 10], seq[MAX + 10];

void backtrack(int i, int j, int counter){
//    if (counter == 14){
//        for (int k = 0; k < n; k++){
//            for (int l = 0; l < m; l++){
//                printf("%d ", board[k][l]);
//            }
//            puts("");
//        }
//        puts("");
//        exit(0);
//
//    }

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
        seq[i + 1] = seq[i - 3] + 2;
        seq[i + 2] = seq[i - 3] + 2;
    }

    clr(dp);
    for (m = 1; m < MAX; m++){
        for (n = 1; n < MAX; n++){
            if (m % 3 == 0){
                int s = (m / 3) * 2;
                dp[n][m] = s * n;
            }
            else dp[n][m] = dp[n][m - 1] + seq[n];
            //if ((n % 5 == 0) && (m % 5 == 0)) dp[n][m]++;
        }
    }
}

int solve(int n, int m){
    if (n > m) swap(n, m);
    if (n == 1) return dp[n][m];
    if (n == 2) return dp[n][m];

    int i, j, k, l, x, y, c, d, res = 0, ar[] = {3, 5, 6};

    for (; ;){
        clr(board);
        for (i = 0; i < n; i++){
            for (j = 0; j < m; j++){
                if (ar[i % 3] & (1 << (j % 3))) board[i][j] = 1;
            }
        }

        int flag = 1, counter = 0;
        for (i = 0; i < n; i++){
            for (j = 0; j < m; j++){
                if (board[i][j]){
                    counter++;
                    c = 0, d = board[i][j + 1];
                    if (j && board[i][j - 1]) c = 1;
                    if (c && d) flag = 0;

                    c = 0, d = board[i + 1][j];
                    if (i && board[i - 1][j]) c = 1;
                    if (c && d) flag = 0;
                }
            }
        }
        if (flag) res = max(res, counter);

        if (!next_permutation(ar, ar + 3)) break;
    }
    return res;
}

int main(){
    read();
    write();
    Generate();
    int T = 0, t, i, j, k, x;
//
//    m = 1;
//    for (n = 1; n <= 30; n++){
//        dbg(brute(n, m));
//    }
//    return 0;

//    for (n = 1; n <= 30; n++){
//        for (m = 1; m <= 30; m++){
//            if (n == 7 && m == 7) continue;
//            if (n == 7 && m == 6) continue;
//            if (n == 6 && m == 7) continue;
//            if (n * m > 28) continue;
//            //if ((n * m) > 27 && min(n, m) > 6) continue;
//
//            if (brute(n, m) != solve(n, m)){
//                printf("%d %d = %d %d\n", n, m, solve(n, m), brute(n, m));
//            }
//
//            //assert(dp[n][m] == brute(n, m));
//
//            //printf("%d %d = %d\n", n, m, brute(n, m));
//        }
//    }
//    return 0;

    scanf("%d", &t);
    while (t--){
        scanf("%d %d", &n, &m);
        printf("Case #%d: %d\n", ++T, solve(n, m));
    }
    return 0;
}
