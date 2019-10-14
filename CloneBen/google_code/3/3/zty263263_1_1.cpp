#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int N;

int main(){
    
    FILE *err;
    err = fopen("stderr.txt", "w");
    
    int T;
    scanf("%d", &T);
    for(int currentT=1; currentT<=T; currentT++){
        
        scanf("%d", &N);
        
        long long tmp;
        vector<long long> L;
        
        for(int i=0;i<N;i++){
            scanf("%lld", &tmp);
            L.push_back(tmp);
        }
        
        sort(L.begin(), L.end());
        
        long long result = 0;
        
        for(int i=0;i<L.size();i++){
            int sideNum=1;
            long long sideLen = L[i];
            
            int side_idx_start, side_idx_end;
            side_idx_start=i;
            while(i+1<L.size() && L[i+1]==L[i]){
                i++;
                sideNum++;
            }
            side_idx_end=i;
            if(sideNum<2)
                continue;
            
            long long numOfSideSet = 0;
            numOfSideSet = sideNum*(sideNum-1)/2;
            
            int short_idx = 0;
            int long_start_idx = 1;
            int long_end_idx = 1;
            
            while(short_idx < N){

                if(L[short_idx] == sideLen){
                    short_idx++;
                    continue;
                }
            
                while(long_start_idx<N && L[long_start_idx]<=L[short_idx])
                    long_start_idx++;
                while(long_end_idx<N && L[long_end_idx]-L[short_idx]<2*sideLen)
                    long_end_idx++;
                
                int longSideNum = long_end_idx-long_start_idx;
                if(long_start_idx<=side_idx_start && long_end_idx>side_idx_end)
                    longSideNum -= side_idx_end-side_idx_start+1;
                result += longSideNum*numOfSideSet;
                
                short_idx++;
            }
            
            //hold side*3
            if(sideNum>2){
                long long baseOptionNum = (sideNum)*(sideNum-1)*(sideNum-2)/2/3;
                for(int j=0;j<N;j++){
                    if(L[j]==sideLen)
                        continue;
                    if(sideLen-L[j]>0 && sideLen-L[j]<2*sideLen)
                        result+=baseOptionNum;
                    if(L[j]-sideLen>0 && L[j]-sideLen<2*sideLen)
                        result+=baseOptionNum;
                }
            }

        }
            
        
        fprintf(err, "T=%d\n", currentT);
        printf("Case #%d: %lld\n", currentT, result);
    }
    fclose(err);
    
    return 0;
}
    