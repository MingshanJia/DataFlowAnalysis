#include <stdio.h>

int T,C,GO[1000010],DA[1000010],END[1000010],LEN,CYC,ST;
long long M,D,W,ANS,S,SUM[1000010],ALL,CYS;

int main()
{
	freopen ("input.txt","r",stdin);
	freopen ("output.txt","w",stdout);

	int i;

	scanf ("%d",&T); while (T--){
		scanf ("%lld %lld %lld",&M,&D,&W);

		for (i=0;i<W;i++){
			GO[i] = (D + i) % W;
			DA[i] = (D + i + W - 1) / W;
			END[i] = -1; SUM[i] = 0;
		}

		S = 0; END[0] = 0; SUM[0] = DA[0];
		while (1){
			if (END[GO[S]] != -1){
				ALL = SUM[S] + DA[GO[S]];
				LEN = END[GO[S]] + 1;
				CYC = END[S] - END[GO[S]] + 1;
				CYS = ALL - SUM[GO[S]];
				ST = S;
				break;
			}
			END[GO[S]] = END[S] + 1;
			SUM[GO[S]] = SUM[S] + DA[GO[S]];
			S = GO[S];
		}

		ANS = 0;
		if (M <= LEN){
			S = 0;
			while (M--){
				ANS += DA[S];
				S = GO[S];
			}
		}
		else{
			S = 0;
			while (LEN--){
				ANS += DA[S];
				S = GO[S];
				M--;
			}

			ANS += CYS * (long long)(M / CYC);
			M %= CYC;
			S = GO[GO[ST]];
			while (M--){
				ANS += DA[S];
				S = GO[S];
			}
		}

		printf ("Case #%d: %lld\n",++C,ANS);
	}

	return 0;
}