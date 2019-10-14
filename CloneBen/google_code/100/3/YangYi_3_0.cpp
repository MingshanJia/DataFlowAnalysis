#include<cstdio>
#include<memory>

int h,i,j,k,n,m,t,z,a[11][11],b[11][11],c[11],p[11];

void tr(int i)
{
    int j,k,l;
    if(i>m)
    {
        l=1;
        for(j=1;j<m;j++)
            for(k=j+1;k<=m;k++)
                if(b[j][k]!=a[p[j]][p[k]])l=0;
        if(l)z=1;
    }
    for(j=1;j<=n;j++)
        if(!c[j])
        {
            c[j]=1;p[i]=j;
            tr(i+1);
            c[j]=0;
        }
}

int main()
{
    freopen("d.in","r",stdin);
    freopen("d.out","w",stdout);
    scanf("%d",&t);
    for(h=0;h<t;h++)
    {
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        scanf("%d",&n);
        for(i=1;i<n;i++)
        {
            scanf("%d%d",&j,&k);
            a[j][k]=1;a[k][j]=1;
        }
        scanf("%d",&m);
        for(i=1;i<m;i++)
        {
            scanf("%d%d",&j,&k);
            b[j][k]=1;b[k][j]=1;
        }
        memset(c,0,sizeof(c));
        z=0;tr(1);
        printf("Case #%d: ",h+1);
        if(z)puts("YES");
        else puts("NO");
    }
    return 0;
}
