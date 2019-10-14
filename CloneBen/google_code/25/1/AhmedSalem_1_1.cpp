#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std ;

#define MAXN 1005


class COMP
{
    public:
        int od,ev;
}cur,tn,comp[MAXN];

bool cmp(const COMP &a,const COMP &b)
{
    if (a.od!=b.od)return a.od>b.od;
    return a.ev>b.ev;
}

int cnt;
bool flag[MAXN];
bool odd[MAXN];
int n,m;
vector<vector<int> >ed;
int ns[MAXN];


void flood(int ind)
{
    if (flag[ind])return ;
    if (odd[ind])comp[cnt].od++;
    else comp[cnt].ev++;
    flag[ind]=1;
    int c,c2;
    for (c=0;c<ns[ind];c++)
        flood(ed[ind][c]);
    return;
}



int main()
{
    FILE *in=fopen("battle.in","r");
    freopen("battle.out","w",stdout);
    int c,c2;
    int tests;
    fscanf(in,"%d",&tests);
    int testn=1;
    while (tests--)
    {
        printf("Case #%d: ",testn);
        testn++;
        memset(odd,0,sizeof(odd));
        fscanf(in,"%d%d",&n,&m);
        ed.clear();
        ed.resize(n);
        memset(ns,0,sizeof(ns));
        for (c=0;c<m;c++)
        {
            int t1,t2;
            fscanf(in,"%d%d",&t1,&t2);
            ns[t1]++;
            ns[t2]++;
            odd[t1]=!odd[t1];
            odd[t2]=!odd[t2];
            ed[t1].push_back(t2);
            ed[t2].push_back(t1);
        }
        cnt=0;
        memset(comp,0,sizeof(comp));
        memset(flag,0,sizeof(flag));
        for (c=0;c<n;c++)
        {
            if (flag[c])continue;
            if (ns[c]==0)continue;
            flood(c);
            cnt++;
        }
        sort(comp,comp+cnt,cmp);
        cur=comp[0];
        int ret=0;
        for (c=1;c<cnt;c++)
        {
            ret++;
            if (cur.od && comp[c].od)
            {
                cur.od+=comp[c].od-2;
                cur.ev+=comp[c].ev+2;
            }
            else if (cur.od==0 && comp[c].od==0)
            {
                cur.od+=comp[c].od+2;
                cur.ev+=comp[c].ev-2;
            }
            else
            {
                cur.od+=comp[c].od;
                cur.ev+=comp[c].ev;
            }
        }
        ret+=cur.od/2;
        printf("%d\n",ret);
    }
    
//    system("pause");
    return 0;
}


































