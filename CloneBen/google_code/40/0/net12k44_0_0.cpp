#include <bits/stdc++.h>
using namespace std;

const double pi = 3.14159265358979323846;

void solve(){
	vector< pair<long long, long long> > a;
	int n, k; scanf("%d%d",&n,&k);
	for(int i = 0; i < n; ++i){
		int r, h;
		scanf("%d%d",&r,&h);
		a.push_back(make_pair(r, h));
	}
	
	sort(a.begin(), a.end(), greater< pair<long long, long long> >());
	long long best = -1;	
	
	for(int i = 0; i < n; ++i){
		long long r0 = a[i].first;
		vector<long long> d;
		long long cur = 0;
		for(int j = i+1; j < n; ++j)
			d.push_back( a[j].first * a[j].second );
		sort(d.begin(), d.end(), greater<long long>());
		if (d.size() < k-1)
			break;
		
		for(int i = 0; i < k-1; ++i)
			cur = cur + d[i];
		
		cur = cur*2 + r0 * r0 + a[i].first * a[i].second * 2;
		if (cur > best) {			;
			//cout << best << " " << cur << endl;
			best = cur;	
		}			
	}
		
	//cout << best << endl;
	printf("%.8f\n", pi * best);
	
	
	
}

int main(){
	freopen("file.out","w",stdout);
	
	int test; scanf("%d",&test);	
	for(int t = 1; t <= test; ++t){
		printf("Case #%d: ", t);
		solve();
	}
	
}