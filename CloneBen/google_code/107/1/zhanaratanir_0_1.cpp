#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cstdio>
#include <fstream>
#include <string> 

using namespace std;

#define f first
#define s second
#define mp make_pair
#define pb push_back
#define forit(it, s) for (__typeof(s.begin()) it = s.begin(); it != s.end(); it++)
#define all(a) a.begin(),a.end()

const int inf = (int)1e9;
const int mod = (int)1e9 + 7;

int t;
int n;
int a[111];
int values[111];

int stupid() {
	int p[111];
	for (int i = 0; i < n; i++) p[i] = i;
	int ans = inf;
	do {
		int cur = 0;
		for (int i = 0; i < n; i++) cur += (a[p[i]] - values[i]) * (a[p[i]] - values[i]);
		ans = min(ans, cur);
	} while(next_permutation(p, p + n));
	return ans;
}

int smart() {
	sort(a, a + n);
	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans += (a[i] - values[i]) * (a[i] - values[i]);
	}
	return ans;
}

void solve(int case_num) {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	for (int i = 0, st = 0; i < n; i += 2, st++) {
		values[i] = st;
		values[i + 1] = st;
	}
	printf("Case #%d: %d\n", case_num, smart());
}

int main() {

	cin >> t;

	for (int i = 1; i <= t; i++)
	{
		solve(i);
	}

	return 0;
}
