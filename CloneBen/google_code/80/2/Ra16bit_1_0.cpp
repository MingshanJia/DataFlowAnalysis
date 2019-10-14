#include <cmath>
#include <cstdio>
#include <utility>
#include <algorithm>
using namespace std;
int t,tt,i,j,n,d;
pair <int, int> a[222];
double z,r;
int main() {
  freopen("Bs.in","r",stdin);
  freopen("Bs.out","w",stdout);
  scanf("%d",&tt);
  for (t=1; t<=tt; t++) {
    scanf("%d%d",&n,&d);
    for (i=0; i<n; i++) scanf("%d%d",&a[i].first,&a[i].second);
    sort(a,a+n); r=0;
    for (i=0; i<n; i++) {
      z=a[i].second;
      r=max(r,0.5*(z-1)*d);
      for (j=i+1; j<n; j++) {
        z+=a[j].second;
        r=max(r,0.5*((z-1)*d-a[j].first+a[i].first));
      }
    }
    printf("Case #%d: %.12lf\n",t,r);
  }
  return 0;
}
