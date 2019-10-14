#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <string.h>
#define ll long long
#define clr(a,b) memset(a,b,sizeof(a))
using namespace std;

char a[1000][1000];
int main(){
//    freopen("/home/zyc/Documents/Code/cpp/in","r",stdin);
    freopen("/home/zyc/Downloads/in","r",stdin);
    freopen("/home/zyc/Downloads/out","w",stdout);
    int T,cas=0;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        getchar();
        int ans = 0;
        for(int i=1;i<=n;i++){
            gets(a[i]);
            int l=0,len = strlen(a[i]);
            for(int j=0;j<len;j++)
                if(a[i][j]!=' ')
                    a[i][l++] = a[i][j];
            a[i][l] = 0;
            for(int j=1;j<i;j++)
                if(strcmp(a[i],a[j])<0){
                    ans++;
                    break;
                }
        }
        printf("Case #%d: %d\n",++cas,ans);
    }
    return 0;

}
