//#define __USE_MINGW_ANSI_STDIO 0
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define debug(x) cout<<#x<<" :: "<<x<<endl;
#define debug2(x,y) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<endl;
#define debug3(x,y,z) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\t"<<#z<<" :: "<<z<<endl;

#define boost ios::sync_with_stdio(0); cin.tie(0)

#define fi first
#define se second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)

typedef long long ll;
typedef double ld;
typedef pair<int, int> pii;

const int N = 2e5 + 5;

/***************************************************************************/

ll F[N];

ll do_for(int a, int b, int c) {
	for(int i=0; i<2; i++) {
		if(a > b) swap(a, b);
		if(b > c) swap(b, c);
	}
	if(a == b and b == c) {
		return (F[a] * (F[a] - 1) * (F[a] - 2)) / 6;
	}
	else if(a == b) {
		return (F[a] * (F[a] - 1) * F[c]) / 2;
	}
	else if(b == c) {
		return (F[a] * F[b] * (F[b] - 1)) / 2;
	}
	else {
		return F[a] * F[b] * F[c];
	}
}

int main() {

	boost;
	int T; cin>>T;
	for(int test = 1; test <= T; test++) {
		int n; cin>>n;
		memset(F, 0, sizeof F);

		for(int i=1; i<=n; i++) {
			int a; cin>>a;
			F[a]++;
		}

		ll ans = 0;

		for(ll i=0; i<=200000; i++) {
			for(ll j=i; j<=200000 and i*j<=200000; j++) {
				ans += do_for(i, j, i*j);
			}
		}

		cout<<"Case #"<<test<<": ";
		cout<<ans<<"\n";
	}
	
	return 0;
}