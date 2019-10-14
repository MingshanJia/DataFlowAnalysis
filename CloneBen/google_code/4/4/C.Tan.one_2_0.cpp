#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

const string file = "C-small-attempt0";

const long long modn = 10e9 + 7;
long long dp[5000];
int nn[500][26];

int main(){
	ios::sync_with_stdio(false);
	freopen((file + ".in").c_str(), "r", stdin);
	freopen((file + ".out").c_str(), "w", stdout);
	int tests;
	cin >> tests;
	int n, m;
    string tmps;
    bool flag;
    int tmp;
    vector<string> words;
	for (int test = 0; test < tests; ++test){
        cin >> n >> m;
        words.clear();
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < 26; ++j)
                nn[i][j] = 0;
        for (int i = 0; i < n; ++i) {
            cin >> tmps;
            words.push_back(tmps);
            for (auto j : tmps)
                ++nn[i][j - 'a'];
        }

        cout << "Case #" << test + 1 << ":";

        for (int j = 0; j < m; ++j) {
            cin >> tmps;
            for (int i = 0; i <= tmps.length(); ++i)  dp[i] = 0;
            dp[0] = 1;

            for (int k = 0; k < tmps.length(); ++k) {
                if (!dp[k])  continue;
                for (int i = 0; i < words.size(); ++i) {
                    if (k + words[i].length() > tmps.length())  continue;

                    flag = true;
                    for (int p = 0; p < 26; ++p) {
                        if (nn[i][p]) {
                            tmp = 0;
                            for(int z = k; z < k + words[i].length(); ++z)
                                if (tmps[z] - 'a' == p) ++tmp;
                            if (tmp != nn[i][p]) {
                                flag = false;
                                break;
                            }
                        }
                    }
                    if (!flag) continue;

                    dp[k + words[i].length()] = (dp[k] + dp[k + words[i].length()]) % modn;
                }
            }
            cout << " " << dp[tmps.length()];
        }
        cout << endl;
	}
}
