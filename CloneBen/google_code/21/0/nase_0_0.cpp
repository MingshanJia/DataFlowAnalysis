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
int M;
vector<int> A, B;
int doit(int C, int W)
{
    if (C == -1) return W + 1;
    if (0 <= W && W < B[C]) {
        return doit(C - 1, A[C] + W);
    }
    else if (B[C] <= W && W < B[C] + A[C]) {
        return doit(C - 1, W - B[C]);
    }
    else {
        return doit(C - 1, W);
    }
}

int doCase()
{
    
    //
    // READ INPUT
    //
    int C, W;
    cin >> M >> C >> W;
    W --;
    A = vector<int>(C);
    B = vector<int>(C);
    FOR(i, 0, C) {
        cin >> A[i] >> B[i];
        A[i] --;
        B[i];
    }
    
    
    //
    // DOIT!
    //
    return doit(C - 1, W);
}

int main()
{
    int cases = readOne<int>();
    for (int caseno = 1; caseno <= cases; caseno++)
        cout << "Case #" << caseno << ": " << doCase() << endl;
    return 0;
}

