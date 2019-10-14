#include<cstdio>

int h,i,j,k,n,m,e,t,p,q,l,r,d,u,x[1111],y[1111],z[1111];
char a[1111];

int main()
{
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    scanf("%d",&t);
    for(h=1;h<=t;h++)
    {
        printf("Case #%d:\n",h);
        l=1<<30;r=0;d=1<<30;u=0;e=0;
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d%d %s",&x[i],&y[i],a);
            z[i]=1;
            if(a[0]=='N')
            {
                z[i]=0;
                scanf(" %s",a);
            }
            else
            {
                if(x[i]<l)l=x[i];
                if(x[i]>r)r=x[i];
                if(y[i]<d)d=y[i];
                if(y[i]>u)u=y[i];
                e=1;
            }
        }
        scanf("%d",&m);
        for(i=0;i<m;i++)
        {
            scanf("%d%d",&p,&q);
            if(!e)
            {
                for(j=0;j<n;j++)
                    if(x[j]==p&&y[j]==q)break;
                if(j<n)puts("NOT BIRD");
                else puts("UNKNOWN");
            }
            else
            {
                if(p>=l&&p<=r&&q>=d&&q<=u)puts("BIRD");
                else
                {
                    for(j=0;j<n;j++)
                        if(!z[j])
                        {
                            if(y[j]>=d&&y[j]<=u&&(x[j]<l&&p<=x[j]||x[j]>r&&p>=x[j])||x[j]>=l&&x[j]<=r&&(y[j]<d&&q<=y[j]||y[j]>u&&q>=y[j]))break;
                            if(x[j]<l&&y[j]<d&&p<=x[j]&&q<=y[j])break;
                            if(x[j]<l&&y[j]>u&&p<=x[j]&&q>=y[j])break;
                            if(x[j]>r&&y[j]<d&&p>=x[j]&&q<=y[j])break;
                            if(x[j]>r&&y[j]>u&&p>=x[j]&&q>=y[j])break;
                        }
                    if(j<n)puts("NOT BIRD");
                    else puts("UNKNOWN");
                }
            }
        }
    }
    return 0;
}
