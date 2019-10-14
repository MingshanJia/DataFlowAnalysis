#include <vector>
#include <list>
#include <map>
#include <set>
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
#include <queue>
#include <fstream>
#include <cstring>

using namespace std;
typedef long long LL;

int dx[8]={-1,0,1,0,-1,1,-1,1};
int dy[8]={0,1,0,-1,1,1,-1,-1};

map<string, int> mp;
map<int, string> mp2;
int din[10010], dout[10010];
string fin[10010], fout[10010];

int main()
{
	freopen("sort_itinerary.in","r",stdin);
	freopen("sorty_itinerary.out","w",stdout);
	int tc, nt=1;
	cin>>tc;
	while (tc--)
	{
		mp.clear();
		mp2.clear();
		memset(din,0,sizeof(din));
		memset(dout,0,sizeof(dout));
		int n;
		cin>>n;
		int cur=0;
		for (int i=0;i<n;i++)
		{
			string s1, s2;
			cin>>s1>>s2;
			if (!mp.count(s1))
			{
				mp[s1]=cur;
				mp2[cur++]=s1;
			}
			if (!mp.count(s2))
			{
				mp[s2]=cur;
				mp2[cur++]=s2;
			}
			din[mp[s2]]++;
			dout[mp[s1]]++;
			fin[mp[s2]]=s1;
			fout[mp[s1]]=s2;
		}
		int st=0;
		for (st=0;st<cur;st++)
			if (din[st]==0) break;
		cout<<"Case #"<<nt++<<": ";
		for (int i=0;i<n;i++)
		{
			cout<<mp2[st]<<"-"<<fout[st]<<" ";
			st=mp[fout[st]];
		}
		cout<<endl;
	}
}
