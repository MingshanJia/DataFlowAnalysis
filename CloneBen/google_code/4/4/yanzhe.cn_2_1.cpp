#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

typedef unsigned long long u64;

const u64 MOD = 1e9 + 7;
int V;
int S;

char v[410][22]; // vocabulary
int vsplit[410][30]; // 26 used, splitted vocab
int l[410]; // len
int maxl; // maxlen
u64 h[410]; // hash
int sorted[410];
bool cmp(int i, int j)
{
    return h[i] < h[j];
}

char q[4040];

u64 letter_hash[30]; // 26 used
bool possible_start[4040];

u64 f[4040]; // dp result

int first_vocab(int st, int len, u64 hv)
{
    int l = 0;
    int r = V - 1; // both inclusive
    while (l < r) {
        if (l + 1 == r) {
            if (h[sorted[l]] == hv) return l;
            if (h[sorted[r]] == hv) return r;
            return -1;
        }
        int mid = (l + r) >> 1;
        if (h[sorted[mid]] > hv) r = mid - 1;
        else if (h[sorted[mid]] < hv) l = mid + 1;
        else if (h[sorted[mid]] == hv) r = mid;
    }
    if (h[sorted[l]] == hv) return l;
    if (h[sorted[r]] == hv) return r;
    return -1;
}

int csplit[26];

int in_vocab(int st, int len, u64 hv)
{
    int first = first_vocab(st, len, hv);
    if (first == -1) return 0;
    int ret = 0;
    for (int i = 0; i < 26; ++i) {
        csplit[i] = 0;
    }
    for (int i = 0; i < len; ++i) {
        csplit[q[st + i] - 'a']++;
    }
    for (int i = first; i < V; i++) {
        // printf("%*s  vs  %s\n", len, q + st, v[sorted[i]]);
        if (h[sorted[i]] != hv) return ret;
        int j = 0;
        for (j = 0; j < 26; j++) {
            if (csplit[j] != vsplit[sorted[i]][j]) break;
        }
        if (j == 26) ret++;
    }
    return ret;
}

void solve(int tcase)
{
    cin >> V >> S;
    maxl = 0;
    for (int i = 0; i < V; i++) {
        scanf(" %s", v[i]);
        l[i] = strlen(v[i]);
        for (int j = 0; j < 26; ++j)
            vsplit[i][j] = 0;
        if (l[i] > maxl) maxl = l[i];
        h[i] = 0;
        for (int j = 0; j < l[i]; j++) {
            h[i] += letter_hash[v[i][j] - 'a'];
            vsplit[i][v[i][j] - 'a']++;
        }
        sorted[i] = i;
    }
    sort(sorted, sorted + V, cmp);
    cout << "Case #" << tcase + 1<< ":";
    for (int i = 0; i < S; i++) {
        scanf(" %s", q);

        // init
        int ql = strlen(q);
        for (int st = 0; st < ql; st++) {
            f[st] = 0;
        }
        f[ql] = 0;
        f[0] = 1; // till 0, 0 is not used
        // solve
        for (int st = 0; st < ql; st++) {
            if (f[st] == 0) continue; // not possible start
            // printf("f[st=%d] = %llu\n", st, f[st]);
            u64 hv = 0;
            for (int len = 1; len <= maxl; len++) {
                int mul;
                hv += letter_hash[q[st + len - 1] - 'a'];
                // printf("cehking %*s  \n", len, q + st);
                if ((mul = in_vocab(st, len, hv)) > 0) {
    // cout << "inca" << endl;
                    // bless me there isn't two same vocab
                    f[st + len] += f[st] * mul;
                    f[st + len] %= MOD;
                }
            }
        }
        cout << ' ' << f[ql];
    }
    cout << endl;
    return;
}

int main()
{
    // f[i] -> f[i + x] accumulation
    int T;
    cin >> T;
    u64 hv = 1;
    for (int i = 0; i < 26; i++) {
        letter_hash[i] = hv;
        hv *= 26;
    }
    for (int i = 0; i < T; i++) {
        solve(i);
    }

    return 0;
}
