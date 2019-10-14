#include <cstring>
#include <string.h>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <set>
#include <complex>
#include <list>

using namespace std;
typedef long long ll;
int n,N;

//#define SMALL
#define LARGE
int main() {
	freopen("a.txt", "rt", stdin);
#ifdef SMALL
	freopen("A-small-attempt0.in","rt",stdin);
	freopen("A-small.out","wt",stdout);
#endif
#ifdef LARGE
	freopen("A-large.in","rt",stdin);
	freopen("A-large.out","wt",stdout);
#endif

	int c;
	ll tt;
	cin >> N;
	for(int nn = 1 ; nn <= N ; nn++ ) {
		cin>>n;
		set<ll> a;
		for(int i = 0 ; i < n; i++){
			cin>>tt;
			if( a.count(tt) )
				a.erase(tt);
			else
				a.insert(tt);
		}

		cout << "Case #" << nn << ": "<< *a.begin() << "\n";
	}
	return 0;
}
