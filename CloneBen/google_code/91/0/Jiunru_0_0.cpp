// =====================================================================================
//   [ Filename    ]  pasmall.cpp
//   [ Description ]  
//   [ Created     ]  10/11/2009 12:32:37 AM CST
//   [ Author      ]  Jiunru Yang , yangjiunru [at] gmail.com, NTUEE
// =====================================================================================

#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <queue>

using namespace std;

int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

class Sol1
{
   public:
      inline bool check(pair<int,int> p) {
         return tar == p;
      }

      bool moveAble(pair<int,int> p, int d) {
         int x, y;
         x = p.first;
         y = p.second;
         int tx = x + dir[d][0];
         int ty = y + dir[d][1];
         int px = x - dir[d][0];
         int py = y - dir[d][1];
         if (px < 0 || px >= R) return false;
         if (py < 0 || py >= C) return false;
         if (tx < 0 || tx >= R) return false;
         if (ty < 0 || ty >= C) return false;
         if (mm[px][py] == '#') return false;
         if (mm[tx][ty] == '#') return false;
         return true;
      }

      pair<int,int> move(pair<int,int> p, int d) {
         return make_pair(p.first + dir[d][0], p.second + dir[d][1]);
      }

      void solve(int caseNo) {
         queue<pair<pair<int, int>, int> > q;
         q.push(make_pair(box, 0));
         rec.insert(box);
         int sol = -1;
         while (!q.empty() && sol == -1) {
            pair<pair<int,int>,int> pp = q.front();
            q.pop();
            pair<int,int> p = pp.first;
            if (check(p)) {
               sol = pp.second;
               break;
            }
            for (int d = 0; d < 4; ++d) {
               if (!moveAble(p, d)) continue;
               pair<int,int> np = move(p, d);
               if (rec.find(np) != rec.end()) continue;
               q.push(make_pair(np, pp.second + 1));
               rec.insert(np);
            }
         }
         cout << "Case #" << caseNo << ": " << sol << endl;
      }

      int R, C;
      string mm[12];
      set<pair<int,int> > rec;
      pair<int,int> tar;
      pair<int,int> box;
};

class Sol
{
   public:
      class Pos
      {
         public:
         Pos(int _x1, int _y1, int _x2, int _y2):
            x1(_x1), y1(_y1), x2(_x2), y2(_y2) { }
         int x1, y1, x2, y2;
         bool operator < (const Pos& op) const {
            return make_pair(make_pair(x1, y1), make_pair(x2, y2)) <
                   make_pair(make_pair(op.x1, op.y1), make_pair(op.x2, op.y2));
         }
         bool operator == (const Pos& op) const {
            return x1 == op.x1 && x2 == op.x2 && y1 == op.y1 && y2 == op.y2;
         }
      };

      inline bool check(const Pos& p) {
         if (tar[0].first == p.x1 && tar[0].second == p.y1 && tar[1].first == p.x2 && tar[1].second == p.y2)
            return true;
         if (tar[1].first == p.x1 && tar[1].second == p.y1 && tar[0].first == p.x2 && tar[0].second == p.y2)
            return true;
         return false;
      }

      inline bool isDangerous(const Pos& p) {
         if (p.x1 == p.x2)
            return !(p.y1 == p.y2 + 1 || p.y1 == p.y2 - 1);
         if (p.y1 == p.y2)
            return !(p.x1 == p.x2 + 1 || p.x1 == p.x2 - 1);
         return true;
      }

      bool moveAble(const Pos& p, int tm, int d) {
         int x, y, bx, by;
         if (tm == 0) {
            x = p.x1;
            y = p.y1;
            bx = p.x2;
            by = p.y2;
         }
         else {
            x = p.x2;
            y = p.y2;
            bx = p.x1;
            by = p.y1;
         }
         int tx = x + dir[d][0];
         int ty = y + dir[d][1];
         int px = x - dir[d][0];
         int py = y - dir[d][1];
         if (px < 0 || px >= R) return false;
         if (py < 0 || py >= C) return false;
         if (tx < 0 || tx >= R) return false;
         if (ty < 0 || ty >= C) return false;
         if (px == bx && py == by) return false;
         if (mm[px][py] == '#') return false;
         if (tx == bx && ty == by) return false;
         if (mm[tx][ty] == '#') return false;
         return true;
      }

      Pos move(const Pos& p, int tm, int d) {
         if (tm == 0)
            return Pos(p.x1 + dir[d][0], p.y1 + dir[d][1], p.x2, p.y2);
         else
            return Pos(p.x1, p.y1, p.x2 + dir[d][0], p.y2 + dir[d][1]);
      }

      void solve(int caseNo) {

         if (box.size() == 1) {
            Sol1 s1;
            s1.R = R;
            s1.C = C;
            for (int i = 0; i < R; ++i)
               s1.mm[i] = mm[i];
            s1.tar = tar[0];
            s1.box = box[0];
            s1.solve(caseNo);
            return;
         }

         queue<pair<Pos, int> > q;
         q.push(make_pair(Pos(box[0].first, box[0].second, box[1].first, box[1].second), 0));
         rec.insert(q.front().first);
         int sol = -1;
         while (!q.empty() && sol == -1) {
            pair<Pos,int> pp = q.front();
            q.pop();
            Pos p = pp.first;
            bool pd = isDangerous(p);
            if (check(p)) {
               sol = pp.second;
               break;
            }
            for (int tm = 0; tm < 2; ++tm) {
               for (int d = 0; d < 4; ++d) {
                  if (!moveAble(p, tm, d)) continue;
                  Pos np = move(p, tm, d);
                  if (pd && isDangerous(np))
                     continue;
                  if (rec.find(np) != rec.end()) continue;
                  q.push(make_pair(np, pp.second + 1));
                  rec.insert(np);
               }
            }
         }
         cout << "Case #" << caseNo << ": " << sol << endl;
      }

      void read()
      {
         cin >> R >> C;
         for (int i = 0; i < R; ++i) {
            cin >> mm[i];
            for (int j = 0; j < C; ++j)
               if (mm[i][j] == 'x') {
                  tar.push_back(make_pair(i, j));
                  mm[i][j] = '.';
               }
               else if (mm[i][j] == 'w') {
                  tar.push_back(make_pair(i, j));
                  box.push_back(make_pair(i, j));
                  mm[i][j] = '.';
               }
               else if (mm[i][j] == 'o') {
                  box.push_back(make_pair(i, j));
                  mm[i][j] = '.';
               }
         }
      }
      int R, C;
      string mm[12];
      set<Pos> rec;
      vector<pair<int,int> > tar;
      vector<pair<int,int> > box;
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
