#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

struct coffee
{
	long long C, T;
	int S;
};

inline bool operator<(const coffee& A, const coffee& B)
{
	return A.T > B.T;
}

int T;
coffee c[101];
int N; long long K;

int main()
{
	scanf("%d", &T);
	for(int t=0;t++<T;){
		scanf("%d%lld", &N, &K);
		for(int i=0;i<N;i++){
			scanf("%lld%lld%d", &(c[i].C), &(c[i].T), &(c[i].S));
		}
		c[N].C = 0; c[N].T = 0; c[N].S = 0;
		sort(c, c+N+1);

		priority_queue<pair<int, long long> > q;

		long long ret = 0;
		for(int i=0;i<=N;i++){
			if(i>0){
				long long days = c[i-1].T - c[i].T;
				while(!q.empty() && days>0){
					pair<int, long long> tmp = q.top(); q.pop();
					//printf("%d %lld %lld\n", tmp.first, tmp.second, days);
					if(days >= tmp.second){
						days -= tmp.second;
						ret += tmp.second * tmp.first;
					}else{
						tmp.second -= days;
						ret += days * tmp.first;
						days = 0;

						q.push(tmp);
					}
				}
			}
			q.push(make_pair(c[i].S, c[i].C));
		}

		printf("Case #%d: %lld\n", t, ret);
	}

	return 0;
}
