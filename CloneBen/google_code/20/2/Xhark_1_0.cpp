#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <string>

using namespace std;
char A[256], B[256], C[256], Tc[256];
char op[128];

int dy[256][2]; // 자리올림 잇냐업냐
string sA[256][2];
string sB[256][2];
string sC[256][2];
void Test(int x,int y,string X,string Y,string Z){
	if (sA[x][y].length() == 0) {
		sA[x][y] = X;
		sB[x][y] = Y;
		sC[x][y] = Z;
		return;
	}
	if (op[0] == '+') {
		if (sA[x][y] > X || 
			(sA[x][y] == X && sB[x][y] > Y) || 
			(sA[x][y] == X && sB[x][y] == Y && sC[x][y] > Z)){
			sA[x][y] = X;
			sB[x][y] = Y;
			sC[x][y] = Z;
		}
	} else {
		if (sC[x][y] > Z || 
			(sC[x][y] == Z && sB[x][y] > Y) || 
			(sC[x][y] == Z && sB[x][y] == Y && sA[x][y] > X)){
			sA[x][y] = X;
			sB[x][y] = Y;
			sC[x][y] = Z;
		}
	}
}
void print1(string T){
	int i;
	int go = 0;
	for(i=0;i<T.length();i++){
		if(T[i] != '0') go = 1;
		if(go) printf("%c",T[i]);
	}
	if(go == 0) printf("0");
}
void print(string X,char op, string Y, string Z){
	print1(X);
	printf(" %c ", op);
	print1(Y);
	printf(" = ");
	print1(Z);
}
int main(){
	freopen("B-small-attempt2.in","r",stdin);
	freopen("output.txt","w",stdout);
	int T;
	scanf("%d",&T);
	while(T-->0){
		int i, j, k, l;
		for(i=0;i<256;i++) for(j=0;j<2;j++){
			sA[i][j]=sB[i][j]=sC[i][j]="";
			dy[i][j] = 0;
		}

		scanf("%s %s %s %*s %s", A, op, B, C);

		if (op[0] == '-') {
			//A - B = C
			//C + B = A
			strcpy(Tc, A);
			strcpy(A, C);
			strcpy(C, Tc);
		}
		int lA, lB, lC, L;
		lA = strlen(A); lB = strlen(B); lC = strlen(C);
		L = max(max(lA, lB), lC);
		for(i=0;i<L;i++){
			if(i < lA) A[L-1-i] = A[lA-1-i];
			else A[L-1-i] = '0';
		}
		
		for(i=0;i<L;i++){
			if(i < lB) B[L-1-i] = B[lB-1-i];
			else B[L-1-i] = '0';
		}

		for(i=0;i<L;i++){
			if(i < lC) C[L-1-i] = C[lC-1-i];
			else C[L-1-i] = '0';
		}

		for(i=0;i<L;i++) {
			for(j=0;j<10;j++){
				if (A[L-1-i] != '?' && A[L-1-i]-'0' != j) continue;
				if (i == lA-1 && j == 0 && lA != 1) continue;
				for(k=0;k<10;k++){
					if (B[L-1-i] != '?' && B[L-1-i]-'0' != k) continue;
					if (i == lB-1 && k == 0 && lB != 1) continue;
					for(l=0;l<10;l++){
						if (C[L-1-i] != '?' && C[L-1-i]-'0' != l) continue;
						if (i == lC-1 && l == 0 && lC != 1) continue;
						int sum, tt;
						sum = j+k;
						tt = l;
						if (sum == tt) { // 자리올림 없이 잘됨 ^^
							if (i == 0){
								dy[i][0] = 1;
								string X, Y, Z;
								X=(char)(j+'0');
								Y=(char)(k+'0');
								Z=(char)(l+'0');
								Test(i, 0, X,Y,Z);
							}
							else{
								if (dy[i-1][0]) {
									dy[i][0] = 1;
									string X, Y, Z;
									
									X=(char)(j+'0') + sA[i-1][0];
									Y=(char)(k+'0') + sB[i-1][0];
									Z=(char)(l+'0') + sC[i-1][0];
									Test(i, 0, X,Y,Z);
								}
							}
						}
						
						if (sum == tt+10) { // 자리올림 
							if (i == 0){
								dy[i][1] = 1;
								string X,Y, Z;
								X=(char)(j+'0');
								Y=(char)(k+'0');
								Z=(char)(l+'0');
								Test(i, 1, X,Y,Z);
							}
							else{
								if (dy[i-1][0]) {
									dy[i][1] = 1;
									string X, Y, Z;
									
									X=(char)(j+'0') + sA[i-1][0];
									Y=(char)(k+'0') + sB[i-1][0];
									Z=(char)(l+'0') + sC[i-1][0];
									Test(i, 1, X,Y,Z);
								}
							}
						}
						
						if (sum+1 == tt) { // 자리올림 없이 잘됨 ^^받음
							if (i != 0){
								if (dy[i-1][1]){
									dy[i][0] = 1;
									string X, Y, Z;
									
									X=(char)(j+'0') + sA[i-1][1];
									Y=(char)(k+'0') + sB[i-1][1];
									Z=(char)(l+'0') + sC[i-1][1];
									Test(i, 0, X,Y,Z);
								}
							}
						}
						
						if (sum+1 == tt+10) { // 자리올림 받음
							if (i != 0){
								if (dy[i-1][1]) {
									dy[i][1] |= dy[i-1][1];
									string X, Y, Z;
									
									X=(char)(j+'0') + sA[i-1][1];
									Y=(char)(k+'0') + sB[i-1][1];
									Z=(char)(l+'0') + sC[i-1][1];
									Test(i, 1, X,Y,Z);
								}
							}
						}
					}
				}
			}
		}

		static int cs = 1;
		printf("Case #%d: ", cs++);
		if (op[0] == '+') {
			print(sA[L-1][0], '+', sB[L-1][0], sC[L-1][0]);
		} else {
			print(sC[L-1][0], '-', sB[L-1][0], sA[L-1][0]);
		}
		printf("\n");
	}
	return 0;
}