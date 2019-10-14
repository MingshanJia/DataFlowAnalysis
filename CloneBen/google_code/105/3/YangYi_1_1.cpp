#include <stdio.h>
#include <string>

int ii,tt,n,m,i,j,k,l,t,s;
int a[2100],b[2100],c[2100],d[2100][2100];// a: likes  b: number  c: states  d: ummalted
int Q[2100];

int main()
{
    freopen("1.in","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d",&tt);
    for (ii=1;ii<=tt;ii++)
    {
        scanf("%d",&n); scanf("%d",&m);
        memset(d,0,sizeof(d)); memset(b,0,sizeof(b)); memset(a,0,sizeof(a));
        for (i=1;i<=m;i++)
        {
            scanf("%d",&k);
            for (j=0;j<k;j++)
            {
                scanf("%d %d",&l,&t);
                if (t==1) a[i] = l; else { d[l][i] = 1; b[i] ++; }
            }
        }
        memset(c,0,sizeof(c));
        s = 0; t = 0;
        for (i=1;i<=m;i++) if (b[i]==0) { t ++; Q[t] = i; }
        while (s<t)
        {
            s ++; k = a[Q[s]];
            if (k==0) { b[Q[s]] = 0; break; }
            b[Q[s]] = 1;
            if (c[k]==1) continue;
            c[k] = 1;
            for (i=1;i<=m;i++) if (d[k][i]==1)
            {
                b[i] --;
                if (b[i]==0) { t ++; Q[t] = i; }
            }
        }
        k = 0;
        for (i=1;i<=m;i++) if (b[i]==0) k ++;
        printf("Case #%d:",ii);
        if (k>0) printf(" IMPOSSIBLE"); else for (i=1;i<=n;i++) printf(" %d",c[i]);
        printf("\n");
    }
    return 0;
}