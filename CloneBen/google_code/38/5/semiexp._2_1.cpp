#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define MOD
#define ADD(X,Y) ((X) = ((X) + (Y)%MOD) % MOD)
typedef long long i64; typedef vector<int> ivec; typedef vector<string> svec;

int T;
int C;
int S[2020], E[2020], L[2020], D[2020];
vector<int> din[1010], dout[1010];

int trans(int t, int l, int d)
{
	if (t % 24 <= l) {
		return t / 24 * 24 + l + d;
	}
	return (t / 24 + 1) * 24 + l + d;
}
int wt(int t)
{
	while (t < 0) t += 24;
	return t % 24;
}
int waittime(int a, int b)
{
	return wt(L[b] - (L[a] + D[a]));
}

int uf[2020];
int root(int p)
{
	return uf[p] < 0 ? p : (uf[p] = root(uf[p]));
}
bool join(int p, int q)
{
	p = root(p);
	q = root(q);
	if (p == q) return false;
	uf[p] += uf[q];
	uf[q] = p;
	return true;
}

int solve(int ia, int ib)
{
	vector<pair<int, pair<int, int> > > edges;
	int ret = 0;
	ret += L[dout[0][1 - ib]];
	ret += waittime(din[0][ia], dout[0][ib]);
	edges.push_back({ 0, {din[0][ia], dout[0][ib]} });
	for (int i = 1; i < C; ++i) {
		int t00 = waittime(din[i][0], dout[i][0]) + waittime(din[i][1], dout[i][1]);
		int t01 = waittime(din[i][0], dout[i][1]) + waittime(din[i][1], dout[i][0]);
		if (t00 <= t01) {
			edges.push_back({ 0, { din[i][0], dout[i][0] } });
			edges.push_back({ 0, { din[i][1], dout[i][1] } });
		} else {
			edges.push_back({ 0, { din[i][0], dout[i][1] } });
			edges.push_back({ 0, { din[i][1], dout[i][0] } });
		}
		ret += min(t00, t01);
		edges.push_back({ max(t00, t01) - min(t00, t01), {din[i][0], din[i][1]} });
	}
	for (int i = 0; i < 2 * C; ++i) uf[i] = -1;
	int n_con = 2 * C;
	sort(edges.begin(), edges.end());
	for (auto e : edges) {
		if (join(e.second.first, e.second.second)) {
			--n_con;
			ret += e.first;
		}
	}
	return ret;
}

int main()
{
	scanf("%d", &T);
	for (int t = 0; t++ < T;){
		scanf("%d", &C);

		for (int i = 0; i < C; ++i) {
			dout[i].clear();
			din[i].clear();
		}
		for (int i = 0; i < 2 * C; ++i) {
			scanf("%d%d%d", E + i, L + i, D + i);
			S[i] = i / 2;
			--E[i];

			dout[S[i]].push_back(i);
			din[E[i]].push_back(i);
		}

		int ret = 2100000000;
		for (int i = 0; i < 2; ++i) {
			for (int j = 0; j < 2; ++j) {
				ret = min(ret, solve(i, j));
			}
		}
		for (int i = 0; i < 2 * C; ++i) ret += D[i];
		printf("Case #%d: %d\n", t, ret);
	}

	return 0;
}
