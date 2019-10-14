#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <numeric>
#include <cstring>

using namespace std;

#define ll          long long
#define VI          vector<int>
#define ALL(a)      (a).begin(), (a).end()
#define SORT(a)     sort( ALL(a) )
#define PB          push_back
#define FOR(i,a,b)  for( int i = (a); i < (int)(b); i++ )
#define dump_(x)     cerr << #x << " = " << (x) << " ";
#define dump(x)     cerr << #x << " = " << (x) << endl
#define dump_vec(x) FOR(zZz,0,x.size()) cout << x[zZz] << " "; cout << endl


template< typename type > type readOne()
{
    type res;
    char inp[5000];
    char* dum = fgets( inp, sizeof( inp ), stdin );
    stringstream ss( dum );
    ss >> res;
    return res;
}

template< typename type > vector<type> readMulti()
{
    vector<type> res;
    char inp[5000];
    char* dum = fgets( inp, sizeof( inp ), stdin );
    stringstream ss( dum );
    for ( type t; ss >> t; )
        res.push_back( t );
    return res;
}

//
//
// LET'S START
//
//
vector<int> bits;
int memo[100][3];
int doit(int pos, int carry)
{
    if (pos >= bits.size()) {
        if (carry) return -1000000;
        return 0;
    }
    int& res = memo[pos][carry];
    if (res != -1) return res;
    res = -1000000;
    FOR(a, 0, 2) FOR(b, 0, 2) {
        if (((a + b + carry) & 1) == bits[pos]) {
            int f = doit(pos + 1, (a + b + carry) / 2);
            if (f == -1000000) continue;
            res = max(res, (a & 1) + (b & 1) + f);
        }
    }
    return res;
}

int doCase()
{
    
    //
    // READ INPUT
    //
    ll N;
    cin >> N;
    bits.clear();
    while (N) {
        bits.push_back(N & 1);
        N /= 2;
    }
    
    //
    // DOIT!
    //
    memset(memo, -1, sizeof(memo));
    return doit(0, 0);
}

int main()
{
    int cases = readOne<int>();
    for (int caseno = 1; caseno <= cases; caseno++)
        cout << "Case #" << caseno << ": " << doCase() << endl;
    return 0;
}

