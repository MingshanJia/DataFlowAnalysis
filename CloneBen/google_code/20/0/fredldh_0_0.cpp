#include<stdio.h>
int n;
long long int month,date,day;
long long int res;
long long int gcd(long long int a,long long int b){
    if(a==0) return b;
    if(b==0) return a;
    if(a>b) return gcd(a%b,b);
    return gcd(a,b%a);
}
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%lld%lld%lld",&month,&date,&day);
        res=(month*date+day-1)/day+month-1;
        res-=(month*date-1)/(day*date/gcd(day,date));
        printf("Case #%d: %lld\n",i+1,res);
    }
    return 0;
}
