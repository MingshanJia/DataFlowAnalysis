#include <algorithm>
#include <iostream>
#include <memory.h>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <cmath>
#include <map>
using namespace std;

    

#define CLR(a, b) memset(a, b, sizeof(a))

const int maxn = 4444;

char words[444][33];
int dp[maxn];

int cnt[33];

char ch[maxn];

int chd[444 * 33][22], tot, val[444 * 33];

void ins() {
    int q = 0;
    for(int i = 0; i < 26; i ++) {
        int p = cnt[i];
        if(!chd[q][p]) {
            CLR(chd[tot], 0);
            val[tot] = 0;
            chd[q][p] = tot ++;
        }
        q = chd[q][p];
    }
    val[q] ++;
}

int ask() {
    int q = 0;
    for(int i = 0; i < 26; i ++) {
        int p = cnt[i];
        if(!chd[q][p]) {
            return 0;
        }
        q = chd[q][p];
    }
    return val[q];
}

const int MOD = 1000000007;

int main() {
    int T, S, V, cas = 1;
    freopen("/Users/daidaidaiyi/Downloads/C-large.in","r",stdin);
    freopen("./out.txt","w",stdout);
    scanf("%d", &T);
    while(T --) {
        scanf("%d%d", &V, &S);
        tot = 1; CLR(chd[0], 0);
        for(int i = 0; i < V; i ++) {
            scanf("%s", words[i]);
            int l = strlen(words[i]);
            CLR(cnt, 0);
            for(int j = 0; j < l; j ++)
                cnt[words[i][j] - 'a'] ++;
            ins();
        }
        printf("Case #%d:", cas ++);
        while(S --) {
            scanf("%s", ch);
            int l = strlen(ch);
            CLR(dp, 0);
            dp[0] = 1;
            for(int i = 1; i <= l; i ++) {
                CLR(cnt, 0);
                for(int j = 1; j <= min(i, 20); j ++) {
                    cnt[ch[i - j] - 'a'] ++;
                    (dp[i] += 1ll * dp[i - j] * ask() % MOD) %= MOD;
                }
            }
            printf(" %d", dp[l]);
        }
        puts("");
    }
    return 0;
}

