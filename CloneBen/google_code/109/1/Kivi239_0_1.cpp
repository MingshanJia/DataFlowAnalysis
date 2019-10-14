#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

#define file "A-large"
//"A-small-attempt1"

const int N = 1000;

long long a[N];
bool sale[N];


int main() {
	
	freopen(file".in", "r", stdin);
	freopen(file".out", "w", stdout);


	int t;
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++) {
		int n;
		scanf("%d", &n);
		for (int i = 0; i < 2 * n; i++) {
		 	scanf("%lld", &a[i]);
		}

		for (int i = 0; i < 2 * n; i++)
			sale[i] = true;

		for (int i = 0; i < 2 * n; i++) 
			if (sale[i]) {
			 	for (int j = i + 1; j < 2 * n; j++) {
			 		if (!sale[j]) continue; 
			 		
			 		
			 		if (a[j] / 4 * 3 == a[i]) {
			 			sale[j] =  false;
			 		  break;
			 		}
			 	 }
			}

		printf("Case #%d: ", tt + 1);
		for (int i = 0; i < 2 * n; i++)
			if (sale[i])
				printf("%lld ", a[i]);
		puts("");

	}


  return 0;
}