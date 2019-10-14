#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
#define g 9.8
double pi = acos(-1.0);
int main()
{
    int v,d,T,cas=0;
    cin>>T;
    while(T--)
    {
        cin>>v>>d;
        double r1 = asin( (g*d)/(v*v) );
        r1 = r1*180/pi;
        r1 = r1*0.5;
        double r2 = 90-r1;
        printf("Case #%d: %.7f\n",++cas,min(r1,r2));
    }
    return 0;
}
