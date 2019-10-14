#include <algorithm>
#include <iostream>
#include <complex>
#include <numeric>
#include <vector>
#include <string>
#include <cstdio>
#include <queue>
#include <cmath>
#include <map>
#include <set>

using namespace std;

#define all(a) (a).begin(),(a).end()
#define sz(a) int((a).size())
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define REP(i,n) FOR(i,0,n)
#define UN(v) sort(all(v)),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define CL(a,b) memset(a,b,sizeof a)
#define pb push_back
#define X first
#define Y second

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

int t, p,q, a[200], c,m;
bool y[200];

int main()
{
freopen("c-small-attempt0.in", "r", stdin);
freopen("c-small.out", "w", stdout);
	scanf("%d", &t);
	REP(it, t)
	{
		scanf("%d%d", &p, &q);
		REP(i, q) scanf("%d", &a[i]), --a[i];
		m=p*q;
		do
		{
			CL(y, 0);
			c=0;
			REP(i, q)
			{
				int j=a[i]-1;
				y[a[i]]=1;
				while(j>=0 && !y[j]) ++c, --j;
				j=a[i]+1;
				while(j<p && !y[j]) ++c, ++j;
			}
			m=min(m, c);
		} while(next_permutation(a, a+q));
		printf("Case #%d: %d\n", it+1, m);
	}	
	return 0;
}
