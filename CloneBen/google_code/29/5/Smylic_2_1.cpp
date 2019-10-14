#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector <long long> ff[40];

long long f(int b, int d)
{
    if (!b || !d)
        return 0;
    if (b == 1)
        return d;
    if (b > 35)
        b = 35;
    if (ff[b].size() <= d)
        return 1LL<<32;
    return ff[b][d];
}

int main()
{
    for (int b=2; b<=35; b++)
    {
        ff[b].push_back(0);
        ff[b].push_back(1);
        for (int d=2; ; d++)
        {
            long long x = min(f(b-1, d-1) + f(b, d-1) + 1, 1LL<<32);
            ff[b].push_back(x);
            if (x == 1LL<<32)
                break;
        }
    }
    int n;
    cin >> n;
    for (int t=0; t<n; t++)
    {
        int ff, d, b;
        cin >> ff >> d >> b;
        long long rb = b;
        long long lb = 0;
        for (; lb + 1 < rb;)
        {
            int cb = rb + lb >> 1;
            if (f(cb, d) >= ff)
                rb = cb;
            else
                lb = cb;
        }
        long long rd = d;
        long long ld = 0;
        for (; ld + 1 < rd;)
        {
            int cd = rd + ld >> 1;
            if (f(b, cd) >= ff)
                rd = cd;
            else
                ld = cd;
        }
        cout << "Case #" << t+1 << ": " << (f(b, d)==1LL<<32?-1:f(b, d)) << " " << rd << " " << rb << endl;
    }
    return 0;
}
