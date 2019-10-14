#define _CRT_SECURE_NO_DEPRECATE
#pragma comment(linker, "/STACK:64000000")

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <cctype>
#include <cassert>

using namespace std;

typedef double D;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<ll> vll;
typedef vector<D> vd;

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define mp make_pair
#define pb push_back

template<typename T> T abs(T x) { return (x>0) ? x : -x; }
template<typename T> T sqr(T x) { return x*x;            }

map<string,int> col;
int ccol;

int getCol(string s) {
	if (col.count(s))
		return col[s];
	col[s]=ccol++;
	return col[s];
}

int n;
int l[10],r[10],c[10];
bool filled[10*1000+2];

int bitCnt(int s) {
	int res=0;
	while (s) {
		res++;
		s&=s-1;
	}
	return res;
}

int main() {
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);

	int tn;
	cin>>tn; 
	for (int tst=0; tst<tn; tst++) {
		cerr<<tst<<endl;
		printf("Case #%d: ",tst+1);
		cin>>n;
		for (int i=0; i<n; i++) {
			string s;
			cin>>s;
			c[i]=getCol(s);
			cin>>l[i]>>r[i];
		}
		int res=1<<30;
		for (int s=0; s<(1<<n); s++) {
			set<int> cols;
			for (int i=0; i<10; i++)
				if (s&(1<<i))
					cols.insert(c[i]);
			if (sz(cols)>3) continue;
			memset(filled,false,sizeof(filled));
			bool ok=true;
			for (int i=0; i<n; i++)
				if (s&(1<<i)) {
					for (int j=l[i]; j<=r[i]; j++)
						filled[j]=true;
				}
			for (int i=1; i<=10*1000; i++)
				if (!filled[i]) {
					ok=false;
					continue;
				}
			if (ok)
				res=min(res,bitCnt(s));
		}
		if (res==(1<<30)) {
			cout<<"IMPOSSIBLE\n";
			continue;
		}
		cout<<res<<endl;
	}

	return 0;
}
