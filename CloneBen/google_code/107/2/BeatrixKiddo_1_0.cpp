#include <bits/stdc++.h>
using namespace std;
int a[110];
int main(){
    
    int t;
    scanf("%d", &t);
    for(int test = 1; t--; test++) {
        printf("Case #%d: ", test);

        int l;
        scanf("%d", &l);
        long long childs = 0, mx = 0;
        for(int i = 0; i < l; i++) {
            long long n, e;
            scanf("%lld %lld\n", &n, &e);
            childs -= n * e;
            childs = max(0ll, childs);
            mx = max(mx, e);
            childs += n;
        }
        long long ans = max(mx + 1, childs);
        printf("%lld\n", ans);
    }

}