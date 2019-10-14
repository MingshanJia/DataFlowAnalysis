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

int N, X, S[10100];

bool test(int K)
{
	for(int i = 0; i < K; i++) if(S[i] + S[2*K-1-i] > X) return false;
	return true;
}

int main()
{
	int T;
	scanf("%d", &T);

	for(int t = 0; t++ < T; ) {
		scanf("%d%d", &N, &X);
		for(int i = 0; i < N; i++) scanf("%d", S+i);
		
		sort(S, S + N);

		int left=0, right=N/2;
		while(left < right) {
			int mid = (left+right+1)/2;

			if(test(mid)) {
				left = mid;
			} else {
				right = mid - 1;
			}
		}
		printf("Case #%d: %d\n", t, N - left);
	}

	return 0;
}
