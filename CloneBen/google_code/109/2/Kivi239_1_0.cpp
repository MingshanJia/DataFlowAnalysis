#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

#define file "B-small-attempt0"

const int N = 100;

int a[N];

int main() {
	
	freopen(file".in", "r", stdin);
	freopen(file".out", "w", stdout);


	int t;
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++) {
		int d, k, n;
		scanf("%d%d%d", &d, &k, &n);
		for (int i = 0; i < d; i++)
			a[i] = i + 1;


		for (int i = 0; i < n; i++) {
			if (i % 2 == 0) {
			 	for (int j = 0; j < d / 2; j++) 
			 		swap(a[2 * j], a[2 * j + 1]);
			}
			else {
			  for (int j = 1; j < d / 2; j++) 
			 		swap(a[2 * j], a[2 * j - 1]);
			 	swap(a[0], a[d - 1]);
			}

		}


		for (int i = 0; i < d; i++)
			if (a[i] == k) {
			 	printf("Case #%d: ", tt + 1);
			 	printf("%d %d\n", a[(i + 1) % d], a[(i + d - 1) % d]);
			}

	}


  return 0;
}