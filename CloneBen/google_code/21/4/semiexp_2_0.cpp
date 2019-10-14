#include <cstdio>

int T;
long long N;

int main()
{
	scanf("%d", &T);
	for(int t=0;t++<T;){
		scanf("%lld", &N);
		int ret = 0;
		for(int i=0;i<62;i++){
			if(N==0) break;
			if(N&(1LL << (long long)i)){
				N -= 1LL << (long long)i;
				ret++;
			}else{
				N -= 2LL << (long long)i;
				ret += 2;
			}
		}
		printf("Case #%d: %d\n", t, ret);
	}
	return 0;
}
