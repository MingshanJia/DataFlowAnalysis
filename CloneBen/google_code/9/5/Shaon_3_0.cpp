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

#define SIZE 110

LL dp[SIZE][SIZE];

LL func( int totake,int left  ){

    if ( totake == 0 ){
        if ( left == 0 ){
            return 1;
        }else{
            return 0;
        }
    }

    LL &ret = dp[totake][left];
    if ( ret != -1 )return ret;

    ret = func( totake-1,left+1 );
    if ( left-1 >= 0 )
        ret += func( totake-1,left-1 );
    if ( ret <0 )ret = LLONG_MAX;

    return ret;
}

char str[SIZE];

int main(){

    freopen("D-small-attempt0.in","r",stdin);
    freopen("out.out","w",stdout);

    NEG(dp) ;


    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){


        printf("Case #%d: ",kk);

        int n;
        LL order;
        scanf("%d %lld",&n,&order);

        n+= n;

        int cnt  = 0;
        str[cnt++]= '(';


        int carry = 1;

        //cout<<func( n,0 )<<endl;

        if ( func( n,0 ) < order ){
            printf("Doesn't Exist!\n");
            continue;
        }

        while ( cnt <n ){
            //cout<<order<<" "<< n-cnt-1 <<" "<<carry+1<<" "<<func( n-cnt-1,carry+1 )<< endl;
            if ( carry>0 &&  func( n-cnt-1,carry+1 ) < order  ){

                //cout<<func( n-cnt-1,carry+1 )<<endl;
                order -= func( n-cnt-1,carry+1 );
                str[cnt++] = ')';
                carry--;
            }else{
                str[cnt++] = '(';
                carry++;
            }
        }
        str[cnt++]= '\0';
        printf("%s\n",str);
    }


    return 0;
}
