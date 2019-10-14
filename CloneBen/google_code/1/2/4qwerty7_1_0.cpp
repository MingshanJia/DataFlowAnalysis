#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
const int N=4e5+100;
ll L[N],R[N],Q[N];
int id[N];
ll ans;
void gen(ll*D,int n){
	ll a,b,c,m;
	scanf("%lld%lld%lld%lld%lld%lld",D,D+1,&a,&b,&c,&m);
	for(int i=2;i<n;i++){
		D[i]=(a*D[i-1]+b*D[i-2]+c)%m;
	}
}
pair<ll,int>V[2*N];
inline bool qcmp(const int&a,const int&b){
	return Q[a]<Q[b];
} 
int main(){
	int T;
	scanf("%d",&T);
	for(int iid=1;iid<=T;iid++){
		ans=0;
		int n,q;
		scanf("%d%d",&n,&q); 
		gen(L,n);gen(R,n);gen(Q,q);
		int vc=0;
		for(int i=0;i<n;i++){
			ll a=L[i],b=R[i];
			L[i]=min(a,b)+1;
			R[i]=max(a,b)+1;
			V[vc++]=make_pair(L[i]-1,-1);
			V[vc++]=make_pair(R[i],1);
		}
		for(int i=0;i<q;i++)Q[i]++,id[i]=i;
		sort(id,id+q,qcmp);
		sort(V,V+vc,greater< pair<ll,int> >());
		int cq=0;
		ll cur=V[0].first,cnt=0,mul=0;
		for(int i=0;i<vc;i++){
			ll nxt=V[i].first;
			ll nc=cnt+mul*(cur-nxt);
			
			//printf("%lld %lld %lld %lld %lld\n",cur,nxt,cnt,nc,mul);
			while(cq<q && Q[id[cq]]<=nc){
				ll s=cur-(Q[id[cq]]-cnt-1)/mul;
				ans+= (1ll+id[cq]) * s; 
				//printf("ANS:%lld %lld\n",Q[id[cq]],s);
				cq++;
			}
			mul+=V[i].second;
			if(cq>=q)break;
			cur=nxt;
			cnt=nc;
		}
		printf("Case #%d: %lld\n",iid,ans);
	} 
} 
