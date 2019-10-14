#include <cstdio>

int T,n,a[3],b[3];
int p[3][3],t[3][3];
int point;

int main() {
    int i,j,pt,first;
    scanf("%d",&T);
    for(int lt=1;lt<=T;lt++){
        scanf("%d",&n);
        for(i=0;i<3;i++)scanf("%d",&a[i]);
        for(i=0;i<3;i++)scanf("%d",&b[i]);
        for(i=0;i<3;i++)for(j=0;j<3;j++)scanf("%d",&p[i][j]);
        first=1;
        for(t[0][0]=0;t[0][0]<=a[0];t[0][0]++)
            for(t[0][1]=0;t[0][1]<=a[0]-t[0][0];t[0][1]++)
                for(t[1][0]=0;t[1][0]<=a[1];t[1][0]++)
                    for(t[1][1]=0;t[1][1]<=a[1]-t[1][0];t[1][1]++){
                        for(i=0;i<2;i++)t[i][2]=a[i]-t[i][0]-t[i][1];
                        for(i=0;i<3;i++){
                            t[2][i]=b[i]-t[0][i]-t[1][i];
                            if(t[2][i]<0)break;
                        }
                        if(i<3)continue;
                        if(t[2][0]+t[2][1]+t[2][2] != a[2])continue;
                        if(t[0][2]+t[1][2]+t[2][2] != b[2])continue;
                        pt=0;
                        for(i=0;i<3;i++)
                            for(j=0;j<3;j++)
                                pt+=p[i][j]*t[i][j];
                        if(first || point<pt){
                            point=pt;
                            first=0;
                        }
                    }
        printf("Case #%d: %d\n",lt,point);
    }
    return 0;
}
