#include <iostream>
#include <cstdio>
#include <cstdlib>
#define ll long long
using namespace std;
double res0[1001][1001];
double res1[1001][1001];
int B,L,N;

void solve(){
    int i, j, k;
    res0[1][1] = B * 750;
    for (i = 1; i < L; i ++) {

        for (j = 1; j <= i + 1; j ++)
            for (k = 1; k <= j; k ++)
                res1[j][k] = 0;

        for (j = 1; j <= i; j ++)
            for (k = 1; k <= j; k ++)
                if (res0[j][k] > 250) {
                    res1[j][k] += (res0[j][k] - 250) / 3;
                    res1[j + 1][k] += (res0[j][k] - 250) / 3;
                    res1[j + 1][k + 1] += (res0[j][k] - 250) / 3;
                    res0[j][k] = 250;
                }

        for (j = 1; j <= i + 1; j ++)
            for (k = 1; k <= j; k ++)
                res0[j][k] = res1[j][k];
    }

    for (i = 1; i <= L; i ++)
        if (N <= i) break;
        else N-= i;
    if (res0[i][N] > 250)
        res0[i][N] = 250;
    printf("%.7lf\n", res0[i][N]);
}
int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int t, T = 0;
	cin >> t;
	while (t --) {
		printf("Case #%d: ", ++T);
		cin >> B >> L >> N;
		solve();
	}
	return 0;
}
