#include <cstdio>
#include <string>
#include <map>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cassert>

using namespace std;

struct CTS {
	long long c;
	long long t;
	int s;
	bool operator < (const CTS & x) const {
		return s < x.s;
	}
};

struct BE {
	BE(long long b, long long e) {
		this->b = b;
		this->e = e;
	}
	long long b;
	long long e;
};

CTS cts[100];


int main() {
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; ++t) {
		int N;
		long long K;
		scanf("%d%lld", &N, &K);
		for(int i=0; i<N; ++i) {
			scanf("%lld%lld%d", &cts[i].c, &cts[i].t, &cts[i].s);
			cts[i].t -= 1;
		}
		vector<BE> beList;
		beList.push_back(BE(0, K-1));
		sort(cts, cts + N);
		long long ssum = 0;
		for(int i=N-1; 0<=i; --i) {
			vector<BE> beList2;
			long long c = cts[i].c;
			long long t = cts[i].t;
			for(int j=0; j<(int)beList.size(); ++j) {
				long long b = beList[j].b;
				long long e = beList[j].e;
				if(b <= t) {
					int ee = min(e, t);
					int cc = min(c, ee-b+1);
					c -= cc;
					ssum += cc * cts[i].s;
					int bb = ee - cc + 1;
					assert(cc<=e-b+1);
					if(ee!=e) {
						beList2.push_back(BE(ee+1, e));
					}
					if(bb!=b) {
						beList2.push_back(BE(b, bb-1));
					}
				}
				else {
					beList2.push_back(beList[j]);
				}
			}
			beList = beList2;
		}

		printf("Case #%d: %lld\n", t+1, ssum);
	}
	return 0;
}
