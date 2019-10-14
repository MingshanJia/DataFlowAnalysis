#line 1 "A.cpp"
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


#line 30 "A.cpp"

int testcasenr;

char line[1000];
char f[100][100];

void visit(int x1, int x2, int y1, int y2) {
	vector<int> cols;
	REP(x,x1,x2) {
		REP(y,y1,y2)
			if (f[x][y] != '?') {
				cols.push_back(x);
				break;
			}
	}
	assert(cols.size() >= 1);
	if (cols.size() >= 2) {
		visit(x1, cols[0]+1, y1, y2);
		visit(cols[0]+1, x2, y1, y2);
	} else {
		vector<int> rows;
		char color = ' ';
		REP(y,y1,y2) {
			REP(x,x1,x2)
				if (f[x][y] != '?') {
					color = f[x][y];
					rows.push_back(y);
					break;
				}
		}
		if (rows.size() >= 2) {
			visit(x1, x2, y1, rows[0]+1);
			visit(x1, x2, rows[0]+1, y2);
		} else {
			REP(x,x1,x2) REP(y,y1,y2)
				f[x][y] = color;
		}
	}
}

void docase() {
	int X, Y;
	scanf("%d%d ", &Y, &X);
	REP(y,0,Y) {
		scanf("%s ", line);
		REP(x,0,X)
			f[x][y] = line[x];
	}
	visit(0,X,0,Y);
	REP(y,0,Y) {
		REP(x,0,X)
			printf("%c", f[x][y]);
		printf("\n");
	}
}

int main() {
	int T;
	scanf("%d ", &T);
	for (testcasenr = 1; testcasenr <= T; testcasenr++) {
		fprintf(stderr, "Test %d/%d\n", testcasenr, T);
		printf("Case #%d:\n", testcasenr);
		docase();
		fflush(stdout);
		fflush(stderr);
	}
	return 0;
}
