#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <sstream>
#include <queue>
#include <bitset>
#include <utility>
#include <list>
#include <numeric>

#include <cstdio>
#include <cmath>
#include <cctype>
using namespace std;

#define REP(i,n) for(__typeof(n) i=0; i<(n); ++i)
#define FOR(i,a,b) for(__typeof(b) i=a; i<(b); ++i)
#define FOREACH(it,c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); ++it)

typedef long long ll;
typedef pair<int, int> PI;
int main() {
    int t; scanf("%d", &t);
    REP(sd,t)
    {
        int k, n;
        scanf("%d %d", &k, &n);
        vector<int> d(n);
        REP(i,n) scanf("%d", &d[i]);

        vector<int> a;
        REP(i,k) a.push_back(i);
        int u = 0;
        vector<int> por, in(k);
        REP(i,k)
        {
            u = (u + i) % a.size();
            por.push_back(a[u]);
            a.erase(a.begin() + u);
        }
        REP(i,k) in[por[i]] = i;

        printf("Case #%d:", sd+1);
        REP(i,n) printf(" %d", in[d[i] - 1] + 1);
        printf("\n");
    }
}
