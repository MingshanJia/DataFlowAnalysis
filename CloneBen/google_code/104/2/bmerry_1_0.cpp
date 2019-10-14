#include <iostream>
#include <algorithm>

using namespace std;

static bool is_prime[1001];

static bool test_prime(int p)
{
    if (p < 2) return false;
    for (int i = 2; i * i <= p; i++)
        if (p % i == 0)
            return false;
    return true;
}

static int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
static bool share(int a, int b, int P)
{
    int g = gcd(a, b);
    for (int i = P; i <= g; i++)
        if (is_prime[i] && g % i == 0)
            return true;
    return false;
}

static int parent[1001];

static int root(int x)
{
    if (parent[x] == -1)
        return x;
    else
        return parent[x] = root(parent[x]);
}

static void merge(int a, int b)
{
    a = root(a);
    b = root(b);
    if (a == b) return;
    parent[b] = a;
}

int main()
{
    int cases;
    cin >> cases;

    for (int i = 1; i <= 1000; i++)
        is_prime[i] = test_prime(i);
    for (int cas = 0; cas < cases; cas++)
    {
        int A, B, P;
        cin >> A >> B >> P;

        for (int i = A; i <= B; i++)
            parent[i] = -1;
        for (int i = A; i <= B; i++)
            for (int j = i + 1; j <= B; j++)
                if (share(i, j, P))
                    merge(i, j);
        int ans = count(parent + A, parent + B + 1, -1);
        cout << "Case #" << cas + 1 << ": " << ans << "\n";
    }
    return 0;
}
