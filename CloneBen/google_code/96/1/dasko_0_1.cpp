#include <cstdio>
#include <cstring>
#include <algorithm>

#define REP(AA,BB) for(AA=0; AA<BB; ++AA)
#define FOR(AA,BB,CC) for(AA=BB; AA<CC; ++AA)
#define FC(AA,BB) for(typeof(AA.begin()) BB=AA.begin(); BB!=AA.end(); ++BB)

using namespace std;

int ok[20][30];
char c[5010][20], s[1010];

int main(void) {
	int L, m, n, len, t, i, j, k, res;
	scanf("%d%d%d", &L, &m, &n);
	REP(i,m) {
		scanf("%s", c[i]);
		REP(j,L)
			c[i][j]-='a';
	}
	REP(t,n) {
		scanf("%s", s); len=strlen(s);
		memset(ok, 0, sizeof ok);
		for(i=0, k=0; i<len; ++k) {
			if(s[i]=='(') {
				for(j=i+1; s[j]!=')'; ++j)
					ok[k][s[j]-'a']=1;
				i=j+1;
			}
			else {
				ok[k][s[i]-'a']=1;
				++i;
			}
		}
		res=0;
		REP(i,m) {
			REP(j,L) {
				if(!ok[j][c[i][j]])
					break;
			}
			if(j==L)
				++res;
		}
		printf("Case #%d: %d\n", t+1, res);
	}
	return 0;
}
				
			
			
