#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

const int N = 1003;
long long cnt[N], presum[N], E[N], rem[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    //freopen("B-large.in", "r", stdin);
    //freopen("b-large.out", "w", stdout);
    
    int t, L;
    cin >> t;
    for(int test = 1; test<=t; test++)
    {
        cin >> L;
        for(int i = 1; i<=L; i++)
        {
            cin >> cnt[i] >> E[i];
            presum[i] = presum[i-1] + cnt[i];
            rem[i] = cnt[i] + max(rem[i-1] - cnt[i]*E[i], 0LL);
        }
        cout << "Case #" << test << ": " << max(rem[L], E[L] + 1) << "\n";
    }

    return 0;
}