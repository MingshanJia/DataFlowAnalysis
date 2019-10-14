#include <stdio.h>
#define	MIN(a, b)	(((a) < (b))? (a):(b))

void solve(){
	long long int a, b, y, i, lasta, lastb;
	int alpha, beta;
	long long int babies, ba, bb;
	long long int da, db;
	scanf("%lld %lld %d %d %lld", &a, &b, &alpha, &beta, &y);

	lasta = a;
	lastb = b;

	for(i=0;i<y;i++){
		da = a/100;
		db = b/100;

		babies = 2*MIN(a, b)/100;
		ba = babies*alpha/100;
		bb = babies*beta/100;
		babies = (babies-ba-bb);
		ba += babies/2;
		bb += (babies+1)/2;

		a += ba - da;
		b += bb - db;

		if(a==lasta && b==lastb)
			break;
		else{
			lasta = a;
			lastb = b;
		}
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

