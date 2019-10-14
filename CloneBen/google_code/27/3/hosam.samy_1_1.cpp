#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <math.h> 
#include <algorithm>
#include <vector> 
#include <string> 
#include<set>
#include<map>
#include<queue>
using namespace std; 

#define pb push_back
#define all(n) n.begin(),n.end() 

typedef vector<int> vi ; 
typedef vector<string> vs ; 
typedef vector<double> vd ; 
typedef vector<long long> vll ;

FILE * in = fopen("in.in","r");
FILE * out = fopen("out.out","w");

class node
{
	public :
	int ind , num , ind1;
};

vector<node> tt;
vector< vector<node> > t;
int n , l , s[1000] , m;


bool cmp(node a , node b)
{
	if(a.num != b.num) return a.num > b.num;
	return a.ind < b.ind;
}

int flag , vis[1000];

int main()
{
	int i , a , k , caseID = 0 , n , ind;
	fscanf(in,"%d",&k);
	while(k--)
	{
		fprintf(out,"Case #%d: ",++caseID);
		t.clear();
		memset(vis,0,sizeof vis);
		fscanf(in,"%d %d",&n,&l);
		memset(s,0,sizeof s);
		for(i=0;i<=n;i++) t.pb(tt);
		fscanf(in,"%d",&m);
		node cur;
		for(i=0;i<m;i++)
		{
			fscanf(in,"%d %d",&ind,&a);
			s[ind]++;
			if(!a) continue;
			cur.ind = ind;
			cur.num = a;
			cur.ind1 = i;
			t[ind].pb(cur);
		}
		for(i=0;i<=n;i++)
			sort(all(t[i]),cmp);
		flag = 1;
		for(i=0;i<=n;i++)
		{
			if(i == l) continue;
			if(!s[i]) continue;
			//printf("%d\n",s[i]);
			for(a=0;a<t[i].size();a++)
			{
				if(s[i] <= 0) break;
				s[i] -= t[i][a].num;
				vis[t[i][a].ind]++;
			}
			if(s[i] > 0){flag = 0; break;}
		}
		if(!flag){fprintf(out,"IMPOSSIBLE\n"); continue;}
		for(i=1;i<n;i++) fprintf(out,"%d ",vis[i]);
		fprintf(out,"%d\n",vis[n]);
	}
	return 0;
}