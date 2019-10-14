// Partial solution for small dataset with brute force
#include <cstdio>
#include <cstring>

int arr[104][104];

int R, C;

int max(int a, int b) { return a > b ? a : b; }

int force(int r, int c, int sum) {
    if (r > R+1)
        return sum;
    if (c > C+1)
        return force(r + 1, 2, sum);

    int ans = 0;

    if (arr[r-1][c] + arr[r-2][c] != 2 && arr[r][c-1] + arr[r][c-2] != 2) {
        arr[r][c] = 1;
        ans = max(ans, force(r, c+1, sum+1));
    }
    arr[r][c] = 0;
    return max(ans, force(r, c+1, sum));
}

int main() {
    int T; scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        scanf("%d%d", &R, &C);
        memset(arr, 0, sizeof arr);
        printf("Case #%d: %d\n", t, force(2, 2, 0));
    }
}
