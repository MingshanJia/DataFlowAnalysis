#include <bits/stdc++.h>

using namespace std;

vector<int> pr;

int main() {
    int cntT;
    scanf("%d", &cntT);
    for (int test = 1; test <= cntT; ++test) {
        int n;
        scanf("%d", &n);
        pr.resize(2*n);
        vector <int> a, b;
        int ps = 0;
        for (int j = 0; j < 2*n; ++ j) {
            scanf("%d", &pr[j]);
            if ((int)b.size() > ps && b[ps] == pr[j]) {
                ++ps;
            } else {
                a.push_back(pr[j]);
                b.push_back(pr[j]*4/3);
            }    
        }
        printf("Case #%d: ", test);
        for (int j = 0; j < n; ++j) {
            printf("%d ", a[j]);
        }
        printf("\n");
    }
}