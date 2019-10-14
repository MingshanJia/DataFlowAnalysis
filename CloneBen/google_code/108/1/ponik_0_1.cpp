#include <vector>
#include <iostream>
#include <stdio.h>

using namespace std;
 
typedef float ld;
const ld eps = 1e-7;
const int maxn = 100000;
 
 
int main() {
    freopen ("A.in", "r", stdin);
    freopen ("A.out", "w", stdout);
    int t, f, s;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> f >> s;
        vector<vector<int>> ans(s, vector<int>(s, 0));
        for (int j = 0; j < f; j++) {
            int a, b;
            cin >> a >> b;
            ans[a - 1][b - 1] = 1;
            ans[b - 1][a - 1] = 1;  
        }
        int max_row = 0;
        for (int h = 0; h < s; h++) {
            int sum = 0;
            for (int r = 0; r < s; r++) {
                sum += ans[h][r];
                if (sum >= max_row) {
                   max_row = sum;   
                }    
            }
        }
        cout << "Case #" << i + 1 << ": " << max_row << "\n";
    }
    
    return 0;
}