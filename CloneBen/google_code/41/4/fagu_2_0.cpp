#line 1 "C.cpp"
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <cassert>
#include <cmath>
#include <cstring>
#include <functional>
#include <random>
using namespace std;
typedef vector<int> VI;
typedef pair<int,int> PII;
typedef vector<PII> VPII;
typedef long long ll;
#define REP(i,a,n) for (int i = (a); i < (n); i++)

template<class T> T& setmin(T &a, const T &b) {return a = min(a, b);}
template<class T> T& setmax(T &a, const T &b) {return a = max(a, b);}
template<class T> T MODD(const T &a, const T &b) {T r = a%b; if (r < 0) r += b; return r;}




///////////////////////////////// BEGIN util.h /////////////////////////////////


#line 1 "util.h"
template <class T, class U>
ostream& operator<<(ostream &o, const pair<T,U> &p) {
	return o << "(" << p.first << ", " << p.second << ")";
}

template <class T>
ostream& print_list(ostream &o, const T &v) {
	o << "[";
	bool first = true;
	for (const auto &t : v) {
		if (first)
			first = false;
		else
			o << ", ";
		o << t;
	}
	return o << "]";
}

template <class T>
ostream& print_map(ostream &o, const T &v) {
	o << "{";
	bool first = true;
	for (const auto &t : v) {
		if (first)
			first = false;
		else
			o << ", ";
		o << t.first << " => " << t.second;
	}
	return o << "}";
}

template <class T>
ostream& operator<<(ostream &o, const vector<T> &v) {
	return print_list(o, v);
}

template <class T>
ostream& operator<<(ostream &o, const set<T> &v) {
	return print_list(o, v);
}

template <class T,size_t N>
ostream& operator<<(ostream &o, const array<T,N> &v) {
	return print_list(o, v);
}

template <class T,class U>
ostream& operator<<(ostream &o, const map<T,U> &v) {
	return print_map(o, v);
}

template <class T, size_t N>
struct TuplePrintHelper {
	static ostream& print(ostream& o, const T &t) {
		TuplePrintHelper<T,N-1>::print(o, t);
		o << ", ";
		return o << get<N-1>(t);
	}
};

template <class T>
struct TuplePrintHelper<T,1> {
	static ostream& print(ostream& o, const T &t) {
		return o << get<0>(t);
	}
};

template <class T>
struct TuplePrintHelper<T,0> {
	static ostream& print(ostream& o, const T &) {
		return o;
	}
};

template <class... Args>
ostream& operator<<(ostream &o, const tuple<Args...> &t) {
	o << "(";
	TuplePrintHelper<tuple<Args...>, sizeof...(Args)>::print(o, t);
	return o << ")";
}


template <class T>
T fastpow(const T &a, ll n) {
	T r = 1, e = a;
	for (int i = 0; (1ll<<i) <= n; i++, e *= e) {
		if (n&(1ll<<i))
			r *= e;
	}
	return r;
}



///////////////////////////////// END util.h /////////////////////////////////


#line 30 "C.cpp"

int testcasenr;

ll Hd, Ad, Hk, Ak, B, D;

struct st {
	ll hd, ad, hk, ak, turns;
	void opponent() {
		if (hk > 0)
			hd -= ak;
		turns++;
	}
	st attack() {
		st r = *this;
		r.hk -= ad;
		r.opponent();
		return r;
	}
	st buff() {
		st r = *this;
		r.ad += B;
		r.opponent();
		return r;
	}
	st cure() {
		st r = *this;
		r.hd = Hd;
		r.opponent();
		return r;
	}
	st debuff() {
		st r = *this;
		r.ak -= D;
		r.opponent();
		return r;
	}
	bool lost() {
		return hd <= 0;
	}
	bool won() {
		return !lost() && hk <= 0;
	}
};

ll res;

void onlyatt(st s) {
	while(s.hk > 0) {
		st s1 = s.attack();
		if (s1.lost()) {
			s1 = s.cure().attack();
			if (s1.lost())
				return;
		}
		s = s1;
	}
	assert(s.won());
	setmin(res, s.turns);
}

void bla(st s) {
	while(true) {
		onlyatt(s);
		
		if (B > 0 && s.ad < s.hk) {
			st s1 = s.buff();
			if (s1.lost()) {
				s1 = s.cure().buff();
				if (s1.lost())
					break;
			}
			s = s1;
		} else {
			break;
		}
	}
}

void docase() {
	scanf("%lld%lld%lld%lld%lld%lld", &Hd, &Ad, &Hk, &Ak, &B, &D);
	ll INF = 1E18;
	res = INF;
	st s{Hd, Ad, Hk, Ak, 0};
	while(true) {
		bla(s);
		
		if (D > 0 && s.ak > 0) {
			st s1 = s.debuff();
			if (s1.lost()) {
				s1 = s.cure().debuff();
				if (s1.lost())
					break;
			}
			s = s1;
		} else {
			break;
		}
	}
	
	if (res < INF)
		printf("%lld\n", res);
	else
		printf("IMPOSSIBLE\n");
}

int main() {
	int T;
	scanf("%d ", &T);
	for (testcasenr = 1; testcasenr <= T; testcasenr++) {
		fprintf(stderr, "Test %d/%d\n", testcasenr, T);
		printf("Case #%d: ", testcasenr);
		docase();
		fflush(stdout);
		fflush(stderr);
	}
	return 0;
}
