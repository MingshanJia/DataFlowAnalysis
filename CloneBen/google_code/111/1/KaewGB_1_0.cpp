#include <stdio.h>
#define	MIN(a, b)	(((a) < (b))? (a):(b))

void solve(){
	long long int a, b;
	int alpha, beta, y, i;
	int babies, ba, bb;
	int da, db;
	scanf("%lld %lld %d %d %d", &a, &b, &alpha, &beta, &y);

	for(i=0;i<y;i++){
		da = a/100;
		db = b/100;

//		printf("da =%d, db=%d\n", da, db);

		babies = 2*MIN(a, b)/100;
		ba = babies*alpha/100;
		bb = babies*beta/100;
//		printf("ba=%d, bb=%d\n", ba, bb);
		babies = (babies-ba-bb);
		ba += babies/2;
		bb += (babies+1)/2;
//		printf("ba=%d, bb=%d\n", ba, bb);

		a += ba - da;
		b += bb - db;
	}

	printf("%lld %lld", a, b);
}

int main(int argc, char *argv[]){
	int i, t;
	scanf("%d", &t);
	for(i=0;i<t;i++){
		printf("Case #%d: ", i+1);
		solve();
		printf("\n");
	}
	return 0;
}

