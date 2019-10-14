#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 50 + 3;
const int MAXM = 100 + 3;

int n, m, sz, tr[MAXN*MAXM][2];
bool mark[MAXN*MAXM];
ll dp[MAXN][MAXN*MAXM];

int insert(string &s){
	int cur = 0;
	for (char c:s){
		int z = (c == 'B'? 0: 1);
		if (!tr[cur][z])
			tr[cur][z] = ++sz;
		cur = tr[cur][z];
	}
	return cur;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int te;	cin >> te;
	for (int w = 1; w <= te; w++){
		cout << "Case #" << w << ": ";
		cin >> n >> m;
		sz = 0;

		memset(mark, 0, sizeof(mark));
		memset(tr, 0, sizeof(tr));
		for (int i = 0; i < m; i++){
			string s;
			cin >> s;
			mark[insert(s)] = true;
		}

		memset(dp, 0, sizeof(dp));
		dp[0][0] = 1;
		for (int i = 0; i < n; i++){
			for (int cur = 0; cur <= sz; cur++)
				for (int w = 0; w < 2; w++){
					int nxt = tr[cur][w];
					if (nxt == 0) nxt = sz+1;
					if (!mark[nxt])
						dp[i+1][nxt] += dp[i][cur];
				}

			for (int w = 0; w < 2; w++)
				dp[i+1][sz+1] += dp[i][sz+1];
		}

		ll ans = 0;
		for (int i = 0; i <= sz+1; i++)
			ans += dp[n][i];
		cout << ans << "\n";
	}
	return 0;
}
