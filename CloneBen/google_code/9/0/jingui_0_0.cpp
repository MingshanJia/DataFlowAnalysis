#include <iostream>
#include <cstdio>
#include <cstdlib>
#define ll long long
using namespace std;
ll c[501][501], f[501][501];
int modN = 1000000007;
void init(){
	int i, j, k;
	c[0][0] = 1;
	for (i = 1; i <= 200; i ++) {
		c[i][0] = 1;
		for (j = 1; j <= 200; j ++)
            c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % modN;
	}
	for (i = 1; i <= 200; i ++)
        f[1][i] = 1;
	for (i = 2; i <= 200; i ++)
		for (j = i; j <= 200; j ++) {
			for (k = 1; k <= j - i + 1; k ++)
				f[i][j] = (f[i][j] + f[i - 1][j - k] * c[j][k]) % modN;
		}
}
int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int n,m;
    int t,T=0;
    init();
	cin >> t;
	while (t --) {
		printf("Case #%d: ", ++T);
		cin >> n >> m;
		cout << f[n][m] << endl;
	}
	return 0;
}
