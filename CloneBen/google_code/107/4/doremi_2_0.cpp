#include<bits/stdc++.h>
using namespace std;


#define dbg(x) cout << #x << " = " << x << endl

vector<string> v;
int l;

void solve()
{
    int i,j;
    char st,ed;
    for(i=0; i<l; i++)
    {
        if(v[1][i] != v[0][i])
        {
            st=v[1][i];
            ed=v[0][i];
            break;
        }
    }
    for(i=0; i<l; i++)
    {
        if(v[2][i] != v[0][i])
        {
            if(st==v[2][i] && ed==v[0][i])
                printf(" NO");
            else
                printf(" YES");
            return;
        }
    }
}

int main()
{
    freopen("C-small-attempt0.in","r",stdin);
    freopen("out.txt","w",stdout);
    int t,ti,i,j,k;
    string a,b,c;
    scanf("%d",&t);
    for(ti=1; ti<=t; ti++)
    {
        v.clear();
        scanf("%d",&l);
        cin >> a >> b >> c;
        v.push_back(a);
        v.push_back(b);
        v.push_back(c);
        printf("Case #%d:",ti);
        for(i=0; i<3; i++)
        {
            solve();
            swap(v[0],v[i+1]);
        }
        puts("");
    }

    return 0;
}

