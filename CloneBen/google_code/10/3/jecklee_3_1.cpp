#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<functional>
#include<iostream>
#include<map>
#include<numeric>
#include<queue>
#include<stack>
#include<set>
#include<stack>
#include<string>
#include<vector>
using namespace std;

const int N = 32;

class Matrix
{
private:
    int M;
    vector<int> tiles;

    // Find max k that: 2^k <= m
    int getMaxK(int m)
    {
        int k = 0;
        while (m > 1)
        {
            m >>= 1;
            ++k;
        }
        return k;
    }

    void incTiles(int a, int b, vector<int>& tiles)
    {
        if (a > b)
            swap(a, b);
        if (0 == a)
            return;
        if (1 == a)
        {
            tiles[0] += b;
            return;
        }

        int ak = getMaxK(a);
        int sa = 1 << ak;
        int ac = a / sa;
        int bc = b / sa;
        tiles[ak] += ac * bc;
        incTiles(b - sa * bc, a, tiles);
        incTiles(a - sa * ac, sa * bc, tiles);
    }

public:
    Matrix(int _M)
    {
        M = _M;
        tiles.resize(N);
        incTiles(M, M, tiles);
    }
    void print()
    {
        for (int i = 0; i < N; ++i)
            if (tiles[i] > 0)
                cout << i << " " << (1<<i) << " " << tiles[i] << endl;
    }
    bool add(int s)
    {
        for (int i = s; i < N-1; ++i)
        {
            if (tiles[i] > 0)
            {
                -- tiles[i];
                incTiles((1<<i)-(1<<s), 1<<i, tiles);
                incTiles(1<<s, (1<<i)-(1<<s), tiles);
                return true;
            }
        }
        return false;
    }
};

int main()
{
    int t;
    cin >> t;
    for (int k = 1; k <= t; ++k)
    {
        int n, m;
        cin >> n >> m;
        vector<int> sn(n);
        for (int i = 0; i < n; ++i)
            cin >> sn[i];
        sort(sn.begin(), sn.end(), greater<int>());

        vector<Matrix> ans;
        for  (vector<int>::iterator it = sn.begin(); it != sn.end(); ++it)
        {
            bool added = false;
            for (int i = 0; i < ans.size(); ++i)
            {
                if (ans[i].add(*it))
                {
                    added = true;
                    break;
                }
            }
            if (!added)
            {
                ans.push_back(Matrix(m));
                ans.back().add(*it);
            }
        }

        cout << "Case #" << k << ": " << ans.size() << endl;
    }
    return 0;
}
