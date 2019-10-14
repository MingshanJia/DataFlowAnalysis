#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <bitset>
#include <cmath>
#include <string>
#include <cstdlib>
#include <vector>

#define X first
#define Y second
#define mp make_pair
#define sqr(x) ((x) * (x))
#define Rep(i, n) for(int i = 0; i<(n); i++)
#define foreach(it, n) for(__typeof(n.begin()) it = n.begin(); it != n.end(); it++)

using namespace std;
typedef long long LL;
typedef pair<int, int> pii;

#define esp 1e-8
#define N 100010

int X;
bool isUsed[10];
vector<int> v, val;

int findFact(int key) {
	int l = 0, r = v.size() - 1;
	while (l <= r) {
		int mid = l + r >> 1;
		if (v[mid] == key) return mid;
		if (v[mid] < key) l = mid + 1;
		else r = mid - 1;
	}
	return -1;
}

bool check(int &x, int y) {
	if (x == -1 || x > y) { x = y; return true; }
	return false;
}
int solve(int X) {
	if (X == 0) return isUsed[0] ? 2 : -1;
	v.clear();
	val.clear();
	for (int i = 1; i * i <= X; i++) {
		if (X % i == 0) {
			v.push_back(i);
			if (i * i != X) v.push_back(X / i);
		}
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		val.push_back(0);
		int x = v[i];
		while (x) {
			if (!isUsed[x % 10]) {val[i] = -1; break;}
			val[i] ++; 
			x /= 10;
		}
		for (int j = 0; j < i && v[j] * v[j] <= v[i]; j++)
			if (v[i] % v[j] == 0) {
				int k = findFact(v[i] / v[j]);
				if (val[j] == -1 || val[k] == -1) continue;
				check(val[i], val[j] + val[k] + 1);
			}
	}
	return val.back() == -1 ? -1 : (val.back() + 1);
}

int main() {
	freopen("C-large.in", "r", stdin);
	freopen("C-large.out", "w", stdout);
	int cas, tt = 0;
	scanf("%d", &cas);
	while (cas --) {
		for (int i = 0, tmp; i < 10; i++) {
			scanf("%d", &tmp);
			isUsed[i] = tmp == 1;
		}
		scanf("%d", &X);
		int ans = solve(X);
		printf("Case #%d: ", ++tt);
		if (ans == -1) printf("Impossible\n");
		else printf("%d\n", ans);
	}
	return 0;
}
