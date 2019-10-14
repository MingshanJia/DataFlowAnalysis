#include <iostream>
#include <vector>
using namespace std;

struct band{
    uint64_t A;
    uint64_t B;
    uint64_t P;
};

int main(){
    uint64_t T;
    cin>>T;
    for(int t=1;t<=T;t++){
        uint64_t N,M,L;
        cin>>N>>M>>L;
        vector<band> vec_bands;
        for(int n=0;n<N;n++){
            band b;
            cin>>b.A>>b.B>>b.P;
            vec_bands.push_back(b);
        }
        vector<vector<uint64_t> > dp;
        dp.resize(N);
        for(int n=0;n<N;n++){
            dp[n].resize(L+1,-1);
            dp[n][0]=0;
        }
        for(int len=vec_bands[0].A;len<=min(vec_bands[0].B,L);len++ ){
            dp[0][len]=vec_bands[0].P;
        }
        for(int n=0;n<N-1;n++){
            for(int len=0;len<=L;len++){
                //calculate dp[n][len]
                if(dp[n+1][len]==-1|| dp[n+1][len]> dp[n][len]){
                    dp[n+1][len]=dp[n][len];
                }
                if(dp[n][len]!=-1){
                    for(int iter=len+vec_bands[n+1].A; iter<= min(len+vec_bands[n+1].B,L);iter++){
                        if(dp[n+1][iter]==-1 || dp[n+1][iter]> dp[n][len]+vec_bands[n+1].P)
                            dp[n+1][iter]=dp[n][len]+vec_bands[n+1].P;
                    }
                }
            }
        }
        // for(int i=0;i<dp.size();i++){
        //     for(int j=0;j<dp[i].size();j++){
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        if(dp[N-1][L]!=-1 && dp[N-1][L]<= M){
            cout<<"Case #"<<t<<": "<<dp[N-1][L]<<endl;
        }else {
            cout<<"Case #"<<t<<": IMPOSSIBLE"<<endl;
        }

    }
}