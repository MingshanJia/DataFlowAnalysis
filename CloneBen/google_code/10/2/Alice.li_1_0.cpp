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
const int N = 25;
int num[N][N];

int main()
{
    freopen("B-small-attempt1.in", "r", stdin);
    freopen("B-small-attempt1.out", "w", stdout);
    int t, cas = 1, n, i, j, k;
    string dir;
    cin >> t;
    while(t--)
    {
        cin >> n >> dir;
        for(i = 1; i <= n; i++)
            for(j = 1; j <= n; j++)
                cin >> num[i][j];
        if(dir == "right" || dir == "left")
        {
            for(i = 1; i <= n; i++)
            {
                if(dir == "left")
                {
                    int last = 1;
                    for(j = 2; j <= n; j++)
                    {
                        if(num[i][j] == 0)  continue;
                        int cur = num[i][j];
                        num[i][j] = 0;
                        if(num[i][last] == 0)
                            num[i][last] = cur;
                        else
                        {
                            if(num[i][last] == cur)
                                num[i][last] *= 2;
                            else
                                num[i][last + 1] = cur;
                            last++;
                        }
                    }
                }
                else
                {
                    int last = n;
                    for(j = n - 1; j >= 1; j--)
                    {
                        if(num[i][j] == 0)  continue;
                        int cur = num[i][j];
                        num[i][j] = 0;
                        if(num[i][last] == 0)
                            num[i][last] = cur;
                        else
                        {
                            if(num[i][last] == cur)
                                num[i][last] *= 2;
                            else
                                num[i][last - 1] = cur;
                            last--;
                        }
                    }
                }
            }
        }
        else
        {
            for(j = 1; j <= n; j++)
            {
                if(dir == "up")
                {
                    int last = 1;
                    for(i = 2; i <= n; i++)
                    {
                        if(num[i][j] == 0)  continue;
                        int cur = num[i][j];
                        num[i][j] = 0;
                        if(num[last][j] == 0)
                            num[last][j] = cur;
                        else
                        {
                            if(num[last][j] == cur)
                                num[last][j] *= 2;
                            else
                                num[last + 1][j] = cur;
                            last++;
                        }
                    }
                }
                else
                {
                    int last = n;
                    for(i = n - 1; i >= 1; i--)
                    {
                        if(num[i][j] == 0)  continue;
                        int cur = num[i][j];
                        num[i][j] = 0;
                        if(num[last][j] == 0)
                            num[last][j] = cur;
                        else
                        {
                            if(num[last][j] == cur)
                                num[last][j] *= 2;
                            else
                                num[last - 1][j] = cur;
                            last--;
                        }
                    }
                }
            }
        }
        cout << "Case #" << cas++ << ":" << endl;
        for(i = 1; i <= n; i++)
        {
            for(j = 1; j <= n; j++)
            {
                cout << num[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
