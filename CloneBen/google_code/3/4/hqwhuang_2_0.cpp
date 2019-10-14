#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <math.h>
#include <stdlib.h>
#include <cstring>
#include <stdio.h>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
//#include <unordered_set>
//#include <unordered_map>
//#include <sstream>
#include <set>
#include <map>
//#include <climits>
//#include <random>
//#include <deque>

using namespace std;

#define INF 2139062143
#define LINF 9187201950435737471
#define mem(a,v) memset(a,v,sizeof(a))
#define maxn 1005
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define red(i, a, b) for (int i = (a); i >= (b); --i)
#define pb push_back
#define eps 1e-7
#define ll long long
#define mp make_pair
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
typedef pair<int,int> pp;

double x[3],y[3],z[3];
int main() {
    ios::sync_with_stdio(false);cout.setf(ios::fixed); cout.precision(20);
//    freopen("/Users/huangqingwei/Documents/C++ workspace/codeforces/input.txt", "r",stdin);
    freopen("/Users/huangqingwei/Downloads/C-small-attempt0.in-2.txt", "r",stdin);
    freopen("/Users/huangqingwei/Documents/C++ workspace/codeforces/output.txt", "w",stdout);
    int T;
    cin>>T;
    rep(t,1,T)
    {
        double maxx = -maxn,minn = maxn;
        rep(i,0,2)
        {
            cin>>x[i]>>y[i]>>z[i];
            maxx = max(maxx,x[i]);
            minn = min(minn,x[i]);
        }
        cout<<"Case #"<<t<<": "<<(maxx-minn)/6<<'\n';
    }

    return 0;
}





















