#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define MOD
#define ADD(X,Y) ((X) = ((X) + (Y)%MOD) % MOD)
typedef long long i64; typedef vector<int> ivec; typedef vector<string> svec;

int T;
char G[11];

i64 C[22][22];
i64 ret;

bool ishoge(vector<int> &seq)
{
	bool ret = false;
	for (int i = 1; i < seq.size(); ++i) if (seq[i] != 0) ret = true;
	return ret;
}

void solve(vector<int> seq);
void solve2(vector<int> &buf, int loc, int *cnt, bool hoge)
{
	if (loc == buf.size()) {
	//	for (int i = 0; i < buf.size(); ++i) printf("%d ", buf[i]); puts("");
		if (hoge || ishoge(buf)) {
			solve(buf);
		}
		return;
	}
	for (int i = 0; i < 10; ++i) {
		if (cnt[i] > 0) {
			--cnt[i];
			buf[loc] = i;
			solve2(buf, loc + 1, cnt, hoge);
			++cnt[i];
		}
	}
}

void solve(vector<int> seq)
{
	int cnt[10];
	for (int i = 0; i < 10; ++i) cnt[i] = 0;
	for (int i = 0; i < seq.size(); ++i) {
		cnt[i + 1] = seq[i];
	}
	++ret;
	
	int sum = 0;
	for (int i = 0; i < 10; ++i) sum += cnt[i];
	int sum2 = 0;
	for (int i = 1; i < 10; ++i) sum2 += i * cnt[i];
	if (sum > seq.size()) return;
	cnt[0] = seq.size() - sum;

	if (sum2 <= seq.size()) {
		vector<int> buf(seq.size(), 0);
		solve2(buf, 0, cnt, ishoge(seq));
	} else {
		i64 val = 1;
		sum = seq.size();
		for (int i = 0; i < 10; ++i) {
			val *= C[sum][cnt[i]];
			sum -= cnt[i];
		}
		ret += val;
	}
}

int main()
{
	for (int i = 0; i <= 20; ++i) {
		C[0][i] = 0;
	}
	C[0][0] = 1;
	for (int i = 1; i <= 20; ++i) {
		C[i][0] = 1;
		for (int j = 1; j <= 20; ++j) {
			C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]);
		}
	}
	scanf("%d", &T);
	for (int t = 0; t++ < T;){
		scanf("%s", G);
		ret = 0;
		vector<int> seq;
		for (int i = 0; G[i]; ++i) {
			seq.push_back(G[i] - '0');
		}
		solve(seq);

		printf("Case #%d: %lld\n", t, ret);
	}

	return 0;
}
