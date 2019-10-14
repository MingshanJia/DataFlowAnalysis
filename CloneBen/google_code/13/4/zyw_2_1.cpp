#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <map>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
char s[110][1010];

int main()
{
    //freopen("C-small-2-attempt0.in", "r", stdin);
    //freopen("C-small-2-attempt0.out", "w", stdout);
    int t, ca = 1;
    cin >> t;
    while ( t -- )
    {
        int n;
        cin >> n;
        getchar();
        for ( int i = 0; i < n; i ++ )
        {
            gets(s[i]);
            //puts(f[i].s);
        }
        int cnt = 0, pre = 0;
        for ( int i = 1; i < n; i ++ )
        {
            if ( strcmp(s[i], s[pre]) < 0 )
            {
                cnt ++;
                //printf("%d\n",i);
            } else {
                pre = i;
            }
        }
        printf("Case #%d: %d\n", ca ++, cnt);
    }
    return 0;
}

