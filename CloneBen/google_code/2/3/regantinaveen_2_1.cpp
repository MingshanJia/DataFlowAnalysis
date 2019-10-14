#define LOCAL

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef double D;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;

#define rd(x) scanf("%d",&x)
#define rd2(x,y) scanf("%d %d",&x,&y)
#define rl(x) scanf("%lld",&x)
#define rl2(x,y) scanf("%lld %lld",&x,&y)
#define wd(x) printf("%d" ,x)
#define wd2(x,y) printf("%d %d",x,y)
#define wl(x) printf("%lld",x)
#define wl2(x,y) printf("%lld %lld",x,y)
#define PC(x) putchar(x)
#define GC() getchar()
#define NL printf("\n")
#define SP printf(" ")

#define F first
#define S second
#define MP make_pair
#define PB push_back

#define fr(i,s,e) for(int i=s;i<e;i++)
#define frr(i,s,e) for(int i=s-1;i>=e;i--)
#define frv(i,a) for(int i = 0;i<(int)a.size();i++)
#define frvr(i,a) for(int i = a.size()-1;i>=0;i--)
#define tr(i,a) for(typeof(a.begin()) i = a.begin(); i != a.end();i++)

#ifdef LOCAL
#define E1(a) cout<<#a<<":" <<a<<endl;
#define E2(a,b) cout<<#a<<":" <<a<<" " <<#b<<":" <<b<<endl;
#define E3(a,b,c) cout<<#a<<":" <<a<<" " <<#b<<":" <<b<<" "<<#c<<":"<<c<<endl;
#define E4(a,b,c,d) cout<<#a<<":" <<a<<" " <<#b<<":" <<b<<" "<<#c<<":"<<c<< " "<<#d<< ":"<<d<<endl;
#define INP freopen("input","r",stdin);
#define OUT freopen("output","w",stdout);
#else
#define E1(a)
#define E2(a,b)
#define E3(a,b,c)
#define E4(a,b,c,d)
#define INP
#define OUT
#endif

#define mod 1000000007
#define maxn 109
#define maxr 100009

#define rw 109
#define co 109


struct matrix{
	D a[rw][co];
	int r,c;
	matrix(int n=0,int m=0){
		init(n,m);
	}

	void init(int n,int m){
		r = n;c = m;
		//initialize matrix if you want
		fr(i,0,r){
			fr(j,0,c){
				a[i][j] = 0;
			}
		}
	}




};






//a.c should be equal to b.r
matrix operator*(matrix a,matrix b){
	matrix c(a.r,b.c);
	fr(i,0,c.r){
		fr(j,0,c.c){
			c.a[i][j] = 0;
			fr(k,0,a.c){
				c.a[i][j] += a.a[i][k]*b.a[k][j];
			}
		}
	}
	return c;
}


//dimensions of a and b should be equal
matrix operator+(matrix a,matrix b){
	matrix c(a.r,a.c);
	fr(i,0,c.r){
		fr(j,0,c.c){
			c.a[i][j] = a.a[i][j] + b.a[i][j];
		}
	}
	return c;
}


//dimensions of a and b should be equal
matrix operator-(matrix a,matrix b){
	matrix c(a.r,a.c);
	fr(i,0,c.r){
		fr(j,0,c.c){
			c.a[i][j] = a.a[i][j] - b.a[i][j];
		}
	}
	return c;
}

//returns identity matrix - store it somewhere after calling
matrix getI(int n){
	matrix c(n,n);
	fr(i,0,n)fr(j,0,n)c.a[i][j] = (i==j);
	return c;
}



void print(matrix m){
	cout<<m.r<<" "<<m.c<<endl;
	fr(i,0,m.r){
		fr(j,0,m.c){
			cout<<m.a[i][j]<<" ";
		}
		cout<<endl;
	}
}

matrix pw(matrix a,ll p){
//	cerr<<p<<endl;
	matrix x = getI(a.r);
	while(p){
		if(p&1){x = x*a;}
		a = a*a;
		p /=2;
	}
	return x;
}



//am=>adj matrix, dis[i][j][k] - dis from i to j using first k vertices
//if there is no edge between i and j, keep it as inf
void floyd_warshall(int n,ll am[][maxn],ll dis[][maxn][maxn]){
	fr(k,0,n+1){
		fr(i,1,n+1){
			fr(j,1,n+1){
				dis[i][j][k] = (k==0) ? am[i][j] : min(dis[i][j][k-1],dis[i][k][k-1]+dis[k][j][k-1]);
			}
		}
	}
}


ll am[maxn][maxn];
ll dis[maxn][maxn][maxn];


#define INF 100000000000000000LL



matrix B,C,M,I,Z;
matrix tmp;


map<int,matrix> mp;


//void calc(int p){
//	cerr<<p<<endl;
//	if(mp.find(p)==mp.end()){
//		calc(p/2);
//		tmp = mp[p/2];
//		if(p&1){
//			mp[p] =  tmp + pw(B,p/2)*tmp;
//		}
//		else{
//			mp[p] = tmp + (pw(B,p/2)*B)*(I + tmp);
//		}
//	}
//}


matrix pr[40],pww[40];

matrix RS,ret;


matrix go(ll p){
//	E1(p);
	pr[0] = B;
	pww[0] = B;
	ll x = 1;
	while((1<<ll(x))<=p){
		pww[x] = pww[x-1]*pww[x-1];
		pr[x] = pr[x-1]+pww[x-1]*pr[x-1];
		x++;
	}

	RS = I;
	ret = Z;
	while(p&&x>=0){
		while((1<<ll(x))>p)x--;
		if(x<0)break;
		ret = ret + RS*pr[x];
		RS = RS*pww[x];
		p -= (1<<ll(x));
//		E2(p,x);
//		print(ret);
	}
//	print(ret);
	return ret;
}


int main(){
//	freopen("input","r",stdin); //check 1 2 3 check large p
	freopen("input.in","r",stdin);
	freopen("output","w",stdout);
	int t;
	rd(t);
	int cc = 0;
	while(t--){
		cerr<<t<<endl;
		mp.clear();
		cc++;
		int n,m,p;
		rd2(n,m);
		rd(p);

		fr(i,1,n+1){
			fr(j,1,n+1){
				am[i][j] = INF;
				if(i==j)am[i][j] = 0;
			}
		}

		fr(i,0,m){
			int u,v,c;
			rd2(u,v);
			rd(c);
			am[u][v] = min(am[u][v],ll(c));
			am[v][u] = min(am[v][u],ll(c));
		}

		floyd_warshall(n,am,dis);

//		cerr<<"HI"<<endl;
		B.init(n,n);
		C.init(n,n);
		M.init(n,n);
		I = getI(n);
		Z.init(n,n);
		fr(i,0,n){
			C.a[0][i] = 0;
			fr(j,0,n){
				if(i==j)B.a[i][j] = 0;
				else B.a[i][j] = 1.0/D(n-1);
				C.a[0][i] += dis[i+1][j+1][n];
			}
			C.a[0][i] /= D(n-1);
		}

//		cerr<<"HI"<<endl;
		matrix MP = M*pw(B,p) + C*(I + go(p-1));
//		cerr<<"HI"<<endl;

		D ans = MP.a[0][0];

		printf("Case #%d: %.10f\n",cc,ans);



	}
}
