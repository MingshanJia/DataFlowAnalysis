#include <bits/stdc++.h>
using namespace std;
const double pi=acos(-1.0);
int t,tt,n,m,i,j,r[1010],h[1010];
vector<double> a;
double c,res;
int main() {
  scanf("%d",&tt);
  for (t=1; t<=tt; t++) {
    scanf("%d%d",&n,&m);
    a.reserve(n); res=0;
    for (i=0; i<n; i++) scanf("%d%d",&r[i],&h[i]);
    for (i=0; i<n; i++) {
      a.clear();
      for (j=0; j<n; j++) if (i!=j && r[j]<=r[i]) a.push_back(h[j]*2.*pi*r[j]);
      if (a.size()>=m-1) {
        sort(a.rbegin(),a.rend());
        c=pi*r[i]*r[i]+2.*pi*h[i]*r[i];
        for (j=0; j<m-1; j++) c+=a[j];
        res=max(res,c);
      }
    }
    printf("Case #%d: %.10lf\n",t,res);
  }
  return 0;
}

