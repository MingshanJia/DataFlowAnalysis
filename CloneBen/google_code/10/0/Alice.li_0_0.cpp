#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <string>
using namespace std;

#define eps 1e-9
#define PB push_back
#define LL long long
#define INF 0x3f3f3f3f

template<class T> void checkMax(T &a, T b){a = max(a, b);}
template<class T> void checkMin(T &a, T b){a = min(a, b);}

const int N = 105;

string digit[10] = {"1111110",
                    "0110000",
                    "1101101",
                    "1111001",
                    "0110011",
                    "1011011",
                    "1011111",
                    "1110000",
                    "1111111",
                    "1111011"};
int input[N], num[10], dict[1 << 7];
int convert(string str)
{
    int i, ret = 0;
    for(i = 0; i < str.size(); i++)
        ret = ret * 2 + str[i] - '0';
    return ret;
}
string toString(int num)
{
    string ans = "";
    for(int i = 0; i < 7; i++)
    {
        ans += (num % 2 + '0');
        num /= 2;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
void init()
{
    memset(dict, -1, sizeof(dict));
    for(int i = 0; i < 10; i++)
    {
        num[i] = convert(digit[i]);
        dict[num[i]] = i;
    }
}
int main()
{
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-small-attempt0.out", "w", stdout);
    //cout << digit[2] << " " << toString(convert(digit[2])) << endl;
    int t, cas = 1, n, i, j, k;
    string str;
    init();
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i = 1; i <= n; i++)
        {
            cin >> str;
            input[i] = convert(str);
        }
        set<string> ans;
        for(k = 0; k <= 9; k++)
        {
            for(i = 0; i < (1 << 7); i++)
            {
                for(j = 1; j <= n; j++)
                {
                    if((i & input[j]) != 0)
                        break;
                }
                if(j <= n)  continue;
                int cur = k;
                for(j = 1; j <= n; j++)
                {
                    if((input[j] | num[cur]) != num[cur])
                        break;
                    if(((input[j] | i) & num[cur]) != num[cur])
                        break;
                    cur = (cur - 1 + 10) % 10;
                }
                if(j <= n)  continue;
                ans.insert(toString(num[cur] ^ (num[cur] & i)));
            }
        }
        cout << "Case #" << cas++ << ": ";
        if(ans.size() != 1)    cout << "ERROR!" << endl;
        else                   cout << *ans.begin() << endl;
        //cout << ans.size() << endl;
    }
    return 0;
}
