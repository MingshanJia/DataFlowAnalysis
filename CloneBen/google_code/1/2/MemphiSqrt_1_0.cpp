#include<cstdio>
#include<algorithm>
#include<cstring>
#define rep(i,x,y) for(int i=x;i<=y;++i)
#define dep(i,x,y) for(int i=x;i>=y;--i)
using namespace std;
const int N=400005;
const int S=0;
const int T=(int)1e9;

int n,q,x[N],y[N],z[N];

struct node{
	node *l,*r;
	long long val;
	int tag,sz;
	
	void add(int v){
		tag+=v;
		val+=(long long)sz*v;
	}
}pool[50000000],*rt;
int cur;

inline node* newnode(){
	cur++;
	node *x=pool+cur;
	x->l=x->r=NULL;
	x->tag=x->sz=0;
	x->val=0;
	return x;
}

inline void downdata(node *x){
	if(x->l==NULL){
		x->l=newnode();
		x->l->sz=x->sz/2+(x->sz&1);
	}
	x->l->add(x->tag);
	if(x->r==NULL){
		x->r=newnode();
		x->r->sz=x->sz/2;
	}
	x->r->add(x->tag);
	x->tag=0;
}

void epoke(int *x,int n){
	int a,b,c,m;
	scanf("%d%d%d%d%d%d",&x[1],&x[2],&a,&b,&c,&m);
	rep(i,3,n)
		x[i]=((long long)a*x[i-1]+(long long)b*x[i-2]+c)%m;
}

void modify(node *x,int l,int r,int a,int b){
	//printf("?? %d %d\n",l,r);
	if(l==a && b==r){
		//puts("!!!");
		
		//printf("hhh %lld\n",x->val);
		x->add(1);
		//printf("hhh %lld\n",x->sz);
		//exit(0);
		return;
	}
	int mid=l+r>>1;
	downdata(x);
	if(b<=mid) modify(x->l,l,mid,a,b);
	else if(a>mid) modify(x->r,mid+1,r,a,b);
	else modify(x->l,l,mid,a,mid),modify(x->r,mid+1,r,mid+1,b);
	x->val=x->l->val+x->r->val;
}

int getans(node *x,int l,int r,long long k){
	//printf("l=%d,r=%d\n",l,r);
	//printf("k=%d\n",k);
	if(l==r) return l;
	downdata(x);
	//if(l==6 && r==7){
	//	printf("%d\n",x->r->val);
	//	printf("k=%d\n",k);
//		exit(0);
	//}
	
	int mid=l+r>>1;
	if(x->r->val>=k) return getans(x->r,mid+1,r,k);
	else return getans(x->l,l,mid,k-x->r->val);
}

void solve(){ 
	scanf("%d%d",&n,&q);
	epoke(x,n);
	epoke(y,n);
	epoke(z,q);
	cur=0;
	rt=newnode();
	rt->sz=T-S+1;
	rep(i,1,n) {
		int l=min(x[i],y[i]);
		int r=max(x[i],y[i]);
		modify(rt,S,T,l,r);
		//printf("%d %d\n",l,r);
		//printf("%lld\n",rt->val);
	}
	//exit(0);
	//modify(rt,S,T,8,8);
	//exit(0);
	//printf("%lld\n",rt->val);
	//exit(0);
	long long ans=0;
	rep(i,1,q){
		long long k=z[i]+1;
		//printf("k=%d\n",k);
		int num=0;
		if(k>rt->val) num=0;
		else num=getans(rt,S,T,k)+1;
		ans+=(long long)num*i;
		//printf("%d\n",num);
	}
	printf("%lld\n",ans);
	//exit(0);
}

int main(){
	freopen("1.txt","r",stdin);
	freopen("2.txt","w",stdout);
	
	int c;
	scanf("%d",&c);
	rep(i,1,c){
		printf("Case #%d: ", i);
		solve();
	}
}
