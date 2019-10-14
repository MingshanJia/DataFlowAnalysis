#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <iostream>
#define MOD 9901

using namespace std; typedef unsigned long ulong; typedef long long llong;
typedef unsigned long long ullong;
typedef pair<int,int> edge;

int n,k;
int dead[10][10];

bool valid(int *p)
{
  if (p[0]>p[n-2]) return false;
  if (dead[0][p[0]] || dead[0][p[n-2]]) return false;
  for(int i=0;i<n-2;i++) if (dead[p[i]][p[i+1]]) return false;
  return true;
}

int main()
{
int cases;

cin >> cases;

for(int loop=1;loop<=cases;loop++)
{
  cin >> n >> k;
  memset(dead,0,sizeof(dead));

  for(int i=0;i<k;i++) { int x,y;cin>>x>>y; dead[x-1][y-1]=dead[y-1][x-1]=1; }
  int t=0;
  int p[n-1]; for(int i=1;i<n;i++) p[i-1]=i;

  do
  {
    //printf("0"); for(int i=0;i<n-1;i++) printf(" %d",p[i]); printf(" 0");
    if (valid(p)) { t++; }
    //puts("");
  } while (next_permutation(p,p+n-1));

  printf("Case #%d: %d\n",loop,t%MOD); fflush(stdout);
}

}
