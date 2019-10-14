#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

struct coffee {
  long long c;
  long long t;
  int s;
  int id;
};
bool cmp(const coffee& c1, const coffee& c2)
{
  return c1.t > c2.t;
}
bool cmp_s(const coffee& c1, const coffee& c2)
{
  return c1.s > c2.s;
}

int main()
{
  int T;
  scanf("%d", &T);
  for(int CN=1; CN<=T; ++CN) {
    int N; long long K;
    scanf("%d%lld", &N, &K);
    vector<coffee> C;
    for(int i=0; i<N; ++i) {
      long long c; long long t; int s;
      scanf("%lld%lld%d", &c, &t, &s);
      coffee x;
      x.c = c; x.t = t; x.s = s;
      C.push_back(x);
    }
    sort(C.begin(), C.end(), cmp);
    for(int i=0; i<N; ++i)
      C[i].id = i;
    long long sol = 0;
    for(int i=0; i<N; ) {
      long long lt = C[i].t;
      int j = i;
      while(j < N && C[j].t == lt) ++j;
      long long nextt = j==N ? 0 : C[j].t;
      long long len = lt - nextt;
      vector<coffee> X;
      for(int k=0; k<j; ++k)
	X.push_back(C[k]);
      sort(X.begin(), X.end(), cmp_s);
      for(int k=0; k<j; ++k) {
	long long d = min(len, (long long)X[k].c);
	sol += X[k].s * d;
	C[X[k].id].c -= d;
	len -= d;
	if(len == 0) break;
      }
      i = j;
    }
    printf("Case #%d: %lld\n", CN, sol);
  }
  return 0;
}
