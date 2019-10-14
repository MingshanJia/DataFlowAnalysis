#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <string.h>
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
using namespace std;

const double pi = acos(-1.0);

int main(){
//    freopen("/home/zyc/Documents/Code/cpp/in","r",stdin);
    freopen("/home/zyc/Downloads/in","r",stdin);
    freopen("/home/zyc/Downloads/out","w",stdout);
    int T,cas=0;
    scanf("%d",&T);
    while(T--){
        double v,d;
        scanf("%lf%lf",&v,&d);
        double ans;
        if(fabs(d*9.8-v*v) < 1e-10)
            ans = pi/4;
        else
            ans = asin(d*9.8/v/v)/2;
        printf("Case #%d: %.10lf\n",++cas,ans/pi*180);
    }
    return 0;

}
