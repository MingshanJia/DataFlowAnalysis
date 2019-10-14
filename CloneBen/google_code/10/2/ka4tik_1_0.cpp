/*
 *Kartik Singal @ ka4tik
 */
#include<bits/stdc++.h>
using namespace std;
#define s(n) scanf("%d",&n)
vector<int> solveleft(vector<int> v)
{
    int n=v.size();
    vector<int> curr;
    curr=v;
    //cout<<"doing"<<endl;
    //for(int i=0;i<v.size();i++)
    //{
        //cout<<v[i]<<" ";
    //}
    //cout<<endl;
    while(1){
        vector<int> nw;
        for(int i=0;i<curr.size();i++)
        {
            if(curr[i]==0)
                continue;
            if(nw.size()&&nw.back()<0)
            {
                nw.push_back(v[i]);
            }
            else if(nw.size()&&nw.back()==curr[i])
            {
                nw.pop_back();
                nw.push_back(-(2*curr[i]));
            }
            else if(curr[i]==0)
                continue;
            else
            {
                nw.push_back(curr[i]);
            }
        }
        while(nw.size()<n) nw.push_back(0);
        for(int i=0;i<nw.size();i++) nw[i]=abs(nw[i]);
        if(nw==curr)
            break;
        curr=nw;
        break;
    }
    return curr;
}
int main()
{
    freopen("in","r",stdin);
    freopen("out","w",stdout);

    int test;s(test);
    int kase=1;
    while(test--)
    {
        int N;cin>>N;
        string dir;cin>>dir;
        vector< vector<int> > a(N);
        for(int i=0;i<N;i++)
        {
            a[i].resize(N);
            for(int j=0;j<N;j++)
            {
                s(a[i][j]);
            }
        }
        printf("Case #%d:\n",kase++);
        if(dir=="left")
        {
            for(int i=0;i<N;i++)
            {
                a[i]=solveleft(a[i]);
                for(int j=0;j<N;j++)
                {
                    cout<<a[i][j]<<" ";
                }
                cout<<endl;
            }
            
        }
        if(dir=="right")
        {
            for(int i=0;i<N;i++)
            {
                vector<int> t;
                for(int j=0;j<N;j++)
                {
                    t.push_back(a[i][N-1-j]);
                }
                a[i]=solveleft(t);
                for(int j=0;j<N;j++)
                    cout<<a[i][N-1-j]<<" ";
                cout<<endl;
            }
        }
        
        if(dir=="up")
        {
            vector< vector<int> > ans=a;
            for(int i=0;i<N;i++)
            {
                vector<int> t;
                for(int j=0;j<N;j++)
                {
                    t.push_back(a[j][i]);
                }
                t=solveleft(t);
                for(int j=0;j<N;j++)
                {
                    ans[j][i]=t[j];
                }
            }
            for(int i=0;i<ans.size();i++)
            {
                for(int j=0;j<ans.size();j++)
                {
                    cout<<ans[i][j]<<" ";
                }
                cout<<endl;
            }
        }
        if(dir=="down")
        {
            vector< vector<int> > ans=a;
            for(int i=0;i<N;i++)
            {
                vector<int> t;
                for(int j=0;j<N;j++)
                {
                    t.push_back(a[N-1-j][i]);
                }
                t=solveleft(t);
                for(int j=0;j<N;j++)
                {
                    ans[N-1-j][i]=t[j];
                }
            }
            for(int i=0;i<ans.size();i++)
            {
                for(int j=0;j<ans.size();j++)
                {
                    cout<<ans[i][j]<<" ";
                }
                cout<<endl;
            }
        }
    }

    return 0;
}



