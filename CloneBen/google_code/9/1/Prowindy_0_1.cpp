#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;
#define MOD 1000000007
int C[101][101];
int run(){
    int N,M;
    cin >> M >> N;
    long long ret=0, tmp;
    for(int i=1; i<=M; ++i){
        tmp=C[M][i];
        if ((M - i) % 2 == 1) 
            tmp = MOD-tmp;
        for (int j = 0; j < N; ++j)
            tmp = tmp * i % MOD;
        ret=(ret + tmp) % MOD;
    }
    return ret;
}
int main(){
    int T;
    for (int i = 0; i < 101; i++)
        for (int j = 0; j <= i; j++)
        if (j == 0 || j == i)
            C[i][j] = 1;
        else {
            C[i][j] = C[i-1][j-1] + C[i-1][j];
            C[i][j] %= MOD;
        }
    cin >> T;
    for(int i = 1; i <= T ; ++i)
        cout << "Case #" << i << ": " << run() << endl;
} 
