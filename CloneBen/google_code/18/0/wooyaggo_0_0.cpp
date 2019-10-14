// C++ Header

// -- Base
#include <iostream>
#include <sstream>
// Data Structure
#include <vector>
#include <map>
#include <set>
#include <list>
#include <deque>
#include <stack>
#include <queue>
#include <string>
#include <numeric>
#include <algorithm>

// C Header
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <cstring>
#include <cctype>
#include <cfloat>
#include <climits>
#include <cstddef>

using namespace std;

// Global Macro

#define FOR(V,I,L) for(int V=(I);V<(L);(V)++)     // for loop macro start from I until < L
#define FORe(V,I,L) FOR(V,I,L+1)
#define FORd(V,I,L) for(int V=(I);V>=(L);(V)--)
#define REP(V,L) FOR(V,0,L)                           // for loop start from 0
#define REPe(V,L) FORe(V,0,L)
#define REPd(V,I) FORd(V,I,0)
#define IT(adt) adt::iterator        // Create Iterator
#define FOR_EACH(I,C) for(I=(C).begin(); I!=(C).end(); ++I)    // for loop for iterator

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int    ui;
typedef long double     ld;

ll a[3];
ll b[3];
vector< pair<int,int> > vpii;
ll c[3][3];

int main(void) {
	//freopen("input.txt", "r", stdin);
	freopen("A-small-attempt1.in", "r", stdin);
	freopen("A-small-attempt1.out", "w", stdout);

	int T; scanf("%d", &T);
	for(int tc=1; tc<=T; tc++) {
		int N; scanf("%d", &N);
		for(int i=0;i<3;i++) scanf("%lld", &a[i]);
		for(int i=0;i<3;i++) scanf("%lld", &b[i]);

		vpii.clear();
		for(int i=0;i<3;i++) for(int j=0;j<3;j++) {
			scanf("%lld", &c[i][j]);
			vpii.push_back(make_pair(i, j));
		}

		sort(vpii.begin(), vpii.end());

		ll res = LLONG_MIN;
		do {
			ll aa[3] = { a[0], a[1], a[2] };
			ll bb[3] = { b[0], b[1], b[2] };

			ll val = 0;
			for(int i=0;i<int(vpii.size());i++) {
				int ai = vpii[i].first;
				int bi = vpii[i].second;

				ll minv = min(aa[ai], bb[bi]);
				val += minv * c[ai][bi];

				aa[ai] -= minv;
				bb[bi] -= minv;
			}

			res = max(res, val);
		}while(next_permutation(vpii.begin(), vpii.end()));

		printf("Case #%d: %lld\n", tc, res);
		fprintf(stderr, "Case #%d: %lld\n", tc, res);
		fflush(stdout);
	}

	return 0;
}
