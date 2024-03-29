#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:64000000")
#include <algorithm>
#include <numeric>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <iostream>
#include <iterator>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <sstream>

using namespace std;

#define REP(i,n) for (int i=0,_n=(n); i < _n; i++)
#define REPD(i,n) for (int i=(n)-1; i >= 0; i--)
#define FOR(i,a,b) for (int _b=(b), i=(a); i <= _b; i++)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;i--)
#define ALL(c) (c).begin(), (c).end()
#define SORT(c) sort(ALL(c))

#define CLEAR(x) memset(x,0,sizeof x);
#define CLEARA(x) memset(&x,0,sizeof x);
#define FILL(x,v) memset(x,v,sizeof x);
#define FILLA(x,v) memset(&x,v,sizeof x);

#define VAR(a,b) __typeof(b) a=(b)
#define FOREACH(it,c) for(VAR(it,(c).begin());it!=(c).end();++it)

#define REVERSE(c) reverse(ALL(c))
#define UNIQUE(c) SORT(c),(c).resize(unique(ALL(c))-(c).begin())
#define INF 0x7fffffff
#define X first
#define Y second
#define pb push_back
#define SZ(c) (int)(c).size()
#define MP make_pair
#define eps 1.0e-11
const double pi = acos(-1.0);

typedef pair<int, int> PII;
typedef vector<PII> VPII;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long LL;

#define FN "C-small-attempt2"

#define N 256
LL m,f;
int n;
map<LL,LL> bb;
pair<LL,LL> b[N];
LL sum[N];
int bk;

LL getCost(LL days) {
	if (days == 0) return 0;
	--days;
	if (days > b[bk-1].first)
		cerr << "bad getcost\n";
	int p = lower_bound(b,b+bk,make_pair(days,-1LL))-b;
	LL prev = p == 0 ? -1 : b[p-1].first;
	return sum[p] + (days-prev)*b[p].second;
}

LL getDays(LL cost) {
	if (cost < sum[0]) return 0;
	REP(i,n) if (cost <= sum[i+1])
	{
		return (i==0 ? -1 : b[i-1].first)+1+(cost-sum[i])/b[i].second;
	}
	return 0;
}

LL gcost[2048000];
LL gdays[2048000];

int main()
{
	freopen(FN ".in","r",stdin);
	freopen(FN ".out","w",stdout);

	int tests;
	scanf("%d",&tests);
	for (int test = 1; test<=tests; test++)
	{
		cerr << "*\n";
		cin >> m >> f >> n;
		bb.clear();
		REP(i,n) {
			LL p,s;
			cin >> p >> s;
			bb[p] = max(bb[p], s);
		}
		bk=0;
		for (map<LL,LL>::iterator it = bb.begin(); it != bb.end(); ++it) {
			if (bk == 0 || it->second > b[bk-1].first)
				b[bk++] = make_pair(it->second, it->first);
		}

		gcost[0] = 0;
		for (int i = 1, j = 0; i <= m; i++) {
			while (j<bk && b[j].first < i-1) ++j;
			LL cur = j==bk ? 1LL<<32 : b[j].second;
			gcost[i] = gcost[i-1];
			if (i==1) gcost[i] += f;
			gcost[i] += cur;
		}
		CLEAR(gdays);
		REP(i,m+1) if (gcost[i] < 2048000)
			gdays[gcost[i]] = max(gdays[gcost[i]], (LL)i);
		FOR(x,1,2048000-1) gdays[x] = max(gdays[x-1],gdays[x]);

		/*sum[0]=f;
		LL prev = -1;
		REP(i,bk) {
			LL days = b[i].second == 0 ? b[i].first - prev : (m-sum[i])/b[i].second;
			LL end = min(b[i].first, prev+days);
			if (end < b[i].first) {
				bk = i+1;
				b[i].first = end;
				if (days == 0) --bk;
				else
				{
					sum[i+1] = sum[i] + days*b[i].second;
				}
				break;
			}
			sum[i+1] = sum[i] + (b[i].first - prev)*b[i].second;
			prev = b[i].first;
		}*/

		LL res = 0;
		if (bk > 0)
		{
			FOR(k,1,m/f) {
				LL cost1 = m/k;//min(sum[bk],m/k);
				LL days1 = gdays[cost1];
				LL ccc1 = gcost[days1];
				LL cur = k*days1;
				LL over = m-ccc1*k;
				//if (days1 < b[bk-1].first) {
					LL ccc2 = gcost[(days1+1)];
					//if (ccc1==ccc2) cerr << "!!!!xx\n";
					if (ccc2 > ccc1) cur += over/(ccc2-ccc1);
				//}
				res = max(res,cur);
			}
		}

		cout << "Case #" << test << ": " << res << endl;
	}
	return 0;
}