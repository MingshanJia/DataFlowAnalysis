#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

const int N = 105;
int D[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    //freopen("A-large.in", "r", stdin);
    //freopen("out-large.out", "w", stdout);
    
    int t, n, ans;
    cin >> t;
    for(int test = 1; test<=t; test++)
    {
        cin >> n;
        for(int i = 1; i<=n; i++)
            cin >> D[i];
        sort(D+1, D+1+n);
        ans = 0;
        if(n&1)
            ans = ((n-1)/2 - D[n])*((n-1)/2 - D[n]);
        for(int i = 1; i<=(n/2); i++)
        {
            ans += (D[2*i - 1] - i + 1)*(D[2*i - 1] - i + 1);
            ans += (D[2*i] - i + 1)*(D[2*i] - i + 1);
        }
        cout << "Case #" << test << ": " << ans << "\n";
    }

    return 0;
}