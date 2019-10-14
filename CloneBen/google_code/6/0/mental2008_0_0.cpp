#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<cmath>
#include<iomanip>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<vector>
#include<bitset>

using namespace std;

#define mem(a,i) memset(a,i,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
#define lowbit(x) (x&-x)
#define sqr(x) (x*x)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef pair<int,int> pii;
const ll INF=0x3f3f3f3f3f3f3f3f;
const int inf=0x3f3f3f3f;
const int mod=1e9+7;
const db exps=1e-8;
const db pi=acos(-1.0);
const int maxn=105;

string s[maxn];
int n,k;

bool judge(string res) {
    rep(i,1,k) {
        int len=min(res.size(),s[i].size());
        bool ok=true;
        rep(j,0,len-1) {
            if(s[i][j]!=res[j]) {
                ok=false;
                break;
            }
        }
        if(ok) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    int caseCnt;
    cin>>caseCnt;
    rep(T,1,caseCnt) {
        cin>>n>>k;
        rep(i,1,k) cin>>s[i];
        int ans=0;
        rep(i,0,(1<<n)-1) {
            string res="";
            rep(j,0,n-1) {
                if((i>>j)&1) {
                    res+="R";
                }
                else {
                    res+="B";
                }
            }
            if(judge(res)) ans++;
        }
        cout<<"Case #"<<T<<": "<<ans<<"\n";
    }
    return 0;
}