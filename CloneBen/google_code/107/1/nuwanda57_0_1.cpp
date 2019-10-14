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
#define in_file(f_in) ifstream (f_in); (f_in).open("input1.txt");
#define out_file(f_out) ofstream (f_out); (f_out).open("output1.txt");
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

    int test_cnt, var1, var2;
    f_in >> test_cnt;
    vector<int> v;
    // vector<int> res;
    int64_t ans = 0;
    for (int i = 0; i < test_cnt; ++i) {
        f_in >> var1;
        v.clear();
        // res.clear();
        for (int j = 0; j < var1; ++j) {
            f_in >> var2;
            v.push_back(var2);
        }
        sort(v.begin(), v.end());
        for (int i = 0; i < var1; ++i) {
            // cout << ans << " " ;
            if (i % 2 == 0) {
                ans = ans + ((i / 2 - v[i]) * (i / 2 - v[i]));
            } else {
                ans = ans + (((i - 1) / 2 - v[i]) * ((i - 1) / 2 - v[i]));
            }
        }
        f_out << "Case #" << i + 1 << ": " << ans << "\n";
        ans = 0;
    }
    
    f_in.close();
    f_out.close();
    return 0;
}