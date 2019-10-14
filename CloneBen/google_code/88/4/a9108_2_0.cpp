#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <string>

using namespace std;

long long f[1100000];

bool check(long long i,long long j){
	long long k;
	for (k=j;k<i;k+=j){
		if (f[i-k]<=j&&f[j]<=i-k) return true;
	}
	return false;
}

long long getans(long long i,long long l,long long r){
	if (r<f[i]) return (r+1-l);
	if (l>=f[i]) return 0;
	return f[i]-l;
}

int main(){
	long long a0,a1,b0,b1,o,T,ans,i,n;
	n=1000000;
	f[1]=1;
	for (i=2;i<=n;i++){
		f[i]=f[i-1];
		for (;check(i,f[i]);f[i]++);
	}
	scanf("%d",&o);
	for (T=1;T<=o;T++){
		cout<<"Case #"<<T<<": ";
		cin>>a0>>a1>>b0>>b1;
		ans=0;
		for (i=a0;i<=a1;i++){
			if (b1<=i) ans+=getans(i,b0,b1);
			else if (b0<=i) ans+=getans(i,b0,i);
		}
		for (i=b0;i<=b1;i++){
			if (a1<=i) ans+=getans(i,a0,a1);
			else if (a0<=i) ans+=getans(i,a0,i);
		}
		cout<<ans<<endl;
	}
	return 0;
}
