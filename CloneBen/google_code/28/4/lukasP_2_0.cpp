#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <sstream>
#include <queue>
#include <bitset>
#include <utility>
#include <list>
#include <numeric>

#include <cstdio>
#include <cmath>
#include <cctype>
using namespace std;

#define REP(i,n) for(__typeof(n) i=0; i<(n); ++i)
#define FOR(i,a,b) for(__typeof(b) i=a; i<(b); ++i)
#define FOREACH(it,c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); ++it)

const int mod = 9901;
vector<int> w;
int sef(int a)
{
    if (w[a] < 0) return a;
    return w[a] = sef(w[a]);
}
bool spoj(int a, int b)
{
    int x = sef(a), y = sef(b);
    if (x == y) return false;
    if (w[x] > w[y]) swap(x, y);
    w[x] += w[y]; w[y] = x;
    return true;
}
int main() {
    int t; scanf("%d", &t);
    REP(sd,t)
    {
        int n, k; scanf("%d %d", &n, &k);
        int a[k], b[k];
        REP(i,k)
        {
            scanf("%d %d", &a[i], &b[i]);
            a[i]--; b[i]--;
        }

        int res = 0;
        REP(l,1<<k)
        {
            bitset<15> c(l);
            w.assign(n, -1);
            vector<int> kol(n, 0);
            bool ok = true;
            REP(i,k) if (c[i])
            {
                if (!spoj(a[i], b[i])) ok = false;
                kol[a[i]]++; kol[b[i]]++;
            }

            int poc_spoj = 0, poc = 0;
            bool check = true, zle = false;
            REP(i,n)
            {
                if (w[i] < 0) poc++;
                if (kol[i] > 2) zle = true;
                if (kol[i] == 1) poc_spoj++;
                if (kol[i] != 2) check = false;
            }
            if (poc > 1) check = false;
            if (!check)
                poc_spoj /= 2;
            else poc_spoj = 1;

            if ((!ok && !check) || zle) continue;
            int akt = (1<<poc_spoj)%mod;

            FOR(i,2,poc)
                akt = (akt * i) % mod;
            if (c.count() % 2) akt *= -1;
            res = (res + akt + mod) % mod;

            /*
            cout << c << " " << akt << " " << poc << ":";
            REP(i,k) if (c[i])
            {
                cout << a[i] << "/" << b[i] << " ";
            }
            cout << endl;
            */
        }

        res = (res * 4951) % mod;
        printf("Case #%d: %d\n", sd+1, res);
    }
}
