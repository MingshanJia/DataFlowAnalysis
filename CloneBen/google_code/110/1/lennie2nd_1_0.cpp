#include <stdio.h>
#include <string>
#include <iostream>
#include <math.h>

using namespace std;
int tc;
int k, v;

int abs(int a, int b) {
  if (a > b)
    return a-b;
  else
    return b-a;
}
int main() {
  scanf("%d", &tc);
  for (int t = 0; t < tc; t++) {
    scanf("%d %d", &k, &v);

    unsigned long long ret = 0;
    for (int i = 0; i <= k; i++) {
      for (int j = 0; j <= k; j++) {
        for (int l = 0; l <= k; l++) {
          if ((abs(l - i) > v) || (abs(l - j) > v) || (abs(j - i) > v))
	    continue;
          ret += 1;

        }
      }
    }
    printf("Case #%d: %lld\n", t+1, ret);
  }
}


/*
k = 2, v = 1
(0, 0, 1) (0, 0, 0)
(0, 1, 1),(0, 1, 0)
 1, 0, 0   1, 0, 1
 1, 1, 0   1, 1, 1

 1, 1, 2  
 1, 2, 1
 1, 2, 2
 2, 1, 1
 2, 1, 2
 2, 2, 2
 2, 2, 2

8

 0, 0, 0
 0, 0, 2
 0, 2, 0
 0, 2, 2
 2, 0, 0
 2, 0, 2
 2, 2, 0
 2, 2, 2

8

k = 2, v = 1
0, 0, 0
0, 0, 1
0, 1, 0
0, 1, 1


k = 3, v = 3
0, 1, 2, 3 
 

*/
