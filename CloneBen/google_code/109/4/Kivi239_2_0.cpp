#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

#define file "C-small-1-attempt0"

const int N = 600;
const int mod = (1e9) + 7;

long long C[N][N];

long long power(int a, int p) {
  long long ans = 1;
  for (int i = 0; i < p; i++) {
    ans *= a;
    ans %= mod;
  }

  return ans;
}

void init() {
	for (int i = 0; i < N; i++)
		C[i][0] = 1;

	for (int i = 1; i < N; i++)
		for (int j = 1; j <= i; j++) {
			C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
		  C[i][j] %= mod;
		}

}

int main() {
	
	freopen(file".in", "r", stdin);
	freopen(file".out", "w", stdout);


	init();

	int t;
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++) {
	  int c, v, l;
	  scanf("%d%d%d", &c, &v, &l);

	  long long ans = 0;
	  printf("Case #%d: ", tt + 1);
	  for (int i = 0; i <= l / 2; i++) {
	  	ans += (((C[l - i][i] * power(c, i)) % mod) * power(v, l - i)) % mod;
	  	ans %= mod;
	    cerr << ans << endl;
	  }

	  printf("%lld\n", ans);
	}


  return 0;
}