#include <cstdio>
#include <cmath>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <utility>
#include <stack>
#include <queue>
#include <map>

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define pii pair<int,int> 
#define pdd pair<double,double> 
#define LL long long

#define PI 2*acos(0.0)
#define EPS 1e-9
#define INF 1000000000

using namespace std;

int T, N;
int dp[1000010];
bool bisa[15];
vector<int> factor, temp, avail, cost;

int solve(int num)
{
	if(num == N) return 1;
	if(num > N) return INF;
	if(dp[num] != -1) return dp[num];

	int &ret = dp[num] = INF;
	for(int i = 0; i < avail.size(); i++)
	{
		int next = num ? num * avail[i] : avail[i];
		int tekan = num ? cost[i] + 1 : cost[i];
 
		ret = min(ret, solve(next) + tekan);
	}

	return ret;
}

int main()
{
	scanf("%d", &T);
	for(int t = 1; t <= T; t++)
	{
		for(int i = 0; i < 10; i++) scanf("%d", &bisa[i]);
		scanf("%d", &N);

		factor.clear(); temp.clear();
		for(int i = 1; i * i <= N; i++) if(N % i == 0)
		{
			factor.pb(i);
			if(i * i != N) temp.pb(N / i);
		}

		for(int i = (int) temp.size() - 1; i >= 0; i--) factor.pb(temp[i]);

		avail.clear(); cost.clear();
		for(int i = 0; i < factor.size(); i++)
		{
			int temp = factor[i], digit = 0;
			bool oke = true;

			while(temp > 0 && oke)
			{
				int chopped = temp % 10;
				temp /= 10;
				digit++;

				if(!bisa[chopped]) oke = false;
			}

			if(oke) 
			{
				avail.pb(factor[i]);
				cost.pb(digit);
			}
		}

		memset(dp, -1, sizeof(dp));
		int ans = solve(0);

		printf("Case #%d: ", t);
		if(ans == INF) printf("Impossible\n"); else printf("%d\n", ans);
	}
	return 0;
}

