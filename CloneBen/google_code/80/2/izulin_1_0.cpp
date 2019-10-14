#include <algorithm>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <set>
#include <queue>
#include <string>
#include <iostream>
using namespace std;
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define mp make_pair
#define tr(i,x) for(typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)

int c,d;
vector<int> h;

bool test(int x)
{
    int last = h[0]-x;
    for(int i=1;i<h.size();i++)
    {
        last += d;
        if(last < h[i]-x)
            last = h[i] - x;
        else if(last > h[i]+x)
            return false;
    }
    return true;
}

void tst()
{
    cin >> c >> d;
    d*=2;
    h.clear();
    for(int i=0;i<c;i++)
    {
        int p,v;
        cin >> p >> v;
        for(int j=0;j<v;j++)
            h.pb(2*p);
    }
    sort(h.begin(),h.end());

    int m = 0;
    for(;!test(m);m++);
    cout << (double)m/2 << endl;

}

int main()
{
    int t;
    cin >> t;
    for(int i=1;i<=t;i++)
    {
        cout << "Case #" << i << ": ";
        tst();
    }

}
