#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cassert>
using namespace std;
typedef long long ll;

#define REP(i,n) for (int i=0; i<(int)(n); ++i)
#define FOR(i,k,n) for (int i=(k); i<(int)(n); ++i)
#define FOREQ(i,k,n) for (int i=(k); i<=(int)(n); ++i)
#define FORIT(it,c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)

#define SZ(v) (int)((v).size())
#define MEMSET(v,h) memset((v),(h),sizeof(v))
#define FIND(m,w) ((m).find(w)!=(m).end())

string s[120];

void solve_small() {
    int N,M; cin>>N>>M;
    REP(y, N) cin>>s[y];
    int to[N*M][2];
    REP(y, N) REP(x, M) {
        int ay0=y, ax0=x, ay1=y, ax1=x;
        if (s[y][x]=='-') ax0++, ax1--;
        if (s[y][x]=='|') ay0++, ay1--;
        if (s[y][x]=='\\') ax0++, ay0++, ax1--, ay1--;
        if (s[y][x]=='/')  ax0++, ay0--, ax1--, ay1++;
            // ugly
        ay0=(ay0+N)%N;
        ax0=(ax0+N)%M;
        ay1=(ay1+N)%N;
        ax1=(ax1+N)%M;
        to[y*M+x][0] = ay0*M+ax0;
        to[y*M+x][1] = ay1*M+ax1;
    }
        // brute force
    int res=0;
    REP(bit, 1<<(N*M)) {
        set<int> st;
        REP(i, N*M) {
            int val = to[i][(bit>>i)&1];
            if (FIND(st, val)) goto SKIP;
            st.insert(val);
        }
        res++;
SKIP:;
    }
    printf("%d\n", res);
}

int main()
{
    int T; scanf("%d", &T);
    while (T--) {
        static int test = 1;
        printf("Case #%d: ",test++);
        solve_small();
    }
}
