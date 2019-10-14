#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

// 0-based!
//

typedef long long ll;

ll genpos(ll D, ll K, ll N){
	if(K%2==0) return (K+N)%D;
	return ((K-N)%D+D)%D;
}

ll person(ll D, ll pos, ll N){
	if(pos%2==N%2) return ((pos-N)%D+D)%D;
	else return (pos+N)%D;
}

int main(){
	int T;
	scanf("%d", &T);
	for(int tt=1;tt<=T;++tt){
		ll D, K, N;
		scanf("%lld%lld%lld", &D, &K, &N);
		--K;
		ll pos = genpos(D, K, N);
		ll left = person(D, (pos+1)%D, N);
		ll right = person(D, (pos-1+D)%D, N);
		printf("Case #%d: %lld %lld\n", tt, left+1, right+1);
	}
}
