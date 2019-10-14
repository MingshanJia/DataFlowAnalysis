#include<stdio.h>
#define max 250
int n;
int cnt1[max+5],cnt2[max+5],num[max+5],dig[max+5];
char d[max+5];
void input(){
    gets(d);
    for(n=0;d[n]!=NULL;n++){
        cnt1[n]=0;
        cnt2[n]=0;
        num[n]=0;
        dig[n]=0;
    }
}
int possible(){
    int ret=1;
/*    for(int i=0;i<5;i++){
        printf("%d %d %d\n",num[i],cnt1[i],cnt2[i]);
    }
    */
    for(int i=0;i<max;i++){
        num[i]-=cnt1[i];
        num[i+1]+=num[i]/10;
        num[i]=num[i]-(num[i]/10)*10;
        if(num[i]<0){
            num[i+1]--;
            num[i]+=10;
        }
    }
    if(num[max]<0) ret=0;
    int ran=0;
    for(int i=0;i<max;i++){
        ran+=cnt2[i]*9+cnt1[i]*8;
        if(ran<num[i]) ret=0;
        if((ran%10)<num[i]) ran=ran/10-1;
        else ran/=10;
        num[i]+=cnt1[i];
    }
//    if(ret) printf("!!!!!!\n");
    return ret;
}
void process(){
    char buf[max+5];
    int bn=0,sign=1;
    for(int i=0;i<=n;i++){
        if(d[i]==' ' || d[i]==NULL){
            for(int j=0;j<bn;j++){
                if(buf[j]=='?'){
                    if(j==0 && bn>=2){
                        cnt1[bn-1-j]++;
                        if(sign==-1) num[bn-1-j]+=10;
                    }
                    else{
                        cnt2[bn-1-j]++;
                        if(sign==-1) num[bn-1-j]+=9;
                    }
                }
                else{
                    num[bn-1-j]-=(buf[j]-'0')*sign;
                }
                dig[i-j-1]=j;
            }
            bn=0;
        }
        else{
            if(d[i]=='+') sign=1;
            else if(d[i]=='-' || d[i]=='=') sign=-1;
            else buf[bn++]=d[i];
        }
    }
    sign=1;
    bn=0;
    for(int i=0;i<n;i++){
        if(d[i]=='-' || d[i]=='=') sign=-1;
        else if(d[i]=='+') sign=1;
        if((d[i]>='0' && d[i]<='9') || d[i]=='?'){
            if(d[i]=='?'){
                if(bn==0 && (d[i+1]!=' ' && d[i+1]!=NULL)) cnt1[dig[i]]--;
                else cnt2[dig[i]]--;
                if(sign==1){
                    for(int j=(bn==0 && (d[i+1]!=' ' && d[i+1]!=NULL));j<=9;j++){
                        num[dig[i]]-=j;
                        if(possible()){
                            d[i]=j+'0';
                            break;
                        }
                        num[dig[i]]+=j;
                    }
                }
                else{
                    for(int j=9;j>=(bn==0 && (d[i+1]!=' ' && d[i+1]!=NULL));j--){
                        num[dig[i]]-=j;
                        if(possible()){
                            if(bn==0 && (d[i+1]!=' ' && d[i+1]!=NULL)) d[i]=10-j+'0';
                            else d[i]=9-j+'0';
                            break;
                        }
                        num[dig[i]]+=j;
                    }
                }
            }
            bn++;
        }
        else bn=0;
    }
}
void output(int t){
    printf("Case #%d: %s\n",t,d);
}
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n;
    scanf("%d\n",&n);
    for(int i=0;i<n;i++){
        input();
        process();
        output(i+1);
    }
    return 0;
}
