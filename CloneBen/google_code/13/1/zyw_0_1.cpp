#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <map>
#include <vector>
#include <queue>
using namespace std;
string sa[120], sb[120];
map<string, int>mp;
map<string, int>ms;
vector<int>dr[240];
int zy[240];
int cl[240];
int inq[240];
int cnt;
int main()
{
    freopen("A-small-2-attempt0.in", "r", stdin);
    freopen("A-small-2-attempt0.out", "w", stdout);
    int t, ca = 1;
    cin >> t;
    while ( t -- )
    {
        int m;
        cin >> m;
        cnt = 0;
        mp.clear();
        ms.clear();
        for ( int i = 0; i < 240; i ++ ) dr[i].clear();
        memset(cl, 0, sizeof(cl));
        memset(zy, -1, sizeof(zy));
        memset(inq, 0, sizeof(inq));
        for ( int i = 0; i < m; i ++ )
        {
            string pa, pb;
            cin >> pa >> pb;
            int a, b;
            if ( ms[pa] ) a = mp[pa];
            else a = mp[pa] = cnt ++, ms[pa] = 1;
            if ( ms[pb] ) b = mp[pb];
            else b = mp[pb] = cnt ++, ms[pb] = 1;
            dr[a].push_back(b);
            dr[b].push_back(a);
        }
        bool fg = true;
        queue<int>que;
        que.push(0);
        zy[0] = 0;
        int cc = 1;
        inq[0] = 1;
        while ( !que.empty() )
        {
            int p = que.front();
            que.pop();
            cl[p] = 1;
            for ( int i = 0; i < (int)dr[p].size(); i ++ )
            {
                int k = dr[p][i];
                if ( zy[k] != -1 && zy[k] == zy[p] )
                {
                    fg = false;
                    break;
                }
                zy[k] = 1 - zy[p];
                if ( inq[k] == 0 )
                {
                    inq[k] = 1;
                    que.push(k);
                    cc ++;
                    //printf("*%d\n",k);
                }
            }
            if ( !fg ) break;
            if ( que.empty() && cc < cnt )
            {
                for ( int i = 0; i < cnt; i ++ )
                {
                    if ( inq[i] == 0 )
                    {
                        inq[i] = 1;
                        zy[i] = 0;
                        que.push(i);
                        break;
                    }
                }
            }
        }
        printf("Case #%d: %s\n", ca ++, fg? "Yes" : "No");
    }
    return 0;
}
