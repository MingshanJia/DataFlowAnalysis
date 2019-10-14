#include <iostream>
#include <string.h>
#include <stdio.h>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
using namespace std;
string a[110];
char str[110];
int main(){
    freopen("dd.in","r",stdin);
    freopen("out.txt","w+",stdout);
    int ncase,T=0;
    scanf("%d\n",&ncase);
    while(ncase--){
        int n;
        scanf("%d\n",&n);
        for(int i=0;i<n;i++){
            string x,y;
            gets(str);
            //printf("%s\n",str);
            x=str;
            a[i]=x;
        }
        int sum=0;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(a[j]>a[i]){
                    sum++;
                    break;
                }
            }
        }
        printf("Case #%d: %d\n",++T,sum);
    }
    return 0;
}
