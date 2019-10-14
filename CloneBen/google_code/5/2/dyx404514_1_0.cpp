#include <iostream>
#include <string.h>
#include <stdio.h>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
const double pi=acos(-1);
int main(){
    freopen("dd.in","r",stdin);
    freopen("out.txt","w+",stdout);
    int ncase,T=0;
    scanf("%d\n",&ncase);
    while(ncase--){
        int v,d;
        scanf("%d%d",&v,&d);
        double x=asin(d*9.8/v/v)/pi*90.0;
        printf("Case #%d: %.6lf\n",++T,x);
    }
    return 0;
}
