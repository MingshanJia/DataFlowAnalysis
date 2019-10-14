#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

int L;
string S[3];

bool check(int i1, int i2, int i3)
{
    pair<char, char> p1, p2;
    for(int i = 0; i<L; i++)
    {
        if(S[i1][i] != S[i2][i])
        {
            p1 = make_pair(S[i1][i], S[i2][i]);
            break;
        }
    }
    for(int i = 0; i<L; i++)
    {
        if(S[i2][i] != S[i3][i])
        {
            p2 = make_pair(S[i2][i], S[i3][i]);
            break;
        }
    }
    if(p1.first == p2.second && p1.second == p2.first)
        return false;
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    //freopen("C-small.in", "r", stdin);
    //freopen("c-small.out", "w", stdout);
    
    int t;
    bool flag[3];
    cin >> t;
    for(int test = 1; test<=t; test++)
    {
        cin >> L;
        for(int i = 0; i<3; i++)
        {
            cin >> S[i];
            flag[i] = false;
        }
        flag[0] = flag[0]|check(1, 0, 2);
        flag[0] = flag[0]|check(2, 0, 1);
        flag[1] = flag[1]|check(2, 1, 0);
        flag[1] = flag[1]|check(0, 1, 2);
        flag[2] = flag[2]|check(0, 2, 1);
        flag[2] = flag[2]|check(1, 2, 0);

        cout << "Case #" << test << ": ";
        for(int i = 0; i<3; i++)
        {
            if(flag[i])
                cout << "YES ";
            else
                cout << "NO ";
        }
        cout << "\n";
    }

    return 0;
}