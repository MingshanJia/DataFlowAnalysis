#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<stdio.h>
using namespace std;

#define LARGE

int main()	{

	freopen("a.in","r",stdin);
	
#ifdef SMALE	
	freopen("a_small.in","r",stdin);
	freopen("a_small.out","w",stdout);
#endif

#ifdef LARGE	
	freopen("a_large.in","r",stdin);
	freopen("a_large.out","w",stdout);
#endif
	
	int tc;
	cin>>tc;
	for(int tt=1; tt<=tc; tt++)	{
		vector<int> r,b;
		int s,l;
		char c;
		cin>>s;
		for(int i=0;i<s;i++) {
			cin>>l>>c;
			if(c=='R') r.push_back(l);
			else b.push_back(l);
		}
		sort(r.rbegin(), r.rend());
		sort(b.rbegin(), b.rend());
		int ans = 0, size = min(r.size(), b.size());
		for(int i=0;i<size;i++)
			ans += r[i] + b[i];
		cout<<"Case #"<<tt<<": "<<ans-size*2<<endl;
	}
	

	return 0;
}
