#include <cstdio>
#include <algorithm>

using namespace std;

long long sum[1000001];

int main()
{
    int t, i;
    
    scanf("%d", &t);
    
    for (i = 0; i < t; i++) {
        int n, p, q, r, s, j;
        long long ans = 0;
        
        scanf("%d %d %d %d %d", &n, &p, &q, &r, &s);
        
        sum[0] = 0;
        
        for (j = 0; j < n; j++) {
            sum[j + 1] = sum[j] + ((long long)j * p + q) % r + s;
        }
        
        for (j = 0; j < n; j++) {
            int l, r, m;
            
            l = j, r = n, m = (l + r) / 2;
            
            while (r - l > 1) {
                if (sum[m + 1] - sum[j] <= sum[n] - sum[m + 1]) {
                    l = m;
                    m = (l + r) / 2;
                } else {
                    r = m;
                    m = (l + r) / 2;
                }
            }
            
            ans = max(ans, sum[n] - max(sum[j], max(sum[r + 1] - sum[j], sum[n] - sum[r + 1])));
            if (r > j) ans = max(ans, sum[n] - max(sum[j], max(sum[r] - sum[j], sum[n] - sum[r])));
        }
        
        printf("Case #%d: %.12lf\n", i + 1, (double)ans / sum[n]);
    }
    
    return 0;
}
