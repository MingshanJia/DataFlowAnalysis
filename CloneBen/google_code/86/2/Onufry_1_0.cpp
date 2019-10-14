#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <cstdio>
using namespace std;

/* PREWRITTEN CODE */

#define ALL(x) x.begin(),x.end()
#define PB push_back


#define FOR(i,p,k) for (int i=p; i<k; i++)
#define REP(i,n) for (int i=0; i<n; i++)
#define SIZE(x) (int)x.size()
/* COMPETITION CODE */
int L,P,C;
int main () {
  int number_of_tests;
  scanf("%d", &number_of_tests);
  REP (test_number, number_of_tests) {
    printf("Case #%d:", test_number+1);
		scanf("%d %d %d", &L, &P, &C);
		int cc = C;
		int res = 0;
		while (L * cc < P) {
			cc *= cc;
			res += 1;
		}
    printf(" %d\n", res);
  }
  return 0;
}

