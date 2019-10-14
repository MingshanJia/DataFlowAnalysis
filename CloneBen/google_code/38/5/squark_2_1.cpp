#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cassert>
using namespace std;
typedef long long ll;
typedef double R;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define FOR(i, s, t) for(i = (s); i < (t); i++)
#define RFOR(i, s, t) for(i = (s)-1; i >= (t); i--)

void debug1(){}

template<class T, class ... Tails>
void debug1(const T &v, const Tails& ... tails){
	cout<<" "<<v;
	debug1(tails...);
}

template<class T, class ... Tails>
void debug(const T &v, const Tails& ... tails){
#ifdef LOCAL
	cout<<"Debug: "<<v;
	debug1(tails...);
	cout<<endl;
#endif
}

const R PI = acos(-1);
const int MAXN = 2123;
const int P = 1e9+7;

int in[MAXN][2], out[MAXN][2];
int s[MAXN], t[MAXN];
int from[MAXN], to[MAXN];
int c[MAXN];
int e[MAXN][2];
bool vis[MAXN];
bool ind[MAXN];
int f[MAXN];
int n;

int r(int x){
	while(x >= 24)
		x -= 24;
	while(x < 0)
		x += 24;
	return x;
}

int getF(int i){
	if(f[i] == i)
		return i;
	return f[i] = getF(f[i]);
}

void merge(int i, int j){
	i = getF(i);
	j = getF(j);
	f[i] = j;
}

int solve(){
	int i, j, k;
	int total = 0;
	for(i = 1; i < n; i++){
		if(r(s[out[i][0]] - t[in[i][0]]) + r(s[out[i][1]] - t[in[i][1]])
				> r(s[out[i][0]] - t[in[i][1]]) + r(s[out[i][1]] - t[in[i][0]]))
			swap(out[i][0], out[i][1]);
		if(r(s[out[i][0]] - t[in[i][0]]) + r(s[out[i][1]] - t[in[i][1]])
				== r(s[out[i][0]] - t[in[i][1]]) + r(s[out[i][1]] - t[in[i][0]]))
			c[i] = 0;
		else
			c[i] = 1;
		total += r(s[out[i][0]] - t[in[i][0]]) + r(s[out[i][1]] - t[in[i][1]]);
	}
	total += min(s[out[0][0]] + r(s[out[0][1]] - t[in[0][1]]), s[out[0][1]] + r(s[out[0][0]] - t[in[0][0]]));

	memset(vis, 0, sizeof vis);
	memset(ind, 0, sizeof ind);
	memset(e, -1, sizeof e);
	for(i = 0; i < n*2; i++)
		if(!vis[i]){
			ind[i] = true;
			f[i] = i;
			j = i;
			while(!vis[j]){
				vis[j] = true;
				if(e[to[j]][0] == -1)
					e[to[j]][0] = i;
				else
					e[to[j]][1] = i;
				if(j == in[to[j]][0])
					j = out[to[j]][0];
				else
					j = out[to[j]][1];
			}
		}
	for(i = 1; i < n; i++)
		if(c[i] == 0)
			merge(e[i][0], e[i][1]);
	int cnt = 0;
	for(i = 0; i < n*2; i++)
		if(ind[i] && f[i] == i)
			cnt++;
	total += (cnt-1) * 24;
	for(i = 1; i < n; i++)
		merge(e[i][0], e[i][1]);
	cnt = 0;
	for(i = 0; i < n*2; i++)
		if(ind[i] && f[i] == i)
			cnt++;
	if(cnt == 1)
		return total;
	return 1<<30;
}

int main(){
#ifdef LOCAL
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#endif
	int T, i0;
	scanf("%d", &T);
	for(i0 = 1; i0 <= T; i0++){
		int total = 0;
		int i, j, k;
		scanf("%d", &n);
		memset(in, -1, sizeof in);
		memset(out, -1, sizeof out);
		for(i = 0; i < 2*n; i++){
			int d;
			scanf("%d%d%d", &to[i], &s[i], &d);
			from[i] = i/2;
			to[i]--;
			if(in[to[i]][0] == -1)
				in[to[i]][0] = i;
			else
				in[to[i]][1] = i;
			if(out[from[i]][0] == -1)
				out[from[i]][0] = i;
			else
				out[from[i]][1] = i;
			total += d;
			t[i] = (s[i] + d) % 24;
		}
		int ans = 1<<30;
		ans = min(ans, total + solve());
		swap(in[0][0], in[0][1]);
		ans = min(ans, total + solve());
//		swap(out[0][0], out[0][1]);
//		ans = min(ans, total + solve());
//		swap(in[0][0], in[0][1]);
//		ans = min(ans, total + solve());
		printf("Case #%d: %d\n", i0, ans);
	}
	return 0;
}
