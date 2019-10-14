#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int T;
int M, C, W;

vector<pair<int, int> > state1;

void split(int p)
{
	//split state1;
	int total = 0;
	for(int i=0;i<state1.size();i++){
		if(total==p-1){
			break;
		}
		if(total<p-1 && total+state1[i].second-state1[i].first+1 > p-1){
			pair<int, int> tmp = state1[i];
			state1.erase(state1.begin() + i);
			state1.insert(state1.begin() + i, make_pair(tmp.first, tmp.first + (p-1) - total - 1));
			state1.insert(state1.begin() + i+1, make_pair(tmp.first + (p-1) - total, tmp.second));
			break;
		}
		total += state1[i].second - state1[i].first + 1;
	}
}

int main()
{
	int a, b;
	scanf("%d", &T);
	for(int t=0;t++<T;){
		scanf("%d%d%d", &M, &C, &W);
		state1.clear();

		state1.push_back(make_pair(1, M));
		for(;C--;){
			scanf("%d%d", &a, &b);
			
			split(a);
			split(a+b);

			//for(int i=0;i<state1.size();i++) printf("%d--%d ", state1[i].first, state1[i].second);
			//puts("");

			int total = 0;
			int mp = 0;
			for(int i=0;i<state1.size();i++){
				//printf("%d ", total);
				if(total >= a-1 && total < a+b-1){
					total += state1[i].second - state1[i].first + 1;
					pair<int, int> tmp = state1[i];
					state1.erase(state1.begin() + i);
					state1.insert(state1.begin() + (mp++), tmp);
				}else{
					total += state1[i].second - state1[i].first + 1;
				}
			}

			//for(int i=0;i<state1.size();i++) printf("%d--%d ", state1[i].first, state1[i].second);
			//puts("");
		}

		int ret = -1;
		int t2 = 0;
		for(int i=0;i<state1.size();i++){
			if(t2 < W && W <= t2 + state1[i].second - state1[i].first + 1){
				ret = state1[i].first + (W - t2 - 1);
				break;
			}
			t2 += state1[i].second - state1[i].first + 1;
		}

		printf("Case #%d: %d\n", t, ret);
	}
	return 0;
}
