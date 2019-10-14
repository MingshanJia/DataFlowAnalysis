#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <sstream>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define SZ(x) (int)(x.size())
#define F0(i,n) for(i=0;i<n;i++)
#define F1(i,n) for(i=1;i<=n;i++)
const int inf = 1000000009;
const double pi = atan(1.0)*4.0;
const double eps = 1e-8;
ll gcd(ll x, ll y) { return y ? gcd(y, x%y) : x; }
int bc(int n) { return n ? bc((n-1)&n)+1 : 0; }

int i, j, m, n, l;
int d[10001];
ll L, a[101], N, ans, curr, k;
char ss[1000002];

int main() {
//	freopen("b.in", "r", stdin);

	freopen("B-small-attempt0.in", "r", stdin);
	freopen("B-small-attempt0.out", "w", stdout);

//	freopen("B-large.in", "r", stdin);
//	freopen("B-large.out", "w", stdout);

	int tt, tn; cin >> tn;
	F1(tt,tn) {
		cin >> L >> n;
		F0(i,n) cin >> a[i];
		memset(d, -1, sizeof(d));
		N = 10000;
		d[0] = 0;
		F0(i,n) {
			F0(j,N)
				if (d[j] != -1 && j+a[i] <= N && (d[j+a[i]] > d[j] + 1 || d[j+a[i]] == -1))
					d[j+a[i]] = d[j] + 1;
		}
		ans = -1;
		F0(i,n) {
			curr = (L-N+a[i]-1) / a[i];
			k = L - a[i] * curr;
			if (d[k] == -1) curr = -1; else curr += d[k];
			if (curr != -1) {
				if (ans == -1 || curr < ans) ans = curr;
			}
		}
		printf("Case #%d: ", tt);
		if (ans != -1)
			cout << ans << endl;
		else 
			cout << "IMPOSSIBLE" << endl;
	}
	
	return 0;
}
