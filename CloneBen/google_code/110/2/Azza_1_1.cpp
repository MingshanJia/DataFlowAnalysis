#include <iostream>
#include<vector>
#include<cmath>
#include<math.h>
#include<algorithm>
#include<string>

using namespace std;


int main() {
    freopen ("in.txt", "r", stdin);
    freopen ("out.txt", "w", stdout);

    int T, K, V;
    cin >> T;

    for (int c= 1; c <=T; c++)
    {
       cin >> K >> V;

        long long tmp1, t2;
        long long res;
        tmp1 = pow((double)V+1, 3.0);
        tmp1 *= (K-V+1);
        t2 = pow((double) V, 3.0);
        t2 *= (K-V);
        res = tmp1 - t2;

        cout << "Case #" << c << ": ";

        cout << res;
        cout << endl;

    }

    return 0;
}