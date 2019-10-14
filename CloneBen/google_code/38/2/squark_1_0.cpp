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
const int MAXN = 1123;
const int P = 1e9+7;

int f[MAXN];
vector<pair<int, int> > e[MAXN];
int u[MAXN*2], v[MAXN*2];
bool vis[MAXN];
int _prev[MAXN];
int q[MAXN];
vector<int> r;
vector<int> x;

bool bfs(int i){
	int h, t;
	memset(vis, false, sizeof vis);
	h = t = 0;
	q[t++] = v[i];
	vis[v[i]] = true;
	while(h < t && !vis[u[i]]){
		int j = q[h++];
		for(int k = 0; k < e[j].size(); k++){
			if(abs(e[j][k].se) != i && !vis[e[j][k].fi]){
				_prev[e[j][k].fi] = e[j][k].se;
				q[t++] = e[j][k].fi;
				vis[e[j][k].fi] = true;
			}
		}
	}
	if(!vis[u[i]])
		return false;
	return true;
}

void backtrace(int i){
	assert(vis[u[i]]);
	r.clear();
	r.pb(i);
	int j = u[i];
	while(j != v[i]){
		r.pb(_prev[j]);
		int k = abs(_prev[j]);
		j = j ^ u[k] ^ v[k];
	}
}

int get(int i){
	if(i > 0)
		return f[i];
	else
		return -f[-i];
}

void add(int i, int x){
	if(i > 0)
		f[i] += x;
	else
		f[-i] -= x;
}

int findFirst1(const vector<int> &x){
	int i, j, k;
	i = find(x.begin(), x.end(), 0) - x.begin();
	if(i == x.size())
		return 0;
	while(i+1 < (int)x.size() && x[i+1] - x[i] <= 1)
		i++;
	return x[i]+1;
}

int findFirst2(const vector<int> &x){
	int i, j, k;
	i = find(x.begin(), x.end(), 0) - x.begin();
	if(i == x.size())
		return 0;
	while(i > 0 && x[i] - x[i-1] <= 1)
		i--;
	return x[i]-1;
}

int main(){
#ifdef LOCAL
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#endif
	int T, i0;
	scanf("%d", &T);
	for(i0 = 1; i0 <= T; i0++){
		int i, j, k;
		int n, m;
		scanf("%d%d", &n, &m);
		for(i = 1; i <= m; i++){
			scanf("%d%d", &j, &k);
			e[j].pb(mp(k, i));
			e[k].pb(mp(j, -i));
			u[i] = j;
			v[i] = k;
		}
		bool bad = false;
		while(true){
			for(i = 1; i <= m; i++)
				if(f[i] == 0)
					break;
			if(i > m)
				break;
			if(!bfs(i)){
				bad = true;
				break;
			}
			backtrace(i);
			x.clear();
			for(int j : r)
				x.pb(-get(j));
			sort(x.begin(), x.end());
			j = findFirst1(x);
			k = findFirst2(x);
			if(-k < j)
				j = k;
			for(int k : r)
				add(k, j);
		}

		for(i = 1; i <= m; i++)
			assert(abs(f[i]) <= n*n);

		printf("Case #%d: ", i0);
		if(bad)
			printf("IMPOSSIBLE\n");
		else{
			for(i = 1; i <= m; i++)
				printf("%d ", f[i]);
			printf("\n");
		}

		for(i = 1; i <= n; i++)
			e[i].clear();
		for(i = 1; i <= m; i++)
			f[i] = 0;
	}
	return 0;
}
