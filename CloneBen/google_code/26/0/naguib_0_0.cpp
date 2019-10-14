#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <cctype>
#include <algorithm>
#include <vector>
#include <numeric>
#include <set>
#include <queue>
#include <map>
#include <list>
#include <string>
#include <iostream>
#include <stack>
#include <sstream>
using namespace std; 
#define PB push_back
#define MP make_pair
#define F first
#define S second 
#define BE(a) a.begin(),a.end() 
#define CLS(a,b) memset(a,b,sizeof(a))
#define SZ(a) ((int)a.size())
const long double pi=acos(-1.0);
#define torad(a) ((a)*pi/180.0)
typedef vector<int> vi ; 
typedef vector<string> vs ; 
typedef vector<double> vd ; 
typedef pair<int,int> pii ; 
typedef long long ll ; 
typedef long double ld ; 
typedef double dl ; 
class node {public:
};
typedef vector<node> vn ; 
int cases,g,n;
vi red;
vi blue;
int main()
{
	freopen("A-small-attempt0.in","r",stdin);
	freopen("A-small-attempt0.out","w",stdout);
////////////////////////////////////////////
	int i,j,k;
	scanf("%d",&cases);
	for(g=0;g<cases;g++)
	{
		red.clear();
		blue.clear();
		printf("Case #%d: ",g+1);
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			int l;
			char c;
			scanf("%d%c",&l,&c);
			if(c=='R')
				red.push_back(l);
			else
				blue.push_back(l);
		}
		int ns=min(red.size(),blue.size());
		sort(BE(red),greater<int>());
		sort(BE(blue),greater<int>());
		int ans=0;
		for(i=0;i<ns;i++)
		{
			ans+=red[i];
			ans+=blue[i];
		}
		ans-=ns*2;
		printf("%d\n",ans);
	}

	return 0;
}