#include <stdio.h>
#include <memory.h>
#include <vector>
#include <queue>
#define MN 10000
#define MP 100
using namespace std;
int N, P, M;
int X[MP], V[MP];
vector<pair<int,int> > d[MN];
int r[MN], dis[MN];
int main()
{
    FILE *in=fopen("input.txt","r");
    FILE *out=fopen("output.txt","w");
    int t, T, i, j, k, pr;
    int p, v, q, vv;
    
    fscanf(in,"%d",&T);
    for (t = 1; t <= T; t++) {
        fprintf(out,"Case #%d: ",t);
        fscanf(in,"%d%d%d",&N,&P,&M);
        for (i = 0; i < P; i++) {
            fscanf(in,"%d%d",&X[i],&V[i]);
            X[i]--;
        }
        for (i = 0; i < N; i++) d[i].clear();
        while (M--) {
              fscanf(in,"%d%d",&k,&i);
              pr = -1;
              while (i--) {
                    fscanf(in,"%d",&j); j--;
                    if (pr != -1) {
                           d[j].push_back(make_pair(pr,k));
                           d[pr].push_back(make_pair(j,k));
                    }
                    pr = j;
              }
        }
        memset(r,0,sizeof(r));
        while (P--) {
              printf("%d\n",P);
              memset(dis,-1,sizeof(dis));
              priority_queue<pair<int,int> > pq;
              dis[X[P]] = 0; pq.push(make_pair(-0,X[P]));
              while (!pq.empty()) {
                    v = -pq.top().first; p = pq.top().second; pq.pop();
                    if (v > dis[p]) continue;
                    for (i = 0; i < d[p].size(); i++) {                    
                        q = d[p][i].first;
                        vv = v+d[p][i].second;
                        if (dis[q] == -1 || dis[q] > vv)
                           dis[q] = vv; pq.push(make_pair(-vv,q));
                    }
              }
              for (i = 0; i < N; i++) {
                  if (dis[i] != -1) {
                     if (r[i] < dis[i]*V[P] && r[i] != -1)
                        r[i] = dis[i]*V[P];
                  }
                  else r[i] = -1;
              }
        }
        k = -1;
        for (i = 0; i < N; i++) {
            if (r[i] != -1) {
                     if (k == -1 || k > r[i])
                        k = r[i];
            }
        }
        fprintf(out,"%d\n",k);
        printf("%d\n",t);
    }
    return 0;
}
