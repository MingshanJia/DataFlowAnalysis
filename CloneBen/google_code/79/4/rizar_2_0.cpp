#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <cctype>
#include <cassert>
#include <utility>
#include <complex>

using namespace std;

typedef long long LL;
typedef long double LD;

#define NAME "task"

//solution

const int MAX_N = 10010;
int n, l, h;
int f [MAX_N];

int main()
{
    int nTests;
    cin >> nTests;
    for (int test = 1; test <= nTests; test++)
    {
        cin >> n >> l >> h; 
        for (int i = 0; i < n; i++) cin >> f[i];

        printf("Case #%d: ", test);

        bool ok = false;
        for (int x = l; x <= h; x++)
        {
            ok = true;
            for (int i = 0; i < n; i++)
                if (f[i] % x != 0 && x % f[i] != 0)
                {
                    ok = false;
                    break;
                }
            if (ok)
            {
                printf("%d\n", x);
                break;
            }
        } 

        if (!ok)
            printf("NO\n");
    }

    return 0;
}
