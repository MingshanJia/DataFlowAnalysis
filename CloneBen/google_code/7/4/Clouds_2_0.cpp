#include <iostream>
#include <map>

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
        map<string,string> tic;
        map<string,int> cnt;
        for(int i=0;i<n;i++)
        {
            string a,b;
            cin>>a>>b;
            cnt[a]++;
            cnt[b]--;
            tic[a]=b;
        }
        cout<<"Case #"<<tt<<":";
        string a,b;
        for(map<string,int>::iterator it=cnt.begin();it!=cnt.end();it++)
        {
            if(it->second==1)
                a=it->first;
        }
        for(int k=0;k<n;k++)
        {
            b=tic[a];
            cout<<" "<<a<<"-"<<b;
            a=b;
        }
        cout<<endl;
    }
    return 0;
}
