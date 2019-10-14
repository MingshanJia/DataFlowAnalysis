#include <stdio.h>
#include <vector>
#include <algorithm>

int t,T;
long long n,m[6];
long long p[3][3];

int main(){
	freopen("a-small-attempt1.in","rt",stdin);
	freopen("a-small-attempt1.out","wt",stdout);
	scanf("%d",&T);
	for (int t=1;t<=T;++t){
		scanf("%lld",&n);
		for (int i=0;i<6;++i){
			scanf("%lld",&m[i]);
		}

		for (int i=0;i<3;++i){
			for (int j=0;j<3;++j){
				scanf("%lld",&p[i][j]);
			}
		}

		std::vector<std::pair<int,int> > order;
		for (int i=0;i<3;++i){
			for (int j=3;j<6;++j){
				order.push_back(std::make_pair(i,j));
			}
		}

		long long ans=-1000000000000000000LL;

		while(std::next_permutation(order.begin(),order.end())){

			long long val = 0;
			long long mm[6] = {0};
			for (int i=0;i<6;++i)
				mm[i] = m[i];

			for (int i=0;i<9;++i){
				int left = order[i].first;
				int right = order[i].second;
				long long mmax = std::min(mm[left],mm[right]);
				val += mmax * p[left][right-3];
				mm[left] -= mmax;
				mm[right] -= mmax;
			}
			ans = std::max(ans,val);
		}

		printf("Case #%d: %lld\n",t,ans);
	}
	return 0;
}