#include<stdio.h>
#include<string.h>
#include<memory.h>
int T, L, N;
char s[300], op;
char a[300], b[300], c[300];
int A, B, C;
int d[300][2], path[300][2];
bool exists()
{
	int i, j, k, aa, bb, cc, aa_to, bb_to, cc_to, aa_fr, bb_fr, cc_fr;
	memset(d, 0, sizeof(d));
	d[0][0] = 1;
	for(i = 0; i < N; i++){
		aa_fr = (i != 0 && (i+1) == A)? 1 : 0;
		aa_fr = (a[i] == '?') ? aa_fr :(a[i]-'0');
		aa_to = (a[i] == '?') ? 10 :(a[i]-'0'+1);
		bb_fr = (i != 0 && (i+1) == B)? 1 : 0;
		bb_fr = (b[i] == '?') ? bb_fr :(b[i]-'0');
		bb_to = (b[i] == '?') ? 10 :(b[i]-'0'+1);
		cc_fr = (i != 0 && (i+1) == C)? 1 : 0;
		cc_fr = (c[i] == '?') ? cc_fr :(c[i]-'0');
		cc_to = (c[i] == '?') ? 10 :(c[i]-'0'+1);

		for(aa = aa_fr; aa < aa_to; aa++){
			for(bb = bb_fr; bb < bb_to; bb++){
				for(cc = cc_fr; cc < cc_to; cc++){
					if(op == '+'){
						if(d[i][0] == 1){
							if(aa + bb == cc) d[i+1][0] = 1;
							if(aa + bb - 10 == cc) d[i+1][1] = 1;
						}
						if(d[i][1] == 1){
							if(aa + bb + 1 == cc) d[i+1][0] = 1;
							if(aa + bb - 9 == cc) d[i+1][1] = 1;
						}
					}
					else {
						if(d[i][0] == 1){
							if(aa - bb == cc) d[i+1][0] = 1;
							if(aa - bb + 10 == cc) d[i+1][1] = 1;
						}
						if(d[i][1] == 1){
							if(aa - bb - 1 == cc) d[i+1][0] = 1;
							if(aa - bb + 9 == cc) d[i+1][1] = 1;
						}
					}
				}
			}
		}
	}
	if(d[N][0] == 1) return true;
	return false;
}
int main()
{
	freopen("input4.txt", "r", stdin);
	freopen("output4.txt", "w", stdout);
	int t, i, j, k;
	scanf("%d\n", &T);
	for(t = 1; t <= T; t++)
	{
		gets(s);
		L = strlen(s);
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		memset(c, 0, sizeof(c));
		op = '-';
		for(i = 0; i < L; i++) if(s[i] == '+') op = '+';
		for(i = 0; i < L; i++)
		{
			if(s[i] == ' '){
				s[i] = 0;
				strcpy(a, s);
				s[i] = ' ';
				break;
			}
		}
		for(j = i + 3; j < L; j++)
		{
			if(s[j] == ' '){
				s[j] = 0;
				strcpy(b, s+i+3);
				strcpy(c, s+j+3);
				s[j] = ' ';
				break;
			}
		}
		strrev(a); strrev(b); strrev(c);
		A = strlen(a); B = strlen(b); C = strlen(c);
		N = A > B? A : B; N = N > C? N : C;
		a[N] = b[N] = c[N] = 0;
		for(i = A; i < N; i++) a[i] = '0';
		for(i = B; i < N; i++) b[i] = '0';
		for(i = C; i < N; i++) c[i] = '0';

		for(i = A-1; i >= 0; i--){
			if(a[i] != '?') continue;
			k = (i != 0 && (i+1 == A))? 1 : 0;
			for(; k < 10; k++){
				a[i] = k + '0';
				if(exists()) break;
			}
			if(k == 10) printf("ERROR");
		}
		for(i = B-1; i >= 0; i--){
			if(b[i] != '?') continue;
			k = (i != 0 && (i+1 == B))? 1 : 0;
			for(; k < 10; k++){
				b[i] = k + '0';
				if(exists()) break;
			}
			if(k == 10) printf("ERROR");
		}
		for(i = C-1; i >= 0; i--){
			if(c[i] != '?') continue;
			k = (i != 0 && (i+1 == C))? 1 : 0;
			for(; k < 10; k++){
				c[i] = k + '0';
				if(exists()) break;
			}
			if(k == 10) printf("ERROR");
		}

		a[A] = b[B] = c[C] = 0;
		strrev(a); strrev(b); strrev(c);
		printf("Case #%d: %s %c %s = %s\n", t, a, op, b, c);
	}
	return 0;
}