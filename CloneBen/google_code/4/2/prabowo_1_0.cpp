#include <bits/stdc++.h>
using namespace std;

bool seat[222][222];

int n, m;

int Main() {    
    scanf ("%d %d", &n, &m);
    
    if (n <= 2) return 0 * printf ("%d\n", n * ((m - 1) / 3 * 2 + 1 + ((m-1) % 3 > 0)));
    else if (m <= 2) return 0 * printf ("%d\n", m * ((n - 1) / 3 * 2 + 1 + ((n - 1) % 3 > 0)));
    
    int ans = 0;
    for (int i=0; i<n; i++) for (int j=0; j<m; j++) ans += seat[i][j];
    printf("%d\n", ans);
    return 0;
}

int main() {
    memset(seat, 1, sizeof seat);
    for (int i=2; i<205; i+=3) for (int j=0; j<100; j++)
        if (i-j >= 0 && i-j < 100) seat[i-j][j] = 0;

    int t;
    scanf ("%d", &t);
    for (int tc=0; tc<t; tc++) {
        printf ("Case #%d: ", tc+1);
        Main();
    }
    return 0;
}