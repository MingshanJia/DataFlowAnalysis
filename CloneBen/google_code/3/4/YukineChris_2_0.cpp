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
int main() {
	int testdata;
	scanf("%d",&testdata);
	rep(_,1,testdata) {
		printf("Case #%d: ", _);
		int a;
		vector<int> vi;
		scanf("%d",&a); vi.push_back(a);
		scanf("%d",&a);
		scanf("%d",&a);
		scanf("%d",&a); vi.push_back(a);
		scanf("%d",&a);
		scanf("%d",&a);
		scanf("%d",&a); vi.push_back(a);
		scanf("%d",&a);
		scanf("%d",&a);

		sort(vi.begin(), vi.end());
		double gg = vi[2] - vi[0];
		
		printf("%.10f\n", gg / 6.0);
	}
}

