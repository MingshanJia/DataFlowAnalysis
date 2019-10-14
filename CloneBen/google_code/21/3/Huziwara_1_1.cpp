#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

struct Cf
{
  long long c,t;
  int s;
};

bool operator<(Cf c1,Cf c2)
{
  return c1.t>c2.t;
}



int main()
{
  int t;
  scanf("%d",&t);
  for(int P=1;P<=t;P++){
    int n;
    long long K;
    scanf("%d%lld",&n,&K);
    Cf C[101];
    for(int i=0;i<n;i++){
      scanf("%lld%lld%d",&(C[i].c),&(C[i].t),&(C[i].s));
    }
    C[n].c=0;
    C[n].t=0;
    C[n].s=0;
    sort(C,C+n+1);
    priority_queue<pair<int,long long> > Q;
    long long A=0;
    for(int i=0;i<=n;i++){
      long long t=C[i].t,D=K-t;
      while(!Q.empty()){
	pair<int,long long> p=Q.top();
	Q.pop();
	int s=p.first;
	long long c=p.second;
	//printf("%lld %d %lld\n",D,s,c);
	if(D<=c){
	  A+=s*D;
	  c-=D;
	  Q.push(make_pair(s,c));
	  break;
	}
	else{
	  A+=s*c;
	  D-=c;
	}
      }
      Q.push(make_pair(C[i].s,C[i].c));
      K=t;
    }
    printf("Case #%d: %lld\n",P,A);
  }
  return 0;
}
