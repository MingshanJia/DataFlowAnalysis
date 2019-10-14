#include <cstdio>
#include <cmath>
#include <algorithm>
#include <map>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <set>
#include <cstring>
#include <string>
#define LL long long int

#define FOR(i, s, e) for (int i=(s); i<(e); i++)
#define FOE(i, s, e) for (int i=(s); i<=(e); i++)
#define FOD(i, s, e) for (int i=(s)-1; i>=(e); i--)
#define CLR(x, a) memset(x, a, sizeof(x))

#define N 100005

using namespace std;

char m1[20][20] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
char m2[20][20] = {"", "", "double ", "triple ", "quadruple ", "quintuple ", "sextuple ", "septuple ", "octuple ", "nonuple ", "decuple "};

int n, c[N], TC;
char ret[N], num[N];

void Solve(int cas){
	printf("Case #%d: ", cas);
	scanf("%s", num);
	n = strlen(num);
	int cur = 0, cnt = 0;
	scanf("%d", &c[cur]);
	cnt += c[cur++];
	while (cnt < n){
		scanf("-%d", &c[cur]);
		cnt += c[cur++];
	}
	
	int pos = 0, len = 0;
	CLR(ret, 0);
	FOR(i, 0, cur){
		//printf("C[%d] = %d\n", i, c[i]);
		int last = -1, cnt = 0;
		FOE(j, pos, pos + c[i])
			if (last == -1 || num[j] != num[j - 1] || j == pos + c[i]){
				if (last != -1){
					//printf("  [%d %d]\n", last - '0', cnt);
					if (cnt <= 10){
						sprintf(ret + len, "%s%s ", m2[cnt], m1[last - '0']);
						len = strlen(ret);
					}
					else {
						FOR(j, 0, cnt){
							sprintf(ret + len, "%s ", m1[last - '0']);
								len = strlen(ret);
						}
					}
				}
				last = num[j], cnt = 1;
			}
			else cnt++;
		pos += c[i];
	}
	
	ret[len - 1] = 0;
	printf("%s\n", ret);
	
}


int main(){
	scanf("%d", &TC);
	FOE(i, 1, TC) Solve(i);
	return 0;
}
