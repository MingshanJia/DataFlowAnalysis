#include <vector>
#include<cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <deque>
#include <set>
#ifdef __GXX_EXPERIMENTAL_CXX0X__
#include <unordered_map>
#include <cassert>
#endif
#include <ctime>
#include <queue>
#include <stack>
#include<iomanip>
#include <sstream>
#include <cmath>
using namespace std;
typedef pair<int, int> PII;
typedef unsigned long long ll;
string str[] = {"1111110", "0110000", "1101101", "1111001", "0110011", "1011011", "1011111", "1110000", "1111111", "1111011"};
int check(vector<string>& num, int x, string& b, string& l) {
    b.assign(7, '0');
    l = string(7, '0');
    for(int i = 0; i < num.size(); i ++) {
        for(int j = 0; j < 7; j ++) {
            if (num[i][j] == '1') l[j] = '1';
            if (num[i][j] != str[x][j]) {
                if (num[i][j] == '1') return 0;
                b[j] = '1';
            }
        }
        x --;
        if (x < 0) x = 9;
    }
    for(int i = 0; i < 7; i ++) {
        if (l[i] == '1' && b[i] == '1') return 0;
    }
    return 1;
}
string nextNum(int x, string& b, string& l) {

    string ret = str[(x + 10) % 10];
    for(int i = 0; i < 7; i ++) {
        if (ret[i] == '1' && b[i] == '0' && l[i] == '0') return "ERROR!";
        if (b[i] == '1') ret[i] = '0';
    }
    return ret;
}
void solve(int ncase) {
    int n;
    cin >> n;
    vector<string> num(n);
    for(int i = 0; i < n; i ++) {
        cin >> num[i];
    }
    vector<int> good;
    vector<string> broken, light;
    for(int i = 0; i <= 9; i ++) {
        string b, l;
        if (check(num, i, b, l)) {
            good.push_back(i);
            broken.push_back(b);
            light.push_back(l);
            if (good.size() > 1) break;
        }
    }
    cout << "Case #" << ncase << ": ";
    if (good.size() == 1) {
        cout << nextNum((good[0] - n % 10 + 10) % 10, broken[0], light[0]) << endl;
    } else {
        cout << "ERROR!" << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    //cout << setprecision(16) << endl;
#ifdef _zzz_
   freopen("A-small-attempt2.in", "r", stdin);
   freopen("out.txt", "w", stdout);
#endif
    int T = 1;
    //scanf("%d", &T);
    cin >> T;
    int ncase = 0;
    while(T --) {
        solve(++ ncase);
    }
}
