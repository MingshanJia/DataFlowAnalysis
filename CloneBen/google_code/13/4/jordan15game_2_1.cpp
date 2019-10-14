#pragma comment(linker, "/STACK:65536000")
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<algorithm>
#include<string>
#include<sstream>
#include<set>
#include<map>
#include<vector>
#include<queue>
#include<iostream>
#include<time.h>
#include <list>
#include <numeric>
#include <complex>
#define forn(i,n) for(int i=0;i<n;i++)
#define clr(a,b) memset(a,b,sizeof(a))
#define ll long long
#define lowb(i) (i&(-i))
#define bug(n,m,x) forn(i,n){forn(j,m)printf("%d ",x[i][j]);puts("");}puts("")
#define sqr(x) ((x)*(x))
using namespace std;
const int inf=1<<30;
const double eps=1e-8;
const double pi=acos(-1.0);
const int mod = 1e9+7;
//const double inf = 1e10;


int t,n,ti=1;
char a[10000],b[10000];
int main(){
#ifdef jordan13game
    freopen("D:\\in.txt","r",stdin);
    freopen("D:\\out.txt","w",stdout);
#endif
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);gets(a);
        clr(a,0);
        int ans=0;
        for(int i=0;i<n;i++){
            gets(b);
            if(strcmp(a,b)>0)ans++;
            else strcpy(a,b);
        }
        printf("Case #%d: %d\n",ti++,ans);
    }
    return 0;
}

//#include <cstdio>
//#include <cstring>
//#include <cmath>
//#include <algorithm>
//using namespace std;
//const double eps = 1e-9;
//inline int dcmp(double x) {
//    if (fabs(x) < eps)
//        return 0;
//    return x > eps ? 1 : -1;
//}
//struct point {
//    double x, y;
//    int id;
//    inline void in(int i) {
//        scanf("%lf%lf", &x, &y);
//        id = i;
//    }
//    point(double x = 0, double y = 0) :
//            x(x), y(y) {
//    }
//    inline point operator -(const point &t) const {
//        return point(x - t.x, y - t.y);
//    }
//    inline point operator +(const point &t) const {
//        return point(x + t.x, y + t.y);
//    }
//    point operator /(const double &t) const {
//        return point(x / t, y / t);
//    }
//    point operator *(const double &t) const {
//        return point(x * t, y * t);
//    }
//    inline double operator *(const point &t) const {			//叉乘
//        return x*t.y-y*t.x;
//    }
//    bool operator <(const point &t) const {
//        if(y == t.y) return x < t.x;
//        return y < t.y;
//    }
//}p[55], v[55], tp[55], st[55];
//double t[55*55*55], T, cur, ans;
//int sz, n, m;
//double a, b, c;
//inline double cross(const point &o, const point &a, const point &b) {
//    return (a.x-o.x)*(b.y-o.y)-(a.y-o.y)*(b.x-o.x);
//}
//
//int graham(point *p, int n, point *st) {		//凸包
//    sort(p, p + n);
//    int top = 0;
//    int i;
//    for (i = 0; i < n; i++) {
//        while (top >= 2 && cross(st[top - 2], st[top - 1], p[i]) < eps)
//            top--;
//        st[top++] = p[i];
//    }
//    int t = top + 1;
//    for (i = n - 2; i >= 0; i--) {
//        while (top >= t && cross(st[top - 2], st[top - 1], p[i]) < eps)
//            top--;
//        st[top++] = p[i];
//    }
//    return top;
//}
//
//
//inline void gao(int i, int j, int k) {		//计算系数的函数
//    point a1 = p[i]-p[j], a2 = p[i]-p[k];
//    point b1 = v[i]-v[j], b2 = v[i]-v[k];
//    a += b1*b2; b += a1*b2+b1*a2; c += a1*a2;
//}
//inline void solve(double a, double b, double c) {	//解方程，注意a==0的情况
//    double x;
//    if(a == 0) {
//        if(b!= 0) {
//            x = -c/b;
//            if(x >= 0 && x <= T) t[sz++] = x;
//        }
//        return;
//    }
//    double dlt = b*b-4*a*c;
//    if(dlt < 0) return;
//    if(dlt == 0) {
//        x = -b*0.5/a;
//        if(x >= 0 && x <= T) t[sz++] = x;
//        return;
//    }
//    dlt = sqrt(dlt);
//    x = 0.5*(-b+dlt)/a;
//    if(x >= 0 && x <= T) t[sz++] = x;
//    x = 0.5*(-b-dlt)/a;
//    if(x >= 0 && x <= T) t[sz++] = x;
//}
//
//inline double F(double x) {		//积分求值函数
//    return a*x*x*x/3.0+b*x*x/2.0+c*x;
//}
//int main() {
//    int i, j, k;
//    while( ~scanf("%d%lf", &n, &T)) {
//        for(i = 0; i < n; i++) p[i].in(i), v[i].in(i);
//        if(n <= 2) {
//            printf("%.10f\n", 0.0);
//            continue;
//        }
//        t[0] = 0; t[1] = T;	//处理出所有时间点
//        sz = 2;
//        for(i = 0; i < n; i++)
//            for(j = i+1; j < n; j++)
//                for(k = j+1; k < n; k++) {
//                    a = b = c = 0;
//                    gao(i, j, k);
//                    solve(a, b, c);
//                }
//        sort(t, t+sz);
//        ans = 0;
//        for(i = 0; i < sz-1; i++) { //枚举相邻时间段
//            cur = 0.5*(t[i]+t[i+1]);
//            a = b = c = 0;
//            for(j = 0; j < n; j++) {
//                tp[j] = p[j]+v[j]*cur;
//                tp[j].id = p[j].id;
//            }
//            m = graham(tp, n, st);//凸包求出该时间段在凸包上的点
//            for(j = 2; j < m; j++)
//                gao(st[0].id, st[j-1].id, st[j].id);	//求系数
//            ans += F(t[i+1])- F(t[i]);//手动积分算面积
//        }
//        printf("%.10f\n", fabs(ans*0.5/T));
//    }
//    return 0;
//}
