#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include <algorithm>

using namespace std;
vector <string>s (3);
vector <string> v(3);

pair <char, char> get_diff(string s1, string s2)
{
    int i = 0;
    while (s1[i] == s2[i])
        i++;
    return make_pair(s1[i], s2[i]);
}


bool good(string s1, string s2, string s3)
{
    vector <pair<char, char> > v;

    v.push_back(get_diff(s1, s2));
    v.push_back(get_diff(s2, s3));

    if ((v[0].first == v[1].second) && (v[0].second == v[1].first))
        return false;
    return true;
}

string solve(int i)
{
    if (i == 0)
    {
        if (good(s[1], s[0], s[2]))
            return "YES";
        else
            return "NO";
    }
    if (i == 1)
    {
        if (good(s[0], s[1], s[2]))
            return "YES";
        else
            return "NO";
    }
    if (i == 2)
    {
        if (good(s[0], s[2], s[1]))
            return "YES";
        else
            return "NO";
    }
}



int main()
{
    freopen("in.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int T;
    cin >> T;


    for (int u = 0; u < T; u++)
    {
        int n;
        cin >> n;


        for (int i = 0; i < 3; i++)
        {
            cin >> s[i];
            //v[i] = s[i];
        }

        cout << "Case #" << u + 1 << ": ";
        for (int i = 0; i< 3; i++)
            cout << solve(i) << ' ';
        cout << endl;
    }


    return 0;
}