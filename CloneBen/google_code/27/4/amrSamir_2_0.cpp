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

int n,N;

#define SMALL
//#define LARGE
int main() {
	freopen("a.txt", "rt", stdin);
#ifdef SMALL
	freopen("C-small-attempt0.in","rt",stdin);
	freopen("C-small.out","wt",stdout);
#endif
#ifdef LARGE
	freopen("C-large.in","rt",stdin);
	freopen("C-large.out","wt",stdout);
#endif

	int c,tt;
	cin >> N;
	for(int nn = 1 ; nn <= N ; nn++ ) {
		cin>>n>>c;
		vector <int> r;
		for(int i = 0 ; i < n; i++)
			cin>>tt, r.push_back(tt);
		int cnt = 0;
		while(1){
			sort(r.rbegin(),r.rend());
			bool f = 0;
			for (int i = 0; i < c; ++i) {
				if( r[i] == 0 ){
					f = 1;
					break;
				}
				r[i]--;
			}
			if( f )
				break;
			cnt++;
		}
		printf("Case #%d: ", nn);
		printf("%d\n",cnt);
	}
	return 0;
}
