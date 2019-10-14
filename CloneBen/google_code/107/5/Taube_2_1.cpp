#pragma comment(linker, "/STACK:256000000")

#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <assert.h>
#include <time.h>
#include <memory.h>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <utility>
#include <algorithm>
#include <random>
#include <bitset>
#include <unordered_set>
#include <unordered_map>

using namespace std;

typedef long long int64;
typedef unsigned long long uint64;
typedef pair<int, int> pii;
typedef pair<int64, int64> pll;
typedef pair<char, char> pcc;
typedef pair<int64, int> pli;
typedef pair<int, int64> pil;
const int INF = (int)(1e9 + 1e5);
const int64 LINF = (int64)(1e18);
const int64 MX = 100500;
const double EPS = 1e-9;
#define sq(x) ((x)*(x))
#define FAIL() (*(int*)(0))++
#ifdef _MY_DEBUG
#define I64d lld
#endif
const int MOD = 1000000007;
const int ROOT = 700;
const int PRM_ROOT = 5;

int test_num = 0;

struct group
{
    int64 n, e;
};

const int MAXN = 1005;

int n;
string s[3];
pair<string, int> t[3];
bool can[3];
int bc[8] = {0, 1, 1, 2, 1, 2, 2, 3};
int lg[8] = {0, 0, 1, 0, 2, 0, 0, 0};

void init()
{
    cin >> n;
    cin >> s[0] >> s[1] >> s[2];
}

int get_first(string& s1, string& s2)
{
    for (int i = 0; i < min(s1.size(), s2.size()); ++i)
    {
        if (s1[i] != s2[i])
        {
            return i;
        }
    }
    return -1;
}

void solve()
{
    can[0] = can[1] = can[2] = false;
    set<char> let;
    for (int i = 0; i < 3; ++i)
    {
        for (int j = i + 1; j < 3; ++j)
        {
            int pos = get_first(s[i], s[j]);
            if (pos != -1)
            {
                let.insert(s[i][pos]);
                let.insert(s[j][pos]);
            }
        }
    }
    cerr << let.size() << endl;
    vector<char> ord(let.begin(), let.end());
    sort(ord.begin(), ord.end());
    do
    {
        for (int i = 0; i < 3; ++i)
        {
            t[i].first = s[i];
            t[i].second = i;
            for (int j = 0; j < s[i].size(); ++j)
            {
                char l = s[i][j];
                auto it = find(ord.begin(), ord.end(), l);
                if (it == ord.end())
                {
                    t[i].first[j] = '0';
                }
                else
                {
                    t[i].first[j] = char('1' + (it - ord.begin()));
                }
            }
            cerr << i << " " << t[i].first << endl;
        }
        sort(t, t + 3);
        cerr << t[0].second << " " << t[1].second << " " << t[2].second << endl;
        cerr << t[0].first << " " << t[1].first << " " << t[2].first << endl;
        can[t[1].second] = true;
    } while(next_permutation(ord.begin(), ord.end()));
}

void print_answer()
{
    printf("Case #%d: %s %s %s\n", test_num, (can[0] ? "YES" : "NO"), (can[1] ? "YES" : "NO"), (can[2] ? "YES" : "NO"));
}

void run()
{
#ifdef _MY_DEBUG
    freopen("input.txt", "rt", stdin); freopen("output.txt", "wt", stdout);
#endif // _MY_DEBUG
    int t = 1; cin >> t;
    for (test_num = 1; test_num <= t; ++test_num)
    {
        init();
        solve();
        print_answer();
    }
}
int main()
{
    srand(90);
    ios_base::sync_with_stdio(false); cin.tie(0);
    //test();
    run();
    return 0;
}