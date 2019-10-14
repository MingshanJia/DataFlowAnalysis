#include "bits/stdc++.h"

#ifdef PRINTERS
#include "printers.hpp"
using namespace printers;
#define tr(a)		cerr<<#a<<" : "<<a<<endl
#else
#define tr(a)    
#endif
#define int 		long long
#define ll          long long
#define pb          push_back
#define mp          make_pair
#define pii         pair<int,int>
#define vi          vector<int>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (int)x.size()
#define hell        1000000007
#define endl        '\n'
#define rep(i,a,b)	for(int i=a;i<b;i++)
using namespace std;
int test=1;
void solve(){
	cout<<"Case #"<<test++<<": ";
	int N;
	cin>>N;
	int current_left=0;
	int current_max=0;
	rep(i,0,N){
		int a,b;
		cin>>a>>b;
		current_max=max(current_max,b);
		current_left=max(0LL,current_left-a*b);
		current_left+=a;
	}
	cout<<max(current_max+1,current_left)<<endl;
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t=1;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}