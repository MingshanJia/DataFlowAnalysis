#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 210;
double mm[40][maxn][maxn];
long long e[40];
int T, tt, n, m;
long long p;
int dis[maxn][maxn], d[maxn];
double f[maxn], ff[maxn];
double a[maxn];
bool vis[maxn];

void init(){
    for ( int i = 0; i < maxn; i++ ) a[i] = 0;
    for ( int i = 0; i < maxn; i++ )
        for ( int j = 0; j < maxn; j++ ){
            dis[i][j] = 10000000;
        }
    for ( int k = 0; k < 40; k++ )
        for ( int j = 0; j < maxn; j++ )
            for ( int i = 0; i < maxn; i++ )
                mm[k][i][j] = 0;
}

void get_dis(){
    for ( int st = 0; st < n; st++ ){
        for ( int j = 0; j < n; j++ )
            d[j] = 100000000;
        for ( int i = 0; i < n; i++ ) vis[i] =false;
        vis[st] = true;
        d[st] = 0;
        for ( int i = 0; i < n; i++ )
            if ( d[i] > d[st] + dis[st][i])
                d[i] = d[st] + dis[st][i];

        for ( int t = 1; t < n; t++ ){
//            cout <<"st: " << st << "; "; for (int i = 0; i < n; i++ ) cout << d[i] << " "; cout << endl;
            int k, minn = 1000000;
            for ( int i = 0; i < n; i++ )
                if ( minn > d[i] && !vis[i] ){
                    minn = d[i];
                    k = i;
                }
            vis[k] = true;
            for ( int i = 0; i < n; i++ )
                if ( d[i] > d[k] + dis[k][i] )
                    d[i] = d[k] + dis[k][i];
        }

        double sum = 0;
        for ( int i = 0; i < n; i++ )
            if ( i != st )
                sum += d[i];
//        cout << sum << " " << sum/(n-1) << endl;
        a[st] = sum / (n-1);
    }
//    for ( int i = 0; i < n; i++ )cout << a[i] << " "; cout << endl;
}

double doit(){
    for ( int i = 0; i < n; i++ ){
        for ( int j = 0; j < n; j++ )
            if ( i != j )
                mm[0][i][j] = (double)(1/(double)(n-1));
        mm[0][i+n][i] = 1;
        mm[0][i+n][i+n] = 1;
    }
   // for (int i = 0; i<2*n; i++){for(int j =0; j<2*n; j++) cout << mm[0][i][j] << " "; cout << endl;}
    for (int p = 1; p <= 33; p++ ){
        for (int i = 0; i < 2*n; i++ )
            for ( int j = 0; j < 2*n; j++)
                for ( int k = 0; k < 2*n; k++ )
                    mm[p][i][j] += mm[p-1][i][k]*mm[p-1][k][j];
      //  cout <<"p: " << p << endl; for (int i = 0; i<2*n; i++){for(int j =0; j<2*n; j++) cout << mm[p-1][i][j] << " "; cout << endl;}
    }
    for ( int i = 0; i < 2*n; i++ )
        f[i] = 0;
    for ( int i = n; i < 2*n; i++ )
        f[i] = a[i-n];
    int st = 32;
    while ( p > 0 ){
      //  cout << p << " " << e[st] << endl;
        if ( p >= e[st] ){
            p -= e[st];
            for ( int i = 0; i < 2*n; i++ ){
                ff[i] = f[i];
                f[i] = 0;
            }
            for ( int i = 0; i < 2*n; i++ )
                for ( int k = 0; k < 2*n; k++ )
                    f[i] += ff[k] * mm[st][k][i];
        //    for ( int i = 0; i < 2*n; i++ ){  for ( int j = 0; j < 2*n; j++ )  cout << mm[st][i][j] << " "; cout << endl;}
        }
        st--;
    }
  //  for ( int i = 0; i < 2*n; i++ )  cout << f[i] << " "; cout << endl;
    return f[0];
}

int main(){
    freopen("C-small-attempt0.in","r", stdin);
    freopen("C-small-attempt0.out","w",stdout);
    e[0] = 1;
    for ( int i = 1; i < 40; i++ )
        e[i] = e[i-1] * 2;
    cin >> T;
    int aa, bb, cc;
    for ( tt = 1; tt <= T; tt++ ){
        cin >> n >> m >> p;
        init();
        for ( int i = 0; i < m; i++ ){
            cin >> aa >> bb >> cc;
            dis[aa-1][bb-1] = cc;
            dis[bb-1][aa-1] = cc;
        }
        get_dis();
        double res = doit();
        cout << "Case #" << tt << ": " << res << endl;
        //break;
    }
    return 0;
}

