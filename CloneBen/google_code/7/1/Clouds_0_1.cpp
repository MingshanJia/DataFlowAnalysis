#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N=1000+5;
int m[N*N][2];

int main()
{
    int T;
    cin>>T;
    for(int tt=1;tt<=T;tt++)
    {
        int r,d=1;
        int maxr,maxd;
        int s;
        memset(m,0,sizeof(m));
        m[0][0]=-1,m[0][1]=-1;
        cin>>s;
        maxr=s*s,maxd=1;
        for(int i=0;i<s;i++)
            for(int j=0;j<s;j++)
            {
                int x;
                cin>>x;
                m[x][0]=i;
                m[x][1]=j;
            }
        for(r=s*s-1;r>=0;r--)
        {
            if((abs(m[r][0]-m[r+1][0])+abs(m[r][1]-m[r+1][1]))==1)
                d++;
            else
            {
                if(d>=maxd)
                    maxd=d,maxr=r+1;
                d=1;
            }
        }
        cout<<"Case #"<<tt<<": "<<maxr<<" "<<maxd<<endl;
    }
    return 0;
}
