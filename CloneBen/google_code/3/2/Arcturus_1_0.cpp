#include <stdio.h>
#include <algorithm>

using namespace std;

long long arr[5010];
int N;

int Work(){
	if(N < 4) return 0;
	
	long long last = arr[0];
	arr[N] = -2;
	int run = 1;
	int ans = 0;
	
	for(int i=1; i<=N; i++){
		if(arr[i] == last) run++;
		else{
			for(int j=0; j<N; j++){
				for(int k=j+1; k<N; k++){
					if(arr[j] == arr[k]) continue;
					if(arr[j] == last) continue;
					if(arr[k] == last) continue;
					if(arr[j] + 2*last <= arr[k]) continue;
					
					ans += run*(run-1)/2;
				}
			}
			if(run > 2){
				for(int j=0; j<N; j++){
					if(arr[j] >= last*3) continue;
					if(arr[j] == last) continue;
					
					ans += run*(run-1)*(run-2)/6;
				}
			}
			
			run = 1;
			last = arr[i];
		}
	}
	
	return ans;
}

int main(){
	freopen("B-small-attempt1.in", "r", stdin);
	freopen("B-small-attempt1.out", "w", stdout);
	
	int jcase;
	
	scanf("%d", &jcase);
	for(int icase=0; icase<jcase; icase++){
		scanf("%d", &N);
		for(int i=0; i<N; i++){
			scanf("%lld", &arr[i]);
		}
		sort(arr, arr+N);
		
		int ans = Work();
		printf("Case #%d: %d\n", icase+1, ans);
	}
	
	return 0;
}
