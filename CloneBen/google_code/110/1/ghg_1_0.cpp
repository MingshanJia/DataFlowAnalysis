#include <iostream>
#include <string>
using namespace std;
long long p3(long long a)
{
    return a*a*a;
}
int abs(int a)
{
    if(a<0)
        return -a;
    return a;
}
int main()
{
    int N;
    cin>>N;
    long long k, v, ans;
    for(int I=0;I<N;I++)
    {
        cin>> k >>v;
        ans = (k-v) * ( p3(v+1) - p3(v) ) + p3(v+1);
        cout<<"Case #"<<I+1<<": "<<ans<<endl;
    }
    return 0;
}
