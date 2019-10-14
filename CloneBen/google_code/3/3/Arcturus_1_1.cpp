#include <stdio.h>
#include <algorithm>

using namespace std;

long long arr[5010];
int N;

int bsleq(long long leq){
	int lo=0, hi=N-1;
	int ans = -1;
	int mid;
	
	while(lo <= hi){
		mid = (lo + hi) / 2;
		if(arr[mid] <= leq){
			ans = mid;
			lo = mid+1;
		}
		else{
			hi = mid - 1;
		}
	}
	return ans;
}

long long Work(){
	if(N < 4) return 0;
	
	long long last = arr[0];
	arr[N] = -2;
	long long run = 1;
	long long ans = 0;
	
	long long jlast;
	long long jrun;
	
	for(int i=1; i<=N; i++){
		if(arr[i] == last) run++;
		else{
			jlast = -1;
			jrun = 0;
			
			for(int j=0; j<N; j++){
				/*
				for(int k=j+1; k<N; k++){
					if(arr[j] == arr[k]) continue;
					if(arr[j] == last) continue;
					if(arr[k] == last) continue;
					if(arr[j] + 2*last <= arr[k]) continue;
					
					ans += run*(run-1)/2;
				}
				*/
				if(arr[j] == jlast) jrun++;
				else {
					jlast = arr[j];
					jrun = 1;
				}
				
				if(arr[j] == last) continue;
				long long leq = arr[j] - 2*last;
				int k = bsleq(leq);
				//printf("i=%d j=%d last=%lld arr=%lld leq=%lld k=%d\n", i, j, last, arr[j], leq, k);
				long long num = j - k - 1;
				//printf("num = %lld\n", num);
				if(arr[k+1] <= last && arr[j] > last) num -= run;
				num -= (jrun-1);
				
				long long add = num * (run) * (run-1) / 2;
				//printf("run=%lld num=%lld add=%lld\n", run, num, add);
				ans += add;
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
	freopen("B-large.in", "r", stdin);
	freopen("B-large.out", "w", stdout);
	
	int jcase;
	
	scanf("%d", &jcase);
	for(int icase=0; icase<jcase; icase++){
		scanf("%d", &N);
		for(int i=0; i<N; i++){
			scanf("%lld", &arr[i]);
		}
		sort(arr, arr+N);
		
		long long ans = Work();
		printf("Case #%d: %lld\n", icase+1, ans);
	}
	
	return 0;
}
