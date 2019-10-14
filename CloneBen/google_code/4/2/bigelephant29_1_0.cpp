#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
  int TN;
  scanf("%d", &TN);
  for(int casen = 1 ; casen <= TN ; casen++) {
    printf("Case #%d: ", casen);
    int n, m;
    scanf("%d %d", &n, &m);
    int ans1 =  n * m, ans2 = 0;
    if( n < m ) swap(n, m);
    for(int i = 0 ; i < n ; i++) {
      for(int j = 0 ; j < m ; j++) {
        if( ((i - j) % 3 + 3) % 3 == 2 ) ans1--;
        if( i % 3 == 2 && j % 3 == 2) ans2++;
        else if(i % 3 != 2 && j % 3 != 2) ans2++;
      }
    }
    printf("%d\n", max(ans1, ans2));
  }
  return 0;
}
