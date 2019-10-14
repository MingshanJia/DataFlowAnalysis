#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <map>
#include <set>
#include <functional>
#include <utility>
#include <algorithm>

using namespace std;

const int MAXN = 15;
const double AIM = 1000000;

int main() {
	map<double, double, greater<double> > pMap[MAXN + 1];
	int caseNum;
	scanf("%d", &caseNum);
	for (int caseIndex = 1; caseIndex <= caseNum; caseIndex++) {
		int n, x;
		double p;
		scanf("%d%lf%d", &n, &p, &x);
		for (int i = 0; i <= n; i++) {
			pMap[i].clear();
		}
		pMap[0][AIM] = 1.0;
		pMap[0][0] = 0.0;
		for (int i = 0; i < n; i++) {
			map<double, double, greater<double> >::const_iterator iu, id;
			for (iu = pMap[i].begin(); iu != pMap[i].end() && iu->first > 0; ++iu) {
				for (int j = 0; j <= i; j++) {
					for (id = pMap[j].upper_bound(iu->first); id != pMap[j].end(); ++id) {
						//printf("%d %lf %lf\n", i + 1, (id->first + iu->first) / 2.0, p * iu->second + (1 - p) * id->second); 
						double & next = pMap[i + 1][(id->first + iu->first) / 2.0];
						next = max(next, p * iu->second + (1 - p) * id->second);
					}
				}
			}
			pMap[i + 1][AIM] = 1.0;
			pMap[i + 1][0] = 0.0;
		}
		double ans = 0;
		for (int i = 0; i <= n; i++) {
			ans = max(ans, pMap[i].lower_bound(x)->second);
		}

		printf("Case #%d: %.7lf\n", caseIndex, ans);
		
	}

	return 0;
}
