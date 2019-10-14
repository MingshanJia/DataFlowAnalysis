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


int main()
{
	int tc;
	cin >> tc;
	for(int ic=0;ic<tc;ic++)
	{
		int n;
		int64 A,B,C,D,x0,y0,M;
		cin >> n >> A >> B >> C >> D >> x0 >> y0 >> M;
		vector<ii> v;
		int64 X=x0,Y=y0;
		v.push_back(ii((int)x0,(int)y0));
		for(int i=1;i<=n-1;i++)
		{
			  X=(A*X+B)%M;
			  Y=(C*Y+D)%M;
			  v.push_back(ii((int)X,(int)Y));
		}
		int res=0;
		for(int i=0;i<sz(v);i++)
			for(int j=i+1;j<sz(v);j++)
				for(int k=j+1;k<sz(v);k++){
					if(((int64)v[i].first+(int64)v[j].first+(int64)v[k].first)%3!=0) continue;
					if(((int64)v[i].second+(int64)v[j].second+(int64)v[k].second)%3!=0) continue;					
					res++;
				}
		printf("Case #%d: ",ic+1);
		printf("%d",res);
		printf("\n");
	}
	return 0;
}
