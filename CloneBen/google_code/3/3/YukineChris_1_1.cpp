#include<bits/stdc++.h>
using namespace std;
#define rep(i,s,t) for (int i=s;i<=t;i++)
#define pi acos(-1)
#define FOR(i,s,t) for (int i = s; i < t; i++)
typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> PII;
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
const int maxn = 6001;
int n, m;
PII b[maxn];
int A[maxn];
LL sum[maxn];
int main() {
	int testdata;
	scanf("%d",&testdata);
	rep(_,1,testdata) {
		printf("Case #%d: ", _);
		scanf("%d",&m);
		rep(i,1,m) scanf("%d",&A[i]);
		sort(A+1,A+1+m);
		n = 0;
		rep(i,1,m) {
			if (n == 0 || b[n].first != A[i]) {
				b[++n] = PII(A[i], 1);
			} else {
				b[n].second++;
			}
		}
		rep(i,1,n) sum[i] = sum[i-1] + b[i].second;
		LL ans = 0;

		rep(c,1,n) {
			if (b[c].second < 2) continue;
			int r = 1;
			rep(a,1,n) {
				while (r <= n && r <= a) r++;
				while (r <= n && 1ll * b[r].first < 2ll * b[c].first + b[a].first) 
					++r;					
				int L = a + 1;
				int R = r - 1;
				LL tot = sum[R] - sum[L - 1];	

				if (c != a && !(L <= c && c <= R)) {
					ans += (b[c].second * (b[c].second-1) / 2) * 
						b[a].second * tot;
				}
				else if (c == a) {
					if (b[c].second < 3) continue;
					ans += (1ll * (b[c].second) * (b[c].second-1) * (b[c].second - 2) / 6) *
						tot;					
				} else {
					tot -= b[c].second;
					ans += (b[c].second * (b[c].second-1) / 2) *
						b[a].second * tot;

					if (b[c].second < 3) continue;
					ans += (1ll * (b[c].second) * (b[c].second-1) * (b[c].second - 2) / 6) *
						b[a].second;
				}
			}
		}
		cout << ans << endl;
	}
}


