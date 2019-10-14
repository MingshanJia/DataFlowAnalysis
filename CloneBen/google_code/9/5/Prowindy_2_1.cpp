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
const int MAXN = 110;
int f[MAXN][MAXN];
int A[MAXN];
int N, K;
int checkV(int a,int b, int c){
    if (a + K == b && b + K == c)
        return 0;
    return 3;
}

void checkMin(int &a,int b){
    if (a>b) a = b;
}

int run(){
    cin >> N >> K;
    for (int i = 1; i <= N; i++)
        cin >> A[i];
    memset(f, 0, sizeof(f));
    for (int D = 1; D <= N; D++)
        for (int L = 1; L + D - 1 <= N; L++){
            int R = L + D - 1;
            
            if (D < 3) f[L][R] = D;
            else if (D == 3)
                f[L][R] = checkV(A[L], A[L+1], A[L+2]);
            else {
                //connect
                f[L][R] = D;
                for (int ls = L; ls <= R; ls++)
                    for (int rs = ls; rs <= R; rs++)
                        checkMin(f[L][R], f[L][ls-1] + f[ls][rs] + f[rs+1][R]);
                for (int mid = L+1; mid < R; mid ++)
                    if (checkV(A[L], A[mid], A[R]) == 0 && f[L+1][mid-1] == 0 && f[mid+1][R-1] == 0)
                        f[L][R] = 0;
                if (checkV(A[L], A[R-1], A[R])==0 && f[L+1][R-2] ==0)
                    f[L][R] = 0;
                if (checkV(A[L], A[L+1], A[R]) == 0 && f[L+2][R-1] ==0)
                    f[L][R] = 0;
            }
        }
    return f[1][N];
}
                

int main(){
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++)
        cout << "Case #" << i << ": " << run() << endl;
    
}

/*
10
12 1
1 2 4 5 6 7 1 2 3 8 9 3
14 1
1 2 4 5 6 7 1 2 3 8 9 3 4 5


*/

