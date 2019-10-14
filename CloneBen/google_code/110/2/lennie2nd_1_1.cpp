#include <stdio.h>
#include <string>
#include <iostream>
#include <math.h>

using namespace std;
int tc;
int k, v;


int main() {
  scanf("%d", &tc);
  for (int t = 0; t < tc; t++) {
    scanf("%d %d", &k, &v);
    unsigned long long ret = pow(v+1, 3);
    for (int i = v+1; i <= k; i++) {
       ret += pow(v, 2) * 3;
       ret += v * 3;
       ret += 1;
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
 2, 1, 1

 1, 2, 2
 2, 1, 2
 2, 2, 1

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
