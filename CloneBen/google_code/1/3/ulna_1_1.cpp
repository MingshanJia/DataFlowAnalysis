#include <bits/stdc++.h>
using namespace std;

int x[400055], y[400055], z[100055];
int l[400055], r[400055], k[100055];
int a[4], b[4], c[4], m[4];
int lb[100055], ub[100055], mid[100055];

typedef pair<int, int> P;

#define ft first
#define sd second

void solve() {
	int n, q;
	scanf("%d %d", &n, &q);
	
	scanf("%d %d %d %d %d %d", &x[1], &x[2], &a[1], &b[1], &c[1], &m[1]);
	scanf("%d %d %d %d %d %d", &y[1], &y[2], &a[2], &b[2], &c[2], &m[2]);
	scanf("%d %d %d %d %d %d", &z[1], &z[2], &a[3], &b[3], &c[3], &m[3]);
	
	for (int i = 3; i <= n; i++) {
		x[i] = (1ll * a[1] * x[i - 1] + 1ll * b[1] * x[i - 2] + c[1]) % m[1];
		y[i] = (1ll * a[2] * y[i - 1] + 1ll * b[2] * y[i - 2] + c[2]) % m[2];
	}
	for (int i = 3; i <= q; i++) {
		z[i] = (1ll * a[3] * z[i - 1] + 1ll * b[3] * z[i - 2] + c[3]) % m[3];
	}
	
	for (int i = 1; i <= n; i++) {
		l[i] = min(x[i], y[i]) + 1;
		r[i] = max(x[i], y[i]) + 1;
	}
	for (int i = 1; i <= q; i++) {
		k[i] = z[i] + 1;
	}
	
	for (int i = 1; i <= q; i++) {
		lb[i] = 0, ub[i] = (int)1e9 + 1;
	}
	
	vector<int> inter;
		
	for (int i = 1; i <= n; i++) inter.push_back(i);
	
	sort(inter.begin(), inter.end(), [&] (int u, int v) {
		return r[u] > r[v];
	});
	
	
	for (int _ = 0; _ < 32; _++) {
		vector<P> vec;
		
		for (int i = 1; i <= q; i++) if (ub[i] - lb[i] > 1) {
			mid[i] = (ub[i] + lb[i]) >> 1;
			vec.push_back(P(mid[i], i));
		}
		
		sort(vec.begin(), vec.end());
		reverse(vec.begin(), vec.end());
		
		int pt = 0;
		long long tot = 0;
		
		priority_queue<int> pq;
		
		int last = (int)1e9 + 1;
		
		for (auto p : vec) {
			while (!pq.empty() && pq.top() >= p.ft) {
				tot += last - pq.top();
				pq.pop();
			}
			
			tot += 1ll * (last - p.ft) * pq.size();
			
			while (pt < n && r[inter[pt]] >= p.ft) {
				tot += r[inter[pt]] - max(l[inter[pt]], p.ft) + 1;
				
				if (l[inter[pt]] < p.ft) {
					pq.push(l[inter[pt]]);
				}
				
				pt++;
			}
			if (tot >= 1ll * k[p.sd]) {
				lb[p.sd] = mid[p.sd];
			} else ub[p.sd] = mid[p.sd];
			
			last = p.ft;
		}
	}
	
	long long res = 0;
	
	for (int i = 1; i <= q; i++) {
		res += 1ll * lb[i] * i;
	}
	
	printf("%lld\n", res);
}
int main() {
	int _t;
	cin >> _t;
	
	for (int _ = 0; _ < _t; _++) {
		printf("Case #%d: ", _ + 1);
		solve();
	}
}
