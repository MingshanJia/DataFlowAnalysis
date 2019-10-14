#include <stdio.h>
#include <string>
using namespace std;

string num = "0123456789?"; string W[3],SIG,ANS;
int T,CASE; bool YES[300][10][10][2];
char P[300],Q[300],R[300],S[5],E[5];

bool solve(string a, string s, string b, string c)
{
	int L = max(a.length(),max(b.length(),c.length())) + 1;
	while (a.length() < L) a = num[0] + a;
	while (b.length() < L) b = num[0] + b;
	while (c.length() < L) c = num[0] + c;
	a += '0'; b += '0'; c += '0'; L++;
	int m,i,p,q,r;

	m = (s[0] == '+') ? 1 : -1;

	for (p=0;p<L;p++) for (q=0;q<=9;q++) for (r=0;r<=9;r++) YES[p][q][r][0] = YES[p][q][r][1] = 0;
	YES[L-1][0][0][0] = 1;

	for (i=L-2;i>=0;i--){
		bool carry = false; int ct = 10000;
		bool noncarry = false; int nct = 10000;

		for (p=0;p<=9;p++){
			for (q=0;q<=9;q++){
				if (m == 1){
					if (YES[i+1][p][q][0]){
						r = p + q;
						if (r >= 10) carry |= true;
						else noncarry |= true;
					}
					if (YES[i+1][p][q][1]){
						r = p + q + 1;
						if (r >= 10) carry |= true;
						else noncarry |= true;
					}
				}
				else{
					if (YES[i+1][p][q][0]){
						r = p - q;
						if (r < 0) carry |= true;
						else noncarry |= true;
					}
					if (YES[i+1][p][q][1]){
						r = p - q - 1;
						if (r < 0) carry |= true;
						else noncarry |= true;
					}
				}
			}
		}
		if (!carry && !noncarry) return false;

		for (p=0;p<=9;p++){
			if (a[i] == num[p] || a[i] == '?'){
				for (q=0;q<=9;q++){
					if (b[i] == num[q] || b[i] == '?'){
						for (r=0;r<=9;r++){
							if (c[i] == num[r] || c[i] == '?'){
								if (carry && (10 + p + m + q * m) % 10 == r) YES[i][p][q][1] = 1;
								if (noncarry && (10 + p + q * m) % 10 == r) YES[i][p][q][0] = 1;
							}
						}
					}
				}
			}
		}
	}

	return YES[0][0][0][0];
}

void go(int a)
{
	if (a == 3){
		int i,j; string w[3];
		w[0] = W[0]; w[1] = W[1]; w[2] = W[2];
		if (!solve(w[0],SIG,w[1],w[2])) return;
		for (i=0;i<w[0].length();i++){
			if (w[0][i] == '?'){
				for (j=0;j<=9;j++){
					if (w[0].length() != 1 && i == 0 && j == 0) continue;
					w[0][i] = num[j];
					if (solve(w[0],SIG,w[1],w[2])) break;
				}
				if (j == 10) return;
			}
		}
		for (i=0;i<w[1].length();i++){
			if (w[1][i] == '?'){
				for (j=0;j<=9;j++){
					if (w[1].length() != 1 && i == 0 && j == 0) continue;
					w[1][i] = num[j];
					if (solve(w[0],SIG,w[1],w[2])) break;
				}
				if (j == 10) return;
			}
		}
		for (i=0;i<w[2].length();i++){
			if (w[2][i] == '?'){
				for (j=0;j<=9;j++){
					if (w[2].length() != 1 && i == 0 && j == 0) continue;
					w[2][i] = num[j];
					if (solve(w[0],SIG,w[1],w[2])) break;
				}
				if (j == 10) return;
			}
		}

		ANS = min(ANS,w[0] + " " + SIG + " " + w[1] + " = " + w[2]);
	}
	else{
		if (W[a][0] != '?') go(a+1);
		else{
			int i;
			for (i=0;i<=9;i++){
				if (W[a].length() != 1 && i == 0) continue;
				W[a][0] = num[i];
				go(a+1);
				W[a][0] = num[10];
			}
		}
	}
}

int main()
{
	freopen ("input.txt","r",stdin);
	freopen ("output.txt","w",stdout);

	scanf ("%d",&T); while (T--){
		scanf ("%s %s %s %s %s",P,S,Q,E,R); SIG = S;
		W[0] = P; W[1] = Q; W[2] = R;
		printf ("Case #%d: ",++CASE);
		ANS = "z"; go(0);
		printf ("%s\n",ANS.c_str());
	}

	return 0;
}