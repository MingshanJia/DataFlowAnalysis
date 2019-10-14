#include <cstdio>
#include <cstring>
#include <algorithm>
#define FOR(i,s,e) for (int i=(s); i<(e); i++)
#define FOE(i,s,e) for (int i=(s); i<=(e); i++)
#define FOD(i,s,e) for (int i=(s)-1; i>=(e); i--)
#define CLR(a,x) memset(a, x, sizeof(a))
#define EXP(i,l) for (int i=(l); i; i=qn[i])
#define LLD long long
using namespace std;

char dig[10][10] = {
	"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"
};

char occ[11][10] = {
	"", "", "double", "triple", "quadruple", "quintuple",
	"sextuple", "septuple", "octuple", "nonuple", "decuple"
};

char s[1000], p[1000];
int a[105];

void solve(int tc){
	printf("Case #%d:", tc);
	scanf("%s%s", s, p);
	int n, m, x;
	n = strlen(s);
	m = 0;
	x = 0;
	for (int i=0; p[i]; ++i){
		if (p[i] == '-') a[m++] = x, x = 0;
		else x = x * 10 + (p[i] - '0');
	}
	a[m++] = x;
	x = 0;
	FOR(i,0,m){
		int cur = 0;
		int cnt = 0;
		FOE(j,0,a[i]){
			if (j == a[i] || (j && s[x] != s[x-1])){
				if (cnt == 1) printf(" %s", dig[cur]);
				else if (cnt > 10) FOR(k,0,cnt) printf(" %s", dig[cur]);
				else printf(" %s %s", occ[cnt], dig[cur]);
				cnt = 1;
				cur = s[x] - '0';
			}
			else ++cnt, cur = s[x] - '0';
			if (j != a[i]) ++x;
		}
	}
	puts("");
}

int main(){
	int tc;
	scanf("%d", &tc);
	FOE(i,1,tc) solve(i);
	return 0;
}
