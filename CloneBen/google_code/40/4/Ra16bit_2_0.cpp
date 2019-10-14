#include <bits/stdc++.h>
using namespace std;
int t,tt,n,m,i,j;
double s,r,p[55],x,y,eps=1e-9;
int main() {
  scanf("%d",&tt);
  for (t=1; t<=tt; t++) {
    scanf("%d%d",&n,&m);
    scanf("%lf",&s);
    for (i=0; i<n; i++) scanf("%lf",&p[i]);
    sort(p,p+n);
    reverse(p,p+n);
    for (i=m-1; i>=0 && s>eps; i--) {
      x=min((m-i)*((i==0?1:p[i-1])-p[i]),s);
      s-=x;
      y=x/(m-i);
      for (j=i; j<m; j++) p[j]+=y;
    }
    for (i=m; i<n && s>eps; i++) {
      x=min(1-p[i],s);
      s-=x;
      p[i]+=x;
    }
    for (r=1, i=0; i<m; i++) r*=p[i];
    printf("Case #%d: %.8lf\n",t,r);
  }
  return 0;
}

