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
#define in_file(f_in) ifstream (f_in); (f_in).open("input3.txt");
#define out_file(f_out) ofstream (f_out); (f_out).open("output3.txt");
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
    string s1, s2, s3;
    f_in >> test_cnt;
    // map<uint64_t, uint64_t> m;
    // uint64_t rest1;
    // bool flag = false;
    char c1, c2, c3;
    for (int t = 0; t < test_cnt; ++t) {
        f_in >> var1;
        
        f_in >> s1 >> s2 >> s3;

        for (int i = 0; i < var1; ++i) {
            if ((s1[i] == s2[i]) && (s1[i] == s3[i])) {
                continue;
            }
            if ((s1[i] != s2[i]) && (s1[i] != s3[i]) && (s2[i] != s3[i])) {
                f_out << "Case #" << t + 1 << ": " << "YES " << "YES " << "YES" << "\n";
                break;
            }

            if (s1[i] == s2[i]) {
                c1 = s1[i];
                c2 = s2[i];
                c3 = s3[i];
                for (int j = i + 1; j < var1; ++j) {
                    if (s1[j] != s2[j]) {
                        if (s1[j] != c3 && s2[j] != c3) {
                            f_out << "Case #" << t + 1 << ": " << "YES " << "YES " << "NO" << "\n";
                            break;
                        }
                        if (s1[j] == c3 && s2[j] == c1) {
                            f_out << "Case #" << t + 1 << ": " << "YES " << "NO " << "NO" << "\n";
                            break;
                        }
                        if (s2[j] == c3 && s1[j] == c1) {
                            f_out << "Case #" << t + 1 << ": " << "NO " << "YES " << "NO" << "\n";
                            break;
                        }
                        f_out << "Case #" << t + 1 << ": " << "YES " << "YES " << "NO" << "\n";
                        break;
                    }
                }
                break;

            } else if (s1[i] == s3[i]) {
                c1 = s1[i];
                c2 = s2[i];
                c3 = s3[i];
                for (int j = i + 1; j < var1; ++j) {
                    if (s1[j] != s3[j]) {
                        if (s1[j] != c2 && s3[j] != c2) {
                            f_out << "Case #" << t + 1 << ": " << "YES " << "NO " << "YES" << "\n";
                            // flag = true;
                            break;
                        }
                        if (s1[j] == c2 && s3[j] == c1) {
                            f_out << "Case #" << t + 1 << ": " << "YES " << "NO " << "NO" << "\n";
                            // flag = true;
                            break;
                        }
                        if (s3[j] == c2 && s1[j] == c1) {
                            f_out << "Case #" << t + 1 << ": " << "NO " << "NO " << "YES" << "\n";
                            // flag = true;
                            break;
                        }
                        f_out << "Case #" << t + 1 << ": " << "YES " << "NO " << "YES" << "\n";
                        // flag = true;
                        break;
                    }
                }
                break;
            } else if (s3[i] == s2[i]) {
                c1 = s1[i];
                c2 = s2[i];
                c3 = s3[i];
                for (int j = i + 1; j < var1; ++j) {
                    if (s3[j] != s2[j]) {
                        if (s3[j] != c1 && s2[j] != c1) {
                            f_out << "Case #" << t + 1 << ": " << "NO " << "YES " << "YES" << "\n";
                            // flag = true;
                            break;
                        }
                        if (s3[j] == c1 && s2[j] == c2) {
                            f_out << "Case #" << t + 1 << ": " << "NO " << "NO " << "YES" << "\n";
                            // flag = true;
                            break;
                        }
                        if (s2[j] == c1 && s3[j] == c2) {
                            f_out << "Case #" << t + 1 << ": " << "NO " << "YES " << "NO" << "\n";
                            // flag = true;
                            break;
                        }
                        f_out << "Case #" << t + 1 << ": " << "NO " << "YES " << "YES" << "\n";
                        // flag = true;
                        break;
                    }
                }
                break;
            }
        }

    }
    
    f_in.close();
    f_out.close();
    return 0;
}