#include <stdio.h>
#include <iostream>
#include <sstream>
#include <iomanip>

#include <algorithm>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <utility>

#include <math.h>
#include <complex>

#include <assert.h>
#include <time.h>

#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <bitset>
#define FI first
#define SE second
#define MP make_pair
#define PB push_back
#define endl '\n'
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

void desperate_optimization(int precision){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(precision);
}

const int N = 2 * 100000;
LL fct[N + 5];
LL po[N + 5];
LL inv[N + 5];
const LL MOD = 1e9 + 7;

LL fast(LL A,LL B) {
    LL ans = 1;
    while(B) {
        if(B & 1) ans = ans * A % MOD;
        A = A * A % MOD;
        B /= 2;
    }
    return ans;
}

void pre() {
    fct[0] = 1;
    for(LL i = 1;i <= N;i++) fct[i] = fct[i-1] * i % MOD;
    inv[N] = fast(fct[N], MOD - 2);
    for(LL i = N - 1;i >= 0;i--) inv[i] = inv[i + 1] * (i + 1) % MOD;
    po[0] = 1;
    for(int i = 1;i <= N;i++) po[i] = po[i-1] * 2 % MOD;
}

LL combin(int n,int r) {
    return fct[n] * inv[r] % MOD * inv[n - r] % MOD;
}

int main(){
    desperate_optimization(10);
    pre();
    clock_t CLOCK;
    CLOCK = clock();
    int ntc;
    cin>>ntc;
    for(int tc = 1;tc <= ntc;tc++) {
        int n,m;
        cin>>n>>m;
        n *= 2;
        LL ways = 0;
        for(int i = 0;i <= m;i++) {
            LL subways = combin(m,i) * po[i] % MOD * fct[n - i] % MOD;
            if(i % 2) ways = (ways + MOD - subways) % MOD;
            else ways = (ways + subways) % MOD;
        }
        cout<<"Case #"<<tc<<": "<<ways<<endl;
    }
    
    cerr<<"PROCESSED TIME "<<(clock() - CLOCK) * 1.0 / (1.0 * CLOCKS_PER_SEC)<<endl;
    return 0;
}


