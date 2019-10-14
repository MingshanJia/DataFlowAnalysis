#include <iostream>
#include <cstdio>

using namespace std;
int T, tt;
int f[11000];

int main()
{
    freopen("D-small-attempt0.in","r",stdin);
    freopen("D-small-attempt0.out","w",stdout);
    cin >> T;
    for ( int i = 0; i <= 10000; i++ ) f[i] = 10000000;
    f[1] = 1; f[2] = 2; f[3] = 3;
    for ( int i = 4; i <= 10000; i++ ){
        for ( int k = 1; k*k <= i; k++ ){
            if ( i == k * k )
                f[i] = 1;
            else
            if ( f[i-k*k] +1 < f[i] )
                f[i] =f[i-k*k]+1;
        }
    }
    int a;
    for ( tt = 1; tt <= T; tt++ ){
        cin >> a;
        cout << "Case #" << tt << ": " << f[a] << endl;
    }
    return 0;
}
