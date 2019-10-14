#include <algorithm>
#include <iostream>
#include <memory.h>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <cmath>
#include <map>
using namespace std;


#define CLR(a, b) memset(a, b, sizeof(a))

int main() {
    
    freopen("/Users/daidaidaiyi/Downloads/B-large.in","r",stdin);
    freopen("./out.txt","w",stdout);
    

    int n, m, T, cas = 1;
    scanf("%d", &T);
    while(T --) {
        scanf("%d%d", &n, &m);
        if(n == 2 || m == 2) {
            if(m == 2) swap(n,  m);
            int cnt = (m * 2 + 2) / 3, sum = cnt * 2;
            printf("Case #%d: %d\n", cas ++, sum);
            continue;
        }
        int cnt = (m * 2 + 2) / 3, sum = 0;
        if(m % 3 == 1) {
            sum = (cnt * 3 - 1) * (n / 3);
            if(n % 3 >= 1) sum += cnt;
            if(n % 3 == 2) sum += cnt;
        }
        else if(m % 3 == 2) {
            sum = (cnt * 3 - 2) * (n / 3);
            if(n % 3 >= 1) sum += cnt;
            if(n % 3 == 2) sum += cnt - 1;
        }
        else {
            sum = (cnt * 3) * (n / 3);
            if(n % 3 >= 1) sum += cnt;
            if(n % 3 == 2) sum += cnt;
        }
        printf("Case #%d: %d\n", cas ++, sum);
    }
    return 0;
}

