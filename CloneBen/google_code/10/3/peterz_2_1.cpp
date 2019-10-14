#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<set>
#include<queue>
#include<map>
using namespace std;
#define PII pair<int,int>
#define X first
#define Y second
#define PB push_back
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define FOE(i,a,b) for (int i=(a);i<=(b);i++)
#define INF (1 << 30)
#define EPS (1e-9)
#define REP(i,n) FOR(i,0,n)
#define LL long long
#define N 20000
int n, m, eq, q, st, end;
int nx[N], p[N], v[N], u[N], w[N], sz, t, col[N], pre[N], mid, ok, vis[N];
map<string, int> mp;
vector<int> vec, vec2, vec3;
char s[N];
void add(int x, int y, int z){
	nx[sz] = p[x]; v[sz] = y; w[sz] = z; p[x] = sz++;
	nx[sz] = p[y]; v[sz] = x; w[sz] = z; p[y] = sz++;
}

int dfs1(int x){
	vis[x] = 1;
	if (x == end) return 1;
	for (int i = p[x]; i != -1; i = nx[i]){
		int y = v[i];
		if (vis[y]) continue;
		pre[y] = x;
		col[y] = 1 - col[x];
		if (dfs1(y)) return 1;
	}
	return 0;
}

int dfs2(int x){
	vis[x] = 1;
	for (int i = p[x]; i != -1; i = nx[i]){
		int y = v[i];
		if (vis[y]){
			if (col[y] == 1 - col[x]) continue;
			if (y != x){
				mid = y;
				ok = 1;
			}
			vec2.PB(w[i]);
			return 1;
		}
		else{
			if (col[y] == -1) col[y] = 1 - col[x];
			if (dfs2(y)){
				if (ok) vec2.PB(w[i]);
				if (x == mid) ok = 0;
				return 1;
			}
		}
	}
	return 0;
}

int dfs3(int x, int z){
	vis[x] = 1;
	if (x == z) return 1;
	for (int i = p[x]; i != -1; i = nx[i]){
		int y = v[i];
		if (vis[y]) continue;
		if (!dfs3(y, z)) continue;
		vec3.PB(w[i]);
		//printf("%d\n", w[i]);
		return 1;
	}
	return 0;
}

int main(){
	int T;
	scanf("%d", &T);
	FOE(cc,1,T){
		mp.clear();
		sz = n = 0;
		memset(p, -1, sizeof(p));
		printf("Case #%d:\n", cc);
		scanf("%d", &eq);
		FOR(i,0,eq){
			scanf("%s", s);
			char *pt = strtok(s, "+=");
			int a, b, c;
			if (!mp.count(pt)) mp[pt] = n++;
			a = mp[pt];
			pt = strtok(NULL, "+=");
			if (!mp.count(pt)) mp[pt] = n++;
			b = mp[pt];
			pt = strtok(NULL, "+=");
			c = atol(pt);
			add(a, b, c);
		}
		scanf("%d", &q);
		FOR(i,0,q){
			vec.clear();
			vec2.clear();
			vec3.clear();
		memset(col, -1, sizeof(col));
			scanf("%s", s);
			char *pt = strtok(s, "+");
			string s1, s2;
			int x, y;
			if (!mp.count(pt)) continue;
			else x = mp[pt];
			s1 = pt;
			
			pt = strtok(NULL, "+=");
			if (!mp.count(pt)) continue;
			else y = mp[pt];
			s2 = pt;

			memset(vis, 0, sizeof(vis));
			st = x, end = y;
			col[x] = 0;
			if (!dfs1(x)) continue;
			if (col[x] != col[y]){
				int ans = 0;
				memset(vis, 0, sizeof(vis));
				dfs3(x, y);
				FOR(i,0,vec3.size()) vec.PB(vec3[i]);
				FOR(i,0,vec.size()) if (i & 1) ans -= vec[i]; else ans += vec[i];
				printf("%s+%s=%d\n", s1.c_str(), s2.c_str(), ans);
				continue;	
			}
			memset(vis, 0, sizeof(vis));
			ok = 0;
			if (!dfs2(x)) continue;
			//printf("%d\n", mid);
			memset(vis, 0, sizeof(vis));
			dfs3(mid, x);
			FOR(i,0,vec3.size()) vec.PB(vec3[i]);
			memset(vis, 0, sizeof(vis));
			vec3.clear();
			dfs3(y, mid);
			FOR(i,0,vec2.size()) vec.PB(vec2[i]);
			if (!((vec.size() + vec3.size()) & 1))
				FOR(i,0,vec2.size()) vec.PB(vec2[i]);
			FOR(i,0,vec3.size()) vec.PB(vec3[i]);
			int ans = 0;
			FOR(i,0,vec.size()) if (i & 1) ans -= vec[i]; else ans += vec[i];
			printf("%s+%s=%d\n", s1.c_str(), s2.c_str(), ans);
		}
	}
	return 0;
}
