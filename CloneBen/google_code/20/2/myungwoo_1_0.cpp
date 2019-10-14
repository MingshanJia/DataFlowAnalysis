#include <stdio.h>
#include <string.h>
#include <string>
#include <algorithm>
using namespace std;

typedef long long lld;

int T,K,D[2][256];
char A[256],B[256],C[256],ch,tmp[256];

struct Z{
	int fa,fb;
	string a,b,c;
	Z(){ fa=fb=0; a=b=c="z"; }
	Z(int fa,int fb,string a,string b,string c){ this->fa = fa, this->fb = fb, this->a = a, this->b = b; this->c = c; }
	bool operator < (const Z &ot)const{
		if (a != ot.a) return a<ot.a;
		if (b != ot.b) return b<ot.b;
		if (c != ot.c) return c<ot.c;
		return 0;
	}
} P[2][256],t;

void rearr(char *str)
{
	int i,len=strlen(str);
	bool sw=0;
	for (i=0;i<256;i++) tmp[i] = '0';
	if (len > 1 && str[0] == '?') str[0] = '-';
	for (i=0;i<len;i++) tmp[255-i] = str[len-i-1];
	for (i=0;i<256;i++) str[i] = tmp[i];
}

int main()
{
	int i,j,k,a,b,c;
	bool sw;
	freopen("input.txt","r",stdin), freopen("output.txt","w",stdout);
	for (scanf("%d",&T);T--;){
		scanf("%s %c%s %*c%s",A,&ch,B,C);
		rearr(A), rearr(B), rearr(C);
		for (i=0;i<256;i++) D[0][i] = D[1][i] = 0, P[0][i] = P[1][i] = Z();
		D[0][255] = 1;
		for (i=255;i>0;i--){
			for (a=10;a--;) if (A[i] == '?' || (A[i] == '-' && a > 0) || A[i]-'0' == a){
				for (b=10;b--;) if (B[i] == '?' || (B[i] == '-' && b > 0) || B[i]-'0' == b){
					for (c=10;c--;) if (C[i] == '?' || (C[i] == '-' && c > 0) || C[i]-'0' == c){
						if (ch == '+'){
							if (D[1][i]){
								if (c == (a+b+1)%10){
									if (a+b+1 > 9){
										D[1][i-1] = 1;
										if (Z(1,i,char(a+'0')+P[1][i].a,char(b+'0')+P[1][i].b,char(c+'0')+P[1][i].c) < P[1][i-1])
											P[1][i-1] = Z(1,i,char(a+'0')+P[1][i].a,char(b+'0')+P[1][i].b,char(c+'0')+P[1][i].c);
									}
									else{
										D[0][i-1] = 1;
										if (Z(1,i,char(a+'0')+P[1][i].a,char(b+'0')+P[1][i].b,char(c+'0')+P[1][i].c) < P[0][i-1])
											P[0][i-1] = Z(1,i,char(a+'0')+P[1][i].a,char(b+'0')+P[1][i].b,char(c+'0')+P[1][i].c);
									}
								}
							}
							if (D[0][i]){
								if (c == (a+b)%10){
									if (a+b > 9){
										D[1][i-1] = 1;
										if (Z(0,i,char(a+'0')+P[0][i].a,char(b+'0')+P[0][i].b,char(c+'0')+P[0][i].c) < P[1][i-1])
											P[1][i-1] = Z(0,i,char(a+'0')+P[0][i].a,char(b+'0')+P[0][i].b,char(c+'0')+P[0][i].c);
									}
									else{
										D[0][i-1] = 1;
										if (Z(0,i,char(a+'0')+P[0][i].a,char(b+'0')+P[0][i].b,char(c+'0')+P[0][i].c) < P[0][i-1])
											P[0][i-1] = Z(0,i,char(a+'0')+P[0][i].a,char(b+'0')+P[0][i].b,char(c+'0')+P[0][i].c);
									}
								}
							}
						}else{
							if (D[1][i]){
								k = (a-1-b);
								sw = 0;
								while (k < 0) k += 10, sw = 1;
								if (k == c){
									D[sw][i-1] = 1;
									if (Z(1,i,char(a+'0')+P[1][i].a,char(b+'0')+P[1][i].b,char(c+'0')+P[1][i].c) < P[sw][i-1])
										P[sw][i-1] = Z(1,i,char(a+'0')+P[1][i].a,char(b+'0')+P[1][i].b,char(c+'0')+P[1][i].c);
								}
							}
							if (D[0][i]){
								k = (a-b);
								sw = 0;
								while (k < 0) k += 10, sw = 1;
								if (k == c){
									D[sw][i-1] = 1;
									if (Z(0,i,char(a+'0')+P[0][i].a,char(b+'0')+P[0][i].b,char(c+'0')+P[0][i].c) < P[sw][i-1])
										P[sw][i-1] = Z(0,i,char(a+'0')+P[0][i].a,char(b+'0')+P[0][i].b,char(c+'0')+P[0][i].c);
								}
							}
						}
					}
				}
			}
		}
		/*for (a=b=0;;){
			t = P[a][b];
			A[b] = t.a+'0', B[b] = t.b+'0', C[b] = t.c+'0';
			if (b == 255) break;
			a = t.fa, b = t.fb;
		}*/
		if (!D[0][0]){ puts("impossible"); continue; }
		printf("Case #%d: ",++K);
		for (i=0,sw=0;i<255;i++){
			if (i == 254 || P[0][0].a[i] != '0') sw = 1;
			if (sw) printf("%c",P[0][0].a[i]);
		}
		printf(" %c ",ch);
		for (i=0,sw=0;i<255;i++){
			if (i == 254 || P[0][0].b[i] != '0') sw = 1;
			if (sw) printf("%c",P[0][0].b[i]);
		}
		printf(" = ");
		for (i=0,sw=0;i<255;i++){
			if (i == 254 || P[0][0].c[i] != '0') sw = 1;
			if (sw) printf("%c",P[0][0].c[i]);
		}
		puts("");
	}
}