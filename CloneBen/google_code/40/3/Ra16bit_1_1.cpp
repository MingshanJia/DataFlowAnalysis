#include <bits/stdc++.h>
using namespace std;
struct Seg {
  int l,r,w;
} a[222];
int t,tt,na,nb,i,cur,x,z,r,e[2];
vector<int> v[2];
bool cmp(const Seg& x, const Seg& y) {
  return x.l<y.l;
}
int main() {
  scanf("%d",&tt);
  for (t=1; t<=tt; t++) {
    scanf("%d%d",&na,&nb);
    for (i=0; i<na; i++) {
      scanf("%d%d",&a[i].l,&a[i].r);
      a[i].w=0;
    }
    for (i=0; i<nb; i++) {
      scanf("%d%d",&a[na+i].l,&a[na+i].r);
      a[na+i].w=1;
    }
    sort(a,a+na+nb,cmp);
    a[na+nb]=a[0];
    a[na+nb].l+=24*60;
    a[na+nb].r+=24*60;
    for (r=z=i=0; i<2; i++) {
      v[i].clear();
      e[i]=0;
    }
    for (i=1; i<=na+nb; i++) {
      e[a[i].w]+=a[i].r-a[i].l;
      cur=a[i].l-a[i-1].r;
      if (a[i].w==a[i-1].w) {
        e[a[i].w]+=cur;
        v[a[i].w].push_back(cur);
      } else {
        r++;
        e[0]+=cur;
        z+=cur;
      }
    }
    if (e[1]>e[0]) {
      sort(v[1].rbegin(),v[1].rend());
      for (i=0; i<v[1].size() && e[0]!=e[1]; i++) {
        x=min(v[1][i],(e[1]-e[0])/2);
        if (x>0) {
          r+=2;
          e[0]+=x;
          e[1]-=x;
        }
      }
    } else {
      x=min(z,(e[0]-e[1])/2);
      z-=x;
      e[0]-=x;
      e[1]+=x;
      sort(v[0].rbegin(),v[0].rend());
      for (i=0; i<v[0].size() && e[0]!=e[1]; i++) {
        x=min(v[0][i],(e[0]-e[1])/2);
        if (x>0) {
          r+=2;
          e[0]-=x;
          e[1]+=x;
        }
      }
    }
    printf("Case #%d: %d\n",t,r);
  }
  return 0;
}

