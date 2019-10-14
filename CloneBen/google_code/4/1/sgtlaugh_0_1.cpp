#include <bits/stdtr1c++.h>

#define MAX 505
#define clr(ar) memset(ar, 0, sizeof(ar))
#define read() freopen("lol.txt", "r", stdin)
#define write() freopen("out.txt", "w", stdout)
#define dbg(x) cout << #x << " = " << x << endl
#define ran(a, b) ((((rand() << 15) ^ rand()) % ((b) - (a) + 1)) + (a))

using namespace std;

int main(){
    read();
    write();
    int T = 0, t, n, m;

    scanf("%d", &t);
    while (t--){
        scanf("%d %d", &n, &m);
        double res = (double)(n - m) / (double)(n + m);
        printf("Case #%d: %0.12f\n", ++T, res + 1e-15);
    }
    return 0;
}
