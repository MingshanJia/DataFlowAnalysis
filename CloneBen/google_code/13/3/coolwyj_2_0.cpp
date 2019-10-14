#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
char s[105][105];
bool isbiger(char a[],char b[])//ret a>b
{
    int s1=strlen(a),s2=strlen(b);
    int ss=min(s1,s2);
    for(int i=0;i<ss;i++)
    {
        if(a[i]>b[i]) return true;
        else if(a[i]<b[i]) return false;
    }
    if(s1 >= s2) return true;
    else return false;
}
int main()
{
    int T,n,cas=0;
    cin>>T;
    while(T--)
    {
        cin>>n;
		getchar();
		for(int i=1;i<=n;i++) 
			cin.getline(s[i],105);
        int res=0,pre=1;
        for(int i=2;i<=n;i++)
        {
            if(isbiger(s[i],s[pre]))
            {
                pre=i;
            }
            else res++;
        }
        printf("Case #%d: ",++cas);
        cout<<res<<endl;
    }
    return 0;
}
