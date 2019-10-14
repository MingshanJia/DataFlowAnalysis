#include <bits/stdc++.h>

using namespace std;

template <typename T>
using V = vector<T>;

typedef long double ld;
typedef long long ll;

#define FO(i, N) for (int (i) = 0; (i) < (N); ++(i))
#define FOll(i, N) for (ll (i) = 0; (i) < (N); ++(i))
#define READALL(c) for (auto &e : c) { cin >> e; }
#define PRINTALL(c) for (const auto &e : c) { cout << e << "\t"; } cout << "\n";
#define MP(x, y) (make_pair((x), (y)))
#define MT(...) make_tuple(__VA_ARGS__)
#define G(i, x) get<i>(x)
#define ALL(x) begin(x), end(x)


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; ++tc) {
		cout << "Case #" << tc << ": ";
		int N;
		cin >> N;
		V<ll> A(N);
		READALL(A);

		ll zeros = 0, nz = 0;
		for (int a : A) {
			if (a == 0) ++zeros;
			else ++nz;
		}

		ll ans = 0;
		if (zeros >= 3)
			ans += zeros*(zeros-1)*(zeros-2)/6;

		if (zeros >= 2)
			ans += (zeros*(zeros-1)/2)*nz;
		

		sort(ALL(A));


		FO(i, N) if (A[i] > 0) {
			unordered_map<int, int> cnts;
			FO(j, i) if (A[j] > 0) {
				if (A[i]%A[j] == 0) {
					ans += cnts[A[i]/A[j]];
				}
				cnts[A[j]]++;
			}
		}

		cout << ans << endl;
	}
}