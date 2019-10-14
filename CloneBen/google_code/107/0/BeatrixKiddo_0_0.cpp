#include <bits/stdc++.h>
using namespace std;
int a[110];
int main(){
    
    int t;
    scanf("%d", &t);
    for(int test = 1; t--; test++) {
        printf("Case #%d: ", test);

        int n;
        scanf("%d", &n);
        for(int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        sort(&a[0], &a[n]);
        int ans = 1e9;
        do {
            int cur = 0;
            for(int i = 0; i < n; i++) {
                int nearest = min(i, n - 1 - i);
                cur += (nearest - a[i]) * (nearest - a[i]);
            }
            ans = min(ans, cur);
        } while(next_permutation(&a[0], &a[n]));
        printf("%d\n", ans);
    }

}