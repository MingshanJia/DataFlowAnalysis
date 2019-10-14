#include<cstdio>
#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<string>
#include<sstream>
#include<vector>
#include<map>
#include<set>
#include<bitset>
#include<algorithm>
#include<cassert>
#include<ctime>
#include<queue>
using namespace std;

#define REP(i,n) for(int i = 0; i < (int)n; i++)
#define FOR(i,n,m) for(int i = (int)n; i <= (int)m; i++)
#define FOD(i,n,m) for(int i = (int)n; i >= (int)m; i--)
#define EACH(i,v) for(__typeof((v).begin()) i = (v).begin(); i != (v).end(); i++)

typedef long long i64;
typedef pair<int, int> PI;

#define sz(v) ((i64)(v).size())
#define all(v) (v).begin(),(v).end()
#define bit(n) (1LL<<(i64)(n))

#define PB push_back
#define MP make_pair
#define X first
#define Y second
template<class T> void fmax(T &a, const T &b) { if (a < b) a = b; }
template<class T> void fmin(T &a, const T &b) { if (a > b) a = b; }
template<class T> T sqr(const T &a) { return a * a; }

string a[999];
int ans;
int n;

int main() {
	int Te;
	cin >> Te;
	for (int Ti = 1; Ti <= Te; Ti++) {
		cin >> n;
		string s;
		getline(cin, s);
		s = "";
		ans = 0;
		FOR(i, 1, n) {
			getline(cin, a[i]);
		//	cout << a[i] << endl;
			if (i == 1) s = a[i]; else {
				if (a[i] < s) ans++;
				else s = a[i];
			}
		}
		printf("Case #%d: %d\n", Ti, ans);
	}
}