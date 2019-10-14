#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 1<<14;

char a[maxn][maxn+maxn];
char s[maxn];

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int dl[] = {2, 3, 1, 0};
int dr[] = {3, 2, 0, 1};

int main()
{
    int t;
    cin >> t;
    for (int tt=0; tt<t; tt++)
    {
        memset(a, 0, sizeof(a));
        int x = 0;
        int y = maxn;
        int minx = 1;
        int maxx = x;
        int miny = y;
        int maxy = y;
        int d = 1;
        for (int k=0; k<2; k++)
        {
            cin >> s;
            for (int i=0; ; i++)
            {
                if (s[i] == 'L')
                {
                    d = dl[d];
                    continue;
                }
                if (s[i] == 'R')
                {
                    d = dr[d];
                    continue;
                }
                a[x][y] |= 1 << d;
                x += dx[d];
                y += dy[d];
                a[x][y] |= 1 << (d ^ 1);
                if (!s[i+1])
                    break;
                maxx = max(maxx, x);
                    miny = min(miny, y);
                maxy = max(maxy, y);
            }
            d ^= 1;
        }

        cout << "Case #" << tt+1 << ":" << endl;
        for (x=minx; x<=maxx; x++)
        {
            for (y=miny; y<=maxy; y++)
                cout << (char)(a[x][y] < 10?a[x][y]+'0':a[x][y]+'a'-10);
            cout << endl;
        }

    }    

    return 0;
}
