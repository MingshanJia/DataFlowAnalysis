#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

const int MAXN = 1005;

int T, n;

int main() {
    scanf("%d", &T);
    for(int t = 1; t <= T; ++t) {
        scanf("%d", &n);
        map<string, int> m1;
        map<string, string> m2;
        for(int i = 0; i < n; ++i) {
            string s1, s2;
            cin >> s1 >> s2;
            m1[s1]++;
            m1[s2]++;
            m2[s1] = s2;
        }
        string cur;
        for(auto it = m1.begin(); it != m1.end(); ++it)
            if (it->second == 1 && m2.find(it->first) != m2.end())
                cur = it->first;
        printf("Case #%d:", t);
        for(int i = 0; i < n; ++i) {
            cout << " " << cur << "-" << m2[cur];
            cur = m2[cur];
        }
        printf("\n");
    }
    return 0;
}