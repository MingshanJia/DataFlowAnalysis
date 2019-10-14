#include "bits/stdc++.h"

#ifdef PRINTERS
#include "printers.hpp"
using namespace printers;
#define tr(a)		cerr<<#a<<" : "<<a<<endl
#else
#define tr(a)    
#endif

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
	priority_queue<int,vi,greater<int>>pq1,pq2;
	rep(i,0,N){
		pq1.push(min(i,N-1-i));
	}
	rep(i,0,N){
		int temp;
		cin>>temp;
		pq2.push(temp);
	}
	int ans=0;
	while(!pq1.empty()){
		ans+=(pq1.top()-pq2.top())*(pq1.top()-pq2.top());
		pq1.pop();
		pq2.pop();
	}
	cout<<ans<<endl;
}

int main(){
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