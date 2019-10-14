#include<bits/stdc++.h>
using namespace std;
 
#define LL long long int
#define ULL unsigned LL
#define PII pair<int,int>
#define PB push_back
#define MP make_pair
#define INF 1000000000
#define MOD 1000000007
 
double val[401][401][401];
void pour(int lev) {
    if (lev > 400)
        return;
    int i, j;
    for (i = 1; i <= lev; i++) {
        for (j = 1; j <= i; j++) {
            if (val[lev][i][j] > 250) {
                double left = val[lev][i][j] - 250;
                val[lev][i][j] = 250;
                val[lev + 1][i][j]  += left / 3.0;
                val[lev + 1][i + 1][j] += left / 3.0;
                val[lev + 1][i + 1][j + 1] += left / 3.0;
            }
        }
    }
    pour(lev + 1);
}
int main() {
    int t, i, j, k, b, l, n, cs = 0;
    cin >> t;
    while (t--) {
        for (i = 0; i <= 400; i++)
            for (j = 0; j <= 400; j++) 
                for (k = 0; k <= 400; k++)
                    val[i][j][k] = 0;
        cin >> b >> l >> n;
        val[1][1][1] = b * 750;
        pour(1);
        int cnum = 1;
        for (i = 1; i <= 400; i++) {
            for (j = 1; j <= i; j++) {
                if (cnum == n)
                    break;
                cnum ++;
            }
            if (j != i + 1)
                break;
        }
        printf("Case #%d: %.10lf\n", ++cs, val[l][i][j]);
    }
    return 0;
}

