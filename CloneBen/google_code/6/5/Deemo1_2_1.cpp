#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 2e5 + 10;
const int MOD = 1e9 + 7;

int n, m;
int ss[MAXN], tt[MAXN];

int pw(int a, int b){
	int ret = 1;
	while (b){
		if (b & 1)
			ret = 1ll*ret*a%MOD;
		b >>= 1;
		a = 1ll*a*a%MOD;
	}
	return ret;
}

int choose(int a, int b){
	if (a < b) return 0;
	return 1ll*ss[a]*tt[b]%MOD*tt[a-b]%MOD;
}

void add(int &x, int y){
	x += y;
	while (x >= MOD) x -= MOD;
	while (x < 0) x += MOD;
}

int get(int t){
	return 1ll*choose(m, t)*ss[2*n-t]%MOD*pw(2, t)%MOD;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ss[0] = 1;
	for (int i = 1; i < MAXN; i++) ss[i] = 1ll*ss[i-1]*i%MOD;
	tt[0] = 1;
	for (int i = 1; i < MAXN; i++) tt[i] = 1ll*tt[i-1]*pw(i, MOD-2)%MOD;

	int te;	cin >> te;
	for (int w = 1; w <= te; w++){
		cout << "Case #" << w << ": ";
		cin >> n >> m;
		int ans = ss[2*n];
		for (int t = 1; t <= m; t++){
			int temp = get(t);
			if (t & 1)
				add(ans, -temp);
			else
				add(ans, temp);
		}
		cout << ans << "\n";
	}
	return 0;
}
