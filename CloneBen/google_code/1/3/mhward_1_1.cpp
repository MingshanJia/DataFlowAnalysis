#include <bits/stdc++.h>

using namespace std;

template <typename T>
using V = vector<T>;

typedef long double ld;
typedef long long ll;

#define FO(i, N) for (int (i) = 0; (i) < (N); ++(i))
#define FOll(i, N) for (ll (i) = 0; (i) < (N); ++(i))
#define READALL(c) for (auto &e : c) { cin >> e; }
#define PRINTALL(c) for (const auto &e : c) { cout << e << " "; } cout << "\n";
#define MP(x, y) (make_pair((x), (y)))
#define MT(...) make_tuple(__VA_ARGS__)
#define G(i, x) get<i>(x)
#define ALL(x) begin(x), end(x)


typedef ll ind_t; typedef ll data_t;
const data_t base_value = 0;
const data_t identity = 0;
struct SegTree {
	// Base value is the "initial" value of any index.
	// The identity value for f (0 for +, 1 for *, INF for min, etc).
	// left, right, node value, lazy delta, and left/right children.
	ind_t l, r;
	data_t val, delta;
	unique_ptr<SegTree> children[2];
	SegTree(ind_t l, ind_t r) : l(l), r(r), val(base_value), delta(0) {}
	// Binary function. Max is given, min is the same. Commented additon shown.
	data_t f(data_t a, data_t b) { return a + b; }
	// How to modify f for the delta over this range. Change for + is commented.
	data_t f_delta() { return delta*(r-l+1); }
	data_t value() { return val + f_delta(); }
	data_t middle() { return l == r-1 ? l : l + (r-l+1)/2; }
	void lazy_push() {
		ind_t mid = middle();
		if (delta != 0) {
			// Push delta into children.
			if (children[0] == nullptr)
				children[0] = unique_ptr<SegTree>(new SegTree(l, mid));
			children[0]->delta += delta;
			if (children[1] == nullptr)
				children[1] = unique_ptr<SegTree>(new SegTree(mid+1, r));
			children[1]->delta += delta;
			val += f_delta();
			delta = 0;
		}
	}
	data_t update(ind_t ql, ind_t qr, data_t v) {
		if (l == ql && r == qr) {
			delta += v;
			return val + f_delta();
		}
		lazy_push();
		// init left and right.
		data_t left = base_value, right = base_value;
		ind_t mid = middle();
		if (children[0] != nullptr) left = children[0]->value();
		if (children[1] != nullptr) right = children[1]->value();
		// update
		if (ql <= mid) {
			if (children[0] == nullptr)
				children[0] = unique_ptr<SegTree>(new SegTree(l, mid));
			left = children[0]->update(ql, qr < mid ? qr : mid, v);
		}
		if (qr > mid) {
			if (children[1] == nullptr)
				children[1] = unique_ptr<SegTree>(new SegTree(mid+1, r));
			right = children[1]->update(ql < mid+1 ? mid+1 : ql, qr, v);
		}
		return val = f(left, right);
	}
	data_t query(ind_t ql, ind_t qr) {
		if (l == ql && r == qr)
			return val + f_delta();
		lazy_push();
		data_t left = identity, right = identity;
		ind_t mid = middle();
		if (ql <= mid)
			if (children[0] == nullptr) left = base_value;
			else left = children[0]->query(ql, qr < mid ? qr : mid);
		if (qr > mid)
			if (children[1] == nullptr) right = base_value;
			else right = children[1]->query(ql < mid+1 ? mid+1 : ql, qr);
		
		return f(left, right);
	}
	void print_vals() {
		for (int i = l; i <= r; ++i)
			cout << query(i, i) << " ";
		cout << endl;
	}
	
	void print(int indent) {
		for (int i = 0 ; i < indent; ++i)
			cout << " ";
		cout << l << " " << r << " " << val << " " << delta << endl;
		if (children[0] != nullptr)
			children[0]->print(indent+2);
		if (children[1] != nullptr)
			children[1]->print(indent+2);
	}
};


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; ++tc) {
		cout << "Case #" << tc << ": ";
		
		ll N, Q;
		cin >> N >> Q;
		V<ll> X(N), Y(N), Z(Q);

		ll A1, B1, C1, M1;
		cin >> X[0] >> X[1] >> A1 >> B1 >> C1 >> M1;
		ll A2, B2, C2, M2;
		cin >> Y[0]>> Y[1] >> A2 >> B2 >> C2 >> M2;
		ll A3,B3,C3,M3;
		cin >> Z[0]>>Z[1]>>A3>>B3>>C3>>M3;

		for (int i = 2; i < N; ++i) {
			X[i] = (A1*X[i-1]+B1*X[i-2]+C1)%M1;
			Y[i] = (A2*Y[i-1]+B2*Y[i-2]+C2)%M2;
		}

		for (int i = 2; i < Q; ++i) {
			Z[i] = (A3*Z[i-1]+B3*Z[i-2]+C3)%M3;
		}

		// PRINTALL(X);
		// PRINTALL(Y);

		SegTree st(0, 1e9+10);

		FO(i, N) {
			st.update(min(X[i],Y[i])+1, max(X[i],Y[i])+1, 1);
			// cerr << min(X[i],Y[i])+1 << " to " << max(X[i],Y[i])+1 <<endl;
			// cerr << st.query(min(X[i],Y[i])+1, max(X[i],Y[i])+1) <<endl;
		}

		// cerr << st.query(0, 1e9+1) << endl;

		ll sum = 0;

		FO(i, Q) {
			ll K = Z[i]+1;

			ll lo = 0, hi = 1e9+1, best = 0;
			while (lo <= hi) {
				ll mid = (lo+hi)/2;
				// cout << mid << " " << st.query(mid, 1e9+1) << endl;
				if (st.query(mid, 1e9+1) >= K) {
					best = max(best, mid);
					lo = mid+1;
				} else {
					hi = mid-1;
				}
			}
			sum += best*(i+1);
			// cout << best << endl;
		}

		cout << sum << endl;



	}
}