#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <string>
#include <cstring>
using namespace std;
typedef long long i64;

int N, A[1010];

int main()
{
	int T;
	scanf("%d", &T);

	for(int t = 0; t++ < T; ) {
		scanf("%d", &N);
		for(int i=0;i<N;i++) scanf("%d", A+i);

		vector<int> vals;
		for(int i=0;i<N;i++) vals.push_back(A[i]);
		sort(vals.begin(), vals.end());

		int ret = 0;
		for(int i=0;i<vals.size();i++) {
			int pos = -1;
			for(int j=0;j<N;j++) if(A[j] == vals[i]){
				pos = j;
				break;
			}

			int lef = 0;
			for(int j=0;j<pos;j++) if(A[j] > A[pos]) ++lef;

			int rig = 0;
			for(int j=pos+1;j<N;j++) if(A[j] > A[pos]) ++rig;

			ret += min(lef, rig);
		}

		printf("Case #%d: %d\n", t, ret);
	}

	return 0;
}
