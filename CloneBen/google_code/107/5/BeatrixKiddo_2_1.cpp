#include <bits/stdc++.h>
using namespace std;

bool check(string s1, string s2, string s3) {

    int cmp[26][26];
    int n = s1.length();
    char c1, c2, c3, c4;
    for(int i = 0; i < n; i++) {
        if(s1[i] != s2[i]) {
            c1 = s1[i], c2 = s2[i];
            break;
        }
    }
    for(int i = 0; i < n; i++) {
        if(s2[i] != s3[i]) {
            c3 = s2[i], c4 = s3[i];
            break;
        }
    }
    if(c1 == c4 && c2 == c3) {
        return 0;
    }

    return 1;
}

int main(){
    
    int t;
    scanf("%d", &t);
    for(int test = 1; t--; test++) {
        printf("Case #%d: ", test);

        int n;
        scanf("%d", &n);
        string s[3];
        cin >> s[0] >> s[1] >> s[2];
        if(check(s[1], s[0], s[2]) || check(s[2], s[0], s[1])) {
            printf("YES");
        } else {
            printf("NO");
        }
        printf(" ");
        if(check(s[0], s[1], s[2]) || check(s[2], s[1], s[0])) {
            printf("YES");
        } else {
            printf("NO");
        }
        printf(" ");
        if(check(s[0], s[2], s[1]) || check(s[1], s[2], s[0])) {
            printf("YES");
        } else {
            printf("NO");
        }
        printf("\n");
    }

}