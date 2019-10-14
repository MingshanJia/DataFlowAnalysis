/*
ID: mythic_1
PROG: b
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
#define SMALL
//#define LARGE
int comps[1012];
vector<vector<int> > adj;
void ff(int st,int c)
{

	for(int i = 0 ; i < sz(adj[st]) ; i++)
	{
		if(comps[adj[st][i]]==-1){
			comps[adj[st][i]]=c;
			ff(adj[st][i],c);
		}
	}

}

int main()
{
#ifdef SMALL
	freopen("b-small-attempt0.in","rt",stdin);
	freopen("b-small.out","wt",stdout);
#endif
#ifdef LARGE
	freopen("b-large.in","rt",stdin);
	freopen("b-large.out","wt",stdout);
#endif
	int tt,n,r,f,to;
	cin>>tt;
	int cit[1012];
	vector<pair<int,int> > edges;
	for(int t = 1 ; t <= tt ; t++)
	{
		cin>>n>>r;
		adj.clear();
		adj.resize(n);
		memset(cit,0,sizeof cit);
		for(int i  = 0 ; i < r; i ++)
		{
			cin>>f>>to;
			adj[f].push_back(to);
			adj[to].push_back(f);
			cit[f]++;
			cit[to]++;
		}
		int k = 0;
		for(int i = 0 ; i < n ; i++)
		{
			if(cit[i]%2)
				k++;
		}
		int ind = 0;
		memset(comps,-1,sizeof comps);
		for(int i = 0 ; i < n ; i++)
			if(comps[i]==-1){
				comps[i]=++ind;
				ff(i,ind);
			}
		vector<vector<int> > cmps;
		cmps.resize(ind);
		int dg[1010];
		memset(dg,0,sizeof dg);
		for(int i = 0 ; i < n ; i++)
		{
			cmps[comps[i]-1].push_back(i);
			if(cit[i]%2)
				dg[comps[i]-1]=1;
		}
		int ev = 0;
		for(int i = 0 ; i < ind ; i++)
		{
			if(sz(cmps[i])==1)continue;
			if(dg[i]==0)
				ev++;
		}


		cout<<"Case #"<<t<<": ";
		if(k==0&&ev==1)
			cout<<0;
		else
			cout<<k/2+ev;
		cout<<endl;
	}




	return 0;
}
