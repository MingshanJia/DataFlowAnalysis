#include<bits/stdc++.h>
using namespace std;

#define LL long long int
#define ULL unsigned long long int
#define MP make_pair
#define PB push_back
#define LD long double
#define MOD 1000000007

void input(){
	freopen("B-small-attempt0.in","r",stdin);
   	freopen("B-small-attempt0.out","w",stdout);
}




int main(){
input();
LL t,test=1;
LD v,d,x;
cout.precision(15);
cin>>t;
while(t--){
	cin>>v>>d;
	x=(d*9.8)*1.0/(v*v);
	if(int(x)==1){
		cout<<"Case #"<<test<<": "<<"45.00000000"<<endl;test++;
		continue;
	}
	x=asin(x);
	x=(x*1.0)*(180*1.0/3.141592654)/2;
	cout<<"Case #"<<test<<": "<<x<<endl;test++;
} 
	



return 0;
}
