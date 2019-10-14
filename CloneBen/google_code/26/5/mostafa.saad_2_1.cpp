/*
 * C.cpp
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

const int MAXN = 100;
int dp[MAXN][MAXN];

int main()
{
//#ifndef ONLINE_JUDGE
	freopen("C-large.in", "rt", stdin);
    freopen("C-large.txt", "wt", stdout);
//#endif

	int bad = -30000;
	int cases;
	scanf("%d", &cases);

	lp(cc, cases) {
		int w, h;
		scanf("%d%d", &w, &h);
		swap(w, h);

		clr(dp, 0);
		lp(i, w)
		{
			lp(j, h) {
				char ch;
				scanf(" %c", &ch);
				if(ch == 'W' || ch == 'R' || ch == 'T')
					dp[i+1][j+1] = bad;
				else
					dp[i+1][j+1] = 1;
			}
		}

		int i, j, row, col, elem, wid, mis, mrs, best;

		row = w, col = h;

		for(i=1; i<=row; i++)
		{
			for (j=1; j<=col; j++)
			{

				dp[i][j] += dp[i][j-1];
			}
		}

		best=mrs=0;
		for(wid = 1; wid <= col; wid++)
		{
			for(j = wid; j <= col; j++)
			{
				for(i = 1, mis = 0; i <= row; i++)
				{
					elem = dp[i][j] - dp[i][j-wid];
					mis = (mis < 0) ? elem : mis+elem;
					if(mis > best)	best= mis;
				}
				if(best> mrs)	mrs = best;
			}
		}
		printf("Case #%d: %d\n", cc+1, mrs);
	}


	return 0;
}


