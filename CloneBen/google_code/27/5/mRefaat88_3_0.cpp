/*
ID: mythic_1
PROG: d
LANG: C++
*/

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <complex>
#include <cctype>
#include <algorithm>
#include <functional>
#include <cmath>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <stack>
#include <queue>
#include <map>
#include <valarray>
#include <set>
#ifdef _MSC_VER
#include <hash_set>
#include <hash_map>
using namespace stdext;
#else
#if __GNUC__ > 2
#include <ext/hash_set>
#include <ext/hash_map>
using namespace __gnu_cxx;
#else
#include <hash_set>
#include <hash_map>
#endif
#endif

template<class key>
struct hashtemp
{

	enum
	{
		bucket_size = 4, min_buckets = 8
	};
	virtual size_t operator()(const key &p) const=0;

};
using namespace std;

#define fo(i,n) for(i=0;i<(n);++i)

typedef vector<int> vi ;
typedef vector<string> vs ;
typedef vector<double> vd ;
#define sz(x) ((int)(x).size())
#define all(x) x.begin(),x.end()
#define pb(x) push_back(x)
typedef long long ll;
vector<string> res;
vector<pair<pair<int,char>,pair<int,int> > > qs;
bool check(string& s, int i,char ss,int a,int b)
{
	switch(ss)
	{
	case 'D':
		if(s[i]=='T'&&s[a]==s[b])return false;
		if(s[i]=='L'&&s[a]!=s[b])return false;
		break;
	case 'S':
		if(s[i]=='T'&&s[a]!=s[b])return false;
		if(s[i]=='L'&&s[a]==s[b])return false;
		break;
	case 'L':
		if(s[i]=='T'&&s[a]=='T')return false;
		if(s[i]=='L'&&s[a]=='L')return false;
		break;
	case 'T':
		if(s[i]=='T'&&s[a]=='L')return false;
		if(s[i]=='L'&&s[a]=='T')return false;
	}
	return true;
}
bool checkall(string s)
{
	for(int i = 0 ; i < sz(qs) ; i++)
		if(check(s,qs[i].first.first,qs[i].first.second,qs[i].second.first,qs[i].second.second)==false)return false;
	return true;
}

int n,q;
void get(string cur)
{
	if(sz(cur)==n)
	{	if(checkall(cur))
			res.push_back(cur);
		return;
	}get(cur+"T");
	get(cur+"L");
}

int main()
{
	freopen("D-small-attempt0.in","rt",stdin);
	freopen("d.out","wt",stdout);
	int tt= 0 ;
	int ttt = 0;
	scanf("%d",&tt);


	while(tt--)
	{

		scanf("%d%d",&n,&q);
		int t,a,b;
		char c;
		qs.clear();
		res.clear();
		for(int i = 0 ; i < q ; i++)
		{
			scanf("%d %c%d",&t,&c,&a);
			if(c=='S'||c=='D')scanf("%d",&b);
			qs.push_back(make_pair(make_pair(t-1,c),make_pair(a-1,b-1)) );
		}
		get("");
		string ress="";
		char rr ;

		for(int i = 0 ; i < n ; i++)
		{
			rr = res[0][i];
			for(int j = 0 ; j < sz(res) ; j++)
			{
				if(rr!=res[j][i])
				{
					rr = '-';
					break;
				}
			}
			ress+=" ";
			ress+=rr;
		}
		printf("Case #%d:%s\n",++ttt,ress.c_str());
	}


	return 0;
}
