#define _CRT_SECURE_NO_WARNINGS
#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <vector>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <numeric>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <ctime>
using namespace std;

typedef long long int64;
typedef vector<int> vi;
typedef vector<string> vs;

template<typename T> inline T sqr(T a) { return a*a; }
template<typename T> inline int Size(const T& c) { return (int)c.size(); }

#define For(i, a, b) for (int i = int(a), _b = int(b); i <= _b; ++i)
#define Ford(i, a, b) for (int i = int(a), _b = int(b); i >= _b; --i)
#define Rep(i, n) for (int i = 0, _n = int(n); i < _n; ++i)
#define Repd(i, n) for (int i = int(n)-1; i >= 0; --i)
#define Fill(a, c) memset(&a, c, sizeof(a))
#define MP(x, y) make_pair(x, y)
#define All(v) (v).begin(), (v).end()

const int mod = 9901;
const int rev2 = 4951;

int n, k;
int a[15], b[15];

int solve(int mask) {
	int perm[10];
	bool adj[10][10] = {{}};
	Rep(i, n)
		perm[i] = i;
	int res = 0;
	do {
		Rep(i, n) 
			adj[perm[i]][perm[(i+1)%n]] = adj[perm[(i+1)%n]][perm[i]] = true;
		bool add = 1;
		Rep(i, k)
			if (mask&(1<<i))
				if (!adj[a[i]-1][b[i]-1]) {
					add = 0;
					break;
				}
		res += add;
		Rep(i, n) 
			adj[perm[i]][perm[(i+1)%n]] = adj[perm[(i+1)%n]][perm[i]] = false;
	} while (next_permutation(perm, perm+n) && perm[0] == 0);
	return res%mod;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif

	int t;
	scanf("%d", &t);
	For(test, 1, t) {
		scanf("%d%d", &n, &k);
		Rep(i, k) {
			scanf("%d%d", &a[i], &b[i]);
		}
		int res = 0;
		Rep(mask, 1<<k) {
			//int must = solve(mask);
			map<int,int> num;
			Rep(i, k) if (mask&(1<<i)) {
				++num[a[i]];
				++num[b[i]];
			}
			bool ok = true;
			for (map<int,int>::iterator it = num.begin(); it != num.end(); ++it) {
				if (it->second > 2) {
					ok = false;
					break;
				}
			}
			if (!ok) {
				continue;
			}
			set<int> s;
			int cnt = 0;
			for (map<int,int>::iterator it = num.begin(); it != num.end(); ++it) {
				if (it->second == 1 && s.count(it->first) == 0) {
					++cnt;
					int x = it->first, prev = -1;
					while (x != -1 && s.count(x) == 0) {
						s.insert(x);
						int y = -1;
						Rep(i, k) if (mask&(1<<i)) {
							if (a[i] == x || b[i] == x) {
								int z = x^a[i]^b[i];
								if (z != prev) {
									assert(y == -1);
									y = z;									
								}
							}
						}
						prev = x;
						x = y;
					}
				}
			}
			int cur;
			if (Size(s) == 0 && Size(num) == n) {
				int x = num.begin()->first, prev = -1;
				while (x != -1 && s.count(x) == 0) {
					s.insert(x);
					int y = -1;
					Rep(i, k) if (mask&(1<<i)) {
						if (a[i] == x || b[i] == x) {
							int z = x^a[i]^b[i];
							if (z != prev) {
								y = z;									
							}
						}
					}
					prev = x;
					x = y;
				}
				if (Size(s) == n)
					cur = 2;
				else
					cur = 0;
			} else {
				if (Size(s) != Size(num)) {
					continue;
				}
				cur = 1;
				Rep(i, cnt)
					cur = cur*2%mod;
				For(i, 1, n-Size(s)+cnt-1)
					cur = cur*i%mod;
			}
			int sign = 1;
			Rep(i, k) if (mask&(1<<i))
				sign *= -1;
			res = (res+sign*cur)%mod;
		}
		res = res*rev2%mod;
		printf("Case #%d: %d\n", test, (res+mod)%mod);
	}

	exit(0);
}
