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



int main(){
    desperate_optimization(10);
    clock_t CLOCK;
    CLOCK = clock();
    int ntc;
    cin>>ntc;
    for(int tc = 1;tc <= ntc;tc++) {
        int ans = -1;
        int n;
        cin>>n;
        string s;
        cin>>s;
        int mid = (n + 1) / 2;
        int tot = 0;
        for(int i = 0;i < n;i++) {
            tot += s[i] - '0';
            if(i >= mid) tot -= s[i - mid] -'0';
            if(i + 1 >= mid) ans = max(ans,tot);
        }
        cout<<"Case #"<<tc<<": "<<ans<<endl;
    }
    
    cerr<<"PROCESSED TIME "<<(clock() - CLOCK) * 1.0 / (1.0 * CLOCKS_PER_SEC)<<endl;
    return 0;
}


