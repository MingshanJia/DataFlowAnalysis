#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int T,Case;
int N,M; long long B,A;
map<int, int> W,U;
vector<int> C;

int main()
{
	freopen ("A-large.in","r",stdin);
	freopen ("output.txt","w",stdout);
	long long i,x,y; int j;

	scanf ("%d",&T); while (T--){
		scanf ("%d %d %lld",&N,&M,&B);
		W.clear(); U.clear(); C.clear();
		for (i=0;i<M;i++){
			scanf ("%lld %lld",&x,&y);
			if (x >= B) W[x] += y;
			else U[x] += y,C.push_back(x);
		}

		sort(C.begin(),C.end()); A = 0;
		for (i=B;N;i++){
			int &a = W[i];
			while (N && a){
				N--; a--; A += i;
			}

			for (j=0;j<C.size();j++){
				if (C[j] > i - C[j]) break;
				if (C[j] != i - C[j]){
					int &b = U[C[j]];
					int &c = U[i-C[j]];
					while (N && b && c){
						N--; b--; c--; A += i;
					}
				}
				else{
					int &b = U[C[j]];
					while (N && b >= 2){
						N--; b-=2; A += i;
					}
				}
			}
			if (i > 40000) break;
		}
		if (N) A = -1;
		printf ("Case #%d: %d\n",++Case,A);
	}
	return 0;
}