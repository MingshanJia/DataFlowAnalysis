#include <bits/stdc++.h>

using namespace std;

char mat[15][15];

int dx[] = {-1,  0,  1,  1,  1,  0, -1, -1};
int dy[] = {-1, -1, -1,  0,  1,  1,  1,  0};
const int d = 15;

char Get(int i, int j) {
    if(i < 0 || i >= d || j < 0 || j >= d) 
        return '#';
    return mat[i][j];
}

int Calc(int i, int j) {
    if(mat[i][j] != '/') return 0;
    
    int ans = 0;
    for(int d = 0; d < 4; ++d) {
        int newi1 = i + dx[d];
        int newj1 = j + dy[d];
        
        int newi2 = i + dx[d + 4];
        int newj2 = j + dy[d + 4];
        
        char a = Get(newi1, newj1);
        char b = Get(newi2, newj2);
        
    
        ans += (min(a, b) == min('I', 'O')) && (max(a, b) == max('I', 'O'));
    }
    return ans;
}

char line[] = "I/O/I/O/I/O/I/O";

int SumAll() {
    int ret = 0;
    for(int i = 0; i < d; ++i)
    for(int j = 0; j < d; ++j)
        ret += Calc(i, j);
    return ret;
}

pair<int, int> TryGet(int x) {
    for(int i = 0; i < d; ++i)
    for(int j = 0; j < d; ++j)
        if(Calc(i, j) == x)
            return {i, j};
    return {-1, -1};
}

void Solve(int n) {
    int auxn = n;
    assert(d == 15);
    
    for(int i = 0; i < d; ++i)
        for(int j = 0; j < d; ++j)
            mat[i][j] = line[j];
            
    assert(Calc(0, 1) == 1);
            
    n -= SumAll();
    cerr << "SumAll()" << SumAll() << endl;
    
    assert(n <= 0);
    while(n < 0) {
        if(n <= -3) {
            auto p = TryGet(3);
            if(p.first != -1) {
                mat[p.first][p.second] = 'O';
                n += 3;
                continue;
            }
        }
        auto p = TryGet(1);
        assert(p.first != -1);
        mat[p.first][p.second] = 'O';
        n += 1;
    }
    
    assert(n == 0);
    assert(SumAll() == auxn);
}

int main() {
    
    int t;
    cin >> t;
    for(int tt = 1; tt <= t; ++tt) {
        int n, d;
        cin >> d >> n;
        //assert(d == 15);
        
        Solve(n);
        cout << "Case #" << tt << ": " << endl;
        for(int i = 0; i < ::d; ++i) {
            for(int j = 0; j < ::d; ++j) {
                cout << mat[i][j];
            }
            cout << endl;
        }
    }
    
    return 0;
}