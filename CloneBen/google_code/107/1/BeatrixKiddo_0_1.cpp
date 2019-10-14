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
        long long ans = 0;
        for(int i = 0, j = 0; i < n; i++) {
            ans += (a[i] - j) * (a[i] - j);
            if(i & 1) j++;
        }
        printf("%lld\n", ans);
    }

}