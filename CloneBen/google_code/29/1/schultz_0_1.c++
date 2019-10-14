#include<stdio.h>
#include<string.h>

#include<algorithm>
using namespace std;

typedef unsigned nat;

#define LSIZEMAX 128
#define DMAX 512
#define ALPHASIZE 256

nat SA[ALPHASIZE];
char SL[LSIZEMAX], DL[LSIZEMAX], D[DMAX], OUT[DMAX];

int	main() {
	
	nat cases;
	scanf("%u", &cases);
	for (nat cs = 0; cs != cases; ++cs) {
		scanf("%s%s%s", D, SL, DL);
		nat m = strlen(SL);
		nat n = strlen(DL);
		
		for (nat i = 0; i != m; ++i) SA[SL[i]] = i;
		
		nat x = 0;
		for (char* p = D; *p != '\0'; ++p) {
			x = m*x + SA[nat(*p)];
		}
		
		printf("Case #%u: ", cs+1);
		if (x == 0) printf("%c\n", SL[0]);
		else {
			nat	k = 0;
			while (x != 0) {
				OUT[k] = DL[x%n];
				x/= n;
				++k;
			}
			OUT[k] = '\0';
			reverse(OUT, OUT+k);
			puts(OUT);
		}
	}	
		
	return	0;
}

