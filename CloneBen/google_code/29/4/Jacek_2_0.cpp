#include <iostream>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define REP(i,n) FOR(i,0,n)
#define SIZE(c) (int((c).size()))
typedef long long LL;

const LL threshold = (1LL << 32) + 1LL;

const int D = 1 << 17;
LL res[D][40];

int main() {
	REP(d,D)
		res[d][0] = 0;
	REP(b,40)
		res[0][b] = 0;
	FOR(d,1,D) FOR(b,1,40)
		res[d][b] = (res[d-1][b-1] + res[d-1][b] + 1) <? threshold;
	int cc;
	cin >> cc;
	REP(c,cc) {
		int f, d, b;
		cin >> f >> d >> b;
		LL fmax;
		int dmin, bmin = 0;
		if (b == 0)
			fmax = dmin = bmin = 0;
		else if (b == 1) {
			fmax = d;
			dmin = f;
			d <?= D-1;
		} else {
			if (d >= f)
				bmin = 1;
			b <?= 39;
			d <?= D-1;
			fmax = res[d][b] == threshold ? -1 : res[d][b];
			REP(i,d+1)
				if (res[i][b] >= f) {
					dmin = i;
					break;
				}
		}
		if (!bmin)
			REP(i,b+1)
				if (res[d][i] >= f) {
					bmin = i;
					break;
				}
		cout << "Case #" << c+1 << ": " << fmax << " " << dmin << " " << bmin << endl;
	}
}
