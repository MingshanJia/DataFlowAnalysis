/*
 * B.cpp
 * Another buggy code by mostafa_saad
 *
 *  Created on: Mar 22, 2010
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
using namespace std;

#define all(v)				((v).begin()), ((v).end())
#define sz(v)				((int)((v).size()))
#define clr(v, d)			memset(v, d, sizeof(v))
#define repi(i, j, n) 		for(int i=(j);i<(int)(n);++i)
#define repd(i, j, n) 		for(int i=(j);i>=(int)(n);--i)
#define repa(v)				repi(i, 0, sz(v)) repi(j, 0, sz(v[i]))
#define rep(i, v)			repi(i, 0, sz(v))
#define lp(i, cnt)			repi(i, 0, cnt)
#define lpi(i, s, cnt)		repi(i, s, cnt)
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
#ifndef ONLINE_JUDGE
	freopen("B-large.in", "rt", stdin);
    freopen("blarge.txt", "wt", stdout);
#endif

	int cases;
	cin>>cases;

	lp(cc, cases)
	{
		int n, t, e;
		cin>>n>>t>>e;
		t--;

		vector< vector<int> > v(n);

		lp(i, e)
		{
			int tt, limit;
			cin>>tt>>limit;
			tt--;
			v[tt].push_back(limit);
		}

		vector<int> ans;
		bool good = true;

		lp(i, n) {
			sort( all(v[i]) );
			reverse( all(v[i]));

			int cnt = 0;

			if(i == t) {
				ans.push_back(0);
				continue;
			}


			for (int j = 0; j < sz(v[i]); ++j) {

				int k = v[i][j];

				if(v[i][j] <= 0) {
					good = false;
					break;
				}
				v[i][j]--;
				cnt++;
				if(v[i][j] >= sz(v[i])-j-1) {
					break;
				}
				while(v[i][j]) {
					v[i].pop_back();
					v[i][j]--;
				}
			}

			if(!good)	break;
			ans.push_back(cnt);
		}

		cout<<"Case #"<<cc+1<<":";
		if(!good) {
			cout<<" IMPOSSIBLE\n";
		} else {
			rep(i, ans) {
				cout<<" "<<ans[i];
			}
			cout<<"\n";
		}

	}

	return 0;
}
