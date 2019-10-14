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

vector<PII> kireme(int k, vector<PII>data){
	
	int nokori = k;
	int key = 0;
	while(1){
		if(nokori>data[key].second)nokori -= data[key].second;
		else {
			if(nokori<data[key].second){
				data.push_back(MP(0,0));
				for(int a=data.size()-1;key<a ;a--){
					
					data[a] = data[a-1];
					
				}
				int m = data[key].second;
				data[key].second = nokori;
				data[key+1].first = data[key].first + nokori;
				data[key+1].second = m - data[key].second ; 
				
				
				
			}
			
			break;
			
		}
		key++;
	}
	return data;
	
}



vector<PII> calc(int start,int goal, vector<PII>data){
	
	
	data = kireme(start,data);
	data = kireme(goal,data);
	
	vector<PII>ans;
	vector<PII>yobi;
	int nokori = start;
	int hoge = goal;
	int key = 0;
	bool ok = false;
	bool owari = false;
	for(;key<data.size();key++){
	
		nokori -= data[key].second;
		hoge -= data[key].second;
		
	//	if(data[key].second==0)cout<<"dame"<<endl;
		
		if(ok)ans.push_back(data[key]);
		else yobi.push_back(data[key]);
		
		if(nokori==0)ok = true;
		if(hoge==0){
			if(!owari)for(int a=0; a<yobi.size(); a++)ans.push_back(data[a]);
			owari  = true;
		}
	}
	
	return ans;
	
}


int main(){
	
	int T;
	cin>>T;
	for(int z=1; z<=T; z++){
		
		int ans = 0;
		
		int M,C,W;
		cin>>M>>C>>W;
		
		vector<PII>data;
		data.push_back(MP(1,M));
		
		for(int a=0; a<C; a++){
			int A,B;
			cin>>A>>B;
			
			data =calc(A-1,A+B-1,data);
			
			
		}
		
		int nokori = W;
		int key = 0;
		while(1){
			if(nokori>data[key].second)nokori -= data[key].second;
			else {
				ans = data[key].first +nokori-1;
				
				break;
			}
			
			
			key++;
		}
		
		cout<<"Case #"<<z<<": "<<ans<<endl;
		
	}

}

