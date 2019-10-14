#include <iostream>
#include <algorithm>

using namespace std;

char s[16];
char t[256];

int a[256];

int main()
{
    int n;
    cin >> n;
    int i, j;
    for (i=0; i<n; i++)
    {
        cin >> s;
        cin >> t;
        for (j=0; t[j]; j++)
            a[t[j]] = j;
        int k = j;
        int m = 0;
        for (j=0; s[j]; j++)
            (m *=k ) += a[s[j]];
        cin >> t;
        for (j=0; t[j]; j++);
        k = j;
        for (j=0; m; m/=k, j++)
            s[j] = t[m%k];
        s[j] = 0;
        reverse(s, s+j);
        cout << "Case #" << i+1 << ": " << s << endl;
    }
    return 0;
}
