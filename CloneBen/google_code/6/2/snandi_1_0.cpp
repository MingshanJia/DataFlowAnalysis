#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    for(int test = 1; test <= T; test++)
    {
        int n;
        cin >> n;
        vector <int> score(n);
        for (int &i: score)
        {
            char c;
            cin >> c;
            i = c - '0';
        }

        int len = n / 2 + (n & 1);
        int curr = 0, best = 0;
        queue <int> window;
        for (int i = 0; i < n; i++)
        {
            window.push(score[i]);
            curr += score[i];

            if (window.size() == len)
            {
                best = max(best, curr);
                curr -= window.front();
                window.pop();
            }
        }

        int sol = best;
        cout << "Case #" << test << ": " << sol << '\n';
    }
}
