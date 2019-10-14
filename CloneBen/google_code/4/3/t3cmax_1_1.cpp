#include<iostream>
#include<cmath>
#include<string.h>
#include<stdio.h>
#include<algorithm>
using namespace std;

int t;
int n,m;

int a[3];
int ans;
int main()
{
    int i,j,k,times;
    freopen("B-large.in","r",stdin);
    freopen("ans.out","w",stdout);
    
    
    cin>>t;
    for(times=1;times<=t;times++)
    {
        cin>>n>>m;
        if(n>m)
        {
            swap(n,m);
        }
        
        cout<<"Case #"<<times<<": ";
        if(n==1)
        {
            cout<<m/3*2+m%3<<endl;
            continue;
        }
        
        if(n==2)
        {
            cout<<(m/3*2+m%3)*2<<endl;
            continue;
        }
        
        if(m%3==0)
        {
            a[0]=a[1]=a[2]=0;
        }
        else if(m%3==1)
        {
            a[0]=1;
            a[1]=1;
            a[2]=0;
        }
        else if(m%3==2)
        {
            a[0]=2;
            a[1]=1;
            a[2]=1;
        }
        ans=0;
        for(j=0;j<n;j++)
        {
            ans+=m/3*2+a[j%3];
        }
        
        cout<<ans<<endl;
    }

    
    
    
    return 0;
} 
