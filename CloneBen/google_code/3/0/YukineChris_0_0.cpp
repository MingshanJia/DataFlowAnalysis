#include<bits/stdc++.h>
using namespace std;
#define rep(i,s,t) for (int i=s;i<=t;i++)
#define pi acos(-1)
#define FOR(i,s,t) for (int i = s; i < t; i++)
typedef long long LL;
typedef long double LD;
typedef pair<int,int> PII;
typedef pair<double, double> PDD;
typedef pair<PII, PII> PPP;
typedef pair<PII, int> PPI;
typedef pair<LL, PII> PLP;
typedef pair<double, PII> PDP;
#define repp(i,s,t) for (int i=s;i>=t;i--)
template<class T> T sqr(T x) {return x*x;}
#define debug(x) cerr<<#x"="<<(x)<<endl;
#define pb(x) push_back(x);
#define ori(x) x-'a'
#define y0 AERGAEWFAWERAw
#define y1 ASDFAEWRWERWERW
#define x0 gggsdfsfsfdf
#define x1 SAFREWRREWR
int f[400][400][400];
char str[400];
int n;
inline void update(int &x, int y) {
	if (x == -1 || x > y) x = y;
}
inline bool is_match(int m, int l, int r) {
	if (m + (r - l + 1) > n) return false;	
	
	rep(i,l,r) if (str[i] != str[m + i - l + 1]) {
			
			
		return false;
	}
	return true;
}
int main() {
	int testdata;
	scanf("%d",&testdata);
	rep(_,1,testdata) {
		printf("Case #%d: ", _);
		memset(f,255,sizeof(f));
		

		scanf("%s", str+1);
		n = strlen(str+1);
		
		rep(i,1,n) f[i][0][0] = i;
		int tmp;
		rep(i,1,n) { 
			tmp = f[i][0][0];
			
			rep(l,1,i) 
				rep(r,l,i) if (f[i][l][r] > 0) 
					update(tmp, f[i][l][r]);
			
			assert(tmp > -1);
			if (i == n) break;

			rep(l,1,i) rep(r,l,i) {
				update(f[i][l][r], tmp + 1);
				update(f[i+1][l][r], f[i][l][r] + 1);
			}

				
			rep(l,1,i) {			
				rep(r,l,i) if (f[i][l][r] > 0) {
					if (is_match(i, l ,r))
						update(f[i + (r - l + 1)][l][r], f[i][l][r] + 1);					
				}
			}

		}
	
		printf("%d\n", tmp);
	}
}

