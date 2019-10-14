#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include <algorithm>

using namespace std;





int main()
{
    freopen("in.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int T;
    cin >> T;
    for (int u = 0; u < T; u++)
    {
        int n;
        cin >> n;

        long long ans = 0;
        long long level = 0;

        for (int i = 0; i < n; i++)
        {
            long long x, y;
            cin >> x >> y;

            long long to_manage = min(x * y, ans);

            ans -= to_manage;


            ans += x;

            level = y;

            //cout <<  ans << endl;

        }
        cout << "Case #" << u + 1 << ": " << max(level + 1, ans) << endl;
    }


    return 0;
}