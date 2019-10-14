#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

///////////////////////////////////////////////////////////////////////////////////
#define SPEEDUP ios_base::sync_with_stdio(false);cout.tie(nullptr);cin.tie(nullptr)
///////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////
#define in_file(f_in) ifstream (f_in); (f_in).open("input2.txt");
#define out_file(f_out) ofstream (f_out); (f_out).open("output2.txt");
///////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
///////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////
template <typename T>
T gcd(T a, T b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}
///////////////////////////////////////////////////////////////////////////////////



int main() {
    SPEEDUP;

    in_file(f_in);
    out_file(f_out);

    uint64_t test_cnt, var1, var2, var3, ans;
    f_in >> test_cnt;
    map<uint64_t, uint64_t> m;
    uint64_t rest1;
    // vector<int> res;
    // int64_t ans = 0;
    for (int i = 0; i < test_cnt; ++i) {
        f_in >> var1;
        rest1 = 0;
        // rest2 = 0;
        for (int i = 0; i < var1; ++i) {
            f_in >> var2 >> var3;
            m[var3] = var2;
        }
        if (m.size() != 0) {
            ans = (*(--m.end())).first + 1;
        }
        for (auto c : m) {
            if (rest1 < c.second * c.first) {
                rest1 = 0;
                rest1 = c.second;
            } else {
                rest1 -= (c.second * c.first);
                rest1 += c.second;
            }
        }

        if (rest1 > ans) {
            ans = rest1;
        }
        //

        f_out << "Case #" << i + 1 << ": " << ans << "\n";
        m.clear();
        ans = 0;
        rest1 = 0;
    }
    
    f_in.close();
    f_out.close();
    return 0;
}