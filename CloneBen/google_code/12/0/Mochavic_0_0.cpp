#include <stdio.h>
#include <string.h>
char c[11][20] = {
    "",
    "",
    "double",
    "triple",
    "quadruple",
    "quintuple",
    "sextuple",
    "septuple",
    "octuple",
    "nonuple",
    "decuple"
};
char ss[10][20] = {
    "zero",
    "one",
    "two",
    "three",
    "four",
    "five",
    "six",
    "seven",
    "eight",
    "nine"
};
char str[110];
char s[110];
int main(){
    int T, ri = 1, x, y, i, j, l;
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("out.txt", "w", stdout);
    scanf("%d", &T);
    while (T--){
        scanf("%s%s", str, s);
        x = y = 0;
        l = strlen(s);
        s[l] = '-';
        printf("Case #%d:", ri++);
        for (i = 0; i <= l; i++){
            if (s[i] == '-'){
                int last = -1, cnt = 0;
                for (j = 0; j < x; j++){
                    if (last == -1 || last == str[j + y] - '0'){
                        last = str[j + y] - '0';
                        cnt++;
                    }else{
                        if (cnt == 1){
                            printf(" %s", ss[last]);
                        }else if (cnt < 11){
                            printf(" %s %s", c[cnt], ss[last]);
                        }else{
                            while (cnt--){
                                printf(" %s", ss[last]);
                            }
                        }
                        last = str[j + y] - '0';
                        cnt = 1;
                    }
                }
                if (cnt == 1){
                    printf(" %s", ss[last]);
                }else if (cnt < 11){
                    printf(" %s %s", c[cnt], ss[last]);
                }else if (cnt > 10){
                    while (cnt--){
                        printf(" %s", ss[last]);
                    }
                }
                last = str[j + y] - '0';
                cnt = 1;
                y += x;
                x = 0;
            }else{
                x = x * 10 + s[i] - '0';
            }
        }
        printf("\n");
    }
    return 0;
}
