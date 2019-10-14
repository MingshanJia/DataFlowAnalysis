#include<iostream>
#include<cmath>
#include<string.h>
#include<stdio.h>
#include<algorithm>
using namespace std;

int n,m;
int t;
double dp[4011][2011];

int main()
{
    int i,j,k,times;
    freopen("A-large.in","r",stdin);
    freopen("ans.out","w",stdout);
    
    cin>>t;
    for(times=1;times<=t;times++)
    {
        cin>>n>>m;
        
        memset(dp,0,sizeof(dp));
        dp[0][0]=1.0;
        
        for(i=1;i<=n+m;i++)
        {
            for(j=0;j<=n;j++)
            {
                if(j>i || i-j>=j)continue;
                
                if(j>0)
                {
                    dp[i][j]+=dp[i-1][j-1]*(n-j+1)/(n+m-i+1);
                }
                if(i-j>0)
                {
                    dp[i][j]+=dp[i-1][j]*(m-(i-1-j))/(n+m-i+1);
                }
                
                //cout<<dp[i][j]<<' '<<i<<' '<<j<<endl;
            }
        }
        
        cout.precision(8);
        cout.setf(ios::fixed);
        cout<<"Case #"<<times<<": ";
        cout<<dp[n+m][n]<<endl;
    }
    
    
    return 0;
} 
