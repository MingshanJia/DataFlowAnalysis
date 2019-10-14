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
int L;
pair<int, long long> a[1111];

bool check(long long k) {
	long long cnt = k;
	for (int i = 0; i < L; i++) {
		long long n = a[i].s;
		if (n > cnt) return false;
		int exp = a[i].f;
		cnt -= n;
		cnt += n * 1ll * exp;
		if (cnt >= (long long)1e16) return true;
	}
	return true;
}

void solve(int case_num) {
	cin >> L;
	for (int i = 0; i < L; i++) {
		cin >> a[i].s >> a[i].f;
	}
	sort(a, a + L);
	reverse(a, a + L);
	long long l = a[0].f + 1, r = (long long)1e15;
	long long ans = r;
	while (l <= r) {
		long long mid = (l + r) >> 1;
		if (check(mid)) {
			ans = mid;
			r = mid - 1;
		} else l = mid + 1;
	}
	printf("Case #%d: %lld\n", case_num, ans);
}

int main() {

	cin >> t;
	for (int i = 1; i <= t; i++) {
		solve(i);
	}

	return 0;
}
