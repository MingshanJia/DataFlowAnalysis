// ============================================================================
//   [ Filename    ]  pb.cpp
//   [ Description ]  
//   [ Created     ]  西元2010年05月22日 09時27分35秒 CST
//   [ Author      ]  Jiunru Yang, yangjiunru[at]gmail.com, LaDS3, GIEE, NTU
// ============================================================================

#include <iostream>
#include <algorithm>
using namespace std;

class Sol
{
public:
   void read()
   {
      cin >> D >> I >> M >> N;
      for (int i = 0; i < N; ++i)
         cin >> value[i];
   }
   void solve(int caseNo)
   {
      for (int i = 0; i <= N; ++i) 
         for (int j = 0; j < 256; ++j)
            dp[i][j] = 9999999;
      for (int i = 0; i < 256; ++i)
         dp[0][i] = 0;
      for (int i = 0; i < N; ++i) {
         // Insert
         bool okay;
         do {
            okay = false;
            for (int j = 0; j < 256; ++j)
               for (int m = -M; m <= M; ++m) {
                  if (j + m < 0 || j + m >= 256)
                     continue;
                  if (dp[i][j] + I < dp[i][j+m]) {
                     dp[i][j+m] = dp[i][j] + I;
                     okay = true;
                  }
               }
         } while (okay);
         // Delete
         for (int j = 0; j < 256; ++j)
            if (dp[i][j] + D < dp[i+1][j])
               dp[i+1][j] = dp[i][j] + D;
         // Change value
         for (int j = 0; j < 256; ++j)
            for (int m = -M; m <= M; ++m) {
               if (j + m < 0 || j + m >= 256)
                  continue;
               int diff = abs(j+m-value[i]);
               if (dp[i][j] + diff < dp[i+1][j+m])
                  dp[i+1][j+m] = dp[i][j] + diff;
            }
      }
      int min = 9999999;
      for (int i = 0; i < 256; ++i)
         if (dp[N][i] < min)
            min = dp[N][i];
      cout << "Case #" << caseNo << ": " << min << endl;
   }
   int D, I, M, N;
   int value[110];
   int dp[110][256];   
};

int main()
{
   int T;
   cin >> T;
   for (int t = 1; t <= T; ++t) {
      Sol s;
      s.read();
      s.solve(t);
   }
   return 0;
}
