#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool prefixOf(string &a, string &b) // returns true iff a is prefix of b
{
    if (a.length() <= b.length())
    {
        for (int i = 0; i < a.length(); i++)
            if (a[i] != b[i])
                return false;
        return true;
    }
    else
        return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    for(int test = 1; test <= T; test++)
    {
        int n, p;
        cin >> n >> p;

        vector <string> forbidden(p);
        for (string &s: forbidden)
            cin >> s;

        vector <bool> redundant(p);
        for (int i = 0; i < p; i++)
        {
            for (int j = 0; j < p; j++) if (i != j)
            {
                if (prefixOf(forbidden[i], forbidden[j]))
                    redundant[j] = true;
            }
        }

        ll sol = (1ll << n);
        for (int i = 0; i < p; i++)
        {
            if (!redundant[i])
            {
                int remaining = n - forbidden[i].length();
                sol -= (1ll << remaining);
            }
        }
        cout << "Case #" << test << ": " << sol << '\n';
    }
}
