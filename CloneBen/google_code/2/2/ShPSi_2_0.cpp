#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N=1e2+10;


int n,m,k;
int w[N][N];

struct matrix{
    double a[4][4];
    matrix(){
        for(int i=0;i<4;i++)
            for(int j=0;j<4;j++) a[i][j]=.0;
    }
};

double tmp[2][4];
matrix operator *(matrix a,matrix b){
    matrix ans;
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            for(int k=0;k<4;k++) ans.a[i][j]+=a.a[i][k]*b.a[k][j];
    return ans;
}
int main(){
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    int test;
    scanf("%d",&test);
    for(int te=1;te<=test;te++){
        scanf("%d%d%d",&n,&m,&k);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++) w[i][j]=(i!=j)*1000000;
        while (m--){
            int x,y,wei;
            scanf("%d%d%d",&x,&y,&wei);
            w[x][y]=min(w[x][y],wei);
            w[y][x]=min(w[y][x],wei);
        }
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                for(int k=1;k<=n;k++) w[j][k]=min(w[j][k],w[j][i]+w[i][k]);
        matrix base,ans;
        base.a[0][0]=base.a[2][1]=base.a[3][2]=base.a[3][3]=1;
        for(int i=1;i<=n;i++) base.a[1][0]+=w[1][i];
        base.a[1][0]/=n-1;
        for(int i=2;i<=n;i++)
            for(int j=1;j<=n;j++) base.a[2][0]+=w[i][j];
        base.a[2][0]/=n-1;
        base.a[2][2]=-1.0/(n-1);

//        for(int i=0;i<4;i++){
//            for(int j=0;j<4;j++) printf("%.9f ",base.a[i][j]);
//            cout<<'\n';
//        }
//        tmp[0][1]=1;
//        tmp[0][3]=1.0/(n-1);
//        for(int re=1;re<=k;re++){
//            for(int i=0;i<4;i++) tmp[1][i]=tmp[0][i],tmp[0][i]=0;
//            for(int i=0;i<4;i++)
//                for(int j=0;j<4;j++) tmp[0][i]+=tmp[1][j]*base.a[j][i];
//            for(int i=0;i<4;i++) cout<<tmp[0][i]<<" \n"[i==3];
//        }
        for(int i=0;i<4;i++) ans.a[i][i]=1.0;
        while (k){
            if (k&1) ans=ans*base;
            base=base*base;
            k>>=1;
        }



//        for(int i=0;i<4;i++){
//            double wans=ans.a[1][i]+ans.a[3][i]/(n-1);
//            cout<<wans<<" \n"[i==3];
//        }
        printf("Case #%d: %.9f\n",te,ans.a[1][0]+ans.a[3][0]/(n-1));
    }
}
