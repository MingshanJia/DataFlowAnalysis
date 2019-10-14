/*==================================================*\
 | Author: ziki
 | Created Time: 9/14/2013 9:11:35 AM
 | File Name: A.cpp
 | Description: 
\*==================================================*/
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>
#include <utility>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <string.h>

using namespace std;
using namespace rel_ops;

typedef long long int64;
typedef unsigned long long uint64;
const double pi=acos(-1.0);
const double eps=1e-11;
const int inf=0x7FFFFFFF;
template<class T> inline bool checkmin(T &a,T b){return b<a?a=b,1:0;}
template<class T> inline bool checkmax(T &a,T b){return b>a?a=b,1:0;}
template<class T> inline T sqr(T x){return x*x;}
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VII;
#define MP(A,B) make_pair(A,B)
#define PB(X) push_back(X)
#define mem(a,b) memset(a, b, sizeof(a))
#define clr(a) memset(a, 0, sizeof(a))
#define rep(i,n) for(int i=0; i<n; i++)
#define repit(i,v) for(typeof(v.begin()) i=v.begin(); i!=v.end(); i++)
#define iter(v) typeof(v.begin())
#define ff first
#define ss second
#ifdef LOCAL
#define out(x) (cout<<#x<<": "<<x<<endl)
template<class T>void show(T a, int n){for(int i=0; i<n; ++i) cout<<a[i]<<' '; cout<<endl;}
template<class T>void show(T a, int r, int l){for(int i=0; i<r; ++i)show(a[i],l);cout<<endl;}
#else
#define out(...)
#define show(...)
#endif

const int N = 1e5+10;
bool vis[N];
int type[N];
vector<int> e[N];
map<string,int> mp;

int get(string &s)
{
    if(mp.count(s)) return mp[s];
    int t = mp.size();
    mp[s] = t;
    return t;
}

bool dfs(int now, int t)
{
    vis[now] = true;
    type[now] = t;
    for(int i=0; i<e[now].size(); i++)
    {
        if(!vis[e[now][i]]) {
            if(!dfs(e[now][i], t^1)) return false;
        }
        else 
            if(type[now] == type[e[now][i]])
                return false;
    }
    return true;
}
int main() {
    int n,T;
    cin>>T;
    for(int cas = 1; cas<=T; cas++)
    {
        cin>>n;
        mp.clear();
        clr(vis);
        for(int i=0; i<N; i++) e[i].clear();
        for(int i=0; i<n; i++)
        {
            string s1,s2;
            cin>>s1>>s2;
            int t1 = get(s1), t2 = get(s2);
            e[t1].push_back(t2);
            e[t2].push_back(t1);
        }

        bool ans = true;
        for(int i=0; i<mp.size(); i++)
        {
            if(!vis[i]) if(!dfs(i,0)) ans = false;
        }
        printf("Case #%d: ", cas);
        if(ans) puts("Yes");
        else puts("No");
    }
	return 0;
}

