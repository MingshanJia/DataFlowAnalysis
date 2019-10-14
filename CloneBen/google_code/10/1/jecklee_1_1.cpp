#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<functional>
#include<iostream>
#include<map>
#include<numeric>
#include<queue>
#include <stack>
#include<set>
#include<string>
#include<vector>
using namespace std;

void Usuper2048(vector<vector<int> > &matrix)
{
    const int n = matrix.size();
    for (int j = 0; j < n; ++j)
    {
        int k = 0;  // pos to write the add res
        int first = -1, second = -1;
        for (int i = 0; i < n; ++i)
        {
            while ((i < n) && (0 == matrix[i][j]))
                ++i;
            if (i >= n)
                break;
            if (-1 == first)
                first = matrix[i][j];
            else if (-1 == second)
                second = matrix[i][j];
            if ((-1 != first) && (-1 != second))
            {
                if (first == second)
                {
                    matrix[k++][j] = first + second;
                    first = -1;
                    second = -1;
                }
                else
                {
                    matrix[k++][j] = first;
                    first = second;
                    second = -1;
                }
            }
        }
        if (-1 != first)
            matrix[k++][j] = first;
        for ( ; k < n; ++k)  // set reset 0
            matrix[k][j] = 0;
    }
}
void Dsuper2048(vector<vector<int> > &matrix)
{
    const int n = matrix.size();

    for (int j = 0; j < n; ++j)
    {
        int k = n-1;  // pos to write the add res
        int first = -1, second = -1;
        for (int i = n-1; i >= 0; --i)
        {
            while ((i >= 0) && (0 == matrix[i][j]))
                --i;
            if (i < 0)
                break;
            if (-1 == first)
                first = matrix[i][j];
            else if (-1 == second)
                second = matrix[i][j];
            if ((-1 != first) && (-1 != second))
            {
                if (first == second)
                {
                    matrix[k--][j] = first + second;
                    first = -1;
                    second = -1;
                }
                else
                {
                    matrix[k--][j] = first;
                    first = second;
                    second = -1;
                }
            }
        }
        if (-1 != first)
            matrix[k--][j] = first;
        for ( ; k >= 0; --k)  // set reset 0
            matrix[k][j] = 0;
    }
}
void Lsuper2048(vector<vector<int> > &matrix)
{
    const int n = matrix.size();
    for (int i = 0; i < n; ++i)
    {
        int k = 0;  // pos to write the add res
        int first = -1, second = -1;
        for (int j = 0; j < n; ++j)
        {
            while ((j < n) && (0 == matrix[i][j]))
                ++j;
            if (j >= n)
                break;
            if (-1 == first)
                first = matrix[i][j];
            else if (-1 == second)
                second = matrix[i][j];
            if ((-1 != first) && (-1 != second))
            {
                if (first == second)
                {
                    matrix[i][k++] = first + second;
                    first = -1;
                    second = -1;
                }
                else
                {
                    matrix[i][k++] = first;
                    first = second;
                    second = -1;
                }
            }
        }
        if (-1 != first)
            matrix[i][k++] = first;
        for ( ; k < n; ++k)  // set reset 0
            matrix[i][k] = 0;
    }
}
void Rsuper2048(vector<vector<int> > &matrix)
{
    const int n = matrix.size();

    for (int i = 0; i < n; ++i)
    {
        int k = n-1;  // pos to write the add res
        int first = -1, second = -1;
        for (int j = n-1; j >= 0; --j)
        {
            while ((j >= 0) && (0 == matrix[i][j]))
                --j;
            if (j < 0)
                break;
            if (-1 == first)
                first = matrix[i][j];
            else if (-1 == second)
                second = matrix[i][j];
            if ((-1 != first) && (-1 != second))
            {
                if (first == second)
                {
                    matrix[i][k--] = first + second;
                    first = -1;
                    second = -1;
                }
                else
                {
                    matrix[i][k--] = first;
                    first = second;
                    second = -1;
                }
            }
        }
        if (-1 != first)
            matrix[i][k--] = first;
        for ( ; k >= 0; --k)  // set reset 0
            matrix[i][k] = 0;
    }
}

void super2048(vector<vector<int> > &matrix, const string &dir)
{
    if ("up" == dir)
        Usuper2048(matrix);
    else if ("down" == dir)
        Dsuper2048(matrix);
    else if ("left" == dir)
        Lsuper2048(matrix);
    else
        Rsuper2048(matrix);
}

int main()
{
    int t;
    cin >> t;
    for (int k = 1; k <= t; ++k)
    {
        int n;
        string dir;
        cin >> n >> dir;
        vector<vector<int> > matrix(n, vector<int>(n));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                cin >> matrix[i][j];
        super2048(matrix, dir);

        cout << "Case #" << k << ": " << endl;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                cout << matrix[i][j];
                if (j < n-1)
                    cout << " ";
            }
            cout << endl;
        }
    }
}
