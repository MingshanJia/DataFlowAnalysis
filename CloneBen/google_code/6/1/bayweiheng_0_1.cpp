#include<bits/stdc++.h>

using namespace std;

typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<vvd> vvvd;
typedef vector<string> vs;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;
typedef vector<long long> vll;
typedef vector<vll> vvll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<bool> vb;
typedef vector<vb> vvb;

#define pb push_back
#define ctz __builtin_ctz
#define db(x) cerr << #x << "=" << x << endl
#define db2(x, y) cerr << #x << "=" << x << "," << #y << "=" << y << endl
#define db3(x, y, z) cerr << #x << "=" << x << "," << #y << "=" << y << "," << #z << "=" << z << endl

bool is_prefix(string &s, string &t) {
	if(s.size() >= t.size()) return false;
	int n = s.size();
	for(int i=0;i<n;++i) if(s[i]!=t[i]) return false;
	return true;
}


int main() {
	int tc,n,p;
	string s;
	scanf("%d",&tc);
	for(int casenum=1;casenum<=tc;++casenum) {
		vs v;
		scanf("%d %d\n",&n,&p);
		ll ans = (1LL) << n;
		for(int i=0;i<p;++i) {
			cin>>s;
			v.pb(s);
		}
		vi disabled(p,0);
		//db(111);
		for(int i=0;i<p;++i) {
			for(int j=i+1;j<p;++j) {
				if(is_prefix(v[i],v[j])) disabled[j]=1;
				else if(is_prefix(v[j],v[i])) disabled[i]=1;
			}
		}
		//db(222);
		for(int i=0;i<p;++i) {
			if(!disabled[i]) {
				int len=v[i].size();
				//db3(casenum,i,len);
				ans -= 1LL << (n-len);
			}
		}
		printf("Case #%d: %lld\n",casenum,ans);
	}
}

