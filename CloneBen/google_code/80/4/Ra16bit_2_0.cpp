#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int t,tt,n,m,i,j,it,p,e,d,a[9],b[9],z[9],r[9],f[9][9],cur[9],ans[9],res;
vector <int> c[9];
void rec(int l, int e) {
  int i,j;
  if (l==n) {
    for (i=1; i<=d; i++) {
      for (j=0; j<=e; j++) if (f[i][j]==0) break;
      if (j<=e) break;
    }
    if (i>d && e+1>res) {
      res=e+1;
      for (i=0; i<n; i++) ans[i]=cur[i]+1;
    }
    return;
  }
  for (i=0; i<=e+1; i++) {
    cur[l]=i;
    for (j=0; j<c[l].size(); j++) f[c[l][j]][i]++;
    rec(l+1,max(e,i));
    for (j=0; j<c[l].size(); j++) f[c[l][j]][i]--;
  }
}
int main() {
  freopen("Cs.in","r",stdin);
  freopen("Cs.out","w",stdout);
  scanf("%d",&tt);
  for (t=1; t<=tt; t++) {
    scanf("%d%d",&n,&m); res=0;
    for (i=0; i<n; i++) c[i].clear();
    for (i=0; i<m; i++) { scanf("%d",&a[i]); a[i]--; }
    for (i=0; i<m; i++) { scanf("%d",&b[i]); b[i]--; }
    for (d=i=0; i<(1<<n); i++) {
      ++it; p=e=0;
      for (j=0; j<n; j++) if (i&(1<<j)) { p++; z[j]=it; r[j]=0; }
      if (p<3) continue;
      for (j=0; j<n-1; j++) if (z[j]==it && z[j+1]==it) { e++; r[j]++; r[j+1]++; }
      if (z[0]==it && z[n-1]==it) { r[0]++; r[n-1]++; e++; }
      for (j=0; j<m; j++) if (z[a[j]]==it && z[b[j]]==it) { r[a[j]]++; r[b[j]]++; e++; }
      if (e!=p) continue;
      for (j=0; j<n; j++) if (z[j]==it && r[j]!=2) break;
      if (j<n) continue; else ++d;
      for (j=0; j<n; j++) if (z[j]==it) c[j].push_back(d);
    }
    rec(0,-1);
    printf("Case #%d: %d\n",t,res);
    for (i=0; i<n; i++) {
      if (i) putchar(' ');
      printf("%d",ans[i]);
    }
    puts("");
  }
  return 0;
}
