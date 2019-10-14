#include <map>
#include <iostream>
#include <deque>
#include <list>
#include <cstdio>
#include <algorithm>
#include <set>
#include <vector>
#include <queue>
#include <stack>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <ctime>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define SIZE(c) ((int)((c).size()))
#define FOREACH(i,c) for(__typeof((c).begin()) i =(c).begin();i!=(c).end();++i)
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef long long LL;
typedef long double LD;

#define st first
#define nd second
#define mp make_pair
#define pb push_back

const int NIL = (-1);

const int N = 100;
const int B = 100*1000;
const long long INF = 1000000000000000000LL;

int n;
long long b[N],m;
long long d[B];
typedef pair<long long, int> P;
long long l;

void scase() {
    scanf("%lld%d",&l,&n);
    m = 0;
    REP(i,n) {
        scanf("%lld",&b[i]);
        m = max(m,b[i]);
    }
    for(int i=0;i<m;i++) d[i] = INF;
    d[0] = 0;
    priority_queue<P> q;
    q.push(P(0,0));
    while(!q.empty()) {
        int u = q.top().second;
        long long ud = -q.top().first;
        q.pop();
        if (ud != d[u]) continue;
        REP(i,n) {
            int v = (u+b[i])%m;
            if (d[v] > d[u] + m - b[i]) {
                d[v] = d[u] + m - b[i];
                q.push(P(-d[v],v));
            }
        }
    }
    long long t = l % m;
    if (d[t]==INF) 
        printf("IMPOSSIBLE\n");
    else {
        printf("%lld\n",(l+d[t])/m);
    }
}

int main() {
    int j;
    scanf("%d",&j);
    for(int i=1;i<=j;i++) {
        printf("Case #%d: ",i);
        scase();
    }
    return 0;
}

