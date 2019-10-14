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

int t, n;
char buffer[16];
map<string, map<string, int> > e;
set<string> visited[2];
string target;

int dfs(const string &name, int sign, int value) {
    if (visited[sign].find(name) != visited[sign].end())
        return INT_MIN;
    if (name == target && sign == 0)
        return value;
    visited[sign].insert(name);
    map<string, int> &m = e[name];
    for (map<string, int>::iterator i = m.begin(); i != m.end(); ++i) {
        int res = dfs(i->first, sign ^ 1, (sign == 0 ? value - i->second : value + i->second));
        if (res != INT_MIN)
            return res;
    }
    return INT_MIN;
}

int get_result(const string &name1, const string &name2) {
    map<string, int> &m = e[name1];
    for (map<string, int>::iterator i = m.begin(); i != m.end(); ++i) {
        visited[0].clear();
        visited[1].clear();
        target = name2;
        int res = dfs(i->first, 0, i->second);
        if (res != INT_MIN)
            return res;
    }
    return INT_MIN;
}

void solve() {
    e.clear();
    scanf("%d", &n);
    while (getchar() != '\n');
    for (int i = 0; i < n; ++i) {
        gets(buffer);
        for (int j = 0; buffer[j] != '\0'; ++j)
            if (buffer[j] == '+' || buffer[j] == '=')
                buffer[j] = ' ';
        stringstream ss(buffer);
        string name1, name2;
        int value;
        ss >> name1 >> name2 >> value;
        e[name1][name2] = value;
        e[name2][name1] = value;
    }
    printf("Case #%d:\n", ++t);
    scanf("%d", &n);
    while (getchar() != '\n');
    for (int i = 0; i < n; ++i) {
        gets(buffer);
        for (int j = 0; buffer[j] != '\0'; ++j)
            if (buffer[j] == '+' || buffer[j] == '=')
                buffer[j] = ' ';
        stringstream ss(buffer);
        string name1, name2;
        ss >> name1 >> name2;
        int res = get_result(name1, name2);
        if (res != INT_MIN)
            cout << name1 << '+' << name2 << '=' << res << endl;
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
