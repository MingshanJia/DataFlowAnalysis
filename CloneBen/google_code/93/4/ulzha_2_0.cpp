#include <iostream>
#include <vector>

using namespace std;

vector<int> v;
const int pmax = 10000, qmax = 100;
int d[qmax + 2][qmax + 2];
bool c[qmax + 2][qmax + 2];

int dp(int a, int b) {
	int &r = d[a][b], i;
	
	if (c[a][b]++) return r;
	if (a + 1 == b) return r = 0; //v[b] - v[a] - 1;
	
	r = pmax;
	for (i = a + 1; i < b; i++) r <?= v[b] - v[a] - 2 + dp(a, i) + dp(i, b);
//	cout << "dp(" << a << ',' << b << ")=" << r << '\n';
	
	return r;
}

int main() {
	int nt, it;
	
	cin >> nt;
	for (it = 1; it <= nt; it++) {
		v.clear();
		memset(c, 0, sizeof c);
		
		int p, q, i, t;
		
		v.push_back(0);
		cin >> p >> q;
		for (i = 0; i < q; i++) cin >> t, v.push_back(t);
		v.push_back(p + 1);
		
		cout << "Case #" << it << ": " << dp(0, q + 1) << '\n';
	}
	
	return 0;
}
