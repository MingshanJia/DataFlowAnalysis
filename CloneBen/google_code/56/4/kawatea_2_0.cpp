#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int dp[16][1 << 15];

int main()
{
    int t, i;
    
    scanf("%d", &t);
    
    for (i = 0; i < t; i++) {
        int n, ans = 1e9, j, k, l;
        vector <pair<int, int> > v;
        map <int, int> mp;
        map <int, int>::iterator it;
        
        scanf("%d", &n);
        
        for (j = 0; j < n; j++) {
            int x;
            char s[2];
            
            scanf("%s %d", s, &x);
            
            if (s[0] == 'E') {
                v.push_back(make_pair(0, x));
            } else {
                v.push_back(make_pair(1, x));
            }
            
            if (x != 0) mp[x]++;
        }
        
        for (it = mp.begin(), j = 0; it != mp.end(); it++, j++) it->second = j;
        
        mp[0] = -1;
        
        for (j = 0; j < v.size(); j++) v[j].second = mp[v[j].second];
        
        for (j = 0; j <= v.size(); j++) {
            for (k = 0; k < (1 << v.size()); k++) {
                if (j == 0) {
                    dp[j][k] = 1;
                } else {
                    dp[j][k] = 0;
                }
            }
        }
        
        for (j = 0; j < v.size(); j++) {
            for (k = 0; k < (1 << v.size()); k++) {
                if (dp[j][k] == 0) continue;
                
                if (v[j].first == 0) {
                    if (v[j].second == -1) {
                        for (l = 0; l < v.size(); l++) {
                            if ((k >> l) & 1) continue;
                            
                            dp[j + 1][k ^ (1 << l)] = 1;
                        }
                    } else {
                        if (((k >> v[j].second) & 1) == 0) dp[j + 1][k ^ (1 << v[j].second)] = 1;
                    }
                } else {
                    if (v[j].second == -1) {
                        for (l = 0; l < v.size(); l++) {
                            if ((k >> l) & 1) dp[j + 1][k ^ (1 << l)] = 1;
                        }
                    } else {
                        if ((k >> v[j].second) & 1) dp[j + 1][k ^ (1 << v[j].second)] = 1;
                    }
                }
            }
        }
        
        for (j = 0; j < (1 << v.size()); j++) {
            if (dp[n][j] == 1) ans = min(ans, __builtin_popcount(j));
        }
        
        if (ans == 1e9) {
            printf("Case #%d: CRIME TIME\n", i + 1);
        } else {
            printf("Case #%d: %d\n", i + 1, ans);
        }
    }
    
    return 0;
}
