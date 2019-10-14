#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int t,tt,n,m,i,j,a[2222],b[2222],z[2222],ans[2222],res;
vector <int> g[2222];
void count(int l, int r) {
  int w=1,p,i;
  for (i=l; i!=r; w++) {
    p=g[i][z[i]++];
    if (p>i+1) count(i,p);
    i=p;
  }
  res=min(res,w);
}
void rec(int l, int r) {
  int p,i,t=0,j=0;
  for (i=l; i!=r; i=p) {
    p=g[i][z[i]++];
    if (p!=r) {
      while (t==0 && j<res && (ans[l]==j || ans[r]==j)) j++;
      if (j>=res) { t++; j=0; }
      ans[p]=j++;
      while ((g[p][z[p]]==r && ans[p]==ans[r]) || ans[p]==ans[i]) {
        while (t==0 && j<res && (ans[l]==j || ans[r]==j)) j++;
        if (j>=res) { t++; j=0; }
        ans[p]=j++;
      }
    }
    if (p>i+1) rec(i,p);
  }
}
int main() {
  freopen("Cl.in","r",stdin);
  freopen("Cl.out","w",stdout);
  scanf("%d",&tt);
  for (t=1; t<=tt; t++) {
    scanf("%d%d",&n,&m); res=n;
    for (i=0; i<n; i++) { g[i].clear();  }
    for (i=0; i<m; i++) { scanf("%d",&a[i]); a[i]--; }
    for (i=0; i<m; i++) { scanf("%d",&b[i]); b[i]--; }
    for (i=0; i<m; i++) {
      if (a[i]>b[i]) swap(a[i],b[i]);
      g[a[i]].push_back(b[i]);
    }
    for (i=0; i<n; i++) {
      sort(g[i].rbegin(),g[i].rend());
      if (i<n-1) g[i].push_back(i+1);
      z[i]=0;
    }
    count(0,n-1);
    printf("Case #%d: %d\n",t,res);
    for (i=0; i<n; i++) z[i]=0;
    ans[0]=0; ans[n-1]=1;
    rec(0,n-1);
    for (i=0; i<n; i++) {
      if (i) putchar(' ');
      printf("%d",ans[i]+1);
    }
    puts("");
  }
  return 0;
}
