#include <bits/stdc++.h>
using namespace std;
typedef tuple<int, int, int> tp;
typedef long long LL;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<int, LL> pil;
typedef pair<LL, int> pli;
typedef pair<LL, LL> pll;
typedef pair<pii, int> piipi;
typedef pair<int, pii> pipii;
typedef pair<pii, pii> piipii;
typedef pair<LL, pii> plpii;
typedef pair<LD, LD> pdd;
typedef pair<LD, int> pdi;
typedef pair<LD, LL> pdl;
typedef pair<int, LD> pid;
typedef pair<LL, LD> pld;
const int mod = 1e9 + 7;
const int hf = 999983;
const int N = 1e6;
int v[105][105];
int tidx[105][105];
int idx[105][105];
bool vis[105][105];
bool mark[20];
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

LL dp[(1<<15)+5];
LL dp2[(1<<15)+5];

int p[20005];
LL val[20005];
LL r[20];

pii trapidx[20];

int root(int a){
	return p[a] == a?a:(p[a]=root(p[a]));
}
void merge(int a, int b){
	a = root(a), b = root(b);
	if(a != b){
		// cout << a << " " << b << " -> " << val[a] << " " << val[b] << endl;
		p[a] = b;
		val[b] += val[a];
	}
}

void solve(int tt){
	cerr << tt  << endl;
	memset(dp, -1, sizeof(dp));
	memset(dp2, -1, sizeof(dp2));
	memset(idx, -1, sizeof(idx));
	int n, m, e, sr, sc, tr, tc;
	scanf("%d%d%d%d%d%d%d", &n, &m, &e, &sr, &sc, &tr, &tc);
	int trap = 0;
	int id = 1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%d", &v[i][j]);
			if(v[i][j] == -100000) continue;
			if(v[i][j] < 0){
				r[trap] = v[i][j];
				trapidx[trap] = pii(i, j);
				tidx[i][j] = trap++;
			}
			idx[i][j] = id++;
		}
	}

	id--;
	LL ans = -1;
	for(int k=0;k<(1<<trap);k++){
		memset(mark, 0, sizeof(mark));

		for(int j=0;j<trap;j++){
			if( (k>>j)&1 ){
				mark[j] = 1;
			}
		}

		
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				p[idx[i][j]] = idx[i][j];
				val[idx[i][j]] = v[i][j];
			}
		}

		memset(vis, 0, sizeof(vis));
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(v[i][j] == -100000) continue;
				if(v[i][j] < 0){
					if(!mark[tidx[i][j]]) continue;
				}
				for(int x=0;x<4;x++){
					int vy = i+dir[x][0];
					int vx = j+dir[x][1];
					if(vy >= 1 && vy <= n && vx >= 1 && vx <= m && v[vy][vx] != -100000){
						if(v[vy][vx] < 0){
							if(!mark[tidx[vy][vx]]) continue;
							// cout << "merge " << i << " " << j << " " << idx[i][j] << " " << idx[vy][vx] << endl;
							merge(idx[i][j], idx[vy][vx]);
						}
						else{
							merge(idx[i][j], idx[vy][vx]);
						}
					}
				}
			}
		}

		bool ok = 1;
		for(int j=0;j<trap;j++){
			if(!mark[j]) continue;
			int ty = trapidx[j].first;
			int tx = trapidx[j].second;
			if(root(idx[ty][tx]) != root(idx[sr][sc])) ok = 0;
		}
		if(!ok) continue;

		if(k == 0 && val[root(idx[sr][sc])]+e >= 0){
			dp2[k] = val[root(idx[sr][sc])]+e;
		}
		else{
			for(int j=0;j<trap;j++){
				if(!mark[j]) continue;

				int rem = k^(1<<j);
				if(dp2[rem] >= 0){
					if(dp2[rem]+r[j] >= 0 && val[root(idx[sr][sc])]+e >= 0){
						// cout << "dp2 " << k << " -> " << rem << " dp2 " << dp2[rem] << " " << val[root(idx[sr][sc])]+e << endl;
						dp2[k] = max(dp2[k], val[root(idx[sr][sc])]+e);
					}
				}
			}
		}
		if(root(idx[sr][sc]) != root(idx[tr][tc])) continue;
		if(k == 0 && val[root(idx[tr][tc])]+e >= 0){
			dp[k] = val[root(idx[tr][tc])]+e;
		}
		else{
			for(int j=0;j<trap;j++){
				if(!mark[j]) continue;

				int rem = k^(1<<j);
				if(dp2[rem] >= 0){
					if(dp2[rem]+r[j] >= 0 && val[root(idx[tr][tc])]+e >= 0){
						// cout << "k : " << k << " " << rem << " " << dp2[rem] << endl;
						dp[k] = max(dp[k], val[root(idx[tr][tc])]+e);
					}
				}
			}
		}
		// cout << k << endl;
		ans = max(ans, dp[k]);
	}
	printf("Case #%d: %lld\n", tt, ans);
}
int main(){
	int t;
	scanf("%d", &t);	
	for(int tt=1;tt<=t;tt++) solve(tt);
}