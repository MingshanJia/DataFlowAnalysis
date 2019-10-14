#include <stdio.h>
#include <algorithm>
#include <vector>
#include <memory.h>
#define vc vector
#define pr pair
#define mp make_pair
#define sz(x) x.size()
#define For(i,s,e,p) for(int i=(s);i<=(e);i+=(p))
#define Rep(i,n) For(i,0,n-1,1)
#define Set(A,x) memset(A, x, sizeof(A))

using namespace std;
int main() {
	freopen("A-small-attempt0.in","r",stdin);
	freopen("A-small-attempt0.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T-->0) {
		int n, m, b;
		scanf("%d %d %d",&n,&m,&b);
		int i, j;
		vc<pr<int, int> > A, B;
		for(i=0;i<m;i++){
			int p, q;
			scanf("%d %d",&p,&q);
			if (p >= b) {
				A.push_back(mp(p, q));
			} else {
				B.push_back(mp(p, q));
			}
		}
		sort(B.begin(), B.end());

		vc< pr<int, pr<int, int> > > C;
		for(i=0;i<B.size();i++){
			for(j=0;j<B.size();j++){
				if (B[i].first + B[j].first >= b ){
					C.push_back( mp(B[i].first + B[j].first, mp(i, j)) );
				}
			}	
		}
		sort(C.begin(), C.end());
		for(i=0;i<C.size();i++){
			int x = C[i].second.first;
			int y = C[i].second.second;
			if (B[x].second > 0 && B[y].second > 0) {
				int z;
				if (x == y) z = B[x].second / 2;
				else z = min(B[x].second, B[y].second);
				if (z > 0) {
					A.push_back( mp(C[i].first, z) );
					B[x].second -= z;
					B[y].second -= z;
				}
			}
		}

		sort(A.begin(), A.end());
		long long sol = 0;
		for(i=0;i<A.size();i++){
			int p;
			p = min(n, A[i].second);
			sol +=(long long) p * (long long)A[i].first;
			n -= p;
		}

		static int cs = 1;
		printf("Case #%d: %lld\n",cs++, (n>0)?-1:sol);
	}
	return 0;
}
