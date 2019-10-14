#include <cmath>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <utility>
#define pb push_back
#define mp make_pair
#define f first
#define s second
using namespace std;


int a[200][200];
int main() {
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    int test;

    scanf("%d", &test);
    for(int col = 1; col <= test; col++){
        for (int i = 0; i < 100; i++)
            for (int j = 0; j < 100; j++){
                a[i][j] = 0;
            }
        int f, s;
        scanf("%d%d", &f, &s);
        for (int i = 0; i < f; i++){
            int x, y;
            scanf("%d%d", &x, &y);
            x--, y--;
            a[x][y] = 1;
            a[y][x] = 1;
        }
/*
        for (int i = 0; i < s; i++) {
            for (int j = 0; j < s; j++) {
                cout << a[i][j] << "";
            }
            cout << endl;
        }
*/
        int res = 0, cul = 0;
        for (int i = 0; i < s; i++) {

            for (int j = 0; j < s; j++) {
                if (a[i][j] == 1){
                    cul++;
                    res = max(res, cul);
                }

            }
            cul = 0;
        }
        //cout << "BBB  " << f << " " << s << endl;
        printf("Case #%d: %d\n", col, res);

    }
    return 0;
}
