#include<stdio.h>
#define maxn 10000
#define maxp 100
#define maxm 1000
#define LIM -1
struct _LIST{
    int who,val;
    _LIST *next;
};
struct _HEAP{
    int who,whe,dis;
};
int n,p,m;
int hn;
int res;
int cnt[maxn+5];
int x[maxp+5],v[maxp+5];
int d[maxm+5],l[maxm+5];
int dis[maxp+5][maxn+5],inv[maxp+5][maxn+5];
_HEAP h[maxn*maxp+5];
_LIST *list[maxn+5];
void insert(int a,int b,int c){
    _LIST *mk=new _LIST;
    mk->next=list[a];
    list[a]=mk;
    list[a]->who=b;
    list[a]->val=c;
}
bool compare(_HEAP a,_HEAP b){
    if(a.dis==LIM && b.dis==LIM) return 0<0;
    else if(a.dis==LIM) return 1<0;
    else if(b.dis==LIM) return 0<1;
    return a.dis*v[a.who]<b.dis*v[b.who];
}
void input(){
    scanf("%d%d%d",&n,&p,&m);
    for(int i=0;i<p;i++){
        scanf("%d%d",&x[i],&v[i]);
    }
    for(int i=0;i<m;i++){
        scanf("%d%d",&d[i],&l[i]);
        int c1,c2;
        for(int j=0;j<l[i];j++){
            scanf("%d",&c2);
            if(j>0){
                insert(c1,c2,d[i]);
                insert(c2,c1,d[i]);
            }
            c1=c2;
        }
    }
}
void swap(int a,int b){
    _HEAP t1=h[a];
    h[a]=h[b];
    h[b]=t1;
    int t2=inv[h[a].who][h[a].whe];
    inv[h[a].who][h[a].whe]=inv[h[b].who][h[b].whe];
    inv[h[b].who][h[b].whe]=t2;
}
void up(int x){
    while(x/2>0){
        if(compare(h[x],h[x/2])){
            swap(x,x/2);
            x/=2;
            continue;
        }
        break;
    }
}
void down(int x){
    while(x*2<=hn){
        int flag=1;
        if(x*2+1>hn || compare(h[x*2],h[x*2+1])) flag=0;
        if(compare(h[x*2+flag],h[x])){
            swap(x,x*2+flag);
            x=x*2+flag;
            continue;
        }
        break;
    }
}
void push(int who,int whe,int dis){
    hn++;
    h[hn].who=who;
    h[hn].whe=whe;
    h[hn].dis=dis;
    inv[h[hn].who][h[hn].whe]=hn;
    up(hn);
}
_HEAP pop(){
    _HEAP ret=h[1];
    inv[h[hn].who][h[hn].whe]=1;
    inv[h[1].who][h[1].whe]=0;
    h[1]=h[hn];
    hn--;
    down(1);
    return ret;
}
void process(){
    hn=0;
    for(int i=0;i<p;i++){
        for(int j=1;j<=n;j++){
            dis[i][j]=LIM;
            inv[i][j]=0;
            if(j==x[i]) dis[i][j]=0;
            push(i,j,dis[i][j]);
            cnt[j]=0;
        }
    }
    res=-1;
    while(hn>0){
        _HEAP now=pop();
//        printf("%d %d %d\n",now.who,now.whe,now.dis);
        if(now.dis==LIM) break;
        cnt[now.whe]++;
        if(cnt[now.whe]==p){
            res=now.dis*v[now.who];
            break;
        }
        for(_LIST *i=list[now.whe];i!=NULL;i=i->next){
            if(dis[now.who][i->who]==LIM || dis[now.who][i->who]>now.dis+i->val){
                dis[now.who][i->who]=now.dis+i->val;
                h[inv[now.who][i->who]].dis=dis[now.who][i->who];
                up(inv[now.who][i->who]);
                down(inv[now.who][i->who]);
            }
        }
    }
    for(int i=1;i<=n;i++){
        while(list[i]!=NULL){
            _LIST *temp=list[i]->next;
            delete(list[i]);
            list[i]=temp;
        }
    }
}
void output(int t){
    printf("Case #%d: %d\n",t,res);
}
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        input();
        process();
        output(i+1);
    }
    return 0;
}
