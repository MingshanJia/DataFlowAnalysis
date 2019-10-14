#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <sstream>
#include <complex>
#include <ctime>
#include <cassert>
#include <functional>

using namespace std;

typedef long long ll;
typedef vector<int> VI;
typedef pair<int, int> PII;

#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define FILL(x,v) memset(x,v,sizeof(x))

const int INF = (int)1E7;
#define MAXN 35

int P, p[MAXN], mp[MAXN];
int dp[1000005], u[10];
int getd(int x){
	int ans = 0;
	while (x){
		int g = x % 10;
		if (!u[g]) return INF;
		x /= 10;
		ans++;
	}
	return ans;
}
int aikhtsi(int X){
	if (dp[X] != -1) return dp[X];
	int sol = getd(X);
	REP(i, 2, 1005){
		if (i*i > X) break;
		if (X%i == 0){
			int a = i, b = X / i;
			int sl = aikhtsi(a);
			int sr = aikhtsi(b);
			sol = min(sol, sl + sr + 1);
		}
	}
	dp[X] = sol;
	return sol;
}
int main(){
	int cs;
	cin >> cs;
	REP(csn, 1, cs + 1){
		printf("Case #%d: ", csn);
		int X;
		REP(i, 0, 10){
			int t;
			scanf("%d", &t);
			u[i] = t;
		}
		cin >> X;
		FILL(dp, -1);
		int ans = aikhtsi(X);
		if (ans == INF) puts("Impossible");
		else printf("%d\n", ans+1);
	}
}