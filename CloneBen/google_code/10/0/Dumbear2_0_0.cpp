/******************************************************************************\
*                         Author:  Dumbear                                     *
*                         Email:   dumbear[#at]163.com                         *
*                         Website: http://dumbear.com                          *
\******************************************************************************/
#include <algorithm>
#include <bitset>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <typeinfo>
#include <utility>
#include <vector>

using namespace std;

#define output(x) cout << #x << ": " << (x) << endl;

typedef long long LL;
typedef vector<int> VI;
typedef vector<long long> VL;
typedef vector<double> VD;
typedef vector<string> VS;

const int max_n = 100 + 10;
const string state[10] = {
    "1111110",
    "0110000",
    "1101101",
    "1111001",
    "0110011",
    "1011011",
    "1011111",
    "1110000",
    "1111111",
    "1111011"
};

int t, n, bad[7];
string s[max_n];

bool can_match(const string &p, const string &s) {
    for (int i = 0; i < 7; ++i) {
        if (p[i] == '1' && s[i] != '1')
            return false;
        if (p[i] == '1') {
            if (bad[i] == 1)
                return false;
            bad[i] = 0;
        }
        if (s[i] == '1' && p[i] != '1') {
            if (bad[i] == 0)
                return false;
            bad[i] = 1;
        }
    }
    return true;
}

bool is_valid(int digit) {
    memset(bad, -1, sizeof(bad));
    for (int i = 0; i < n; ++i) {
        if (!can_match(s[i], state[digit]))
            return false;
        digit = (digit + 9) % 10;
    }
    return true;
}

int get_next() {
    vector<int> res;
    for (int i = 0; i < 10; ++i)
        if (is_valid(i))
            res.push_back(i);
    if (res.size() != 1)
        return -1;
    is_valid(res[0]);
    int k = (res[0] - n % 10 + 10) % 10;
    for (int i = 0; i < 7; ++i)
        if (state[k][i] == '1' && bad[i] == -1)
            return -1;
    return k;
}

void solve() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        cin >> s[i];
    printf("Case #%d: ", ++t);
    int res = get_next();
    if (res == -1) {
        puts("ERROR!");
    } else {
        for (int i = 0; i < 7; ++i)
            putchar(bad[i] == 1 ? '0' : state[res][i]);
        putchar('\n');
    }
}

int main() {
    freopen("out.txt", "w", stdout);
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; ++i)
        solve();
    return 0;
}
