#include<stdio.h>

typedef unsigned nat;
typedef unsigned long long natural;

#define N 128
#define LIMIT (natural(1) << 32)

nat F[N][N];
bool I[N][N];

int main() {
	
	for (nat d = 0; d != N; ++d) {
		F[d][0] = 0;
		I[d][0] = false;
	}
	for (nat b = 0; b != N; ++b) {
		F[0][b] = 0;
		I[0][b] = false;
	}
	
	for (nat d = 1; d != N; ++d) for (nat b = 1; b != N; ++b) {
		I[d][b] = false;
		natural s = 0;
		for (nat k = 0; k != d; ++k) {
			if (I[k][b-1]) {
				I[d][b] = true;
				break;
			}
			else {
				s+= natural(F[k][b-1])+1;
				if (s >= LIMIT) {
					I[d][b] = true;
					break;
				}
			}
		}
		F[d][b] = nat(s);
	}
	
	/*for (nat i = 0; i != 16; ++i) {
		for (nat j = 0; j != 16; ++j) printf("%8u", I[i][j] ? -1 : F[i][j]);
		putchar('\n');
	}
	*/
			
	nat cases;
	scanf("%u", &cases);
	for (nat cs = 0; cs != cases; ++cs) {
		nat f, d, b;
		scanf("%u%u%u", &f, &d, &b);
		
		nat x, y;
		for (x = 0; !I[x][b] && F[x][b] < f; ++x);
		for (y = 0; !I[d][y] && F[d][y] < f; ++y);
	
		if (I[d][b]) {
			printf("Case #%u: -1 %u %u\n", cs+1, x, y);
		}
		else {
			printf("Case #%u: %u %u %u\n", cs+1, F[d][b], x, y);
		}
	}

	return 0;
}

