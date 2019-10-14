#include <bits/stdc++.h>
using namespace std;

const double pi = 3.14159265358979323846;

const int MOD = 1440;
const int each = 720;
int f[1600][800][2][2];
bool cam[1600], jam[1600];

void minimize(int& res, int newValue){
	if (res > newValue)
		res = newValue;
}

void solve(){
	memset(f, 0x3f, sizeof f);
	memset(cam, true, sizeof cam);
	memset(jam, true, sizeof jam);
	
	int nc, nj;
	scanf("%d%d",&nc,&nj);
	for(int i = 0; i < nc; ++i){
		int l, r;
		scanf("%d%d",&l,&r);
		for(int k = l; k < r; ++k)
			cam[k] = false;
	}
	
	for(int i = 0; i < nj; ++i){
		int l, r;
		scanf("%d%d",&l,&r);
		for(int k = l; k < r; ++k)
			jam[k] = false;
	}
	
	int res = f[0][0][0][0];
	if (cam[0])
		f[0][1][0][0] = 0;
	if (jam[0])
		f[0][0][1][1] = 0;
	
	for(int t = 0; t+1 < MOD; ++t)
		for(int turn_cam = 0; turn_cam <= each; ++turn_cam)
			for(int last = 0; last < 2; ++last)
				for(int start= 0; start < 2; ++start){					
					for(int cur = 0; cur < 2; ++cur){
						if (cur == 0 && !cam[t+1]) continue;
						if (cur == 1 && !jam[t+1]) continue;
						
						int cur_turncam = turn_cam + (cur == 0);
						int num = f[t][turn_cam][last][start] + (cur != last);
						minimize(f[t+1][cur_turncam][cur][start], num);					
					}					
				}
		
	for(int start = 0; start < 2; ++start)
		for(int last = 0; last < 2; ++last){
			int cur = f[MOD-1][each][last][start] + (last != start);
			minimize(res, cur);
		}
		
	printf("%d\n",res);
	
		
	
		
	
	
	
}

int main(){
	freopen("file.out","w",stdout);
	
	int test; scanf("%d",&test);	
	for(int t = 1; t <= test; ++t){
		printf("Case #%d: ", t);
		solve();
	}
	
}