#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <bitset>
#include <cctype>

#define mp make_pair
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define sz(v) ((int)(v.size()))

using namespace std;

typedef long long int64;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<string> vs;

template<class T> T abs(T x){return x>0 ? x:(-x);}
template<class T> T sqr(T x){return x*x;}

int n,k;
vector<ii> v;

vi mask;

int d[1<<15];

int calc(int m)
{
	if(!m) return 0;
	int& res=d[m];
	if(res!=-1) return res;
	res=1000000;
	for(int i=0;i<sz(mask);i++)
		if((m&(~mask[i]))!=m)
			res=min(res,1+calc(m&(~mask[i])));
	return res;
}

int get_mask(int x,int y,int d)
{
	int res=0;
	for(int i=0;i<sz(v);i++)
		if(x<=v[i].first && y<=v[i].second && x>=v[i].first-d && y>=v[i].second-d)
			res|=(1<<i);
	return res;
}

bool check(int x)
{
	mask.clear();
	for(int i=0;i<sz(v);i++)
		for(int j=0;j<sz(v);j++)
			mask.push_back(get_mask(v[i].first,v[j].second,x));
	sort(all(mask));
	mask.erase(unique(all(mask)),mask.end());
	memset(d,-1,sizeof(d));
	int tmp=calc((1<<n)-1);
	return tmp<=k;
}

int main()
{
	int tc;
	cin >> tc;
	for(int ic=0;ic<tc;ic++)
	{
		printf("Case #%d: ",ic+1);
		int res=200000;		
		cin >> n >> k;
		v.clear();
		vi q;
		for(int i=0;i<n;i++)
		{
			int x,y;
			cin >> x >> y;
			v.push_back(ii(x,y));
		}
		for(int i=0;i<n;i++)
			for(int j=i+1;j<n;j++)
				q.push_back(abs(v[i].first-v[j].first)),q.push_back(abs(v[i].second-v[j].second));
		sort(all(q));
		q.erase(unique(all(q)),q.end());
		for(int i=0;i<sz(q);i++)
		{
			if(check(q[i]))
			{
				res=q[i];
				break;
			}
		}
		cout << res;
		printf("\n");
	}
	return 0;
}
