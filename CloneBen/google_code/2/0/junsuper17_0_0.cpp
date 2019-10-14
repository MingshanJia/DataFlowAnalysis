#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>
#include <cmath>
using namespace std;
const int maxn =11000;
int a[maxn];
int b[maxn];
int c[maxn];
int tt, T;

bool mysort(int l, int r){

    if ( l >= r ) return true;
    int st_b = 0;
    int st_c = 0;
    int cnt_b = 0;
    int k = (int)(floor((r-l)/2) + l);
    int mid = a[k];
 //   cout << tt << " " << l << " " << r << " ";
  //  cout << "mid:  " << mid << " " << (int)(floor((r-l)/2) + l) << endl;
  //  for ( int i = l; i<=r; i++ )cout << a[i] << " "; cout << endl;
    for ( int i = l; i <= r; i++ )
        if ( a[i] < mid ) cnt_b ++;
 //   cout << cnt_b << " " << r-l << endl;
    if ( cnt_b == 0 || cnt_b == r - l ){
        if ( cnt_b == 0 ){
            int st_c = r+1;
            for ( int i = r; i>=l ;i-- ){
                if ( a[i] > mid && i != k )
                    a[--st_c] = a[i];
            }
            return mysort(st_c,r);
        }
        else{
            int st_b = l-1;
            for ( int i = l; i <= r; i++ ){
                if ( a[i] <= mid && i != k)
                    a[++st_b] = a[i];
            }
            return mysort(l, st_b);
        }
    }
    else
        return false;
}

int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small-attempt0.out","w",stdout);
    cin >> T;
    for ( tt = 1; tt <= T; tt++ ){
        int n;
        cin >> n;
        for ( int i = 0; i < n; i++ )
            cin >> a[i];

        bool res = mysort(0, n-1);
        if ( res )
            cout << "Case #" << tt << ": YES" << endl;
        else
            cout << "Case #" << tt << ": NO" << endl;
    }
   // fclose(stdin);
   // fclose(stdout);
    return 0;
}
