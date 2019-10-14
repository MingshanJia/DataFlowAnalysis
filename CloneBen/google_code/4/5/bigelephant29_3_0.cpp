#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 1000 + 10;
const int MAXL = 10000 + 10;
const long long INF = 9999999999LL;

int a[MAXN], b[MAXN];
long long c[MAXN];

long long T[MAXL * 4], TAG[MAXL * 4];

void push(int N, int L, int R) {
  if(L == R) return;
  TAG[2*N+1] = min(TAG[N], TAG[2*N+1]);
  T[2*N+1] = min(T[2*N+1], TAG[2*N+1]);
  TAG[2*N+2] = min(TAG[N], TAG[2*N+2]);
  T[2*N+2] = min(T[2*N+2], TAG[2*N+2]);
}

void build(int N, int L, int R){
  T[N] = TAG[N] = INF;
  if(L == R) {
    return;
  }
  int mid = (L+R) / 2;
  build(N * 2 + 1, L, mid);
  build(N * 2 + 2, mid+1, R);
}

void update(int N, int L, int R, int ql, int qr, long long v) {
  push(N,L,R);
  if(L == ql && R == qr) {
    T[N] = min(v, T[N]);
    TAG[N] = min(v, TAG[N]);
    return;
  }
  int mid = (L+R) / 2;
  if(qr <= mid) {
    update(2 * N + 1, L, mid, ql, qr, v);
  } else if(ql > mid) {
    update(2 * N + 2, mid+1, R, ql, qr, v);
  } else {
    update(2 * N + 1, L, mid, ql, mid, v);
    update(2 * N + 2, mid+1, R, mid+1, qr, v);
  }
}

long long query(int N, int L, int R, int q) {
  push(N,L,R);
  if(L==R) return T[N];
  int mid = (L+R) / 2;
  if(q <= mid) return query(2*N+1, L, mid, q);
  else return query(2*N+2, mid+1, R, q);
}

int main(){
  int TN;
  scanf("%d", &TN);
  for(int casen = 1 ; casen <= TN ; casen ++) {
    printf("Case #%d: ", casen);
    int n, l;
    long long m;
    scanf("%d %lld %d", &n, &m, &l);
    for(int i = 0 ; i < n ; i++) {
      scanf("%d %d %lld", &a[i], &b[i], &c[i]);
    }
    build(0, 0, l);
    for(int i = 0 ; i < n ; i++) {
      for(int j = l ; j > 0 ; j--) {
        int left = j + a[i], right = j + b[i];
        if(left <= l) {
          long long val = query(0, 0, l, j);
          if(val != INF) {
            right = min(right, l);
            update(0, 0, l, left, right, val + c[i]);
          }
        }
      }
      int left = a[i], right = b[i];
      if(left <= l) {
        right = min(right, l);
        update(0, 0, l, left, right, c[i]);
      }
    }
    long long ans = query(0, 0, l, l);
    if(ans == INF || ans > m) {
      puts("IMPOSSIBLE");
    } else {
      printf("%lld\n", ans);      
    }
  }
  return 0;
}
