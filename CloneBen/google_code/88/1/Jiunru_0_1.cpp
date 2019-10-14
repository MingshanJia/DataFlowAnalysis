// ============================================================================
//   [ Filename    ]  pa.cpp
//   [ Description ]  
//   [ Created     ]  西元2010年05月22日 09時02分19秒 CST
//   [ Author      ]  Jiunru Yang, yangjiunru[at]gmail.com, LaDS3, GIEE, NTU
// ============================================================================

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Sol
{
public:
   void read()
   {
      cin >> _n >> _k;
      _b.resize(_n);
      for (unsigned i = 0 ; i < _n; ++i)
         cin >> _b[i];
   }

   void solve(int caseNo)
   {
      _r.resize(_n, vector<char>(_n));
      for (unsigned i = 0; i < _n; ++i)
         for (unsigned j = 0; j < _n; ++j)
            _r[i][j] = _b[_n-j-1][i];
      fall();
      bool rwin = check('R');
      bool bwin = check('B');
      cout << "Case #" << caseNo << ": ";
      if (rwin && bwin)
         cout << "Both";
      else if (rwin)
         cout << "Red";
      else if (bwin)
         cout << "Blue";
      else
         cout << "Neither";
      cout << endl;
   }
   
   void fall()
   {
      for (unsigned j = 0; j < _n; ++j) {
         for (unsigned i = _n-1; (int)i >= 1; --i) {
            if (_r[i][j] != '.') continue;
            unsigned k = i - 1;
            for (; (int)k >= 0; --k)
               if (_r[k][j] != '.')
                  break;
            if ((int)k < 0) break;
            swap(_r[i][j], _r[k][j]);
         }
      }
   }

   bool check(char w) {
      // Row
      for (unsigned i = 0; i < _n; ++i) {
         for (unsigned j = 0; j + _k <= _n; ++j) {
            bool okay = true;
            for (unsigned k = 0; k < _k; ++k)
               if (_r[i][j+k] != w) {
                  okay = false;
                  break;
               }
            if (okay) return true;
         }
      }
      // Col
      for (unsigned j = 0; j < _n; ++j) {
         for (unsigned i = 0; i + _k <= _n; ++i) {
            bool okay = true;
            for (unsigned k = 0; k < _k; ++k)
               if (_r[i+k][j] != w) {
                  okay = false;
                  break;
               }
            if (okay) return true;
         }
      }
      // Diag
      for (unsigned i = 0; i + _k <= _n; ++i) {
         for (unsigned j = 0; j + _k <= _n; ++j) {
            bool okay = true;
            for (unsigned k = 0; k < _k; ++k)
               if (_r[i+k][j+k] != w) {
                  okay = false;
                  break;
               }
            if (okay) return true;
         }
      }
      for (unsigned i = _k - 1; i < _n; ++i) {
         for (unsigned j = 0; j + _k <= _n; ++j) {
            bool okay = true;
            for (unsigned k = 0; k < _k; ++k)
               if (_r[i-k][j+k] != w) {
                  okay = false;
                  break;
               }
            if (okay) return true;
         }
      }
      return false;
   }

   unsigned _n;
   unsigned _k;
   vector<string> _b;
   vector<vector<char> > _r;
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
