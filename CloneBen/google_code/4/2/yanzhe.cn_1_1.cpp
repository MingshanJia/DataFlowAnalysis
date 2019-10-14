#include <iostream>
using namespace std;

struct single{
    int max;
    int repeat;
};
single get_single(int n){
    single s;
    if(n%3==0){
        s.max=n/3*2;
        s.repeat=3;
    } else if(n%3==1){
        s.max=n/3*2+1;
        s.repeat=2;
    } else {
        s.max=n/3*2+2;
        s.repeat=1;
    }
    return s;
}
int calculate(int R,int C){
    single s=get_single(C);
    if(R<=2){
        return s.max * R;
    }
    // C= 3n
    if(s.repeat==3){
        return R*s.max;
    }
    if(s.repeat==2){
        int sum=(R/3)*2*s.max+(R/3)*(s.max-1);
        sum+=(R%3)*s.max;
        return sum;
    }
    if(s.repeat==1){
        int sum=(R/3)*s.max+(R/3)*2*(s.max-1);
        if(R%3==1){
            sum+=s.max;
        } else if(R%3==2){
            sum+=s.max+s.max-1;
        }
        return sum;
    }
    return 0;
}

int main(){
    int T;
    cin>>T;
    for(int i=0;i<T;i++){
        int R,C;
        cin>>R>>C;
        cout<<"Case #"<<i+1<<": "<<max(calculate(R,C),calculate(C,R))<<endl;
    }

}