#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<queue>
#define FI(i,a, b) for(i=a;i<=b;i++)
#define FD(i,a, b) for(i=a;i>=b;i--)

#define CL(x, y) memset(x, y, sizeof(x))
#define INF 100000000
#define MAXN ?
#include<map>
#define MAXE ?
#define pb push_back
#define ll long long
#include<vector>
#define mod 1000000007LL
using namespace std;
int i, j, k, N, M, K, a[1000], bin[10], ans, ansi, Q;
char dig[10][10] = {"1111110", "0110000", "1101101", "1111001", "0110011", "1011011", "1011111", "1110000", "1111111", "1111011"};
char str[1000][10];
int tobin(char a[]){
	int ret = 0, i, j, k;
	FI(i, 0, 6) ret = (ret * 2) + a[i] - '0';
	return ret;
}
void tostr(int x){
	int i =0;
	while(x){
		str[0][i++] = x % 2 + '0';
		x /= 2;
	}
	FI(i, i, 6) str[0][i] = '0';
	reverse(str[0], str[0] + 7);
}
int main(){
	FI(i, 0, 9) bin[i] = tobin(dig[i]);
	scanf("%d", &K);
	while(K--){
		scanf("%d", &N);
		FD(i, N, 1) scanf("%s", str[i]), a[i] = tobin(str[i]);
		M = 0;
		FI(i, 0, 127){
			FI(j, 0, 9){
				int init = j, fg =0;
				FD(k, N, 1){
					int tmp = bin[init] & i;
					if(tmp != a[k]) fg = 1;
					if(init == 0) init = 9;
					else init--;
				}
				if(!fg){ M++;
					ans = init;
					ansi = i;
				}
			}
		}
		if(M == 1){
			tostr(bin[ans] & ansi);
			printf("Case #%d: %s\n", ++Q, str[0]);
		}else printf("Case #%d: ERROR!\n", ++Q);
	
	}
}
