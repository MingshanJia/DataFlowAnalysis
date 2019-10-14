#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

#define file "B-large"

const int N = 100;

int a[N];

int main() {
	
	freopen(file".in", "r", stdin);
	freopen(file".out", "w", stdout);


	int t;
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++) {
		long long d, k, n;
		scanf("%lld%lld%lld", &d, &k, &n);
		
		k--;

		if (k % 2 == 0) {

			long long p = (k + n) % d;
			long long p1 = (p - 1 + d) % d;
			long long p2 = (p + 1) % d;

		  printf("Case #%d: %lld %lld\n", tt + 1, (p2 + n) % d + 1, (p1 + n) % d + 1);
		} else {
			long long p = (k - n + d * n) % d;
			long long p1 = (p - 1 + d) % d;
			long long p2 = (p + 1) % d;

		  printf("Case #%d: %lld %lld\n", tt + 1, (p2 - n + d * n) % d + 1, (p1 - n + d * n) % d + 1);
		}

	}


  return 0;
}