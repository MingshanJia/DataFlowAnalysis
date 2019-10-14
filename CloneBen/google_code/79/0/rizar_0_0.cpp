#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <cctype>
#include <cassert>
#include <utility>
#include <complex>

using namespace std;

typedef long long LL;
typedef long double LD;

#define NAME "task"

//solution

const int N_MAX = 110;

int n, m;
int a [N_MAX][N_MAX];
char b [N_MAX][N_MAX];

int main()
{
    int nTests;
    cin >> nTests;
    for (int test = 1; test <= nTests; test++)
    {
        cin >> n >> m;
        for (int i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            for (int j = 0; j < m; j++)
                a[i][j] = s[j] == '#' ? 1 : 0;
        }                        

        memset(b, '.', sizeof(b));
        bool ok = true;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (a[i][j])
                    for (int di = 0; di < 2; di++)
                        for (int dj = 0; dj < 2; dj++)
                        {
                            int ni = i + di, nj = j + dj;
                            if (!(0 <= ni && ni < n && 0 <= nj && nj < m && a[ni][nj] == 1)) ok = false;
                            a[ni][nj] = 0;
                            b[ni][nj] = ((di + dj) & 1) ? '\\' : '/';
                        }

        printf("Case #%d:\n", test);
        if (!ok)
            printf("Impossible\n");
        else
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                    putchar(b[i][j]);
                putchar('\n');
            }
        }
    }

    return 0;
}
