#include <cstdio>
#include <cstring>
#include <map>

using namespace std;

#define N 30
#define M 30
#define K 50
#define NN (N*M*K/2)

int T,n,m,k;
char b[K][N][M];
int t[K][N][M];
int w[4][2]={{0,-1},{0,1},{-1,0},{1,0}};
int q[N*M][2],hd,tl;
int nn;
int qq[NN],vv[NN],cc[NN],hh,tt;
map<int,int> g[NN];
int f;

int main(){
    int i,j,x,y,z;
    map<int,int>::iterator it;
    scanf("%d",&T);
    for(int lt=1;lt<=T;lt++){
        scanf("%d%d%d",&n,&m,&k);
        for(z=0;z<k;z++)for(x=0;x<n;x++)scanf("%s",b[z][x]);
        nn=0;
        memset(t,0,sizeof(t));
        for(z=0;z<k;z++){
            for(x=0;x<n;x++)for(y=0;y<m;y++)if(b[z][x][y]=='.'&&!t[z][x][y]){
                // flood fill
                nn++;
                hd=tl=0;
                q[tl][0]=x;q[tl][1]=y;
                t[z][q[tl][0]][q[tl][1]]=nn;
                tl++;
                while(hd<tl){
                    for(i=0;i<4;i++){
                        int xx=q[hd][0]+w[i][0],yy=q[hd][1]+w[i][1];
                        if(xx<0||xx>=n||yy<0||yy>=m)continue;
                        if(b[z][xx][yy]!='.'||t[z][xx][yy])continue;
                        q[tl][0]=xx;q[tl][1]=yy;
                        t[z][q[tl][0]][q[tl][1]]=nn;
                        tl++;
                    }
                    hd++;
                }
                // end
            }
        }
        // graph
        nn++;
        for(i=0;i<=nn;i++)g[i].clear();
        for(z=1;z<k;z++)for(x=0;x<n;x++)for(y=0;y<m;y++){
            int aa,bb;
            if(z&1){
                aa=t[z-1][x][y],bb=t[z][x][y];
            }else{
                aa=t[z][x][y],bb=t[z-1][x][y];
            }
            if(aa&&bb){
                g[0][aa]=1; g[aa][0]=0;
                g[aa][bb]=1;g[bb][aa]=0;
                g[bb][nn]=1;g[nn][bb]=0;
            }
        }
        // flow
        memset(cc,-1,sizeof(cc));
        for(f=0;;f++){
            int good=0;
            // bfs
            hh=tt=0;
            qq[tt]=0;vv[tt]=-1;cc[qq[tt]]=f;tt++;
            while(hh<tt){
                for(it=g[qq[hh]].begin();it!=g[qq[hh]].end();it++)if(it->second && cc[it->first]!=f){
                    qq[tt]=it->first;
                    vv[tt]=hh;
                    cc[qq[tt]]=f;
                    if(qq[tt]==nn){good=1;break;}
                    tt++;
                }
                if(good)break;
                hh++;
            }
            if(!good)break;
            // back
            while(qq[tt]){
                g[qq[vv[tt]]][qq[tt]]--;
                g[qq[tt]][qq[vv[tt]]]++;
                tt=vv[tt];
            }
        }
        printf("Case #%d: %d\n",lt,nn-1-f);
    }
    return 0;
}
