#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
typedef unsigned long long ll;
using namespace std;

#define pb push_back
#define mp make_pair
#define sz size()
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<pii> > adjL;
int oo = (int) 1e9;


int main()
{
	freopen("in.txt","rt",stdin);
	freopen("out.txt" ,"wt",stdout);
	int t;scanf("%d",&t);
	for (int ii = 0; ii < t; ++ii) {
		int m;scanf("%d",&m);
		vector<int >v(12);
		for (int i = 0; i < 12; ++i) {
			scanf("%d",&v[i]);
		}
		int mx = -oo , fidx, lidx, pp = oo;
		for (int i = 0; i < 12; ++i) {
			int nm = m/v[i];
			for (int j = i+1; j < 12; ++j) {
				int p = nm*v[j] - nm*v[i];
				if(p > mx)
					mx = p, fidx = i, lidx = j, pp = v[i];
				if(p==mx && v[i] < pp)
					pp = v[i], fidx = i, lidx = j;
			}
		}
		printf("Case #%d: ",ii+1);
		if(mx<=0)
			printf("IMPOSSIBLE\n");
		else printf("%d %d %d\n", fidx+1, lidx+1, mx);
	}
	return 0;
}
