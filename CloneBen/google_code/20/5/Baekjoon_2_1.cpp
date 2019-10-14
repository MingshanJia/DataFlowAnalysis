#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
int d[11111];
int pp[111][2];
int dp[111][11111];
vector<pair<int,int> > a[11111];
int n;
void go(int x) {
    int st = pp[x][0];
    for (int i=1; i<=n; i++)
        d[i] = 1000000000;
    priority_queue<pair<int,int>,vector<pair<int, int> >, greater<pair<int, int> > > q;
    d[st] = 0;
    q.push(make_pair(0,st));
    while(!q.empty()) {
        pair<int,int> top = q.top();
        q.pop();
        int vv = top.second;
        int dd = top.first;
        if (dd<=d[vv]) {
            for (int i=0; i<a[vv].size(); i++) {
                int v2 = a[vv][i].first;
                int cost = a[vv][i].second;
                if (d[v2] > d[vv]+cost) {
                    d[v2] = d[vv]+cost;
                    q.push(make_pair(d[v2],v2));
                }
            }
        }
    }
    for (int i=1; i<=n; i++) {
        if (d[i] >= 1000000000)
            d[i]=-1;
        dp[x][i] = d[i];
    }
}
int main(){
    int t;
    scanf("%d\n",&t);
    for (int tc=1; tc<=t; tc++) {
        long long ans = 0;
        int p,m;
        scanf("%d %d %d\n",&n,&p,&m);
        for (int i=0; i<p; i++) {
            scanf("%d %d\n",&pp[i][0], &pp[i][1]);
        }
        for (int i=1; i<=n; i++) {
            a[i].clear();
        }
        for (int i=0; i<m; i++) {
            int t1,t2;
            int t3,t4;
            scanf("%d %d",&t1,&t2);
            t2--;
            scanf("%d",&t3);
            for (int j=0; j<t2; j++) {
                scanf("%d",&t4);
                a[t3].push_back(make_pair(t4,t1));
                a[t4].push_back(make_pair(t3,t1));
                t3=t4;
            }
        }
        for (int i=0; i<p; i++) {
            go(i);
        }
        ans = 2147483647;
        for (int i=1; i<=n; i++) {
            bool ok = true;
            long long t1 = 0;
            for (int j=0; j<p; j++) {
                if (dp[j][i] == -1) {
                    ok=false;
                }
                if (t1 < dp[j][i]*pp[j][1]) 
                    t1 = dp[j][i]*pp[j][1];
            }
            if (ok && ans > t1)
                ans = t1;
        }
        if (ans == 2147483647)
            ans=-1;
        printf("Case #%d: %lld\n",tc,ans);
    }
    return 0;
}
