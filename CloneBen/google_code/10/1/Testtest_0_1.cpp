#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#define eps 1e-8
#define oo 1<<29
#define LL long long

using namespace std;

LL T, m, n, q, w, mi, ma, cnt, t, fi, cc, r, z, x, an, ans, ansCnt;

char c[20][20] = {"1111110", "0110000", "1101101", "1111001", "0110011", "1011011", "1011111", "1110000", "1111111", "1111011"};
LL b[20], d[20];
char s[110][20];
LL a[110];
LL e[20], f[20];
LL g[20000];

int main(){
	memset(b, 0, sizeof(b));
	for (LL i=0; i<10; i++)
		for (LL j=0; j<7; j++)
			b[i] = b[i] * 2 + c[i][j]-'0';
//	for (LL i=0; i<10; i++)
//		printf("%lld %lld\n", i, b[i]);
	scanf("%lld", &T);
	for (LL rr = 1; rr <= T; rr++){
		ansCnt = 0;
		memset(a, 0, sizeof(a));
		printf("Case #%lld: ", rr);
		scanf("%lld", &m);
		for (LL i=0; i<m; i++){
			scanf("%s", s[i]);
		}

		for (LL i=0; i<m; i++)
			for (LL j=0; j<7; j++)
				a[i] = a[i]*2 + s[i][j]-'0';
/*				
		for (LL i=0; i<m; i++)
			printf("%lld %lld\n", i, a[i]);
*/			
		for (LL k=0; k<128; k++){
			bool fi = false;
			for (LL j=0; j<10; j++)
				d[j] = (b[j] & k);
			for (LL j=0; j<10; j++)
				e[j] = 0, f[j] = 1;
			for (LL i=m-1; i>=0; i--){
				for (LL j=0; j<10; j++)
					e[j] = 0;
				for (LL j=0; j<10; j++)
					if (d[j] == a[i])
						e[j] = 1;
				for (LL j=0; j<10; j++)
					if (e[j] == 1 && f[(j+9)%10] == 1)
						e[j] = 1;
					else e[j] = 0;
				LL temp = 0;
				for (LL j=0; j<10; j++){
					f[j] = e[j];
					temp += e[j];
				}
				if (temp == 0){
					fi = true;
					break;
				}
			}
			if (fi)
				continue;
			else {
				LL cnt = 0, index = -1;
				for (LL j=0; j<10; j++)
					if (e[j] == 1){
						index = j;
//						printf("%lld %lld\n", k, (index - m + 100000)%10);
						index = (index - m + 100000)%10;
						g[ansCnt++] = d[index];
					}
			}
		}
		bool ok = (ansCnt==0?false:true);
//		printf("%lld\n", ansCnt);
//		for (LL i=0; i<ansCnt; i++)
//			printf("%lld %lld\n", i, g[i]);

		for (LL i=0; i<ansCnt; i++)
			if (g[0] != g[i]){
				ok = false;
				break;
			}
		if (ok){
			LL temp[10];
			w = g[0];
			for (LL i=0; i<7; i++){
				temp[i] = w % 2;
				w/=2;
			}
			for (LL i=6; i>=0; i--)
				printf("%lld", temp[i]);
			puts("");
		} else {
			puts("ERROR!");			
		}
	}
	return 0;
}
