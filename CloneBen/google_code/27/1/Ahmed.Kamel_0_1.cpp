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
#define all(n) n.begin(),n.end()a
#define clr(a,n) memset(a,n,sizeof(a))
#define pb push_back
#define FOR(n,a,b) for(n=a;n<b;n++)
#define RFOR(n,b,a) for(n=b;n>=a;n--)
#define fo(i,j) for(int i=0;i<j;i++)

map<int,int> m;
int arr[10000];
int main()
{
    FILE *in=fopen("A.in","r");
    FILE *out=fopen("A.out","w");
    int i,j,k=1,T;
	fscanf(in,"%d",&T);
    while(T--)
    {
        m.clear();
        int n;
		fscanf(in,"%d",&n);
		int x;
		fo(i,n)
		{
		    fscanf(in,"%d",&arr[i]);
            m[arr[i]]++;
		}
		fo(i,n)if(m[arr[i]]==1)
		{
		    fprintf(out,"Case #%d: %d\n",k,arr[i]);
		    break;
		}
		k++;
	}
    //getchar();getchar();
    return 0;
}






















