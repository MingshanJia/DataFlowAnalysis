#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
using namespace std;

int res[1000000 + 1];
vector<bool> button(10);

int go(int x) {
    if(res[x] > 0)
        return res[x];
    else if(res[x] < 0)
        return res[x];

    int ans = -1;
    for (int i = 2; i <= sqrt(x); i ++) {
        if(x / i * i == x) {
            int r1 = go(i);
            if(r1 < 0)
                continue;
            int r2 = go(x/i);
            if(r2 < 0)
                continue;
            int r = r1 + r2 + 1;
            if(ans < 0)
                ans = r;
            else
                ans = min(ans, r);
        }
    }
    res[x] = ans;
    return ans;
}

int solve(int x) {
    memset(res, 0, sizeof(res));
    for(int j = 1; j <= 9; j ++) {
        if(button[j])
            res[j] = 1;
        else
            res[j] = 0;
    }

    for(int i = 1; i <= x; i ++) {
        if(res[i] > 0 ) {
            for(int j = 0; j <= 9; j ++) {
                int v = i * 10 + j;
                if(button[j] && v <= x ) {
                    res[v] = res[i] + 1;
                }
            }
        }
    }
    return go(x);
}

int main() {
    int caseNum = 0;
    cin >> caseNum;
    for(int c = 1; c <= caseNum; c ++) {
        int x, v;
        for(int i = 0; i <= 9; i ++) {
            cin >> v;
            button[i] = bool(v);
        }
        cin >> x;
        int ans = solve(x);
        printf("Case #%d: ", c);
        if(ans < 0)
            cout << "Impossible\n";
        else
            cout << ans + 1 << endl;
    }
}
