// GCJ 2012 Korea Semifinal

#define PROB "A"
#define CONSOLE false  

#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <iostream>
#include <map>
#include <string>

#pragma warning(disable:4996)
using namespace std;

#define REP(i, n) for(int i=0; i<(int)(n); ++i)
#define all(v) (v).begin(), (v).end()
#define uniquify(v) {sort(all(v));(v).erase(unique(all(v)), (v).end());}

int N,A,B,C,D,E,F;

int P14, P15, P16, P24, P25, P26, P34, P35, P36;

int solve()
{
	int ans = -2147483648;
	for(int p=0; p<=A; ++p) {
		for(int q=0; q<=A-p; ++q) {
			for(int r=0; r<=B; ++r) {
				for(int s=0; s<=B-r; ++s) {
					int pq = A-p-q;
					int rs = B-r-s;
					int cx = D - p-r;
					int cy = E - q-s;
					int cz = F - pq - rs;
					if(cx < 0 || cy < 0 || cz < 0) continue;

					if(p + r + cx == D && q + s + cy == E && pq + rs + cz == F);
					else continue;

					int t = P14 * p + P15 * q + P16 * pq +
						P24 * r + P25 * s + P26 * rs +
						P34 * cx + P35 * cy + P36 * cz;
					ans = max(ans, t);
				}
			}
		}
	}
	return ans;

}


int main()
{
	freopen(PROB".in", "r", stdin);
	freopen(PROB".out", "w", stdout);

	int T;
	scanf("%d", &T);

	for(int tt = 1; tt <= T; ++ tt)
	{
		cin >> N;
		cin >> A >> B >> C;
		cin >> D >> E >> F;
		cin >> P14 >> P15 >> P16 >> P24 >> P25 >> P26 >>
				P34 >> P35 >> P36;

		fprintf(stderr, "<!> %d\n", tt);
		printf("Case #%d: %d\n", tt, solve()); 

	}

	return 0;
}
