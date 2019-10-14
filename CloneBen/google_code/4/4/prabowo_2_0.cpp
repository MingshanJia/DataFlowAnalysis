#include <bits/stdc++.h>
using namespace std;

int v, cipher;
string vocab[444];
string s;

int n;

int dp[4444];
int f(int x) {
    if (x >= n) return 1;
    if (~dp[x]) return dp[x];
    
    vector<string> ls;
    int mini = min(x + 20, n);
    ls.push_back((string) "");
    for (int i=x; i<mini; i++) {        
        ls.push_back(ls.back() + s[i]);
        sort(ls.back().begin(), ls.back().end());
    }
    
    long long ret = 0;
    for (int i=0; i<v; i++) {
        if (x + vocab[i].size() <= n && vocab[i] == ls[vocab[i].size()]) ret += f(x + vocab[i].size());
    }
    return dp[x] = ret % 1000000007;
}

int Main() {
    scanf ("%d %d", &v, &cipher);
    for (int i=0; i<v; i++) cin >> vocab[i], sort(vocab[i].begin(), vocab[i].end());
    
    while (cipher--) {
        cin >> s;
        n = s.size();
        
        for (int i=0; i<n; i++) dp[i] = -1;
        printf (" %d", f(0));
    }    
    printf ("\n");
    return 0;
}

int main() {
    int t;
    scanf ("%d", &t);
    for (int tc=0; tc<t; tc++) {
        printf ("Case #%d:", tc+1);
        Main();
    }
    return 0;
}