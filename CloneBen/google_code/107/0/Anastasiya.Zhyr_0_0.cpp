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
        vector <long long> v;
    for (int i = 0; i < n; i++)
    {
        long long x;
        cin >> x;
        v.push_back(x);
    }


    sort(v.begin(), v.end());


    long long ans = 0;

    for (int i = 0; i < v.size(); i++)
    {
        long long cur = i / 2;

        ans += (cur - v[i]) * (cur - v[i]);

    }
    cout << "Case #" << u + 1 << ": " << ans << endl;
    }


    return 0;
}