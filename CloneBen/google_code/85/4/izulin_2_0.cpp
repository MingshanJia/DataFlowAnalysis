#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int tst()
{
    int r;
    int t[100][100];
    bzero(t,sizeof(t));
    cin >> r;
    for(int i=0;i<r;i++)
    {
        int x1,x2,y1,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for(int i=x1;i<=x2;i++)
            for(int j=y1;j<=y2;j++)
                t[i-1][j-1] = 1;
    }
    int ans=0;
    for(;;)
    {
        int cnt=0;
        int tt[100][100];
        for(int i=0;i<100;i++)
            for(int j=0;j<100;j++)
                tt[i][j]=t[i][j];
        bzero(t,sizeof(t));
        for(int i=0;i<100;i++)
            for(int j=0;j<100;j++)
            {
                if(tt[i][j] && ((i>0 && tt[i-1][j]) || (j>0 && tt[i][j-1])))
                {
                    t[i][j]=1;
                    cnt++;
                }
                else if(!tt[i][j] && i>0 && tt[i-1][j] && j>0 && tt[i][j-1])
                {
                    t[i][j]=1;
                    cnt++;
                }
            }
        ans++;
        if(cnt==0)
            break;
    }
    return ans;
}

int main()
{
    int t;
    cin >> t;
    for(int tt=1;tt<=t;tt++)
        cout << "Case #" << tt << ": " << tst() << endl;
}
