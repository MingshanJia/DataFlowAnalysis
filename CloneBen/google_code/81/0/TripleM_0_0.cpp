#include <iostream>
using namespace std;
int gcd(int a, int b) {
    while (b) {
        int t = a%b; a = b; b = t;
    }
    return a;
}
int main() {
    int T; scanf("%d",&T); for (int t=1; t<=T; t++) {
        long long N; int PD; int PG;
        printf("Case #%d: ",t);
        scanf("%I64d %d %d",&N,&PD,&PG);
        if (PG==0) {
            // never won a game
            if (PD==0) printf("Possible\n");
            else printf("Broken\n");
        } else if (PG==100) {
            if (PD==100) printf("Possible\n");
            else printf("Broken\n");
        } else {
            int g = gcd(PD,100);
            int mult = 100/g;
            // need D to be multiple of this
            if (N>=mult) printf("Possible\n");
            else printf("Broken\n");
        }
    }
}
