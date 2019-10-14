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

void scase() {
    
    map<int,int> M;

    int c;
    scanf("%d",&c);
    while(c--) {
        int v,p;
        scanf("%d%d",&p,&v);
        M[p] += v;
    }
    
    int moves = 0;

    for(;;) {
        int x, n = (-1);
        FOREACH(i,M) if (i->second > 1) {
            x = i->first;
            n = i->second;
            break;
        }
        if (n<0) break;
        moves += (n/2);
        M[x-1] += (n/2);
        M[x+1] += (n/2);
        M[x] = M[x]%2;
        
    }

    printf("%d\n",moves);
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

