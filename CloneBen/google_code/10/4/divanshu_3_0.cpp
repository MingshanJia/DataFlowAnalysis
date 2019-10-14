/* Divanshu Garg */

#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <climits>
#include <cctype>
#include <cassert>
#include <complex>

using namespace std;

#define ull unsigned long long
#define ill long long int
#define pii pair<int,int>
#define pb(x) push_back(x)
#define F(i,a,n) for(int i=(a);i<(n);++i)
#define REP(i,a,n) for(i=(a);i<(n);++i)
#define FD(i,a,n) for(int i=(a);i>=(n);--i)
#define FE(it,x) for(it=x.begin();it!=x.end();++it)
#define V(x) vector<x>
#define S(x) scanf("%d",&x)
#define Sl(x) scanf("%llu",&x)
#define M(x,i) memset(x,i,sizeof(x))
#define debug(i,sz,x) F(i,0,sz){cout<<x[i]<<" ";}cout<<endl
#define MAX(a,b) ((a)>(b)?(a):(b))
ill ABS(ill a) { if ( a < 0 ) return (-a); return a; }
#define fr first
#define se second

/* Relevant code begins here */

/* Input from file or online */

void input() {
#ifndef ONLINE_JUDGE
    // freopen("input.txt","r",stdin);
    freopen("D-small-attempt1.in","r",stdin);
    freopen("out.txt","w",stdout);
#endif
}

/* Input opener ends */

#define pll pair<ill,ill>
ill a[55];

int main() {
    // input();
    int t, tst = 1; S(t);
    while ( t-- ) {
        printf("Case #%d: ", tst++);
        ill n,m; Sl(n); Sl(m);
        F(i,0,n) { Sl(a[i]); a[i] = (1LL<<a[i]); }
        sort(a,a+n);
        reverse(a,a+n);
        int ans = n;
        F(i,1,n) {
            // F(j,1,n+1) {
                multiset<pll> s;
                multiset<pll>::iterator it;
                F(j,0,i) s.insert(pll(m,m));
                bool poss = 1;
                F(k,0,n) {
                    bool could = 0;
                    FE(it,s) {
                        if ( it->fr >= a[k] && it->se >= a[k] ) {
                            vector<pll> tmp;
                            if ( (it->fr)-a[k] > 0 ) tmp.pb(pll((it->fr)-a[k],it->se));
                            if ( (it->se)-a[k] > 0 ) tmp.pb(pll(a[k],(it->se)-a[k]));
                            s.erase(it);
                            F(i,0,tmp.size()) s.insert(tmp[i]);
                            could = 1;
                            break; 
                        }
                    }
                    if (!could ) {poss=0; break;}
                }
                if ( poss ) { ans = i; break; }
            // }
        }
        printf("%d\n", ans);
    }
    return 0;
}