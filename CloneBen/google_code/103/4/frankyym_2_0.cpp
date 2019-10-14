#include<iostream>
#include<fstream>
using namespace std;

typedef long long ll;

int T;
ll A[1100];
ll B[1100];
ll F[1100];
ll n, m, X, Y, Z;
const ll S = 1000000007;

int main(){
	ifstream cin("c1.in");
	ofstream cout("c1.out");
	
	cin>>T;
	for (int Case=1; Case<=T; ++Case){
		cin>>n>>m>>X>>Y>>Z;
		for (int i=0;i<m;++i){
			int k;
			cin>>k;
			A[i] = k;
		}
		
		int cnt=0;
		for (int i=0; i<n; ++i){
			B[cnt++] = A[i%m];
			A[i%m] = (X*A[i%m] + Y*(i+1)) % Z;
		}
		
		ll ret=0;		
		for (int i=0;i<n;++i){
			F[i] = 1;
			for (int j=0;j<i;++j)
				if (B[j] < B[i]) F[i] += F[j];
			F[i] %= S;
			
			ret = (ret + F[i]) % S;
		}
		

		cout<<"Case #"<<Case<<": "<<ret<<endl;
	}	
	
	return 0;
}
