#include <stdio.h>
#include <algorithm>
#include <map>
#include <vector>
#include <set>
#include <string>
#include <memory.h>

#define MAX 999999999999999999ll
using namespace std;
long long Map[8][8];
long long Dd[8][8];
long long dis[8], via[8], flw[8];
int main(){
	freopen("A-large.in","r",stdin);
	freopen("A-large.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T-->0){
		memset(Map, 0, sizeof(Map));
		memset(Dd, 0, sizeof(Dd));
		long long N;
		scanf("%lld", &N);
		int i, j, k;
		for(i=0;i<3;i++){
			scanf("%lld", &Map[0][i+1]);
			Map[i+1][0] = -Map[0][i+1];
		}
		for(i=0;i<3;i++){
			scanf("%lld", &Map[i+4][7]);
			Map[7][i+4] = -Map[i+4][7];
		}
		for(i=0;i<3;i++){
			for(j=0;j<3;j++){
				scanf("%lld", &Dd[i+1][j+4]);
				Dd[j+4][i+1] = -Dd[i+1][j+4];
				Map[i+1][j+4] = N;
			}
		}
		long long sol = 0;
		static int cs = 1;
		//if (cs <= 2){ cs ++; continue;}
		while(1) {
			for(i=0;i<8;i++){
				via[i] = -1;
				dis[i] = -MAX;
				flw[i] = 0;
			}
			
			dis[0] = 0;
			flw[0] = N;
			for (i=0;i<8;i++){
				for(j=0;j<8;j++){
					for(k=0;k<8;k++){
						if (dis[j] != -MAX && Map[j][k] > 0 && 
							(dis[k] < dis[j] + Dd[j][k] || 
							dis[k] == dis[j] + Dd[j][k] && flw[k] < min(flw[j], Map[j][k])) ) {
							dis[k] = dis[j] + Dd[j][k];
							via[k] = j;
							flw[k] = min(flw[j], Map[j][k]);
						}
					}
				}
			}
			
			if (dis[7] == -MAX) break;

			int now = 7, bef;
			long long fl;
			fl = flw[7];
			sol += fl * dis[7];
			while(1) {
				bef = via[now];
				if (bef == -1) break;

				Map[bef][now] -= fl;
				Map[now][bef] += fl;

				now = bef;
			}

		}
		printf("Case #%d: %lld\n", cs++, sol);
		
	}
	return 0;
}