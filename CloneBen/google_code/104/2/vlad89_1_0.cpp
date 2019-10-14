#include <iostream>
#include <cstdio>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <numeric>
#include <functional>
#include <string>
#include <cstdlib>
#include <cmath>
#include <list>

using namespace std;

#define FOR(i,a,b) for(int i=(a),_b(b);i<_b;++i)
#define FORD(i,a,b) for(int i=(a),_b(b);i>=_b;--i)
#define REP(i,n) FOR(i,0,n)
#define ALL(a) (a).begin(),a.end()
#define SORT(a) sort(ALL(a))
#define UNIQUE(a) SORT(a),(a).resize(unique(ALL(a))-a.begin())
#define SZ(a) ((int) a.size())
#define pb push_back

#define VAR(a,b) __typeof(b) a=(b)
#define FORE(it,a) for(VAR(it,(a).begin());it!=(a).end();it++)
#define X first
#define Y second
#define DEBUG(x) cout << #x << " = " << x << endl;

#define INF 1000000000

typedef vector<int> VI;
typedef vector< vector<int> > VVI;
typedef pair<int, int> PII;
typedef vector<PII> VPII;
typedef pair <int, VI> PIVI;
typedef long long ll;

int h[1001][1001];
bool t[1001];

int A, B, P;

bool was[1001];

void dfs (int q) {
	was[q] = true;
	FOR (i, A, B + 1)
		if (!was[i] && h[q][i] >= P)
			dfs (i);
}

int main() {
	freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int test;
    cin >> test;

	VI primes;
	
	FOR (i, 2, 1001)
		if (!t[i]) {
			primes.pb (i);
			for (int j = 2; i * j <= 1000; ++j)
				t[i * j] = true;
		}
	
	FOR (a, 1, 1001)
		FOR (b, 1, a) 
			REP (c, SZ (primes)) {
				if (primes[c] > b)
					break; 
				if (a % primes[c] == 0 && b % primes[c] == 0) {
					h[a][b] = primes[c];
					h[b][a] = primes[c];	
				}
			}
    FOR (ntest, 1, test+1) {
		cout << "Case #" << ntest << ": ";
		
		cin >> A >> B;
		cin >> P;
		
		memset (was, 0, sizeof (was));
		int res = 0;		
		FOR (i, A, B + 1) if (!was[i]) {
			++res;
			dfs (i);
		}
		cout << res << endl;
	}    
	return 0;
}
