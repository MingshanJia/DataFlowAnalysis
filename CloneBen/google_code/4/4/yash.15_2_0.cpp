#include <bits/stdc++.h>
using namespace std;
vector<string> s;
#define mod 1000000007
int dp[5000][5000];

bool check(string st,string &s2){
	sort(st.begin(), st.end());
	return st==s2;
}

int solve(string str){
	int n=str.length(),i,j,k,l;
	memset(dp,0,sizeof dp);
	for(l=1;l<=n;l++)
		for(i=0;i+l<=n;i++){
			j=i+l-1;
			for(k=0;k<s.size();k++){
				if(s[k].length()>l)
					continue;
				if(check(str.substr(i,s[k].length()),s[k])){
					if(s[k].length()==l)
						dp[i][j]++;
					else
						dp[i][j]+=dp[i+s[k].length()][j];
					if(dp[i][j]>=mod)
						dp[i][j]-=mod;
				}
		}
	}
	return dp[0][n-1];
}

char str[100000];
string str2;
int main(){
	int tt,t=1;
	int n,m,i,j,k,ans;
	cin >>tt;
	while(tt--) {
		printf("Case #%d:",t++);
		cin >> n >> m;
		s.clear();
		for(i=0;i<n;i++){
			scanf(" %s",str);
			sort(str,str+strlen(str));
			str2=str;
			s.push_back(str2);
		}
		while(m--){
			ans=0;
			scanf(" %s",str);
			str2=str;
			ans=solve(str2);
			printf(" %d",ans);
		}
		puts("");
	}
	return 0;
}