#include <cstdio>
#include <algorithm>
using namespace std;

int D, K, N;

//i = A + Dk + C
int solve(int A, int C) {
    int sum = A + C;
    while (sum > D) sum -= D;
    while (sum <= D) {
        if (sum > 0)
            return sum;
        sum += D;
    }
    return -1;
}

int main() {

    int cases;
    scanf("%d", &cases);
    for (int T=1; T<=cases; ++T) {
        scanf("%d %d %d", &D, &K, &N);

        printf("Case #%d: ", T);

        int pos, ans1, ans2;
        if (K % 2) {
            pos = (K + N) % D;
            ans1 = solve(N-D, (pos-1+D) % D);
            ans2 = solve(N-D, (pos+1) % D);
        }
        else {
            pos = (K - N + D) % D;
            ans1 = solve(-N, (pos-1+D) % D);
            ans2 = solve(-N, (pos+1) % D);
        }

        printf("%d %d\n", ans2, ans1);
    }

    return 0;

}
