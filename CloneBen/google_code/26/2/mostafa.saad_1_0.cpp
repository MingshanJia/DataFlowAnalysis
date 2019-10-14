/*
 * B.cpp
 *
 *  Created on: Feb 17, 2011
 *      Author: t-mosaad
 */


/*
 * template.cpp
 * Another buggy code by mostafa_saad
 *
 *  Created on: Sep 26, 2010
 */


#include<set>
#include<map>
#include<list>
#include<iomanip>
#include<cmath>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<complex>
#include<sstream>
#include<iostream>
#include<algorithm>
#include<numeric>
#include<utility>
#include <functional>
#include<stdio.h>
#include<assert.h>
#include<memory.h>
using namespace std;

#define all(v)				((v).begin()), ((v).end())
#define sz(v)				((int)((v).size()))
#define clr(v, d)			memset(v, d, sizeof(v))
#define rep(i, v)		for(int i=0;i<sz(v);++i)
#define lp(i, n)		for(int i=0;i<(int)(n);++i)
#define lpi(i, j, n)	for(int i=(j);i<(int)(n);++i)
#define lpd(i, j, n)	for(int i=(j);i>=(int)(n);--i)
#define repa(v)				lpi(i, 0, sz(v)) lpi(j, 0, sz(v[i]))
#define P(x)				cout<<#x<<" = { "<<x<<" }\n"
#define pb					push_back
#define MP					make_pair

typedef vector<int>       vi;
typedef vector<double>    vd;
typedef vector< vi >      vvi;
typedef vector< vd >      vvd;
typedef vector<string>    vs;
typedef long long         ll;
typedef long double   	  ld;

const int OO = (int)1e8;	//Small -> WRONG, Large -> OVERFLOW

const double PI  = acos(-1.0);
const double EPS = (1e-7);

int dcmp(double x, double y) {	return fabs(x-y) <= EPS ? 0 : x < y ? -1 : 1;	}


int main()
{
//#ifndef ONLINE_JUDGE
	freopen("B-small-attempt1.in", "rt", stdin);
    freopen("B-small-attempt1.txt", "wt", stdout);
//#endif

	int n;
	cin>>n;
	lp(cc, n) {
		int m;
		cin>>m;
		int arr[12];
		lp(i, 12) cin>>arr[i];

		int best = -1, s, e;
		lpi(i, 1, 12) lpi(j, i+1, 13) {

			int c = m / arr[i-1];
			int profit = c*(arr[j-1] - arr[i-1]);
			if(profit <= 0)
				continue;
			if(best == -1 || best < profit || (best == profit && arr[i-1] < arr[s-1]) )
				best = profit, s = i, e = j;

		}
		if(best > 0)
			printf("Case #%d: %d %d %d\n", cc+1, s, e, best);
		else
			printf("Case #%d: IMPOSSIBLE\n", cc+1);
	}

	return 0;
}


