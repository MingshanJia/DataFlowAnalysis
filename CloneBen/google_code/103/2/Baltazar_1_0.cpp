#include <cstdio>
#include <cstdlib>
#include <string>
#include <list>
#include <set>
#include <map>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <cctype>
using namespace std;
#define maxlen 50
#define plus 0
#define minus 1
int nsc, sc;
char work[maxlen];
int len;
long long cnt;
void init(){
	scanf(" %s ", work);
}
void perebor(int pos, long long num, int znak, long long res){
	if (pos==len){
		if (znak==minus) res-=num;
		else res+=num;
		if (res%2==0 || res%3==0 || res%5==0 || res%7==0){
			cnt++;
		}
	}
	else{
		perebor(pos+1, num*10+work[pos]-'0', znak, res);
		if (znak==plus)
			res+=num;
		else
			res-=num;
		perebor(pos+1, work[pos]-'0', plus, res);
		perebor(pos+1, work[pos]-'0', minus, res);
	}
}
void solve(){
	len=strlen(work);
	cnt=0;
	perebor(1, work[0]-'0', plus, 0);
	printf("Case #%d: %lld\n", sc, cnt);
}
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d", &nsc);
	for(sc=1; sc<=nsc; sc++){
		init();
		solve();
	}
	return 0;
}