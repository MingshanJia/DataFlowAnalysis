/*
#include <stdio.h>
#include <windows.h>
int W[1000], Xr[100], Yr[100];
int main(){
freopen("input.txt","r",stdin);
scanf("%*d");
int K, N, M, H;
scanf("%d %d %d %d",&K,&N,&M,&H);
int i, j, k, s, e, X, a, b, c;

for(a=0;a<=N;a++){ 
for(b=0;b<=M;b++){
for(c=0;c<=H;c++) {
X = 1;
s = e = 0;
if (a == 3 && b == 3 && c == 2){
a=a;
}
else continue;
int ts, te;
ts = te = 0;
for(i=0;i<a;i++) X *= 3;
for(i=0;i<X;i++){
int Y = 1;
for(j=0;j<b;j++) Y *= c;
for(j=0;j<Y;j++){
for(k=0;k<K;k++) W[k] = 0;
for(k=0;k<c;k++) W[k] ++;

int tX = i;
for(k=0;k<a;k++){
Xr[k] = tX % 3;
W[tX % 3] --;
tX /= 3;
}
int tY = j;
if (c > 0){
for(k=0;k<b;k++){
Yr[k] = tY % c;
W[tY % c] ++;
tY /= c;
}
}
for(k=0;k<K;k++){
if (W[k] < 0) break;
}
if (k ==  K) s ++;
else e ++;
if (Xr[0] < 2){
bool test = false;
for(int p=0;p<b;p++) if (Yr[p] == Xr[0]){ test = true;}
if (test) {
if (k ==  K) ts ++;
else te ++;
}
}
}
}

if(s+e == 0) printf("%lf ",1.0);
else printf("%lf(%d,%d,%d) ", 1.0 - (double)e/(double)(s+e), a, b, c);

if (ts+te == 0) printf("%lf ", 1.0);
else printf("%lf", 1.0 - (double)te / (double)(ts+te));


}
printf("\n");
}
printf("\n");
}
}

*/




#include <stdio.h>
#include <algorithm>
#include <vector>
#include <memory.h>
#define vc vector
#define pr pair
#define mp make_pair
#define sz(x) x.size()
#define For(i,s,e,p) for(int i=(s);i<=(e);i+=(p))
#define Rep(i,n) For(i,0,n-1,1)
#define Set(A,x) memset(A, x, sizeof(A))

using namespace std;
double D1[201][101][101];
double D2[201][101][101];
double Comb[201][201];
int main() {
	freopen("D-small-attempt2.in","r",stdin);
	freopen("D-small-attempt2.out","w",stdout);
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	int T;
	scanf("%d",&T);
	int i, j, k, p, q;
	Comb[0][0] = 1.0;
	for(i=1;i<=201;i++){
		Comb[i][0] = 1.0;
		for(j=1;j<=201;j++){
			Comb[i][j] = Comb[i-1][j] + Comb[i-1][j-1];
		}
	}
/*	for(i=0;i<200;i++){
		for(j=0;j<=100;j++){
			for(k=0;k<=100;k++){*/
	
	for(i=0;i<20;i++){
		for(j=0;j<=30;j++){
			for(k=0;k<=30;k++){
				D1[i][j][k] = 0.0;
				D2[i][j][k] = 0.0;
				if (i == 0){
					if (k - j + 1 < 0) continue;
					D2[i][j][k] = 1.0;
					if (k - j < 0) continue;
					D1[i][j][k] = 1.0;
					continue;
				}
				for(p=0;p<=j;p++){
					for(q=0;q<=k;q++){
						//현재에 p개 던지고 q개 막음
						if (q - p < 0) continue;
						D1[i][j][k] += D1[i-1][j-p][k-q] * Comb[j][p] * Comb[k][q];
					}
				}
				D2[i][j][k] = 0.0;
				for(p=0;p<=j;p++){
					for(q=0;q<=k;q++){
						//현재에 p개 던지고 q개 막음
						if (q - p + 1 < 0) continue;
						D2[i][j][k] += D2[i-1][j-p][k-q] * Comb[j][p] * Comb[k][q];
					}
				}
			}
		}
	}
	while(T-->0) {
		int K, N, M, H;
		scanf("%d %d %d %d",&K,&N,&M,&H);
		static int cs = 1;
		int i, j;
		double sol = 0.0;
		for(i=0;i<=N;i++){
			for(j=0;j<=M;j++){
				double X, Y;
				if (K-H == 0){
					if (i == 0 && j == 0) X = 1.0;
					else X = 0.0;
				}
				else X = D1[K-H-1][i][j];

				if (H == 0){
					if (N-i == 0 && M-j == 0) Y = 1.0; 
					else Y = 0.0;
				}
				else Y = D2[H-1][N-i][M-j];
				sol += X*Y * Comb[N][i] * Comb[M][j];
			}
		}
		for(i=0;i<N+M;i++) sol /= K;
		printf("Case #%d: %.9lf\n",cs++, 1.0-sol);
	}
	return 0;
}


