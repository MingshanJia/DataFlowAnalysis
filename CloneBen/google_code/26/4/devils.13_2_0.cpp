#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
typedef unsigned long long ll;
using namespace std;

#define pb push_back
#define mp make_pair
#define sz size()
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<pii> > adjL;
int oo = (int) 1e9;

int arr[60][60], dp[60][60];
int main()
{

	freopen("in.txt","rt",stdin);
	freopen("out.txt" ,"wt",stdout);
	int t;scanf("%d",&t);
	for (int ii = 0; ii < t; ++ii) {
		int c,r;
		scanf("%d%d",&c,&r);
		vector<string>vs;
		string str;
		for (int i = 0; i < r; ++i) {
			cin>>str;
			vs.pb(str);
		}
		memset(arr,0,sizeof arr);
		memset(dp,0,sizeof dp);

		for (int i = 0; i < vs.size(); ++i) {
			for (int j = 0; j < vs[0].size(); ++j) {
				if(vs[i][j]!='G' && vs[i][j]!='S')
					arr[i+1][j+1] = -10000;
				else arr[i+1][j+1] = 1;
			}
		}
		for (int i = 1; i <= r; ++i) {
			for (int j = 1; j <= c; ++j) {
				arr[i][j]+=arr[i-1][j]+arr[i][j-1]-arr[i-1][j-1];
			}
		}

		for (int i = 1; i <= r; ++i) {
			for (int j = 1; j <= c; ++j) {
				if(arr[i][j]==1)
				dp[i][j] = min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1])) + arr[i][j];
			}
		}
		int mx = 0 ;
		for (int i = 1; i <= r; ++i) {
			for (int j = 1; j <= c; ++j) {
				for (int ii = i; ii <= r; ++ii) {
					for (int jj = j; jj <= c; ++jj) {
						int cur = arr[ii][jj] - arr[ii][j-1] - arr[i-1][jj] + arr[i-1][j-1];
						mx = max(mx, cur);

					}
				}
			}
		}
		printf("Case #%d: %d\n",ii+1, mx);

	}
	return 0;
}
/*
 *
4
1 1
G
2 2
GS
SG
2 2
GT
GG
5 8
GGTGG
TGGGG
GSSGT
GGGGT
GWGGG
RGTRT
RTGWT
WTWGR
*/
