#include <cmath>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <utility>
#include <iomanip>
#define pb push_back
#define mp make_pair
#define f first
#define s second
using namespace std;



long double a[100], b[100];

int main() {
    freopen("b.in", "r", stdin);
    freopen("b.out", "w", stdout);
    int test;
    cout.precision(10);
    scanf("%d", &test);
    for(int col = 1; col <= test; col++) {
        int n;
        cin >> n;
        for (int i = 0; i < 2*n; i++) {
            cin >> a[i];
            //cout << a[i] << " ";
        }
        //cout << endl;
        sort(a, a + n + n);
        long double ans = 1;
        for (int i = 0; i < n; i++) {
            b[i] = a[i] * a[2 * n - 1 - i];
            //cout << a[i] << " * " << a[2 * n - 1 - i] << endl;
            ans *= 1 - b[i];
            //cout << "ans = " << ans << endl;
        }
        //cout.precision(10)
        printf("Case #%d: %.10lf\n", col, (double)ans);

        //cout << "Case #" << col << ": " <<   setprecision(10) << ans << endl;

    }

    return 0;
}