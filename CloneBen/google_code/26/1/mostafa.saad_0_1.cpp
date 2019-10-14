/*
 * 1.cpp
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
	freopen("A-large.in", "rt", stdin);
    freopen("A-large.txt", "wt", stdout);
//#endif

	int n;
	cin>>n;
	lp(cc, n) {
		int k;
		cin>>k;
		vector<int> A, B;
		lp(i, k) {
			int x;
			char c;
			cin>>x>>c;
			if(c == 'B')
				A.push_back(x);
			else
				B.push_back(x);
		}

		sort( all(A) );	sort( all(B) );
		reverse( all(A) );	reverse( all(B) );

		int total = 0;
		if(sz(A) && sz(B)) {
			int mn = min(sz(A), sz(B));
			lp(i, mn)
				total += A[i] + B[i];
			total -= 2*mn;
		}
		printf("Case #%d: %d\n", cc+1, total);
	}




	return 0;
}


