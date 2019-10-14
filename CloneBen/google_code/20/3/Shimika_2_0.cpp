#include <queue>
#include <cstdio>
#include <vector>
#include <algorithm>
#define INF 2147480000
using namespace std;
pair<int,int> a[105];
int n,p,m,dy[10005],ck[10005],s[10005];
vector<pair<int,int> > v[10005];
typedef pair<int,int> pp;
priority_queue<pp,vector<pp>,greater<pp> > q;

int recall(){
	int k,i,l,xi,len,sz,mx=INF;
	for(k=1;k<=n;k++){s[k]=0;}
	for(k=1;k<=p;k++){
		for(i=1;i<=n;i++){
			dy[i]=INF; ck[i]=0;
		}
		dy[a[k].first]=0;
		q.push(make_pair(0,a[k].first));
		do{
			len=q.top().first;
			xi=q.top().second;
			q.pop();

			sz=v[xi].size();
			for(i=0;i<sz;i++){
				if(dy[v[xi][i].first]>dy[xi]+a[k].second*v[xi][i].second){
					dy[v[xi][i].first]=dy[xi]+a[k].second*v[xi][i].second;
					//if(s[v[xi][i].first]>=0){ s[v[xi][i].first]+=dy[v[xi][i].first]; }
					q.push(make_pair(dy[v[xi][i].first],v[xi][i].first));
				}
			}
		}while(q.size());
		for(i=1;i<=n;i++){
			if(s[i]<dy[i]){s[i]=dy[i];}
		}
	}
	for(i=1;i<=n;i++){
		if(s[i]<mx){
			mx=s[i];
		}
	}
	if(mx!=INF){
		return mx;
	}
	return -1;
}

int main(){
	freopen("input.txt","r",stdin);
	FILE *fp2=fopen("output.txt","w");
	int t,i,gt,k,j,l,w,t1,t2;
	scanf("%d",&t);
	for(k=1;k<=t;k++){
		scanf("%d %d %d",&n,&p,&m);
		for(i=1;i<=p;i++){
			scanf("%d %d",&a[i].first,&a[i].second);
		}
		for(i=1;i<=n;i++){ v[i].clear(); }

		for(i=1;i<=m;i++){
			scanf("%d %d %d",&l,&w,&t1);
			for(j=2;j<=w;j++){
				scanf("%d",&t2);
				v[t1].push_back(make_pair(t2,l));
				v[t2].push_back(make_pair(t1,l));
				t1=t2;
			}
		}
		gt=recall();
		fprintf(fp2,"Case #%d: %d\n",k,gt);
		printf("Case #%d: %d\n",k,gt);
	}
	return 0;
}
