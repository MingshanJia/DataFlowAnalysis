/* OBSERVATION: I know this code is wrong. I just want partial credit. Could not figure out general pattern. */

#include<stdio.h>
#include<assert.h>

typedef unsigned nat;
typedef unsigned long long natural;

#define N 3000
#define LIMIT (natural(1) << 32)
#define OUT 16

nat F[N][N];
bool I[N][N];

bool inf(nat d, nat b) {
	if (b > d) b = d;
	if (b == 0 || b == 1) return false;
	if (b == 2) {
		if (d < (1 << 18)) {
			natural f = (d*d + d) >> 1;
			return f >= LIMIT;
		}
		else return true;
	}
	else {
		if (d >= N) return true;
		else return I[d][b];
	}
}

nat floor(nat d, nat b) {
	if (b > d) b = d;
	if (b == 0) return 0;
	else if (b == 1) return d;
	else if (b == 2) return (d*d + d) >> 1;
	else if (d < N) return F[d][b];
	assert(false);
}

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
	
	#if 0
	for (nat i = 0; i != OUT; ++i) {
		for (nat j = 0; j != OUT; ++j) {
			if (I[i][j]) printf("%12d", -1);
			else printf("%12u", F[i][j]);
		}
		putchar('\n');
	}
	#endif
	
	#if 0
	nat k = 0;
	while (!I[k][3]) ++k;
	printf("%u %u\n", k, F[k-1][3]);
	#endif
	
	#if 1
	nat cases;
	scanf("%u", &cases);
	for (nat cs = 0; cs != cases; ++cs) {
		nat f, d, b;
		scanf("%u%u%u", &f, &d, &b);
		
		nat x0 = 0, x1 = d, y0 = 0, y1 = b;
		while (x0 < x1) {
			nat m = (x0+x1) >> 1;
			if (inf(m, b) || floor(m, b) >= f) x1 = m;
			else x0 = m+1;
		}
		while (y0 < y1) {
			nat m = (y0+y1) >> 1;
			if (inf(d, m) || floor(d, m) >= f) y1 = m;
			else y0 = m+1;
		}	
		
		if (inf(d, b)) {
			printf("Case #%u: -1 %u %u\n", cs+1, x0, y0);
		}
		else {
			printf("Case #%u: %u %u %u\n", cs+1, F[d][b], x0, y0);
		}
	}
	#endif

	return 0;
}

