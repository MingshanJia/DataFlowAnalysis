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
const int MAX_DIVS = (int)1e7;
int n;
LL L, H;
LL f [MAX_N];
LL cumGCD [MAX_N];
LL cumLCM [MAX_N];

int nDivs, nDivs1, nDivs2;
LL divs1 [MAX_DIVS];
LL divs2 [MAX_DIVS];
LL divs [MAX_DIVS];
//vector<int> divs;

LL gcd(LL a, LL b)
{
    return b ? gcd(b, a % b) : a;
}

LL lcm(LL a, LL b)
{
    if (a == -1 || b == -1) return -1;
    LL t = a / gcd(a, b);
    if (LD(t) * b <= 1.1e18)
        return t * b;
    else
        return -1;        
}

int p;
bool check(LL x)
{
    #ifdef DEBUG
    cerr << "check " << x << ' ' << p << '\n';
    #endif

    return (p + 1 == n || cumGCD[p + 1] % x == 0) && (p == -1 || (cumLCM[p] != -1 && x % cumLCM[p] == 0));
}

int main()
{
    int nTests;
    cin >> nTests;
    for (int test = 1; test <= nTests; test++)
    {
        cerr << "Test " << test << '\n';
        
        cin >> n >> L >> H; 
        for (int i = 0; i < n; i++) cin >> f[i];

        sort(f, f + n);
        cumLCM[0] = f[0];
        for (int i = 1; i < n; i++)
            cumLCM[i] = lcm(cumLCM[i - 1], f[i]);
        cumGCD[n - 1] = f[n - 1];
        for (int i = n - 2; i >= 0; i--)
            cumGCD[i] = gcd(cumGCD[i + 1], f[i]);

        #ifdef DEBUG
        cerr << "cumGCD\n";
        for (int i = 0; i < n; i++)
            cerr << cumGCD[i]<< ' ';
        cerr << '\n';
        cerr << "cumLCM\n";
        for (int i = 0; i < n; i++)
            cerr << cumLCM[i]<< ' ';
        cerr << '\n';

        #endif

        printf("Case #%d: ", test);

        nDivs1 = nDivs2 = 0;
        for (LL x = 1; x * x <= f[n - 1]; x++)
            if (f[n - 1] % x == 0)
            {
                LL y = f[n - 1] / x;
                if (L <= x && x <= H) divs1[nDivs1++] = x;
                if (L <= y && y <= H) divs2[nDivs2++] = y;
            }
        reverse(divs2, divs2 + nDivs2);
        merge(divs1, divs1 + nDivs1, divs2, divs2 + nDivs2, divs);
        nDivs = nDivs1 + nDivs2;

        cerr << "nDivs " << nDivs << '\n';
        #ifdef DEBUG
        for (int i = 0; i < nDivs; i++)
            cerr << divs[i] << ' ';
        cerr << '\n';                                
        #endif

        bool ok = false;
        p = -1;
        for (int i = 0; i < nDivs; i++)
        {
            LL x = divs[i];
            for (; p + 1 < n && f[p + 1] <= x; p++);
            if (check(x))
            {
                ok = true;
                cout << x << '\n';
                break;
            }
        }

        if (!ok && cumLCM[n - 1] != -1)
        {
            LL A = cumLCM[n - 1];
            LL x = (H / A) * A;
            LL y = ((L + A - 1) / A) * A;

            #ifdef DEBUG
            cerr << "x " << x << " y = " << y << '\n';
            #endif

            if (L <= y && y <= H)
            {
                ok = true;
                cout << y << '\n';
            }
            else if (L <= x && x <= H)
            {
                ok = true;
                cout << x << '\n';
            }
        }
                  
        if (!ok) cout << "NO\n";
    }

    return 0;
}
