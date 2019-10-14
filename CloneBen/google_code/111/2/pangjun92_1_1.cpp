#include<vector>
#include<string>
#include<iostream>
#include<sstream>
#include<map>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
#include<set>
#include<stack>
#include<list>
#include<queue>
#include<cmath>
#include<cstdlib>
using namespace std;
pair<int,int> remain(int A, int B, int alpha, int beta,long long Y){
    
    for(long long i=0;i<Y;i++){
    int decomA=A*1/100;
    int decomB=B*1/100;
    int m=min(A,B);///# couples
    int new_born=m*2/100;///# babies
    int nb_A=new_born*alpha/100;
    int nb_B=new_born*beta/100;
    int left=new_born-nb_A-nb_B;
    //afeter day 1;
    nb_A+=left/2;
    nb_B+=left/2+left%2;
        ///after day 2;
        int A_O=A;
        int B_O=B;
        A=A-decomA+nb_A;
        B=B-decomB+nb_B;
        if(A==A_O&&B==B_O)break;
    
    }
    return make_pair(A,B);
}
int main(){
    int num_cases;
    cin>>num_cases;
    for(int line=0;line<num_cases;line++){
        int A, B, alpha,beta;
        long long Y;
        cin>>A;
        cin>>B;
        cin>>alpha;
        cin>>beta;
        cin>>Y;
       // cout<<A<<" "<<B<<" "<<alpha<<" "<<beta<<" "<<Y<<endl;
        pair<int, int> r=remain(A,B,alpha,beta,Y);
        cout<<"Case #"<<(line+1)<<":";
        cout<<" "<<r.first<<" "<<r.second<<endl;
    }
    /*for(int i=0;i<1000000;i++){
    int A=rand()%200;
    int B=rand()%200;
    int alpha=rand()%101;
    int beta;
    if(alpha==100){
        beta=0;
    }else{
        beta=rand()%(101-alpha);
    }
        A=50;
        B=51;
    long long  Y=1000000000000000L;
        cout<<A<<" "<<B<<" "<<alpha<<" "<<beta<<" "<<Y<<endl;
        pair<int, int> r=remain(A,B,alpha,beta,Y);
        cout<<"Case #"<<(i+1)<<":";
        cout<<" "<<r.first<<" "<<r.second<<endl;
    }*/
    
    return 0;
}
