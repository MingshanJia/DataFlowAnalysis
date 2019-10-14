#include<iostream>
#define fr(i,a,b) for(i=a;i<=b;++i)
using namespace std;
long long ca,ti,l,p,c,ans;
int main(){
	freopen("b0.in","r",stdin);
	freopen("b0.out","w",stdout);
	cin>>ca;
	fr(ti,1,ca){
		cin>>l>>p>>c;
		ans=0;
		while(l*c<p){
			c=c*c;
			ans++;
		}
		cout<<"Case #"<<ti<<": "<<ans<<endl;
	}
}