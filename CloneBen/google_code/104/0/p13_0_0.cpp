#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <list>
#include <map>
#include <set>
#include <cmath>
#include <string>
#include <queue>
#include <ext/hash_map>
#include <ext/hash_set>

using namespace std;
typedef pair<int,int> PI;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<PI> vii;

#define REP(i,n)	for(int i=0,_n=(n);i<_n;++i)
#define FOR(i,s,k)	for(int i=(s),_k=(k);i<=_k;++i)
#define FORD(i,s,k)	for(int i=(s),_k=(k);i>=_k;--i)
#define FORE(it,q)	for(__typeof((q).begin()) it=(q).begin();it!=(q).end();++it)
#define FORED(it,q) for(__typeof((q).rbegin())it=(q).rbegin();it!=(q).rend();++it)
#define SIZE(x)     x.size()
#define ALL(v)      v.begin(),v.end()
#define SE          second
#define FI          first
#define pb          push_back

int main()
{
    int N;
    int n,A,B,C,D,x0,y0,M;
    int ile[3][3];
    scanf("%d",&N);
    FOR(cs,1,N) {
        scanf("%d%d%d%d%d%d%d%d",&n,&A,&B,&C,&D,&x0,&y0,&M);
        ll res = 0;
        REP(i,3) REP(j,3) ile[i][j] = 0;
        vii V;
        int x = x0, y = y0;
        ++ile[x%3][y%3];
        V.pb(PI(x,y));
        FOR(i,1,n-1) {
            x = (A*1ll*x%M + B) % M;
            y = (C*1ll*y%M + D) % M;
            ++ile[x%3][y%3];
            V.pb(PI(x,y));
        }
        REP(i,n) FOR(j,i+1,n-1) FOR(k,j+1,n-1) {
            if((V[i].FI + V[j].FI + V[k].FI)%3 == 0 &&
               (V[i].SE + V[j].SE + V[k].SE)%3 == 0)
                    ++res;
        }
        /*
        REP(i,3)REP(j,3)REP(k,3)REP(l,3) REP(p,3) REP(s,3) {
            if((i+k+p)%3==0 && (j+l+s)%3==0)
                res += ile[i][j]*1ll*ile[k][l]*ile[p][s];
        }
        REP(i,3)REP(j,3) res -= ile[i][j]*1ll*ile[i][j];
        */
        printf("Case #%d: %I64d\n", cs, res);
    }
}



