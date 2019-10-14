#include<cstdio>
int gcd(int A, int B){return A % B? gcd(B, A % B): B;}
int T, N, L, R, arr[100];
bool chk(int K){
	for(int i = 0; i < N; i++)
	    if(arr[i] % K != 0 && K % arr[i] != 0)return false;
	return true;
}
int main(){
	freopen("C-small.in", "r", stdin);
	freopen("C-small.out", "w", stdout);
	scanf("%d", &T);
	for(int t = 1; t <= T; t++){
		scanf("%d%d%d", &N, &L, &R);
		for(int i = 0; i < N; i++)
		    scanf("%d", &arr[i]);
		int ans = L;
		for(; ans <= R; ans++)
			if(chk(ans))break;
		printf("Case #%d: ", t);
		if(ans > R)puts("NO");
		else printf("%d\n", ans);
	}
}
