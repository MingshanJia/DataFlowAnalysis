#include <stdio.h>
#include <stdlib.h>

int main() {
	int T, t, i,j,k;
	int L, P, C, R;

	scanf("%d", &T);
	for (t = 1; t <= T; t++) {
		scanf("%d %d %d", &L, &P, &C);
		int N = 0;
		
		while (L * C < P) {
			L *= C;
			N++;
		}	
		
		R = 0;
		while (N > 0) { R++; N/= 2;}
		
		printf("Case #%d: %d\n", t, R);
	}
	
	return 0;
}
