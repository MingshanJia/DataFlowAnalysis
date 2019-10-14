#include <bits/stdc++.h>
using namespace std;

int t, N, sum[5010], a, b, Q;

int main() {
	scanf("%d", &t);
	int xx = 1;
	while (t--) {
		scanf("%d", &N);
		memset(sum, 0, sizeof(sum));
		for (int i = 0; i < N; i++) {
			scanf("%d%d", &a, &b);
			sum[a]++;
			sum[b + 1]--;
		}
		scanf("%d", &Q);
		printf("Case #%d:", xx++);
		for (int i = 1; i <= 5000; i++) {
			sum[i] += sum[i - 1];
		}
		for (int i = 0; i < Q; i++) {
			scanf("%d", &a);
			printf(" ");
			cout << sum[a];	
		}
		cout << endl;
	}
	return 0;
}
