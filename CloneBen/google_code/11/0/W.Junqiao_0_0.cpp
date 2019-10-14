#include <deque>
#include <queue>
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
#include <set>
#include <cstdlib>
#include <hash_map>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<string> VS;

#define rep(i,s,e) for(int i=s;i<e;i++)
#define sz(X) ((int)(X.size()))
#define tr(it,x) for(typeof(x.begin()) it=x.begin();it!=x.end();++it)
#define all(x) x.begin(),x.end()
#define clr(x,c) memset(x,c,sizeof(x))
//---------------------------------------------------------------

int mat[2000][2000];
bool vst[2000];
bool check(vector<int> v) {
	clr(vst, false);
	rep(i, 0, sz(v)) vst[v[i]] = true;
	rep(i, 1, sz(v)+1) if(vst[i]==false) return false;
	return true;
}

int main() {
	freopen("F:/TDDOWNLOAD/A-small-attempt0.in", "r", stdin);
	freopen("F:/TDDOWNLOAD/A-small-attempt0.out", "w", stdout);

	int T;
	cin>>T;
	rep(te, 1, T+1) {
		int N; cin>>N;
		bool fail = false;
		rep(i, 1, N*N+1) rep(j, 1, N*N+1) cin>>mat[i][j];
		rep(i, 1, N*N+1) {
			vector<int> v;
			rep(j, 1, N*N+1) v.push_back(mat[i][j]);
			if(check(v) == false)
				fail = true;
		}
		rep(j, 1, N*N+1) {
			vector<int> v;
			rep(i, 1, N*N+1) v.push_back(mat[i][j]);
			if(check(v) == false) {
				fail = true;
			}
		}

		for(int i=1, j=1;i<=N*N;j+=N) {
			if(j>N*N) {
				i += N; 
				j = 1 - N;
				continue;
			}
			vector<int> v;
			rep(x, 0, N) rep(y, 0, N) v.push_back(mat[i+x][j+y]);
			if(check(v) == false)
				fail = true;
		}


		printf("Case #%d: ", te);
		if(fail) puts("No");
		else puts("Yes");
	}
}

