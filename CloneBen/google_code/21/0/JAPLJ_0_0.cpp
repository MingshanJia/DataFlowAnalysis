#include<cstdio>
#include<deque>

using namespace std;

int main()
{
  int T;
  scanf("%d", &T);
  for(int CN=1; CN<=T; ++CN) {
    int m, c, w;
    scanf("%d%d%d", &m, &c, &w);
    deque<int> f, e;
    f.push_back(1); e.push_back(m);
    for(int i=0; i<c; ++i) {
      int a, b;
      scanf("%d%d", &a, &b);
      b += a - 1;
      deque<int> nf, ne, ff, fe;
      int s = 1, t = 1;
      for(int j=0; j<(int)f.size(); ++j) {
	t = s + e[j] - f[j];
	if(t < a || s > b) {
	  nf.push_back(f[j]);
	  ne.push_back(e[j]);
	} else if(s < a && t <= b) {
	  nf.push_back(f[j]); ff.push_back(f[j]+a-s);
	  ne.push_back(f[j]+a-s-1); fe.push_back(e[j]);
	} else if(a <= s && t <= b) {
	  ff.push_back(f[j]);
	  fe.push_back(e[j]);
	} else if(s <= a && b <= t) {
	  nf.push_back(f[j]); ff.push_back(f[j]+a-s); nf.push_back(f[j]+b-s+1);
	  ne.push_back(f[j]+a-s-1); fe.push_back(f[j]+b-s); ne.push_back(e[j]);
	} else {
	  ff.push_back(f[j]); nf.push_back(f[j]+b-s+1);
	  fe.push_back(f[j]+b-s); ne.push_back(e[j]);
	}
	s += e[j] - f[j] + 1;
      }
      for(int j=0; j<(int)nf.size(); ++j) {
	ff.push_back(nf[j]);
	fe.push_back(ne[j]);
      }
      f = ff; e = fe;
    }
    int r = w-1;
    printf("Case #%d: ", CN);
    for(int j=0; j<(int)f.size(); ++j) {
      if(r <= e[j] - f[j]) {
	printf("%d\n", f[j]+r);
	break;
      }
      r -= e[j] - f[j] + 1;
    }
  }
  return 0;
}
