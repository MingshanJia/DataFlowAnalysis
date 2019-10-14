#include <cstdio>
#include <cstring>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <functional>
#include <vector>
#include <cmath>
#include <cctype>
using namespace std;

struct CMP_STRING {
	bool operator()(const char* a, const char* b) const {
		return strcmp(a,b)<0;
	}
};

#define two(n) (1<<(n))
#define foreach(a,it) for(typeof(a.begin()) it=a.begin();it!=a.end();++it)

int TT,N,M,Q;

double questions[6][4];
vector<double> probs;

void brute_force(int p, double prob) {
	if(p==Q) {
		probs.push_back(prob);
		return;
	}
	for(int i=0;i<4;i++)
		brute_force(p+1,prob*questions[p][i]);
}

int main(void) {
	scanf("%d",&TT);
	for(int T=1;T<=TT;T++) {
		printf("Case #%d: ",T);
		scanf("%d %d",&M,&Q);
		for(int i=0;i<Q;i++)
			for(int j=0;j<4;j++)
				scanf("%lf",&questions[i][j]);
		probs.clear();
		brute_force(0,1.0);
		sort(probs.begin(),probs.end(),greater<double>());
		double ans=0;
		for(int i=0;i<M and i<(int)probs.size();i++)
			ans+=probs[i];
//		ans/=(double)probs.size();
		printf("%lf\n",ans);
	}
	return 0;
}
