#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main()
{
	int tc;
	scanf("%d", &tc);
	for (int ti = 1;ti <= tc;ti++)
	{
		int treeN, target, stickN;
		map<int, int> sticks;

		scanf("%d %d %d", &treeN, &stickN, &target);
		for (int i = 0;i < stickN;i++)
		{
			int p, q;
			scanf("%d %d", &p, &q);
			sticks[p] += q;
		}
		sticks[0] = 0x3FFFFFFF;

		vector< pair<int, pair<int, int> > > ways;

		map<int, int>::iterator it, jt;
		for (it = sticks.begin();it != sticks.end();it++)
		{
			for (jt = it;jt != sticks.end();jt++)
			{
				if (it->first + jt->first >= target)
					ways.push_back(make_pair(it->first + jt->first, make_pair(it->first, jt->first)));
			}
		}

		sort(ways.begin(), ways.end());

		long long ans = 0;
		vector< pair<int, pair<int, int> > >::iterator kt;
		for (kt = ways.begin();kt != ways.end();kt++)
		{
			int val = kt->first;
			int p = kt->second.first;
			int q = kt->second.second;
			int &pcnt = sticks[p];
			int &qcnt = sticks[q];
			int cnt = (p != q ? min(pcnt, qcnt) : pcnt / 2);

			int to_remove = min(cnt, treeN);
			treeN -= to_remove;
			ans += (long long)val * to_remove;
			pcnt -= to_remove;
			qcnt -= to_remove;
		}

		if (treeN > 0)
			ans = -1;
		printf("Case #%d: %lld\n", ti, ans);
	}
	return 0;
}
