#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <set>
#include <queue>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;


long long f[4111];
map<string, int> p;
int n, m;

void work() {
    scanf("%d%d", &n, &m);
    p.clear();
    memset(f, 0, sizeof(f));
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        sort(s.begin(), s.end());
        //p[s] = 1;
        if (p[s] == 0) p[s] = 1;
        else p[s] += 1;
    }
    for (int cs = 0; cs < m; ++cs) {
        string s;
        cin >> s;
        memset(f, 0, sizeof(f));
        f[0] = 1;
        int len = s.size();
        for (int i = 1; i <= len; ++i) {
            string tmps = ""; 
            for (int j = 1; j <= 20; ++j) {
                tmps += s[i-j];
                sort(tmps.begin(), tmps.end());
                if (p[tmps]) {
                    f[i] += f[i-j]*p[tmps];
                    f[i] %= 1000000007;
                }

            }

        }
        printf("%lld", f[len]);
        printf(cs == m-1? "\n" : " ");
    }

}

int main() {
    freopen("C-small-attempt1.in", "r", stdin);
    freopen("C.out", "w", stdout);
    int TC;
    scanf("%d", &TC);
    for (int i  = 1; i <= TC; ++i) {
        printf("Case #%d: ", i);
        work();
    }
    return 0;
}