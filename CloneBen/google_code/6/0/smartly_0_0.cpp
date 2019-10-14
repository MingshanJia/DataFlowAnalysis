#include<bits/stdc++.h>
#define N 105
using namespace std;
string s[N];int m,n;
int cmp(const string &A,const string &B){
	return A.length()<B.length();
}
int main(){
	freopen("A-small-attempt0.in","r",stdin);
	freopen("A-small-attempt0.out","w",stdout);
	int T,Case=0;cin>>T;
	while (T--){
		cin>>m>>n;
		for (int i=1;i<=n;i++)
			cin>>s[i];
		sort(s+1,s+n+1,cmp);
		long long ans=0;
		for (int i=1;i<=n;i++){
			int ok=1;
			for (int j=1;j<i&&ok;j++)
				if (s[j].length()<s[i].length())
					if (s[i].substr(0,s[j].length())==s[j])
						ok=0;
			if (ok)
				ans+=1ll<<(m-s[i].length());
		}
		printf("Case #%d: %lld\n",++Case,(1ll<<m)-ans);
	}
}
