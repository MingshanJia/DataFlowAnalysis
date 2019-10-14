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


int arr[SIZE];

int main(){

    freopen("C-small-attempt0.in","r",stdin);
    freopen("out.out","w",stdout);

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        int n,k;
        scanf("%d %d",&n,&k);
        for (int i=0;i<n;++i){
            scanf("%d",&arr[i]);
        }

        vector<int> stk;
        for (int i=0;i<n;++i){
            stk.PB( arr[i] );
            if ( stk.size() >= 3 ){
                int back= stk.size()-1;
                if ( stk[back]-stk[back-1]== k && stk[back-1]-stk[ back-2 ] == k ){
                    stk.pop_back();
                    stk.pop_back();
                    stk.pop_back();
                }
            }
        }
        printf("Case #%d: %d\n",kk,stk.size());
    }



    return 0;
}
