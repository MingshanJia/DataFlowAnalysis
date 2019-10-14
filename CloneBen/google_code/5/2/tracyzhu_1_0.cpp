//
//  main.cpp
//  GG_onsite
//
//  Created by 祝风翔 on 15/8/14.
//  Copyright (c) 2015年 祝风翔. All rights reserved.
//

#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <string>
#include <time.h>
#include <vector>
#include <unordered_map>
#include <queue>
#include <map>
#include <cmath>
using namespace std;

const double g = 9.800;
const double pi = 3.14159265358;
inline double f(double x) {
    return x * pi / 180.0;
}
int main(){
    freopen("B-small-attempt0.in","r",stdin);
    freopen("B-small-attempt0.out","w",stdout);
    int T,cas = 0;
    scanf("%d",&T);
    while(T--) {
        double V,D;
        scanf("%lf %lf",&V,&D);
        //double dis = 2 * v / g * sin(f(45.0)) * cos(f(45));
        double l = 0,r = 45.00;
        for(int i = 0;i <= 200;i++) {
            double mid = (l + r) / 2.0;
            double dis = 2 * V * V/ g * sin(f(mid)) * cos(f(mid));
            //printf("%.3lf\n",dis);
            if(dis >= D) {
                r = mid;
            }else {
                l = mid;
            }
        }
        printf("Case #%d: %.10lf\n",++cas,l);
    }
    return 0;
}