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

#define M 10000
#define inf 1000000000
//typedef long long LL;
//typedef __int64 LL;

string t="welcome to code jam";
char s[1005];
int n,memo[505][40];

int solve(int pos,int a)
{
	int ret=0;

	if(a==t.size()) return 1;
	if(pos==n) return 0;
	if(memo[pos][a]!=-1) return memo[pos][a];

//	printf("%d %d\n",pos,a);

	ret+=solve(pos+1,a);
	if(s[pos]==t[a])
		ret+=solve(pos+1,a+1);
	ret%=M;

	return memo[pos][a]=ret;
}

int main()
{
	int i,j,k,tests,cs=0;
	
	freopen("D:\\gcj\\C-small-attempt0.in","r",stdin);
	freopen("D:\\gcj\\C-small.out","w",stdout);

	scanf("%d\n",&tests);
	while(tests--)
	{
		gets(s);
		MEM(memo,-1);
		n=strlen(s);
		int ans=solve(0,0);

		printf("Case #%d: %.4d\n",++cs,ans);
	}

	return 0;
} 


