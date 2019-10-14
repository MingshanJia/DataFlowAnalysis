#include <cstdio>
#include <cstring>

#define MAX_INT 1111111111
#define debug printf

int N, M, L;

struct node_t {
    int left;
    int right;
    int value;
};

node_t tree[40000];

int max(int a, int b) { return a > b ? a : b; }
int min(int a, int b) { return a < b ? a : b; }

void build(int n, int l, int r) {
    tree[n].left = l;
    tree[n].right = r;
    tree[n].value = MAX_INT;
    if (l < r) {
        int m = (l + r)/2;
        build(n*2+1, l, m);
        build(n*2+2, m+1, r);
    }
}

void update(int n, int l, int r, int v) {
    /* debug("update(%d %d %d %d)\n", n, l, r, v); */
    if (tree[n].right < l || tree[n].left > r) {
        ;
    } else if (tree[n].left >= l && tree[n].right <= r) {
        /* debug("ok\n"); */
        tree[n].value = min(v, tree[n].value);
    } else {
        update(n*2+1, l, r, v);
        update(n*2+2, l, r, v);
    }
}

int query(int n, int idx) {
    if (tree[n].right < idx || tree[n].left > idx) {
        return MAX_INT;
    } if (tree[n].left == tree[n].right) {
        return tree[n].value;
    } else {
        return min(min(tree[n].value, query(n*2+1, idx)), query(n*2+2, idx));
    }
}

int main() {
    int T; scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        scanf("%d%d%d", &N, &M, &L);

        build(0, 0, L);
        update(0, 0, 0, 0);
        for (int i = 0; i < N; i++) {
            /* for (int k = 0; k <= 2*L; k++) { debug("%d ", tree[k].value); } debug("\n"); */
            /* for (int k = 0; k <= L; k++) { debug("%d ", query(0, k)); } debug("\n"); */
            int a, b, p; scanf("%d%d%d", &a, &b, &p);
            for (int j = L; j >= 0; j--) {
                if (j + a > L) continue;
                /* debug("update %d %d to %d\n", j+a, min(j+b, L), min(query(0, j) + p, MAX_INT)); */
                update(0, j + a, min(j + b, L), min(query(0, j) + p, MAX_INT));
            }
        }
        /* for (int k = 0; k <= L; k++) { debug("%d ", query(0, k)); } debug("\n"); */
        int ans = query(0, L);
        if (ans == MAX_INT || ans > M) {
            printf("Case #%d: IMPOSSIBLE\n", t);
        } else {
            printf("Case #%d: %d\n", t, ans);
        }
    }
    return 0;
}
