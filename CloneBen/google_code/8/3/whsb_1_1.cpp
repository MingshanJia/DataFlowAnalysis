#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <vector>
using namespace std;
#define inf 1000000000
typedef unsigned long long ULL;
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<PII,int> PIII;

int stationNum[128],waitTim[128];
int Tim[128][1024];
int SumTim[128][1024];

int N,M,Q;

map<int,int> hashID;
int reHashID[60000];
int id(int LineID,int StationID)
{
    return LineID*10000+StationID;
}
void reid(int ID,int &LineID,int &StationID)
{
    LineID = ID/10000;
    StationID = ID%10000;
}

int Dis(int Line,int SS,int TT)
{
    if(SS==TT) return 0;
    int ret = SumTim[Line][SS]-SumTim[Line][TT];
    if(ret<0) ret=-ret;
    return ret+waitTim[Line];
}



vector<int> Tunnels[128];

int dis[512][512];

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int casT;
    cin>>casT;
    for(int cas=1;cas<=casT;cas++)
    {
        printf("Case #%d:\n",cas);
        scanf("%d",&N);

        for(int i=1;i<=N;i++)
        {
            scanf("%d%d",&stationNum[i],&waitTim[i]);
            SumTim[i][1] = 0;
            for(int j=1;j<stationNum[i];j++)
            {
                scanf("%d",&Tim[i][j]);
                SumTim[i][j+1] = SumTim[i][j]+Tim[i][j];
            }
            Tunnels[i].clear();
        }
        scanf("%d",&M);
        int Pid = 0;
        hashID.clear();
        for(int i=0;i<512;i++)for(int j=0;j<512;j++) if(i!=j) dis[i][j]=inf;else dis[i][j]=0;
        for(int i=0;i<M;i++)
        {
            ///cout<<M<<" "<<Pid<<endl;
            int La,Sa,Lb,Sb,T;
            scanf("%d%d%d%d%d",&La,&Sa,&Lb,&Sb,&T);
            int Aid = id(La,Sa),Bid = id(Lb,Sb);
            if(hashID.find(Aid)==hashID.end()) {hashID.insert(PII(Aid,Pid));reHashID[Pid++] = Aid;}
            if(hashID.find(Bid)==hashID.end()) {hashID.insert(PII(Bid,Pid));reHashID[Pid++] = Bid;}
            int hA = hashID[Aid],hB = hashID[Bid];
            dis[hA][hB] = dis[hB][hA] = min(dis[hB][hA],T);
            Tunnels[La].push_back(Sa);
            Tunnels[Lb].push_back(Sb);
        }
        for(int i=0;i<Pid;i++)
        for(int j=i+1;j<Pid;j++)
        {
            int Aid = reHashID[i],Bid = reHashID[j];
            int La,Sa,Lb,Sb,T;
            reid(Aid,La,Sa);
            reid(Bid,Lb,Sb);
            if(La==Lb)
            {
                T = SumTim[La][Sa] - SumTim[Lb][Sb];
                if(T<0) T=-T;
                T+=waitTim[La];
                dis[i][j]=dis[j][i]=min(dis[i][j],T);
            }
        }
        ///cout<<"here:"<<Pid<<endl;
        for(int k=0;k<Pid;k++)for(int i=0;i<Pid;i++)for(int j=0;j<Pid;j++)
        {
            dis[i][j]=min(dis[i][k]+dis[k][j],dis[i][j]);
        }

        scanf("%d",&Q);
        while(Q--)
        {
            int Ls,Ss,Lt,St;
            scanf("%d%d%d%d",&Ls,&Ss,&Lt,&St);
            int ans = inf;
            if(Ls==Lt) ans = Dis(Ls,Ss,St);
            int Ssiz = Tunnels[Ls].size();
            int Tsiz = Tunnels[Lt].size();
            ///cout<<Ssiz<<" "<<Tsiz<<endl;
            for(int i=0;i<Ssiz;i++)
            for(int j=0;j<Tsiz;j++)
            {
                int Aid = hashID[id(Ls,Tunnels[Ls][i])], Bid = hashID[id(Lt,Tunnels[Lt][j])];
                int tmpdis = dis[Aid][Bid] + Dis(Ls,Ss,Tunnels[Ls][i]) + Dis(Lt,St,Tunnels[Lt][j]);
                ans = min(ans,tmpdis);
            }
            if(ans>=inf)  ans = -1;
            printf("%d\n",ans);
        }
    }
    return 0;
}
