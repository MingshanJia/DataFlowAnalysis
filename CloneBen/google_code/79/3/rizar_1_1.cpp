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

const int MAX_C = (int)1e3 + 10;
const int MAX_N = (int)1e6 + 10;

int L, N, C;
LL t;
int dist [MAX_N];

int nVars;
LL variants [MAX_N];

int main()
{
    int nTests;
    cin >> nTests;
    for (int test = 1; test <= nTests; test++)
    {
        cerr << "Test " << test << '\n';

        printf("Case #%d: ", test);

        LL totalDist = 0;

        cin >> L >> t >> N >> C;
        for (int i = 0; i < C; i++)
        {
            cin >> dist[i];
            totalDist += dist[i];
        }
        for (int i = C; i < N; i++)
        {   
            dist[i] = dist[i - C];
            totalDist += dist[i];
        }

        LL x1 = t / 2, x = 0;
        int i = 0;
        for (; i < N && x + dist[i] <= x1; x += dist[i++]);

        LL fastDist = 0;
        if (i < N)
        {
            variants[0] = x + dist[i] - x1;
            nVars = 1;
            for (i++; i < N; i++, nVars++)
                variants[nVars] = dist[i];

            sort(variants, variants + nVars);
            for (int i = nVars - 1; i >= 0 && i >= nVars - L; i--)
                fastDist += variants[i];
        }

        LL slowDist = totalDist - fastDist;
        cout << fastDist + 2 * slowDist << '\n';
    }

    return 0;
}
