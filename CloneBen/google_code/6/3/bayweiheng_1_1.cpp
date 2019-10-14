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

vi conv(string &s) {
	vi ans;
	for(char c:s) ans.pb(c-'0');
		return ans;
}

int main() {
	int tc,n;
	string s;
	scanf("%d",&tc);
	for(int casenum=1;casenum<=tc;++casenum) {
		scanf("%d",&n);
		cin >> s;
		vi v = conv(s);
		int k = (n+1)/2;
		int score = 0;
		for(int i=0;i<k;++i) score+=v[i];
		int best = score;
		for(int i=k;i<n;++i) {
			score -= v[i-k];
			score += v[i];
			best = max(best, score);
		}
		printf("Case #%d: %d\n",casenum,best);
	}
}

