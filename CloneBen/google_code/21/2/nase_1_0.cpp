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

int doCase()
{
    
    //
    // READ INPUT
    //
    int N; ll K;
    cin >> N >> K;
    vector<ll> C(N), T(N), S(N);
    set<ll> foo;
    foo.insert(0);
    FOR(i, 0, N) {
        cin >> C[i] >> T[i] >> S[i];
        foo.insert(T[i]);
    }
    vector<ll> days(foo.begin(), foo.end());
    sort(days.begin(), days.end(), greater<ll>());

    //
    // DOIT!
    //
    FOR(i, 0, N) {
        FOR(j, i + 1, N) {
            if (T[i] < T[j] || (T[i] == T[j] && S[i] < S[j])) {
                swap(T[i], T[j]);
                swap(C[i], C[j]);
                swap(S[i], S[j]);
            }
        }
    }

    ll res = 0;
    FOR(i, 0, days.size() - 1) {
        ll span = days[i] - days[i+1];
        vector<ll> CC, TT, SS;
        FOR(j, 0, N) {
            if (T[j] >= days[i] && C[j] > 0) {
                CC.push_back(C[j]);
                TT.push_back(T[j]);
                SS.push_back(S[j]);
            }
        }
        {
            FOR(i, 0, CC.size()) {
                FOR(j, i + 1, CC.size()) {
                    if (SS[i] < SS[j]) {
                        swap(TT[i], TT[j]);
                        swap(CC[i], CC[j]);
                        swap(SS[i], SS[j]);
                    }
                }
            }
        }
        FOR(j, 0, CC.size()) {
            ll add = min(span, CC[j]);
            res += SS[j] * add;
            span -= add;
            FOR(k, 0, N) {
                if (CC[j] == C[k] && TT[j] == T[k] && SS[j] == S[k]) {
                    C[k] -= add;
                    break;
                }
            }
            CC[j] -= add;
        }
    }

    return res;
}

int main()
{
    int cases = readOne<int>();
    for (int caseno = 1; caseno <= cases; caseno++)
        cout << "Case #" << caseno << ": " << doCase() << endl;
    return 0;
}

