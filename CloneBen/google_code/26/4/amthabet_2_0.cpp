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

#define SMALE

int R,C;
vector<pair<int,int> > o;

int check(int x1, int x2, int y1, int y2) {
	if(x1 > x2 || y1 > y2 || x1 <= 0 || x2 > R || y1 <= 0 || y2 > C) return 0;
	for(int i=0;i<o.size();i++)
		if(o[i].first >= x1 && o[i].first <= x2 && o[i].second >= y1 && o[i].second <= y2)
			return 0;
	return (x2-x1+1)*(y2-y1+1);
}

int main()	{

	freopen("c.in","r",stdin);
	
#ifdef SMALE	
	freopen("c_small_1.in","r",stdin);
	freopen("c_small_1.out","w",stdout);
#endif

#ifdef LARGE	
	freopen("c_large.in","r",stdin);
	freopen("c_large.out","w",stdout);
#endif
	
	int tc;
	cin>>tc;
	for(int tt=1; tt<=tc; tt++)	{
		char ch;
		cin>>C>>R;

		o.clear();

		for(int i=0;i<R;i++)
			for(int j=0;j<C;j++) {
				cin>>ch;
				if(ch == 'W' || ch == 'R' || ch == 'T')
					o.push_back(make_pair(i+1,j+1));
			}
		o.push_back(make_pair(0,0));
		o.push_back(make_pair(R+1,C+1));
		int best = 0;
		for(int i0=0;i0<o.size();i0++)
			for(int i1=0;i1<o.size();i1++)
				for(int i2=0;i2<o.size();i2++)
					for(int i3=0;i3<o.size();i3++)
						best = max(best, check(o[i0].first+1, o[i1].first-1, o[i2].second+1, o[i3].second-1));
		cout<<"Case #"<<tt<<": "<<best<<endl;
	}
	

	return 0;
}
