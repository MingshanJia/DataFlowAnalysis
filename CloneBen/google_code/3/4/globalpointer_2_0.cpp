#include <bits/stdc++.h>

int T;
double x[3], y[3], z[3];

int main() {
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        for (int i = 0; i < 3; i++) {
            scanf("%lf%lf%lf", x+i, y+i, z+i);
        }
        printf("Case #%d: %.8lf\n", t, (std::max(std::max(x[0], x[1]), x[2]) - std::min(std::min(x[0], x[1]), x[2])) / 6);
    }
}

