#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#define fo(i,a,b) dfo(int,i,a,b)
#define fr(i,n) dfr(int,i,n)
#define fe(i,a,b) dfe(int,i,a,b)
#define fq(i,n) dfq(int,i,n)
#define nfo(i,a,b) dfo(,i,a,b)
#define nfr(i,n) dfr(,i,n)
#define nfe(i,a,b) dfe(,i,a,b)
#define nfq(i,n) dfq(,i,n)
#define dfo(d,i,a,b) for (d i = (a); i < (b); i++)
#define dfr(d,i,n) dfo(d,i,0,n)
#define dfe(d,i,a,b) for (d i = (a); i <= (b); i++)
#define dfq(d,i,n) dfe(d,i,1,n)
#define ffo(i,a,b) dffo(int,i,a,b)
#define ffr(i,n) dffr(int,i,n)
#define ffe(i,a,b) dffe(int,i,a,b)
#define ffq(i,n) dffq(int,i,n)
#define nffo(i,a,b) dffo(,i,a,b)
#define nffr(i,n) dffr(,i,n)
#define nffe(i,a,b) dffe(,i,a,b)
#define nffq(i,n) dffq(,i,n)
#define dffo(d,i,a,b) for (d i = (b)-1; i >= (a); i--)
#define dffr(d,i,n) dffo(d,i,0,n)
#define dffe(d,i,a,b) for (d i = (b); i >= (a); i--)
#define dffq(d,i,n) dffe(d,i,1,n)
#define ll long long
#define alok(n,t) ((t*)malloc((n)*sizeof(t)))
#define pf printf
#define sf scanf
#define pln pf("\n")
#define flsh fflush(stdout)
#include <map>
#include <algorithm>
#include <vector>
#include <set>
#include <iostream>
using namespace std;

#define LIM 1000111
ll s[LIM];
ll m[LIM];
ll L[LIM];
ll U[LIM];
void init() {

}

int solve() {
	int n, d;
	sf("%d%d", &n, &d);
	ll as, cs, rs;
	ll am, cm, rm;
	sf("%lld%lld%lld%lld", &s[0], &as, &cs, &rs);
	sf("%lld%lld%lld%lld", &m[0], &am, &cm, &rm);
	for (int i = 0; i < n; i++) {
		s[i+1] = (s[i] * as + cs) % rs;
		m[i+1] = (m[i] * am + cm) % rm;
	}
	m[0] = 0;
	L[0] = U[0] = s[0];
	for (int i = 1; i < n; i++) {
		m[i] %= i;
		L[i] = min(L[m[i]], s[i]);
		U[i] = max(U[m[i]], s[i]);
	}

	int ans = 0;
	for (int a = 0; a < rs; a++) {
		int bag = 0;
		for (int i = 0; i < n; i++) {
			if (a <= L[i] && U[i] <= a + d) {
				bag++;
			}
		}
		ans = max(ans, bag);
	}

	return ans;


}
int main() {
	init();
    int z;
    sf("%d", &z);
    fq(cas,z) {

        pf("Case #%d: %d\n", cas, solve());
    }    
}
