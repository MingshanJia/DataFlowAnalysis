#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <stdlib.h>
#include <assert.h>
#include <vector>
#include <string>
#include <set>
#include <map>
using namespace std;
typedef long long lint;

const int MAX_N = 5050;
int a[MAX_N];

int main() {
	int n, T, icase = 1;
	scanf("%d", &T);
	while(T--){
		scanf("%d", &n);
		fill(a, a + MAX_N, 0);
		for(int i = 0; i < n; i++){
			int l, r;
			scanf("%d%d", &l, &r);
			if(l > r) swap(l, r);
			for(int j = l; j <= r; j++) a[j]++;
		}
		int p, x;
		scanf("%d", &p);
		printf("Case #%d:", icase++);
		while(p--){
			scanf("%d", &x);
			printf(" %d", a[x]);
		}
		puts("");
	}
	return 0;
}
