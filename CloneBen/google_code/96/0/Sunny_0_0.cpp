#pragma warning(disable:4786)
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<functional>
#include<string>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<utility>
#include<fstream>
#include<sstream>
#include<cmath>
#include<stack>
#include<cstdio>
#include <iomanip>


using namespace std;

#define MEM(a,b) memset(a,(b),sizeof(a))
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b)  ((a) < (b) ? (a) : (b))
#define istr(S) istringstream sin(S)
#define MP make_pair
#define pb push_back
#define inf 1000000000

typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;
typedef vector<pi> vpi;

#define inf 1000000000
//typedef long long LL;
//typedef __int64 LL;

char word[5005][20],pat[100005];
int flag[20][30];

int main()
{
	int i,j,k,tests,cs=0;
	int L,D,N;
	
	freopen("C:\\A-small-attempt0.in","r",stdin);
	freopen("C:\\Asmall.out","w",stdout);

	scanf("%d%d%d",&L,&D,&N);
	for(i=0;i<D;i++)
		scanf("%s",word[i]);

	while(N--)
	{
		scanf("%s",pat);

		MEM(flag,0);
		int pos=0;

		for(i=0;pat[i];)
		{
			if(pat[i]!='(')
			{
				flag[pos++][pat[i]-'a']=1;
				i++;
				continue;
			}

			for(j=i+1;pat[j]!=')';j++)
				flag[pos][pat[j]-'a']=1;
	
			pos++;
			i=j+1;
		}
		
		int ans=0;
		for(i=0;i<D;i++)
		{
			int ok=1;
			for(j=0;j<L;j++)
				if(flag[j][word[i][j]-'a']==0)
					ok=0;
			ans+=ok;
		}
		printf("Case #%d: %d\n",++cs,ans);
	}

	return 0;
} 


