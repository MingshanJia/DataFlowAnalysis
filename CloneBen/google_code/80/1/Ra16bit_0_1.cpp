#include <cstdio>
using namespace std;
int t,tt,i,j,n;
double a[111],b[111],x[111],y[111];
char s[111][111];
int main() {
  freopen("Al.in","r",stdin);
  freopen("Al.out","w",stdout);
  scanf("%d",&tt);
  for (t=1; t<=tt; t++) {
    scanf("%d",&n);
    for (i=0; i<n; i++) {
      scanf("%s",s[i]);
      for (a[i]=b[i]=j=0; j<n; j++) if (i!=j) {
        if (s[i][j]!='.') a[i]++;
        if (s[i][j]=='1') b[i]++;
      }
    }
    for (i=0; i<n; i++) for (x[i]=j=0; j<n; j++) if (i!=j && s[i][j]!='.') x[i]+=(b[j]-int(s[i][j]=='0'))/(a[j]-1);
    printf("Case #%d: \n",t);
    for (i=0; i<n; i++) {
      for (y[i]=j=0; j<n; j++) if (i!=j && s[i][j]!='.') y[i]+=x[j]/a[j];
      printf("%.12lf\n",(0.25*b[i]+0.5*x[i]+0.25*y[i])/a[i]);
    }
  }
  return 0;
}
