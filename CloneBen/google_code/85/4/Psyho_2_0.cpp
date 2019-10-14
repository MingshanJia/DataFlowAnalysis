#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <map>
#include <set>
#include <list>
#include <deque>
#include <queue>

using namespace std;

#define FOR(i,a,b)  for(int i=(a);i<(b);++i)
#define REP(i,a)    FOR(i,0,a)
#define ZERO(m)     memset(m,0,sizeof(m))
#define ALL(x)      x.begin(),x.end()
#define PB          push_back
#define S           size()
#define LL          long long
#define LD          long double
#define MP          make_pair
#define X           first
#define Y           second
#define VC          vector
#define VI          VC<int>
#define VS          VC<string>

void print(VI v) {cerr << "[";if (v.S) cerr << v[0];FOR(i, 1, v.S) cerr << ", " << v[i];cerr << "]\n";}
void print(VS v) {cerr << "[";if (v.S) cerr << v[0];FOR(i, 1, v.S) cerr << ", " << v[i];cerr << "]\n";}
template<class T> string i2s(T x) {ostringstream o; o << x; return o.str(); }
VS splt(string s, char c = ' ') {VS rv; int p = 0, np; while (np = s.find(c, p), np >= 0) {if (np != p) rv.PB(s.substr(p, np - p)); p = np + 1;} if (p < s.S) rv.PB(s.substr(p)); return rv;}

int x[100][100];
int main() {
	int tc;
	cin >> tc;
	FOR(atc, 1, tc + 1) {
		int n;
		ZERO(x);
		cin >> n;
		int a, b, c, d;
		REP(i, n) {
			cin >> a >> b >> c >> d;
			FOR(e, a - 1, c) FOR(f, b - 1, d) x[e][f] = 1;
		}
		int no = 0;
		while (1) {
			int ok = 0;
			for (int i = 99; i >= 0; i--) for (int j = 99; j >= 0 ; j--) {
				ok += x[i][j];
				//if (x[i][j]) cout << i << " " << j << endl;
				if (i && x[i-1][j] && j && x[i][j-1]) x[i][j] = 1;
				if (x[i][j] && (i == 0 || x[i-1][j] == 0) && (j == 0 || x[i][j-1] == 0)) x[i][j] = 0;
			}
			if (ok == 0) break;
			no++;
			//cout <<ok << endl;
		}
		printf("Case #%d: %d\n", atc, no);
	}
}