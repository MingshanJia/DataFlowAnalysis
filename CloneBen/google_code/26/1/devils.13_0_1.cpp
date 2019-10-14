#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
typedef unsigned long long ll;
using namespace std;

#define pb push_back
#define mp make_pair
#define sz size()
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<pii> > adjL;
int oo = (int) 1e9;


int main()
{
	freopen("in.txt","rt",stdin);
	freopen("out.txt","wt",stdout);
	int n;scanf("%d",&n);
	for (int ii = 0; ii < n; ++ii) {
		int d;scanf("%d",&d);
		vector<int >r,b;

		while(d--)
		{
			string str;
			cin>>str;
//			cout<<str<<endl;
			int cur = 0;
			for (int i = 0; i < str.size()-1; ++i) {
				cur*=10,cur+=(str[i]-'0');
//				cout<<str[i]<<endl;
			}
//			cout<<cur<<endl;
			if(str[str.size()-1] == 'B')
				b.pb(cur);
			else r.pb(cur);
		}
		sort(r.begin(),r.end());
		sort(b.begin(),b.end());
		int mn = min(r.size(),b.size());
		int res =0 ;
		for (int i = 0; i < mn; ++i) {
			res+=b[b.size()-1-i] + r[r.size()-1-i];
		}
/*		if(r.size()>b.size())
			res+=r[r.size()-1-mn];
		else if(r.size()<b.size())
			res+=b[b.size()-1-mn];*/
		res = max(0, res - 2*mn);
		printf("Case #%d: %d\n",ii+1,res);
	}
	return 0;
}
