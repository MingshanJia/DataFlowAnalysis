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
    freopen("A-large.in","r",stdin);
    freopen("out.txt","w",stdout);
#endif
}

/* Input opener ends */

#define N 206

char s[10][10] = { "1111110", "0110000" , "1101101", "1111001", "0110011", "1011011", "1011111", "1110000", "1111111", "1111011"};
int d[10];


int main() {
    // input();
    int t, tst = 1; S(t);

    F(i,0,10) {
        d[i] = 0;
        F(j,0,7) {
            d[i] = d[i]*2 + s[i][j]-'0';
        }
        // cout << i << " "<<d[i] << endl;
    }

    while ( t-- ) {
        
        int n; S(n);
        vector<int> v;

        F(i,0,n) {
            char ss[12]; scanf("%s",ss);
            int x = 0;
            F(j,0,7) x=x*2+ss[j]-48;
            v.pb(x); //cout << x << endl;
        }

        bool poss = 1;
        int ans = -1;

        F(i,0,128) {
            bool can = 1;
            F(j,0,n) if ( (v[j]&i) > 0 ) can = 0;
            if ( !can ) continue;
            F(first,0,10) {
                int dig = first;
                bool can = 1;
                F(j,0,n) {
                    if ( (d[dig]&(~i)) != v[j] ) { can = 0; break; }
                    dig--; if ( dig < 0 ) dig = 9;
                }
                if ( can ) {
                    int get = (d[dig]&(~i));
                    if ( ans == -1 || ans == get ) ans = get;
                    else poss = 0;
                }
            }
        }

        char res[10];
        F(i,0,7) {
            res[6-i] = (((ans&(1<<i))>0)?'1':'0');
        } res[7] = '\0';
        if ( poss && ans >= 0 ) printf("Case #%d: %s\n", tst++,res);
        else printf("Case #%d: ERROR!\n", tst++);
        
    }
    return 0;
}