/*
 *Kartik Singal @ ka4tik
 */
#include<bits/stdc++.h>
using namespace std;
#define s(n) scanf("%d",&n)
#define db(x) cerr << #x << ": " << x << endl;
#define db2(x, y) cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define db3(x, y, z) cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define db4(a, b, c, d) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define db5(a, b, c, d, e) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define db6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;
map<int,string> m;
string tobinary(int x)
{
    string ret;
    while(x!=0)
    {
        ret=(char)(x%2+'0')+ret;
        x>>=1;
    }
    return ret;
}
int main()
{
    freopen("in","r",stdin);
    freopen("out","w",stdout);

    m[0]="1111110";
    m[1]="0110000";
    m[2]="1101101";
    m[3]="1111001";
    m[4]="0110011";
    m[5]="1011011";
    m[6]="1011111";
    m[7]="1110000";
    m[8]="1111111";
    m[9]="1111011";
    int test;s(test);
    int kase=1;
    while(test--)
    {
        int N;s(N);
        vector<string> ans;
        vector<string> v(N);
        for(int i=0;i<N;i++)
        {
            cin>>v[i];
        }
        for(int i=0;i<(1<<7);i++)
        {
            int flag=1;
            for(int j=0;j<7;j++)
            {
                if(i&(1<<j))
                {
                    for(int k=0;k<N;k++)
                    {
                        if(v[k][j]=='1')
                            flag=0;
                    }
                    if(!flag)break;
                }
                if(!flag)
                    break;

            }
            if(flag)
            {
                //db(tobinary(i));
                for(int j=0;j<=9;j++)
                {
                    int flag=1;
                    int curr=j;
                    for(int k=0;k<N;k++)
                    {
                        for(int l=0;l<7;l++)
                        {
                            if(i&(1<<l))
                                continue;
                            if(m[curr][l]!=(v[k][l]))
                            {
                                flag=0;
                            }
                        }
                        if(!flag)break;
                        curr=curr-1;
                        if(curr<0) curr=9;
                    }
                    if(flag)
                    {
                        string t=m[curr];
                        for(int l=0;l<7;l++)
                        {
                            if(i&(1<<l))
                            {
                                t[l]='0';
                            }
                        }
                        ans.push_back(t);
                    }

                }
            }
        }
        printf("Case #%d: ",kase++);
        sort(ans.begin(),ans.end());
        ans.erase(unique(ans.begin(),ans.end()),ans.end());
        if(ans.size()==0||ans.size()>1)
        {
            puts("ERROR!");
        }
        else
        {
            cout<<ans[0]<<endl;
        }
    }

    return 0;
}

