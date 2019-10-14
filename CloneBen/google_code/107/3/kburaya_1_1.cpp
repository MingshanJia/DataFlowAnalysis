#pragma comment(linker, "/STACK:512000000")
#include <cstdio>
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <string>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <array>
#include <sstream>
#include <iomanip>
#include <bitset>
#include <unordered_map>
#include <unordered_set>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef long double ld;
const ll MAX = 100000000LL * 100000000LL;
const ll MIN = numeric_limits<ll>::min();
const double PI = 3.14159265358979;
const ll MOD = 1000000007LL;

template<class T>
ostream& operator<<(ostream& out, vector<T>& v) {
	for (int i = 0; i < v.size(); ++i) out << v[i] << " ";
	return out;
}

template<class T>
istream& operator >> (istream& in, vector<T>& v) {
	for (int i = 0; i < v.size(); ++i) in >> v[i];
	return in;
}

template<class L, class R>
istream& operator >> (istream& in, pair<L, R>& p) {
	in >> p.first >> p.second;
	return in;
}

template<class T>
T lexical_cast(string& s) {
	stringstream ss(s);
	T t;
	ss >> t;
	return t;
}

ll gcd(ll a, ll b) {
	return b ? gcd(b, a % b) : a;
}

ll cdiv(ll a, ll b) {
	return (a + b - 1) / b;
}

ll powmod(ll base, ll power, ll mod) {
	ll ans = 1;
	ll cur = base;
	while (power > 0) {
		if (power & 1) {
			ans *= cur;
			ans %= mod;
		}
		power /= 2;
		cur *= cur;
		cur %= mod;
	}
	return ans;
}

ll inv(ll n, ll mod) {
	return powmod(n, mod - 2, mod);
}

template<class Cont> void sort(Cont& c) { sort(begin(c), end(c)); }
template<class Cont> void reverse(Cont& c) { reverse(begin(c), end(c)); }

/* ------------------------------------------------
------------------------------------------------- */



int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#ifdef DEBUG
	ifstream cin{ "input.txt" };
	ofstream cout{ "output.txt" };
#endif
	int test;
	cin >> test;
	for (int tt = 0; tt < test; ++tt){
		cout << "Case #" << tt + 1 << ": ";
		int l;
		cin >> l;
		map<int, ll> emp;
		for (int i = 0; i < l; ++i) {
			ll e, n;
			cin >> n >> e;
			emp[e] = n;
		}
		ll free = 0;
		for (auto it = emp.begin(); it != emp.end(); ++it) {
			int e = it->first;
			ll n = it->second;
			free -= n * e;
			free = max(free, (ll)0);
			free += n;
		}
		ll ans = max(free, (ll)emp.rbegin()->first + 1);
		cout << ans << endl;
	}
}