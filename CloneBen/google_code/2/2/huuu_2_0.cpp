#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int edge[100][100];

void solve(int time){
    int n,m,p;
    cin >> n >> m >> p;
    for(int i = 0;i < n;i++) for(int j = 0;j < n;j++) edge[i][j] = 1000000000;
    for(int i = 0;i < m;i++){
        int u,v,d;
        cin >> u >> v >> d;
        u--;v--;
        edge[u][v] = d;
        edge[v][u] = d;
    }
    for(int k = 0;k < n;k++){
        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                edge[i][j] = min(edge[i][j],edge[i][k]+edge[k][j]);
            }
        }
    }
    double ans = 0;
    vector<double> cost(n);
    for(int i = 0;i < n;i++){
        cost[i] = 0;
        for(int j = 0;j < n;j++){
            if(i==j) continue;
            cost[i] += edge[i][j];
        }
        cost[i] /= n-1;
    }
    double pa[10000];
    vector<double> exist(n);
    exist[0] = 1;
    for(int i = 1;i < n;i++) exist[i] = 0;
    for(int i = 0;i < 10000;i++){
        pa[i] = 0;
        for(int j = 0;j < n;j++) {
            pa[i] += cost[j] * exist[j];
            exist[j] = (1 - exist[j]) / (n - 1);
        }
    }
    
    if(p <= 10000){
        for(int i = 0;i < p;i++){
            ans += pa[i];
        }
    }
    else{
        for(int i = 0;i < 10000;i++){
            ans += pa[i];
        }
        ans += pa[9999]*(p-10000);
    }
    cout << "Case #" << time << ": ";
    printf("%.8f\n",ans);
}

int main(){
    int t;
    cin >> t;
    for(int i = 1;i <= t;i++){
        solve(i);
    }
}
