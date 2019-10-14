#include<iostream>
#include<cmath>
#include<string.h>
#include<stdio.h>
#include<algorithm>
#include<map>
using namespace std;

int t,n,m;

long long dp[4011];
long long MOD=1000000007;

map<string,int>dic;
char s[4011];
int len;
int ans[11];

int main()
{
    int tmp[31];
    int ll;
    int i,j,k,times,z,w;
    char dd[31];
    string ss;
    freopen("C-small-attempt0.in","r",stdin);
    freopen("ans.out","w",stdout);
    
    cin>>t;
    
    for(times=1;times<=t;times++)
    {
        cin>>n>>m;
        
        dic.clear();
        for(i=1;i<=n;i++)
        {
            cin>>dd;
            sort(dd,dd+strlen(dd));
            ss=dd;
            if(dic.find(ss)==dic.end())
            {
                dic[ss]=1;
            }
            else
            {
                dic[ss]++;
            }
        }
        for(i=1;i<=m;i++)
        {
            cin>>s;
            len=strlen(s);
            memset(dp,0,sizeof(dp));
            dp[0]=1;
            for(j=1;j<=len;j++)
            {
                memset(tmp,0,sizeof(tmp));
                for(k=1;k<=20;k++)
                {
                    if(k>j)break;
                    
                    tmp[s[j-k]-'a']++;
                    
                    ll=0;
                    for(z=0;z<26;z++)
                    {
                        for(w=1;w<=tmp[z];w++)
                        {
                            dd[ll++]='a'+z;
                        }
                    }
                    dd[ll]=0;
                    ss=dd;
                    
                    if(dic.find(ss)!=dic.end())
                    {
                        dp[j]=(dp[j]+dp[j-k]*dic[ss])%MOD;
                    }
                }
            }
            
            
            /*
            for(j=0;j<=len;j++)
            {
                cout<<dp[j]<<' ';
            }
            cout<<endl;
            */
            ans[i]=dp[len];
        }
        
        
        cout<<"Case #"<<times<<": ";
        for(i=1;i<m;i++)
        {
            cout<<ans[i]<<' ';
        }
        cout<<ans[i]<<endl;
    }
    
    
    return 0;
} 
