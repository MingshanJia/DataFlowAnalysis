#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cctype>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>
#include <numeric>
#include <complex>
using namespace std;

typedef long long ll;
typedef unsigned long long llu;
typedef long double ld;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef stringstream ss;

#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define clr(t,v) memset((t),(v),sizeof(t))
#define p(a) cout << #a << ": " << a << endl;

#define rep(i,n) for(int i=0,_##i=(n);i<_##i;++i)
#define dwn(i,n) for(int i=(n);--i>=0;)
#define repr(i,l,r) for(int i=(l),_##i=(r);i<_##i;++i)
#define dwnr(i,l,r) for(int i=(r),_##i=(l);--i>=_##i;)
#define repi(i,a) for(__typeof((a).begin()) i=(a).begin(),_##i=(a).end();i!=_##i;++i)
#define dwni(i,a) for(__typeof((a).rbegin()) i=(a).rbegin(),_##i=(a).rend();i!=_##i;++i)

vi save[2000000];
int arr[21];

int main() { freopen("c.in","r",stdin); freopen("c.out","w",stdout);
	cout << fixed << setprecision(12);
	
	int testn;
	cin >> testn;
	for (int testc = 1; testc <= testn; ++testc) {
		cout << "Case #" << testc << ": ";
		
		rep (i, 2000000) save[i].clear();
		
		int n;
		cin >> n;
		rep (i, n) {
			cin >> arr[i];
		}
		bool ok = false;
		rep (i, (1 << n)) {
			vi coll;
			int tot = 0;
			rep (j, n) {
				if ((i >> j) & 1) {
					coll.push_back(arr[j]);
					tot += arr[j];
				}
			}
			if (!save[tot].empty()) {
				cout << endl;
				bool f = false;
				repi (a, save[tot]) {
					if (f) cout << ' ';
					cout << *a;
					f = true;
				}
				cout << endl;

				f = false;
				repi (a, coll) {
					if (f) cout << ' ';
					cout << *a;
					f = true;
				}
				ok = true;
				break;
			}
			save[tot] = coll;
		}
		if (!ok) {
			cout << endl;
			cout << "Impossible";
		}
		cout << '\n';
	}
}
