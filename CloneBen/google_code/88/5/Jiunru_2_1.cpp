// ============================================================================
//   [ Filename    ]  pc.cpp
//   [ Description ]  
//   [ Created     ]  西元2010年05月22日 10時29分08秒 CST
//   [ Author      ]  Jiunru Yang, yangjiunru[at]gmail.com, LaDS3, GIEE, NTU
// ============================================================================

#include <iostream>
#include <cmath>
using namespace std;

double r1 = (sqrt(5.0)+1)/2.0;
double r2 = (sqrt(5.0)-1)/2.0;

class Sol
{
public:
   void read() { cin >> a1 >> a2 >> b1 >> b2; }
   void solve(int caseNo) {
      long long ans = 0;
      for (int i = a1; i <= a2; ++i) {
         int lb = ceil(r2 * i);
         int ub = floor(r1 * i);
         if (lb > b2 || ub < b1)
            ans += (b2 - b1 + 1);
         else {
            if (ub > b2)
               ub = b2;
            if (lb < b1)
               lb = b1;
            ans += (b2 - ub + lb - b1);
         }
         /*cout << lb << " " << ub << endl;
         if (ub > b2)
            ub = b2;
         if (lb < b1)
            lb = b1;
         cout << lb << " " << ub << endl;
         ans += (b2 - ub + lb - b1);*/
      }
      cout << "Case #" << caseNo << ": ";
      cout << ans << endl;
   }
   int a1, a2, b1, b2;
};

int main()
{
   int T;
   cin >> T;
   for (int t = 1; t <= T; ++t) {
      Sol  s;
      s.read();
      s.solve(t);
   }
   return 0;
}
