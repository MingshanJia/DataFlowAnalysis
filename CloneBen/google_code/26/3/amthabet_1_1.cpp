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

	freopen("b.in","r",stdin);
	
#ifdef SMALE	
	freopen("b_small.in","r",stdin);
	freopen("b_small.out","w",stdout);
#endif

#ifdef LARGE	
	freopen("b_large.in","r",stdin);
	freopen("b_large.out","w",stdout);
#endif
	
	int tc;
	cin>>tc;
	for(int tt=1; tt<=tc; tt++)	{
		int m;
		vector<int> p(12);
		cin>>m;
		for(int i=0;i<12;i++) cin>>p[i];
		int bp = 0, bi, bj, n, cp;
		for(int i=0;i<11;i++) {
			n = m/p[i];
			for(int j=i+1; j<12; j++) {
				cp = n*(p[j]-p[i]);
				if(cp <= 0) continue;
				if(cp > bp || (cp == bp && p[i] < p[bi])) {
					bp = cp;
					bi = i;
					bj = j;
				}
			}
		}
		cout<<"Case #"<<tt<<": ";
		if(bp == 0) cout<<"IMPOSSIBLE"<<endl;
		else cout<<bi+1<<" "<<bj+1<<" "<<bp<<endl;
	}
	

	return 0;
}
