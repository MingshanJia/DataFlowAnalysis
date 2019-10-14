#include <bits/stdc++.h>
using namespace std;
int t;
const double pi = acos(-1);
int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    cin>>t;
    for(int cs=1;cs<=t;cs++){
        int v,d;
        cin>>v>>d;
        double c2 = 9.8 * d / (v * v);
        double theta = asin(c2)/2.0;
        double ans = theta / pi * 180.0;
        cout<<"Case #"<<cs<<": ";
        cout<<fixed<<setprecision(7)<<ans<<endl;
    }
}
