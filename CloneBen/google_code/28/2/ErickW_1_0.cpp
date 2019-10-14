#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <iostream>

using namespace std; typedef unsigned long ulong; typedef long long llong;
typedef unsigned long long ullong;
typedef pair<int,int> pt;

int n,k;
vector<pt> P;

bool can(int c, int*p)
{
  int used=1;
  int mx=P[p[0]].first,Mx=mx,my=P[p[0]].second,My=my;

  for(int i=1;i<n;i++)
  {
    int x=P[p[i]].first,y=P[p[i]].second;
    if (x-mx > c || Mx-x > c || y-my > c || My-y > c)
    { 
      used++;
      mx=Mx=x; my=My=y;
    }
    mx <?= x; Mx >?= x; my <?= y; My >?= y;
  }
  //printf("Used %d squares\n",used);
  return (used<=k);
}

bool cando(int c)
{
  int p[n]; for(int i=0;i<n;i++) p[i]=i;
  do
  {
    if (can(c,p)) return true;
  } while (next_permutation(p,p+n));

  return false;
}

int main()
{
int cases;

cin >> cases;

for(int loop=1;loop<=cases;loop++)
{
  int x,y;
  cin >> n >> k;
  P.clear();
  for(int i=0;i<n;i++) { cin>>x>>y; P.push_back(make_pair(x,y)); }

  int a=0,b=64000;

  while(a<b-1)
  { 
    int c=(a+b)/2;
    if (cando(c)) b=c; else a=c;
  }
  printf("Case #%d: %d\n",loop,b); fflush(stdout);
}

}
