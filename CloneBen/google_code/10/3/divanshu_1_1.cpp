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
    freopen("B-large.in","r",stdin);
    freopen("out.txt","w",stdout);
#endif
}

/* Input opener ends */

#define N 106

int a[N][N];


int main() {
    // input();
    int t, tst = 1; S(t);
    while ( t-- ) {
        vector<int> col[N], row[N];
        char s[20];
        int n; S(n);
        scanf("%s",s);
        F(i,0,n) F(j,0,n) {
            S(a[i][j]);
            if ( a[i][j] == 0 ) continue;
            row[i].pb(a[i][j]);
            col[j].pb(a[i][j]);
        }

        printf("Case #%d:\n", tst++);

        if ( s[0] == 'd' ) {
            vector<int> c[N];
            F(i,0,n) {
                FD(j,col[i].size()-1,0) {
                    if ( j > 0 && col[i][j] == col[i][j-1] ) {
                        c[i].pb(col[i][j]+col[i][j-1]);
                        j--;
                    } else c[i].pb(col[i][j]);
                }
                c[i].resize(n);
                reverse(c[i].begin(),c[i].end());
            }
            F(i,0,n) {
                F(j,0,n) cout << c[j][i] << " ";
                cout << endl;
            }
        } else if ( s[0] == 'u' ) {
            vector<int> c[N];
            F(i,0,n) {
                F(j,0,col[i].size()) {
                    if ( j < col[i].size()-1 && col[i][j] == col[i][j+1] ) {
                        c[i].pb(col[i][j]+col[i][j+1]);
                        j++;
                    } else c[i].pb(col[i][j]);
                }
                c[i].resize(n);
            }
            F(i,0,n) {
                F(j,0,n) cout << c[j][i] << " ";
                cout << endl;
            }
        } else if ( s[0] == 'r' ) {
            vector<int> r[N];
            F(i,0,n) {
                // F(j,0,row[i].size()) cout << row[i][j] << " "; cout << endl;
                FD(j,row[i].size()-1,0) {
                    if ( j > 0 && row[i][j] == row[i][j-1] ) {
                        r[i].pb(row[i][j]+row[i][j-1]);
                        j--;
                    } else r[i].pb(row[i][j]);
                }
                r[i].resize(n);
                reverse(r[i].begin(),r[i].end());
            }
            F(i,0,n) {
                F(j,0,n) cout << r[i][j] << " ";
                cout << endl;
            }
        } else {
            vector<int> r[N];
            F(i,0,n) {
                F(j,0,row[i].size()) {
                    if ( j < row[i].size()-1 && row[i][j] == row[i][j+1] ) {
                        r[i].pb(row[i][j]+row[i][j+1]);
                        j++;
                    } else r[i].pb(row[i][j]);
                }
                r[i].resize(n);
            }
            F(i,0,n) {
                F(j,0,n) cout << r[i][j] << " ";
                cout << endl;
            }
        }

        
    }
    return 0;
}