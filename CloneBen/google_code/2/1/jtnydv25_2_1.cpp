#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 10;

#define ld double
#define ll long long
const ld eps = 1e-8;
inline ld add(ld x, ld y){ return x + y;}
inline ld sub(ld x, ld y){ return x - y;}
inline ld mul(ld x, ld y){ return x * y;}
inline ld powr(ld a, long long b){
    ld x = 1;
    while(b){
        if(b & 1) x = mul(x, a);
        a = mul(a, a);
        b >>= 1;
    }
    return x;
}
inline ld inv(ld a){ return 1./a;}
inline bool double_equal(ld a, ld b){ return abs(a - b) <= eps;}
const int N = 205;
struct matrix{
    ld B[N][N], n;
    matrix(){n = N; memset(B,0,sizeof B);}
    matrix(int _n){
        n = _n; memset(B, 0, sizeof B);
    }
    void iden(){for(int i = 0; i < n; i++) B[i][i] = 1;}
    void operator += (matrix M){
        for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) B[i][j] = add(B[i][j], M.B[i][j]);
    }
    void operator -= (matrix M){
        for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) B[i][j] = sub(B[i][j], M.B[i][j]);
    }
    void operator *= (ld b){
        for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) B[i][j] = mul(b, B[i][j]);
    }
    matrix operator - (matrix M){
        matrix ret = (*this); ret -= M; return ret;
    }
    matrix operator + (matrix M){
        matrix ret = (*this); ret += M; return ret;
    }   
    matrix operator * (matrix M){
        matrix ret = matrix(n); memset(ret.B, 0, sizeof ret.B);
        for(int i = 0; i < n; i++) 
            for(int j = 0; j < n;j++)
                for(int k = 0; k < n; k++){
                    ret.B[i][j] = add(ret.B[i][j], mul(B[i][k], M.B[k][j]));
                }
        return ret;
    }
    matrix operator *= (matrix M){ *this = ((*this) * M);}
    matrix operator * (int b){
        matrix ret  = (*this); ret *= b; return ret;
    }
    matrix power(ll _n){
        matrix I = matrix(n), A = (*this); I.iden();
        for(;_n != 0; A *= A, _n >>= 1) if(_n & 1) I *= A;
        return I;    
    }
    bool operator == (matrix M){
        for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) if(!double_equal(B[i][j], M.B[i][j])) return 0; return 1;
    }
    void print_matrix(){
        for(int i = 1; i < n; i++){ for(int j = 1; j < n; j++) cerr << setprecision(5) << fixed <<B[i][j] << " "; cerr << endl;}
            cerr << endl;
    }
};

int D[N][N];
double f[N];
int main(){
	int t = 1;
	cin >> t;
	for(int tt = 1; tt <= t; tt++){
		cerr << tt << endl;
		int n, m, p, u, v, d;
		cin >> n >> m >> p;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++)
				D[i][j] = INF;
			D[i][i] = 0;
		}
		for(int i = 1; i <= m; i++){
			cin >> u >> v >> d;
			D[u][v] = D[v][u] = d;
		}

		for(int k = 1; k <= n; k++){
		    for(int i = 1; i <= n; i++){
	    		for(int j = 1; j <= n; j++)
	       			if(D[i][j] > D[i][k] + D[k][j])
	           			D[i][j] = D[i][k] + D[k][j];
		    }
		}	
		memset(f, 0, sizeof f);
		for(int i = 1; i <= n;i++){
			for(int j = 1;j <= n; j++)
				f[i] += D[i][j];
			f[i] /= (n - 1);
		}

		// Fi = fi + sum_{j \ne i} F'i
		matrix mat(2 * n + 1);
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++){
				if(i != j)
					mat.B[i][j] = 1./(n - 1);
			}
		for(int i = 1; i <= n; i++){
			mat.B[i][n + i] = 1;
			mat.B[n + i][n + i] = 1;
		}


		// for(int i = 1;i <= n; i++){
		// 	for(int j = 1; j <= n; j++) cerr << D[i][j] << " ";
		// 		cerr << endl;
		// }
		// mat.print_matrix();
		matrix M = mat.power(p);
		// M.print_matrix();
		double ans = 0;
		for(int i = 1; i <= 2 * n; i++){
			double x = ((i <= n) ? 0 : f[i - n]);
			ans += M.B[1][i] * x;
		}


		cout << "Case #" << tt << ": " << setprecision(10) << fixed << ans << endl;
	}
}