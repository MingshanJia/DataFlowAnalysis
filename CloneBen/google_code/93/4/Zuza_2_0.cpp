#include <algorithm>
#include <functional>

#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <vector>
#include <string>

using namespace std;

const int MAXN = 10100;

int bio[ MAXN ];
int V[ MAXN ];

int main( void )
{
    int T; scanf( "%d", &T );

    for( int counter = 0; counter < T; ++counter ) {
        int n, k; scanf( "%d %d", &n, &k );

        for( int i = 0; i < k; ++i ) {
            scanf( "%d", V + i );
            --V[i];
        }

        int mini = 1000000000;

        sort( V, V + k );
        do {
            int sum = 0;
            memset( bio, 0, sizeof bio );

            for( int i = 0; i < k; ++i ) {
                for( int j = V[i]+1; j < n && bio[j] == false; ++j )
                    ++sum;

                for( int j = V[i]-1; j >= 0 && bio[j] == false; --j )
                    ++sum;

                bio[ V[i] ] = true;
            }

            if( sum < mini ) mini = sum;
        } while( next_permutation( V, V + k ) );

        printf( "Case #%d: %d\n", counter + 1, mini );
    }

    return (0-0);
}
