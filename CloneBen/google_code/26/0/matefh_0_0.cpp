#include <cmath>
#include <ctime>
#include <cctype>
#include <cstdio>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#define FOR(i,n) for(int i = 0 ; i < n ; i++)
#define FORL(i,i0,n) for(int i = i0 ; i < n ; i++)
#define FORIT(it,x) for(__typeof(x.begin())it=x.begin();it!=x.end();it++)
#define ALL(x) x.begin(), x.end()
#define SZ(x) int(x.size())
#define LEN(x) int(x.length())
#define PB push_back
#define MP make_pair
#define FST(x) (x).first
#define SEC(x) (x).second
#define LL long long
#define mem(x, n) memset(x, n, sizeof(x))
#define ni() ({int t;scanf("%d",&t);t;})
#define SRAND() srand(time(NULL))
#define RAND(mod, offset) ((rand() % (mod)) + (offset))
#if 1
#define DBG(z) cerr << #z << ": " << (z) << endl
#else
#define DBG(z)
#endif
using namespace std;
int main() {
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
	int t = ni();
	int kase = 1;
	while (t--) {
		int n = ni();
		vector<int> R, B;
		int len;
		char cc[10];
		FOR(i, n) {
			scanf("%d%s", &len, cc);
			if (cc[0] == 'R')
				R.PB(len);
			else
				B.PB(len);
		}
		sort(ALL(R));
		reverse(ALL(R));
		sort(ALL(B));
		reverse(ALL(B));

		int sum = 0, cnt = 0;

		FOR(i, min(SZ(R), SZ(B))) {
			sum += R[i] + B[i];
			cnt += 2;
		}

		printf("Case #%d: %d\n", kase++, max(0, sum - cnt));
	}

}


