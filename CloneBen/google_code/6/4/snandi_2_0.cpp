#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MOD = 1000000007;
const int MAXN = 300005;

int mult(int a, int b, int mod)
{
    return (ll) a * b % mod;
}

int add(int a, int b, int mod)
{
    if (a < 0)
        a += mod;
    if (b < 0)
        b += mod;
    return (a % mod + b % mod) % mod;
}

vector <int> factorials, powers;
void precompute(int n, int mod)
{
    factorials.resize(n + 5), powers.resize(n + 5);
    factorials[0] = 1, powers[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        factorials[i] = mult(i, factorials[i - 1], mod);
        powers[i] = mult(powers[i - 1], 2, mod);
    }
}

int binaryPower(int n, int p, int mod)
{
    int acc = 1;
    for (; p; p >>= 1)
    {
        if (p & 1) acc = mult(acc, n, mod);
        n = mult(n, n, mod);
    }
    return acc;
}

int pmodularInverse(int n, int pmod)
{
    return binaryPower(n, pmod - 2, pmod);
}

int choose(int n, int k)
{
    int denom = mult(factorials[n - k], factorials[k], MOD);
    return mult(factorials[n], pmodularInverse(denom, MOD), MOD);
}

int numWays(int n, int m, int k)
{
    int temp = mult(choose(m, k), factorials[2 * n - k], MOD);
    return mult(temp, powers[k], MOD);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    precompute(MAXN, MOD);

    int T;
    cin >> T;
    for(int test = 1; test <= T; test++)
    {
        int n, m;
        cin >> n >> m;

        int sol = 0;
        for (int i = 0; i <= m; i++)
        {
            int ways = numWays(n, m, i);
            if (i & 1)
            {
                sol = add(sol, -ways, MOD);
            }
            else
            {
                sol = add(sol, ways, MOD);
            }
        }
        cout << "Case #" << test << ": " << sol << '\n';
    }
}
