#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int t;
    cin >> t;
    for(int tt = 1; tt <= t; ++tt) {
        int n, d;
        cin >> d >> n;
        assert(d == 50);
        
        vector<vector<char>> mat(d, vector<char>(d, '/'));
        
        char now = 'I';
        for(int i = 0; i < d; ++i) {
            for(int j = 0; j < d; j += 2) {
                if(n == 0) continue;
                mat[i][j] = now;
                now ^= ('I' ^ 'O');
                if(j != 0) n--;
            }
            if(i % 2 == 1) now ^= ('I' ^ 'O');
        }
        
        cout << "Case #" << tt << ": " << endl;
        for(int i = 0; i < d; ++i, cout << endl) {
            for(int j = 0; j < d; ++j)
                cout << mat[i][j];
        }
    }
    
    
    return 0;
    
}