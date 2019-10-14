#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <utility>
#include <set>
#include <map>
#include <iostream>
#include <queue>
#include <climits>

using namespace std;

typedef long long LL;

#define PB push_back
#define FRO freopen("in.txt","r",stdin);

#define CLR(arr) memset( (arr),0,sizeof(arr) );
#define NEG(arr) memset( (arr),-1,sizeof(arr) );

#define X first
#define Y second

#define MP make_pair

#define snuke(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)


typedef pair<int,int> pint;
typedef map<int,int> mint;

#define SIZE 500000

double now[SIZE];
double nxt[SIZE];

int main(){

    freopen("B-large.in","r",stdin);
    freopen("out.out","w",stdout);


    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        int b,lev,n;
        scanf("%d %d %d",&b,&lev,&n);

        for (int i=0;i<SIZE;++i){
            nxt[i] = 0;
            now[i] = 0;
        }


        nxt[1] = b*750;


        for (int i=1;i<=lev;++i){

            for (int j=1;j<=i*(i+1)/2 ; ++j){
                now[j] = nxt[j];
            }


            for (int j=1;j<=(i+1)*(i+2)/2 ; ++j){
                nxt[j] = 0;
            }
            int tmp = 0;
            int shaon= 0;
            int cnt = 0;
            for (int j=1; j<= (i+1)*i/2 ;++j , ++cnt ){

                if ( cnt == tmp ){
                    cnt = 0;
                    tmp ++;
                    shaon++;
                }

                if ( now[j]>250 ){
                    double per = ( now[j]-250 )/3;
                    now[j] = 250;
                    nxt[j] += per;
                    int var =  shaon* ( shaon+1 )/2 + cnt +1 ;

                    nxt[var] += per;
                    nxt[var+1] += per;
                }
            }
        }
        double ans = now[n];
        if ( ans >250 )ans = 250;
        printf("Case #%d: %.7lf\n",kk,ans);

    }


    return 0;
}
