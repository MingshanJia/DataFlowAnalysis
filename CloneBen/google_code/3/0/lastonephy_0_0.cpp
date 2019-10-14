#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<string>
#include<algorithm>
#include<iostream>
#include<queue>
#include<set>
#define mem(a,b) memset(a,b,sizeof(a))
#define MAX 100010
#define LL long long
using namespace std;

int dp[310][310][310];
string str;
char ch[310];

int main(){
	freopen("A-small-attempt0.in", "r",stdin);
	freopen("A-small-attempt0.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int ii = 1; ii <= T; ii++){
		scanf("%s", ch);
		int len = strlen(ch);
		str = ch;
		mem(dp, 127);
		dp[1][0][0] = 1;
		int inf = dp[0][1][1];
		for (int i = 2; i <= len; i++){
			for (int j = 0; j < i; j++){
				for (int k = j; k < i; k++){
					if (dp[i - 1][j][k] == inf) continue;
					dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j][k] + 1);
					for (int r = i; r <= len; r++){
						string sub = str.substr(i - 1, r - i + 1);
						int id = str.find(sub);
						if (id + r - i < i - 1){
							dp[r][id + 1][id + r - i + 1] = min(dp[r][id + 1][id + r - i + 1], dp[i - 1][j][k] + 2);
						}
						else{
							break;
						}
					}
					if (j == 0){
						break;
					}
					int ed = i + k - j;
					if (ed <= len){
						int flag = 0;
						for (int r = i, p = 0; r <= ed; r++, p++){
							if (str[r - 1] != str[j + p - 1]){
								flag = 1;
								break;
							}
						}
						if (!flag){
							dp[ed][j][k] = min(dp[ed][j][k], dp[i - 1][j][k] + 1);
						}
					}
				}
			}
		}
		int ans = inf;
		for (int i = 0; i <= len; i++){
			for (int j = 0; j <= len; j++){
				ans = min(ans, dp[len][i][j]);
			}
		}
		printf("Case #%d: %d\n",ii,ans);
	}
	return 0;
}