#include <algorithm>
#include <cmath>
#include <climits>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) FOR(i,0,n)
#define MP make_pair

typedef long long LL;
typedef pair<int,int> PII;

int main(){
	
	LL h = (1<<30);
//	cout<<k<<endl;
//	cout<<k*k<<endl;
//	cout<<k*k*4<<endl;
	h = h*h*4;
	int T;
	cin>>T;
	for(int z=1; z<=T; z++){
		int ans = 0;
		
		LL n;
		cin>>n;
		
		LL k =h;
		LL nokori = k-2-n;
		k/=4;
		while(k!=0){
			if(nokori>=k)nokori-=k,ans++;
			if(nokori>=k)nokori-=k,ans++;
			k/=2;
	//		cout<<nokori<<endl;
		}
		ans = 122-ans;
		
		cout<<"Case #"<<z<<": "<<ans<<endl;
	}
	
	
	
	
	
	
	
}


