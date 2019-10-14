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
		vector<string> s(3);
		cin >> s;
		int pos = 0;
		while (s[0][pos] == s[1][pos] && s[0][pos] == s[2][pos]) {
			pos++;
		}
		if (s[0][pos] != s[1][pos] && s[0][pos] != s[2][pos] && s[1][pos] != s[2][pos]) {
			cout << "YES YES YES" << endl;
		}
		else {
			vector<int> order(3), rorder(3);
			if (s[0][pos] == s[1][pos]) {
				order = { 0, 1, 2 };
				rorder = { 0, 1, 2 };
			}
			else if (s[0][pos] == s[2][pos]) {
				order = { 0, 2, 1 };
				rorder = { 0, 2, 1 };
			}
			else {
				order = { 1, 2, 0 };	
				rorder = { 2, 0, 1 };

			}
			string &s1 = s[order[0]];
			string &s2 = s[order[1]];
			string &s3 = s[order[2]];
			char x = s1[pos];
			char y = s3[pos];
			while (s1[pos] == s2[pos]) {
				pos++;
			}
			vector<bool> ans(3);
			if (s1[pos] == x && s2[pos] == y) {
				ans = { false, true, false };
			} else if (s2[pos] == x && s1[pos] == y) {
				ans = { true, false, false };
			}
			else {
				ans = { true, true, false };
			}
			for (int i = 0; i < 3; ++i) {
				cout << ((ans[rorder[i]]) ? ("YES") : ("NO")) << " ";
			}
			cout << endl;
		} 
	}
}