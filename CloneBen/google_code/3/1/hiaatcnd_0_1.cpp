#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define ll long long
#define M 1000000007
#define all(a) a.begin(), a.end()

int f[310][310][310];
char s[310];
int T, ca = 0;
bool eq[310][310][310];

inline void ckmin(int &a, int b){
	(a > b) && (a = b);
}

int main(){
	freopen("A-large.in", "r", stdin);
	freopen("a.out", "w", stdout);
	scanf("%d", &T);
	while(T--){
		scanf("%s", s + 1);
		int n = strlen(s + 1);
		memset(f, 127, sizeof(f));

		f[1][1][0] = 1;
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= n; ++j)
				eq[1][i][j] = s[i] == s[j];
		for(int len = 2; len <= n; ++len)
			for(int i = 1; i + len - 1 <= n; ++i)
				for(int j = 1; j + len - 1 <= n; ++j)
					eq[len][i][j] = eq[len - 1][i][j] && s[i + len - 1] == s[j + len - 1];
		
		for(int i = 1; i <= n; ++i){
			int t = 1e9;
			for(int j = 1; j <= i; ++j)
				for(int l = 0; j + l - 1 <= i; ++l)
					t = min(f[i][j][l], t);
			if(i == n){
				printf("Case #%d: %d\n", ++ca, t);
				break;
			}
			
			for(int j = 1; j <= i; ++j)
				for(int l = 1; j + l - 1 <= i; ++l)
					f[i][j][l] = min(f[i][j][l], t + 1);

			for(int j = 1; j <= i; ++j)
				for(int l = 0; j + l - 1 <= i; ++l){
					if(eq[l][j][i + 1])
						ckmin(f[i + l][j][l], f[i][j][l] + 1);
					ckmin(f[i + 1][j][l], f[i][j][l] + 1);
				}
		}
	}
	return 0;
}
