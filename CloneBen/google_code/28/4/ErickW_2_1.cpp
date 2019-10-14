#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <iostream>
#define MOD 9901
#define two(x) (1<<(x))

using namespace std; typedef unsigned long ulong; typedef long long llong;
typedef unsigned long long ullong;
typedef pair<int,int> edge;

char bitcount(ulong l)
{register char i=0;while(l){l&=(l-1);i++;}return(i);}

int ham(int n,int b) { int t=1; for(int i=3;i<n;i++) t=(t*i)%MOD;
for(int i=0;i<b;i++) t=(2*t)%MOD; return t; }

int n,k;
vector<edge> E;
vector<int> comp(300);

int cont(int B)
{
  int neff=n;
  bool cyc=false;
  int comp=0;

  vector<bool> term(n,true);
  vector<int> op(n); for(int i=0;i<n;i++) op[i]=i;

  for(int i=0;i<k;i++) if (B&two(i))
  {
    int x=E[i].first,y=E[i].second;
    neff--;

    if (!term[x] || !term[y] || cyc) return 0;

    // New pair
    if (op[x]==x && op[y]==y) { op[x]=y; op[y]=x; comp++; }
    // X alone
    else if (op[x]==x) { int q=op[y]; term[y]=false; op[x]=q; op[q]=x; }
    // Y alone
    else if (op[y]==y) { int q=op[x]; term[x]=false; op[y]=q; op[q]=y; }
    else
    {
      term[x]=term[y]=false;
      // Cycle
      if (op[x]==y) { cyc=true; if (neff>0) return 0; }
      // Merge
      else { int q=op[x],r=op[y]; op[q]=r; op[r]=q; comp--; }
    }
  }

  if (cyc) return 1;
  if (neff<3) comp--;
  int t=ham(neff,comp);
  //printf("%d: %d %d --> %d\n",B,neff,comp,t);
  return t;
}

int main()
{
int cases;

cin >> cases;

for(int loop=1;loop<=cases;loop++)
{
  cin >> n >> k;

  E.clear();
  for(int i=0;i<k;i++) { int x,y;cin>>x>>y; E.push_back(make_pair(x-1,y-1)); }

  int t=0;

  for(int B=0;B<two(k);B++)
  {
    if (bitcount(B)%2) t = (t+MOD-cont(B))%MOD; else t = (t+cont(B))%MOD;
  }

  printf("Case #%d: %d\n",loop,t); fflush(stdout);
}

}
