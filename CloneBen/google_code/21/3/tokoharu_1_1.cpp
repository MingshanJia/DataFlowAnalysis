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
typedef pair<LL,LL> PII;

int main(){
	int T;
	cin>>T;
	
	for(int z=0; z<T; z++){
		
		LL N,K;
		cin>>N>>K;
		
		vector<pair<LL,PII> >data;
		
		for(int a=0; a<N; a++){
			LL c,t,s;
			cin>>c>>t>>s;
			pair<LL,PII> hoge= MP(t,MP(c,s));
			data.push_back(hoge);
		}
		
		sort(data.begin(),data.end(), greater<pair< LL,PII> >() );
		
		
		data.push_back(MP(0,MP(0,0)));
		
		int n = data.size();
		
		vector<PII>nokori;
		
		
		LL ans = 0;
		
		
//		for(int a=0; a<n-1; a++)cout<<data[a].first<<endl;
//		cout<<endl;
		for(int a=0; a<n-1; a++){
			
			nokori.push_back(MP( data[a].second.second , data[a].second.first ));
			
			sort(nokori.begin(),nokori.end(), greater<PII >());
			
			LL haba = data[a].first - data[a+1].first;
			
//			cout<<haba<<endl;
			
			for(int b=0; b<nokori.size(); b++){
				if(haba > nokori[b].second){
					haba -= nokori[b].second;
					ans += nokori[b].first * nokori[b].second;
					nokori[b].second = 0;
				}
				
				else {
					nokori[b].second -= haba;
					ans += nokori[b].first * haba;
					haba  = 0;
					
				}	
			}
			
			
			
		}
		cout<<"Case #"<<z+1<<": "<<ans<<endl;
		
	}
	return 0;
}



