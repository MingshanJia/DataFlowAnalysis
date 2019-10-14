// In the name of Allah

#include <vector>
#include <map>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <complex>
#include <queue>
#include <stack>
#include <map>
#include <bitset>
#include <iomanip>
#include <set>
#include <stack>
#include <stdio.h>

using namespace std;

#define dbg(x) cerr << #x << " = " << (x) << endl;
#define FOR(i,a,b) for (int i = (a); i < (b); i ++)
#define rep(i,n) for (int i = 0; i < (n); i ++)
#define repd(i,n) for (int i = (n); i >= 0; i --)
#define PI 3.14159265358979323846
#define pb push_back
#define mp make_pair
#define X first
#define Y second

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

priority_queue <int> Q;
vector <int> ans;

int main ()
{
    int T;
    cin >> T;
    rep (tt, T)
    {
    	int n;
    	cin >> n;
    	ans.clear();
    	rep (i, 2*n)
    	{
    		int x;
    		cin >> x;
    		if ( Q.size() && Q.top() == -x )
    			Q.pop();
    		else
    		{
    			ans.pb (x);
    			Q.push (-100LL*x/75);
    		}
    	}
    	cout << "Case #" << tt+1 << ":";
    	rep (i, n)
    		cout << " " << ans[i];
    	cout << endl;
    }

	return 0;
}