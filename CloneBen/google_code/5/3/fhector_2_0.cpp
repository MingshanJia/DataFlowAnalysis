#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

string str[110];

int main()
{
    #define LOCAL
#ifdef LOCAL
    //freopen("in", "r", stdin);
    freopen("C-small-1-attempt0.in", "r", stdin);
    freopen("C-small-2.out", "w", stdout);
#endif
    int T;
    scanf("%d", &T);
    for (int kase = 1; kase <= T; kase++)
    {
        int n;
        scanf("%d", &n);
        getchar();
        for (int i = 0; i < n; i++)
            getline(cin, str[i]);
        int cnt = 0;
        for (int i = 1; i < n; i++)
            if (str[i] < str[i-1])
            {
                cnt++;
                sort(str, str+i+1);
            }
        printf("Case #%d: %d\n", kase, cnt);
    }
    return 0;
}
