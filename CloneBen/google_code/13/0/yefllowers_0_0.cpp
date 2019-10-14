#include<cstdio>
#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<string>
#include<sstream>
#include<vector>
#include<map>
#include<set>
#include<bitset>
#include<algorithm>
#include<cassert>
#include<ctime>
#include<queue>
using namespace std;

#define REP(i,n) for(int i = 0; i < (int)n; i++)
#define FOR(i,n,m) for(int i = (int)n; i <= (int)m; i++)
#define FOD(i,n,m) for(int i = (int)n; i >= (int)m; i--)
#define EACH(i,v) for(__typeof((v).begin()) i = (v).begin(); i != (v).end(); i++)

typedef long long i64;
typedef pair<int, int> PI;

#define sz(v) ((i64)(v).size())
#define all(v) (v).begin(),(v).end()
#define bit(n) (1LL<<(i64)(n))

#define PB push_back
#define MP make_pair
#define X first
#define Y second
template<class T> void fmax(T &a, const T &b) { if (a < b) a = b; }
template<class T> void fmin(T &a, const T &b) { if (a > b) a = b; }
template<class T> T sqr(const T &a) { return a * a; }

map <string, int> F;
int n, m, Z;
int a[222][222];
int v[222];

int id(string s) {
	if (F.count(s)) return F[s];
	F[s] = ++Z;
	return F[s];
}

bool dfs(int i, int u) {
	v[i] = u;
	FOR(j, 1, Z) 
	if (a[i][j] && !v[j]) {
		if (!dfs(j, 3 - u)) return false;
	} else 
	if (a[i][j] && v[j] && v[j] == v[i])
		return false;
	return true;
}

int main() {
	int Te;
	scanf("%d", &Te);
	for (int Ti = 1; Ti <= Te; Ti++) {
		cin >> m;
		memset(a, 0, sizeof(a));
		F.clear();
		Z = 0;
		FOR(M, 1, m) {
			string s, t;
			cin >> s >> t;
			int is = id(s);
			int it = id(t);
			a[is][it] = a[it][is] = true;
	//		cout << is << ' ' << it << endl;
		}
		memset(v, 0, sizeof(v));
		bool ok = true;
		FOR(i, 1, Z) if (!v[i] && !dfs(i, 1)) {
			ok = false;
			break;
		}
		if (ok)
		printf("Case #%d: Yes\n", Ti);
		else
		printf("Case #%d: No\n", Ti);

	}
}