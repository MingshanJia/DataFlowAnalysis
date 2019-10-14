
#include <bits/stdc++.h>
#define boost ios_base::sync_with_stdio(0)
using namespace std;
int L;
int main()
{
    boost;
    int T;
    cin>>T;
    for(int tt=1;tt<=T;tt++){
        cin>>L;
        long long x,y;
        cin>>x>>y;
        long long rem = x;
        long long exp = y;
        for(int i=2;i<=L;i++){
            cin>>x>>y;
            long long currVal = x*y;
            if(currVal >= rem){
                rem = x;
                exp = y;
            }
            else{
                rem -= currVal;
                rem += x;
                exp = y;
            }
        }
        cout<<"Case #"<<tt<<": ";
        cout<<max(exp+1,rem)<<endl;
    }
    return 0;
}