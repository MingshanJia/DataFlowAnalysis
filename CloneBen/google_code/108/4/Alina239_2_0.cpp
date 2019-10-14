#include <cstring>
#include <cassert>
#include <string>
#include <cstdio>
#include <vector>

using namespace std;


const int N = 15;

char B[51][51];
char C[51][51];
string IO = "I/O";
string P = "I/O/";

int in(int i, int j, int a, int b, int c, int d) {
    int ok = 1;
    ok &= a <= i && i < c;
    ok &= b <= j && j < d;
    return ok;
}

int check(int i, int j, int a, int b, int c, int d) {
    int res = 0;
    for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <= 1; dy++) {
            int ok = 1;
            for (int k = 0; k < 3; k++) {
                int ci = i + dx * k;
                int cj = j + dy * k;
                ok &= in(ci, cj, a, b, c, d) && B[ci][cj] == IO[k];
            }
            res += ok;
        }
    }
    return res;
}

int calc(int a, int b, int c, int d) {
    int res = 0;
    for (int i = a; i < c; i++) {
        for (int j = b; j < d; j++) {
            res += check(i, j, a, b, c, d);
        }
    }
    return res;
}

void fill() {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            B[i][j] = P[j % 4];
}

int A[288][4];

void solve(int x) {
    int v = x;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            B[i][j] = C[i][j];
    while (A[v][0] == -1) v++;
    int X = A[v][0];
    int Y = A[v][1];
    while (calc(0, 0, X, Y) > x) {
        int u = calc(0, 0, X, Y);
        int ok = 0;
        for (int t = 0; t < X * Y; t++) {
            int i = t / Y;
            int j = t % Y;
            if (u - check(i, j, 0, 0, X, Y) >= x && B[i][j] == 'I') {
                B[i][j] = 'O';
                ok = 1;
                break;
            }
        }
        if (ok) continue;
        for (int t = 0; t < X * Y; t++) {
            int i = t / Y;
            int j = t % Y;
            if (i != 0 && i != X - 1) continue;
            if (B[i][j] == '/') {
                B[i][j] = 'O';
                ok = 1;
                break;
            }
        }
        assert(ok);
    }
    assert(calc(0, 0, X, Y) == x);
    for (int i = 0; i < X; i++) {
        for (int j = 0; j < Y; j++) {
            printf("%c", B[i][j]);
        }
        printf("\n");
    }
}

int main() {


    //freopen("c.in", "r", stdin);
    //freopen("c.out", "w", stdout);
    fill();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            C[i][j] = B[i][j];
        }
    }
    memset(A, -1, sizeof(A));
    for (int c = 1; c <= N; c++) {
        for (int d = 1; d <= N; d++) {
            int val = calc(0, 0, c, d);
            if (A[val][0] != -1) continue;
            A[val][0] = c;
            A[val][1] = d;
        }
    }

    int T;
    scanf("%d", &T);
    for (int test = 1; test <= T; test++) {
        int x;
        scanf("%*d%d", &x);
        printf("Case #%d:\n", test);
        solve(x);
    }
    return 0;
}
