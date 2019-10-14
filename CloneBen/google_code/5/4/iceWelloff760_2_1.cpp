#include<bits/stdc++.h>
using namespace std;

#define LL long long int
#define ULL unsigned long long int
#define MP make_pair
#define PB push_back
#define LD long double
#define MOD 1000000007

void input(){
	freopen("C-small-2-attempt0.in","r",stdin);
   	freopen("C-small-2-attempt0.out","w",stdout);
}




int main(){
input();
LL test=1,t,n,i,j,ans;
string s[200],str;

cin>>t;
while(t--){
	cin>>n;ans=0;
	getline(cin,str);
	for(i=0;i<n;i++){
		getline(cin,s[i]);
		for(j=0;j<i;j++){
			if(s[i].compare(s[j])<0){
			ans++;break;
			}
		}
	}
	cout<<"Case #"<<test<<": "<<ans<<endl;test++;
}


return 0;
}
