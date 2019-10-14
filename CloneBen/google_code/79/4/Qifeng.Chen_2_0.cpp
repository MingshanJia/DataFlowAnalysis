#include<iostream>
#include<stdio.h>
#define fr(i,a,b) for(i=a;i<=b;++i)
using namespace std;
const int maxn=10002;
int ti,ca,i,ans,j,n,l,h,x[maxn];
bool ok(int r){
	int i;
	fr(i,1,n)
		if(r%x[i]!=0&&x[i]%r!=0)
			return false;
	return true;
}
int main(){
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	cin>>ca;
	fr(ti,1,ca){
		cin>>n>>l>>h;
		fr(i,1,n)
			cin>>x[i];
		ans=-1;
		fr(j,l,h)
			if(ok(j)){
				ans=j;
				break;
			}
		if(ans<0)
			cout<<"Case #"<<ti<<": NO"<<endl;
		else
			cout<<"Case #"<<ti<<": "<<ans<<endl;
	}
}