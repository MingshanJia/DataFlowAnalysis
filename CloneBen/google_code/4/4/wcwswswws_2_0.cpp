#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <string.h>
#include <iostream>
#include <map>
using namespace std;
const long long MAXNUM = 1e9 + 7;

int main() {
    freopen("C-small-attempt1.in", "r", stdin);
    freopen("C-small-attempt1.out", "w", stdout);
    int test;
    scanf("%d", &test);
    map<string, long long> dict;
    char s[5000];
    long long f[5000];
    for (int t = 1; t <= test; t++) {
        dict.clear();
        int V, S;
        scanf("%d%d", &V, &S);
        gets(s);
        for (int i = 0; i < V; i++) {
            gets(s);
            string str = s;
            sort(str.begin(), str.end());
            map<string, long long>::iterator iter = dict.find(str);
            if (iter == dict.end()) {
                dict.insert(make_pair(str, 1));
            } else {
                iter->second++;
            }
        }
        printf("Case #%d:", t);
        for (int i = 0; i < S; i++) {
            memset(f, 0, sizeof(f));
            gets(s);
            int n = strlen(s);
            for (int i = 0; i < n; i++) {
                string str = "";
                for (int j = i; (j >= 0) && (i - j + 1 <= 20); j--) {
                    str += s[j];
                    if ((j == 0) || (f[j - 1] > 0)) {
                        string temp = str;
                        sort(temp.begin(), temp.end());
                        map<string, long long>::iterator iter = dict.find(temp);
                        if (iter != dict.end()) {
                            long long num = 1;
                            if (j > 0) { num = f[j - 1]; }
                            f[i] += num * iter->second;
                            f[i] %= MAXNUM;
                        }
                    }
                }
            }
            printf(" %lld", f[n - 1]);
        }
        printf("\n");
    }
    return 0;
}
