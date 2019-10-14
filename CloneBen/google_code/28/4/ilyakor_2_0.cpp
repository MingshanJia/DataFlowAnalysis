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

const int mod=9901;
const int maxn=320;

int fact[maxn];
int n,k;
int e[100][2];

int calc(int mask)
{
	int deg[maxn];
	memset(deg,0,sizeof(deg));
	int d1=0;
	for(int i=0;i<k;i++)
		if((mask>>i)&1)
		{
			deg[e[i][0]]++,deg[e[i][1]]++;
			d1++;
		}
	int d2=0,d3=0,d4=0;
	for(int i=0;i<n;i++)
	{
		if(deg[i]>2) return 0;
		if(deg[i]==2)
			d2++;
		if(deg[i]==1)
			d3++;
		if(deg[i]==0)
			d4++;
	}
	int cnum=d1-d2+d4;
	int res=fact[cnum-1];
	for(int i=0;i<(d1-d2);i++)
		res=(res*2)%mod;
	/*int od=0;
	for(int i=0;i<k;i++)
		if((mask>>i)&1)
		{
			if(deg[e[i][0]]==1 && deg[e[i][1]]==1)
				od++;
		}*/
	return res;
}

int main()
{
	fact[0]=1;
	for(int i=1;i<maxn;i++)
	{
		fact[i]=(fact[i-1]*i)%mod;
		if(i==2)
			fact[i]/=2;
	}
	int tc;
	cin >> tc;
	for(int ic=0;ic<tc;ic++)
	{
		printf("Case #%d: ",ic+1);
		cin >> n >> k;
		for(int i=0;i<k;i++)
		{
			cin >> e[i][0] >> e[i][1];
			e[i][0]--,e[i][1]--;
		}
		int res=0;
		vi v;
		for(int i=0;i<n;i++)
			v.push_back(i);
		do{
			bool ok=true;
			for(int i=0;i<sz(v) && ok;i++)
				for(int j=0;j<k && ok;j++)
				{
					if(v[i]==e[j][0] && v[(i+1)%sz(v)]==e[j][1]) ok=false;
					if(v[i]==e[j][1] && v[(i+1)%sz(v)]==e[j][0]) ok=false;
				}
			if(ok)
				res++;
		} while (next_permutation(all(v)));
		res/=n;
		res/=2;
		res%=mod;
		/*for(int i=0;i<(1<<k);i++)
		{
			int x=i,y=0;
			while(x)
				y+=(x&1),x/=2;
			int tmp=calc(i);
			if(y%2) res-=tmp;
			else res+=tmp;
			res=(res%mod+mod)%mod;
		}*/
		cout << res;
		printf("\n");
	}
	return 0;
}
