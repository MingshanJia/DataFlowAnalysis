#include <bits/stdc++.h>

using namespace std;
//memset
#define MEMSET_INF 127 // about 2B
#define set0(a) memset(a,0,sizeof(a));
#define setminus1(a) memset(a,-1,sizeof(a));
#define setinf(a) memset(a,MEMSET_INF,sizeof(a));

//stl
#define mp make_pair
#define pb push_back
//#define pc(x) putchar_unlocked(x)
//#define gc() getchar_unlocked()

//Loops
#define REP(i,b) for(int i = 0 ;i < (int)(b); i++)
#define REP1(i,a,b) for(int i = (int)(a);i <= (int)(b); i++)
#define REPMAP(i,mm) for(auto i = mm.begin();i !=mm.end(); i++)

//Sort
#define sortvec(vec) sort(vec.begin(), vec.end())

//Misc
#define LSOne(i) (i & (-i))	// the first Least Significant One-bit in i

//modulo
#define mod %
#define NUM 1000000007


#define LONG_LONG_MAX	9223372036854775807LL
#define LONG_LONG_MIN	(-LONG_LONG_MAX-1)

#define LMAX LONG_LONG_MAX
#define LMIN LONG_LONG_MIN
#define IMAX INT_MAX
#define IMIN INT_MIN
#define PI M_PI
#define EPS 1e-9
#define INF 1e9
#define M_PI		3.14159265358979323846
#define cin(x) scanf("%d",&x)
#define cout(x) printf("$d",x)
#define endl '\n'
#define s(n) scanf("%d",&n)
#define sll(n) scanf("%I64d",&n)
#define p(n) printf("%d",n)
#define pll(n) printf("%I64d",n)
#define all(v) (v).begin(),(v).end()

//typedef
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;
typedef map<int, int> mii;
typedef tuple<int,int,int> iii;

#define MAX_N 100005


double e[2][100005];

ll dist[105][105];

int n;

const int N = 205;
struct mat{
    double ar[N][N];
};
mat mul(mat m1, mat m2){
    mat mm;
    REP(i,2*n){
        REP(j,2*n){
            mm.ar[i][j] = 0;
            REP(k,2*n){
                mm.ar[i][j] += m1.ar[i][k] * m2.ar[k][j];
            }
        }
    }
    return mm;
}

mat powmod(mat y, ll exponent) {
    mat x;
    
    REP( i, 2*n){
        REP( j , 2*n){
            x.ar[i][j] = 0;
        }
    }
    
    REP(i,2*n){
        x.ar[i][i] = 1;
    }
    
    while(exponent > 0) {
        if(exponent%2 == 1) {
            x = mul(x,y);
        }
        
        
        y = mul(y,y);
        
        exponent /= 2;
    }
    
    return x;
}

void solve(){

    int cur = 0;
    
    
    int m , p;
    cin>>n>>m>>p;
    REP(i , n){
        REP( j , n){
            dist[i][j] = 1e18;
        }
    }
    REP(i , m){
        int x , y , z;
        cin>>x>>y>>z;
        x -- , y -- ;
        dist[x][y] = min(dist[x][y] ,(ll) z);
        dist[y][x] = min(dist[y][x] ,(ll) z);
    }
    
    
    REP( k , n){
        REP( i, n){
            REP( j , n){
                if(dist[i][k] + dist[k][j] < dist[i][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    
    REP( i, n){
        e[cur][i] = 0;
        REP( j , n){
            if(j != i){
                e[cur][i] += dist[i][j];
            }
        }
        e[cur][i] /= (n-1);
    }
    double ans  = 0;
    
    
    if(p == 1){
        ans = e[cur][0];
    }else{
        mat z;
        REP(i,n){
            REP(j,n){
                z.ar[i][j] = 1.0/(n - 1.0);
            }
        }
        REP( i, n){
            z.ar[i][i] = 0 ;
        }
        
        
        REP( i , n){
            for(int j = n; j < 2 * n; j++){
                if(j - n == i){
                    z.ar[i][j] = 1.0;
                }else{
                    z.ar[i][j] = 0.0;
                }
            }
        }
        
        for(int i = n; i < 2 * n; i ++){
            for(int j = 0; j < 2 * n ; j ++){
                if(i == j){
                    z.ar[i][j] = 1.0;
                }else{
                    z.ar[i][j] = 0;
                }
            }
        }
        
//        
//        REP(i , n){
//            REP(j , n){
//                cout.precision(10);
//                cout<<fixed<<z.ar[i][j]<<' ';
//            }
//            cout<<endl;
//        }
        
        
        z = powmod(z, p-1);
        REP( i, n){
            ans += z.ar[0][i] * e[cur][i];
        }
        
        for(int i = n; i < 2 * n; i ++){
            
            ans += z.ar[0][i] * e[cur][i-n];
        }
        
    }
    
    cout.precision(10);
    cout<<fixed<<ans;
    
    
    
    
    
    
}

int main(){
    
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(0);
    cout.sync_with_stdio(0);
    
    freopen("/Users/ritesray/Documents/io/input.in","r",stdin);
    freopen("/Users/ritesray/Documents/io/output.out","w",stdout);
    
    int TC = 1;
    cin>>TC;
    for(int ZZ=1;ZZ<=TC;ZZ++){
        cout<<"Case #"<<ZZ<<": ";
        clock_t start = clock();
        
        //		double ans;
        //		cout.precision(10);
        //		cout<<fixed<<ans<<endl;
        
        solve();
        clock_t end = clock();
        cout<<'\n';
        cerr <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    }
    return 0;
}
