#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N=500+5;
int m[N][2];

int main()
{
    int T;
    cin>>T;
    for(int tt=1;tt<=T;tt++)
    {
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>m[i][0]>>m[i][1];
        cout<<"Case #"<<tt<<":";
        int p;
        cin>>p;
        for(int k=0;k<p;k++)
        {
            int x,t=0;
            cin>>x;
            for(int i=0;i<n;i++)
                if(x>=m[i][0] && x<=m[i][1])
                    t++;
            cout<<" "<<t;
        }
        cout<<endl;
    }
    return 0;
}
