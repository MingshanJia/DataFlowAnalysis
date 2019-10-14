#include <iostream>
#include <fstream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <cmath>

using namespace std;



void do_case(const int cn) {
    const double PI = acos(-1);
    int N,K;
    cin >> N >> K;
    vector<pair<long long,long long> > vp(N);
    vector<vector<long long> > memo(N+1, vector<long long>(N+1, 0));
    for(int i=0;i<N;++i) {
        cin >> vp[i].first >> vp[i].second;
    }
    sort(vp.begin(), vp.end());
    reverse(vp.begin(), vp.end());
    for(int at=N-1;at>=0;--at) {
        for(int left=N;left>=0;--left) {
            long long out = 0;
            out = max(out, memo[at+1][left]);
            if(left > 0) {
                out = max(out, 2*vp[at].first*vp[at].second + memo[at+1][left-1]);
            }
            memo[at][left] = out;
        }
    }
    long long out = 0;
    for(int i=0;i<N;++i) {
        out = max(out, memo[i+1][K-1] + (vp[i].first*vp[i].first) + (2*vp[i].first*vp[i].second));
    }
    printf("Case #%d: %.12lf\n", cn, PI*out);
}

int main(int argc, char **argv)
{
    int CASES;
    cin >> CASES;
    for(int cn=1;cn<=CASES;++cn) {
        do_case(cn);
    }

    return 0;
}
