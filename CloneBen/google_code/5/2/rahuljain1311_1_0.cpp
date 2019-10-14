#include<bits/stdc++.h>
using namespace std;
#define PI 3.141592653589793238462643383279502884197169
#define g 9.80000000000000

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int t,n,i,ii=1;
    cin>>t;
    while(t--)
    {
        double v,d;
        cin>>v>>d;
        double ans;
        double param, result;
        param = (((double)d)*((double)g))/(((double)v)*((double)v));
        result = ((double)asin (param) )* 180.00000000000000 / PI;
        result/=((double)2.00000000);
        //printf ("The arc sine of %f is %f degrees\n", param, result);
        cout<<"Case #"<<ii<<": ";
        printf("%.8f\n",result);ii++;
    }
    return 0;
}
