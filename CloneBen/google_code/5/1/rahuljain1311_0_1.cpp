#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int t,n,i,ii=1;
    cin>>t;
    while(t--)
    {
        cin>>n;
        string s[n+3];
        char s1[1000],s2[10];
        gets(s2);
        for(i=1;i<=n;i++)
        {
            gets(s1);
            s[i]=s1;
        }
        string key;
        int j,ans=0;
        s[0]="                                              ";
        for(i=1; i<=n; i++)
        {
          key = s[i];
          j = i-1;
          //cout<<"key="<<key<<"s[j]="<<s[j]<<"\n";
          if(j>=0&&key<s[j])
          {
              ans++;
                while(j>=0 && key < s[j])
              {
                s[j+1] = s[j];
                j--;
              }
          }
          s[j+1] = key;
        }
        cout<<"Case #"<<ii<<": "<<ans<<"\n";ii++;
    }
    return 0;
}
