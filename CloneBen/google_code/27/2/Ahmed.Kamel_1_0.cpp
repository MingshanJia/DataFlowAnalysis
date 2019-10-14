#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <time.h>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <list>
#include <stack>
using namespace std;

typedef vector<vector<int> > vii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef long long LL;

#define sz size()
#define all(n) n.begin(),n.end()
#define clr(a,n) memset(a,n,sizeof(a))
#define pb push_back
#define FOR(n,a,b) for(n=a;n<b;n++)
#define RFOR(n,b,a) for(n=b;n>=a;n--)
#define fo(i,j) for(int i=0;i<j;i++)

vii arr;
int X[10000],ret[10000];

int main()
{
    FILE *in=fopen("B.in","r");
    FILE *out=fopen("B.out","w");
    int i,j,k=1,t;
	fscanf(in,"%d",&t);
    while(t--)
    {
        arr.clear();
        clr(X,0);
        clr(ret,0);
        int N,T,E;
		fscanf(in,"%d %d %d",&N,&T,&E);
		fo(i,N+1)arr.pb(vi());
		fo(i,E)
		{
		    int H,P;
		    fscanf(in,"%d %d",&H,&P);
		    if(P)arr[H].pb(P);
		    if(H!=T)X[H]++;
		}
		fo(i,N)
		{
		    sort(all(arr[i+1]));
		}
		fo(i,N)
		{
		    j=arr[i+1].sz-1;
		    int sum=0;
		    while(sum<X[i+1])
		    {
		        if(j<0)
		        {
		            fprintf(out,"Case #%d: IMPOSSIBLE\n",k);
		            goto end;
		        }
		        sum+=arr[i+1][j];
		        ret[i+1]++;
		        j--;
		    }
		}
		fprintf(out,"Case #%d:",k);
		fo(i,N)
		fprintf(out," %d",ret[i+1]);
		fprintf(out,"\n");
		end:
		k++;
	}
    //getchar();getchar();
    return 0;
}






















