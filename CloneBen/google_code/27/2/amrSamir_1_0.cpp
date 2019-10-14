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
	freopen("B-small-attempt0.in","rt",stdin);
	freopen("B-small.out","wt",stdout);
#endif
#ifdef LARGE
	freopen("B-large.in","rt",stdin);
	freopen("B-large.out","wt",stdout);
#endif

	int c;
	cin >> N;
	for(int nn = 1 ; nn <= N ; nn++ ) {
		//cin>>c>>n;
		//for(int i = 0 ; i < n; i++)
		//	cin>>arr[i];
		cin >> n;
		int city, e;
		cin >> city >> e;
		vector<deque<int> > all(n);
		for (int i = 0; i < e; ++i) {
			int cur,pass;
			cin >> cur >> pass;
			all[cur-1].push_back(pass);
		}
		printf("Case #%d:", nn);
		vector <int> res;

		for (int i = 0; i < n; ++i) {
			if( i+1 == city )
			{
				res.push_back(0);
				continue;
			}
			sort(all[i].rbegin(),all[i].rend());
			int cnt = 0;
			while(!all[i].empty()){
				int b = all[i].front();
				all[i].pop_front();
				if( b == 0 )
				{
					goto imp;
				}
				for (int ii = 0; ii < b-1 && !all[i].empty(); ++ii) {
					all[i].pop_back();
				}
				cnt++;
			}
			res.push_back(cnt);
		}
		for (int i = 0; i < res.size(); ++i) {
			printf(" %d",res[i]);
		}
		printf("\n");
		continue;
		imp:
		printf(" IMPOSSIBLE\n");
	}
	return 0;
}
