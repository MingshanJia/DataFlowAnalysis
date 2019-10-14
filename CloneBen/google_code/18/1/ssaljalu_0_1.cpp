#include <cstdio>

long long T,n,a[3],b[3];
long long p[3][3],t[3][3];
long long chk1[3],chk2[3];
long long point,first;

void back(){
    int i,j,done=1;
    for(i=0;i<3;i++)for(j=0;j<3;j++)
        if(!chk1[i]&&!chk2[j])done=0;
    if(done){
        long long pt=0;
        for(i=0;i<3;i++)for(j=0;j<3;j++)
            pt+=p[i][j]*t[i][j];
        if(first || point<pt){
            point=pt;
            first=0;
        }
        return;
    }
    for(i=0;i<3;i++)if(!chk1[i]){
        for(j=0;j<3;j++)if(!chk2[j]){
            if(a[i]<=b[j]){
                t[i][j]=a[i];
                a[i]-=t[i][j];b[j]-=t[i][j];
                chk1[i]=1;
                back();
                chk1[i]=0;
                a[i]+=t[i][j];b[j]+=t[i][j];
                t[i][j]=0;
            }
        }
    }
    for(j=0;j<3;j++)if(!chk2[j]){
        for(i=0;i<3;i++)if(!chk1[i]){
            if(b[j]<=a[i]){
                t[i][j]=b[j];
                a[i]-=t[i][j];b[j]-=t[i][j];
                chk2[j]=1;
                back();
                chk2[j]=0;
                a[i]+=t[i][j];b[j]+=t[i][j];
                t[i][j]=0;
            }
        }
    }
}

int main() {
    int i,j;
    scanf("%lld",&T);
    for(long long lt=1;lt<=T;lt++){
        scanf("%lld",&n);
        for(i=0;i<3;i++)scanf("%lld",&a[i]);
        for(i=0;i<3;i++)scanf("%lld",&b[i]);
        for(i=0;i<3;i++)for(j=0;j<3;j++)scanf("%lld",&p[i][j]);
        first=1;
        back();
        printf("Case #%lld: %lld\n",lt,point);
    }
    return 0;
}
