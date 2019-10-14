#include<cstdio>
#include<algorithm>
using namespace std;
long long int P[3][3],n,a,b,c,d,e,f,res;
int T,t;
void back(long long int now,long long int aa,long long int bb,long long int cc,long long int dd,long long int ee,long long int ff){
	if(aa+bb+cc+dd+ee+ff==0){
		if(res<now) res=now;
		return;
	}
	if(aa){
		if(dd) back(now+P[0][0]*min(aa,dd),aa-min(aa,dd),bb,cc,dd-min(aa,dd),ee,ff);
		if(ee) back(now+P[0][1]*min(aa,ee),aa-min(aa,ee),bb,cc,dd,ee-min(aa,ee),ff);
		if(ff) back(now+P[0][2]*min(aa,ff),aa-min(aa,ff),bb,cc,dd,ee,ff-min(aa,ff));
	}
	if(bb){
		if(dd) back(now+P[1][0]*min(bb,dd),aa,bb-min(bb,dd),cc,dd-min(bb,dd),ee,ff);
		if(ee) back(now+P[1][1]*min(bb,ee),aa,bb-min(bb,ee),cc,dd,ee-min(bb,ee),ff);
		if(ff) back(now+P[1][2]*min(bb,ff),aa,bb-min(bb,ff),cc,dd,ee,ff-min(bb,ff));
	}
	if(cc){
		if(dd) back(now+P[2][0]*min(cc,dd),aa,bb,cc-min(cc,dd),dd-min(cc,dd),ee,ff);
		if(ee) back(now+P[2][1]*min(cc,ee),aa,bb,cc-min(cc,ee),dd,ee-min(cc,ee),ff);
		if(ff) back(now+P[2][2]*min(cc,ff),aa,bb,cc-min(cc,ff),dd,ee,ff-min(cc,ff));
	}
}
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int i,j;
	for(scanf("%d",&T),t=1; T--; t++){
		scanf("%lld%lld%lld%lld%lld%lld%lld",&n,&a,&b,&c,&d,&e,&f);
		for(i=0; i<3; i++)
			for(j=0; j<3; j++) scanf("%lld",&P[i][j]);
		res=0x7fffffffffffffff+1;
		back(0,a,b,c,d,e,f);
		printf("Case #%d: %d\n",t,res);
		fprintf(stderr,"Case #%d: %d\n",t,res);
	}
	return 0;
}