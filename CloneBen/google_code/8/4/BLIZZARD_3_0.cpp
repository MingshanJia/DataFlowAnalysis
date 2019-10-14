// Problem D
// 
#include<cmath>
#include<cstdlib>
#include<cstdio>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;
#define MAX_W 105
#define MAX_H 105

struct Tetro {
  //int type;
  //int rotate;
  int wid;
  int hei;
  int loc_x;
  int loc_y;
  char** content;
};

char map[MAX_W][MAX_H];
int map_wid;
int map_hei;
Tetro std_tetro[8][4];

void PrintTetro(const Tetro tetro) {
  cout << "Tetro: " << endl;
  for (int y = 0; y < tetro.hei; ++y) {
    for (int x = 0; x < tetro.wid; ++x) {
      cout << tetro.content[y][x];
    }
    cout << endl;
  }
}
void PrintMap(void) {
  for (int y = 0; y < map_hei; ++y) {
    for (int x = 0; x < map_wid; ++x) {
      cout << map[y][x];
    }
    cout << endl;
  }
}
void PrintAllTetro(void) {
  for (int t = 1; t <= 7; ++t) {
    for (int r = 0; r < 4; ++r) {
      cout << "t = " << t << " r = " << r << endl;
      for (int y = 0; y < std_tetro[t][r].hei; ++y) {
        for (int x = 0; x < std_tetro[t][r].wid; ++x) {
          cout << std_tetro[t][r].content[y][x];
        }
        cout << endl;
      }
    }
  }
}
void RotateTetro(const Tetro& from, Tetro& to) {
  to.wid = from.hei;
  to.hei = from.wid;
  to.content = new char*[to.hei];
  for (int y = 0; y < to.hei; ++y) {
    to.content[y] = new char[to.wid];
    for (int x = 0; x < to.wid; ++x) {
      to.content[y][x] = '.';
    }
  }

  for (int y = 0; y < from.hei; ++y) {
    for (int x = 0; x < from.wid; ++x) {
      to.content[to.hei - 1 - x][y] = from.content[y][x];
    }
  }
}

void InitStdTetro(void) {
  for (int t = 1; t <= 7; ++t) {
    switch (t)
    {
    case 1:
      // x.
      // xx
      // .x
      std_tetro[t][0].wid = 2;
      std_tetro[t][0].hei = 3;
      std_tetro[t][0].content = new char*[std_tetro[t][0].hei];
      for (int y = 0; y < std_tetro[t][0].hei; ++y) {
        std_tetro[t][0].content[y] = new char[std_tetro[t][0].wid];
        for (int x = 0; x < std_tetro[t][0].wid; ++x) {
          std_tetro[t][0].content[y][x] = '.';
        }
      }
      std_tetro[t][0].content[0][0] = 'x';
      std_tetro[t][0].content[1][0] = 'x'; std_tetro[t][0].content[1][1] = 'x';
      std_tetro[t][0].content[2][1] = 'x';
      break;
    case 2:
      // .x
      // xx
      // x.
      std_tetro[t][0].wid = 2;
      std_tetro[t][0].hei = 3;
      std_tetro[t][0].content = new char*[std_tetro[t][0].hei];
      for (int y = 0; y < std_tetro[t][0].hei; ++y) {
        std_tetro[t][0].content[y] = new char[std_tetro[t][0].wid];
        for (int x = 0; x < std_tetro[t][0].wid; ++x) {
          std_tetro[t][0].content[y][x] = '.';
        }
      }
      std_tetro[t][0].content[0][1] = 'x';
      std_tetro[t][0].content[1][0] = 'x'; std_tetro[t][0].content[1][1] = 'x';
      std_tetro[t][0].content[2][0] = 'x';
      break;
    case 3:
      // x.
      // x.
      // xx
      std_tetro[t][0].wid = 2;
      std_tetro[t][0].hei = 3;
      std_tetro[t][0].content = new char*[std_tetro[t][0].hei];
      for (int y = 0; y < std_tetro[t][0].hei; ++y) {
        std_tetro[t][0].content[y] = new char[std_tetro[t][0].wid];
        for (int x = 0; x < std_tetro[t][0].wid; ++x) {
          std_tetro[t][0].content[y][x] = '.';
        }
      }
      std_tetro[t][0].content[0][0] = 'x';
      std_tetro[t][0].content[1][0] = 'x';
      std_tetro[t][0].content[2][0] = 'x'; std_tetro[t][0].content[2][1] = 'x';
      break;
    case 4:
      // .x
      // .x
      // xx
      std_tetro[t][0].wid = 2;
      std_tetro[t][0].hei = 3;
      std_tetro[t][0].content = new char*[std_tetro[t][0].hei];
      for (int y = 0; y < std_tetro[t][0].hei; ++y) {
        std_tetro[t][0].content[y] = new char[std_tetro[t][0].wid];
        for (int x = 0; x < std_tetro[t][0].wid; ++x) {
          std_tetro[t][0].content[y][x] = '.';
        }
      }
      std_tetro[t][0].content[0][1] = 'x';
      std_tetro[t][0].content[1][1] = 'x';
      std_tetro[t][0].content[2][0] = 'x'; std_tetro[t][0].content[2][1] = 'x';
      break;
    case 5:
      // xx
      // xx
      std_tetro[t][0].wid = 2;
      std_tetro[t][0].hei = 2;
      std_tetro[t][0].content = new char*[std_tetro[t][0].hei];
      for (int y = 0; y < std_tetro[t][0].hei; ++y) {
        std_tetro[t][0].content[y] = new char[std_tetro[t][0].wid];
        for (int x = 0; x < std_tetro[t][0].wid; ++x) {
          std_tetro[t][0].content[y][x] = 'x';
        }
      }
      break;
    case 6:
      // x
      // x
      // x
      // x
      std_tetro[t][0].wid = 1;
      std_tetro[t][0].hei = 4;
      std_tetro[t][0].content = new char*[std_tetro[t][0].hei];
      for (int y = 0; y < std_tetro[t][0].hei; ++y) {
        std_tetro[t][0].content[y] = new char[std_tetro[t][0].wid];
        for (int x = 0; x < std_tetro[t][0].wid; ++x) {
          std_tetro[t][0].content[y][x] = 'x';
        }
      }
      break;
    case 7:
      // .x.
      // xxx
      std_tetro[t][0].wid = 3;
      std_tetro[t][0].hei = 2;
      std_tetro[t][0].content = new char*[std_tetro[t][0].hei];
      for (int y = 0; y < std_tetro[t][0].hei; ++y) {
        std_tetro[t][0].content[y] = new char[std_tetro[t][0].wid];
        for (int x = 0; x < std_tetro[t][0].wid; ++x) {
          std_tetro[t][0].content[y][x] = '.';
        }
      }
      std_tetro[t][0].content[0][1] = 'x';
      std_tetro[t][0].content[1][0] = 'x'; std_tetro[t][0].content[1][1] = 'x'; std_tetro[t][0].content[1][2] = 'x';
      break;
    }
    for (int r = 1; r < 4; ++r) {
      RotateTetro(std_tetro[t][r - 1], std_tetro[t][r]);
    }
  }
}
void InitMap(void) {
  for (int y = 0; y < map_hei; ++y) {
    for (int x = 0; x < map_wid; ++x) {
      map[y][x] = '.';
    }
  }
}
// false means cannot put Tetro
bool PutTetro(Tetro& tetro) {
  for (int loc_y = map_hei - 1; loc_y >= 0; --loc_y) {
    if (loc_y < tetro.hei - 1) {
      return false;
    }
    else {
      bool can_put = true;
      for (int y = 0; y < tetro.hei && can_put; ++y) {
        for (int x = 0; x < tetro.wid && can_put; ++x) {
          if (tetro.content[y][x] == 'x' && map[loc_y - (tetro.hei - y - 1)][tetro.loc_x + x] == 'x') {
            can_put = false;
            break;
          }
        }
      }
      if (can_put) {
        // put tetro
        tetro.loc_y = loc_y;
        for (int y = 0; y < tetro.hei; ++y) {
          for (int x = 0; x < tetro.wid; ++x) {
            if (tetro.content[y][x] == 'x') {
              map[loc_y - (tetro.hei - y - 1)][tetro.loc_x + x] = 'x';
            }
          }
        }
        return true;
      }
    }
  }
  return false;
}
void ClearRow(void) {
  for (int y = map_hei - 1; y >= 0; --y) {
    bool is_clear = true;
    for (int x = 0; x < map_wid; ++x) {
      if (map[y][x] == '.') {
        is_clear = false;
        break;
      }
    }
#ifdef _DEBUG
    PrintMap();
#endif
    if (is_clear) {
      for (int cur_y = y; cur_y >= 0; --cur_y) {
        for (int x = 0; x < map_wid; ++x) {
          if (cur_y > 0) {
            map[cur_y][x] = map[cur_y - 1][x];
          }
          else {
            map[cur_y][x] = '.';
          }
          
        }
      }
      ++y;
    }
  }
}
int main(void) {
#ifndef _DEBUG
  freopen("D-small-attempt1.in", "r", stdin);
  freopen("D-small-attempt1.out", "w", stdout);
#endif
  InitStdTetro();
  //PrintAllTetro();
 
  int test_case = 0;
  cin >> test_case;
  for (int t_idx = 1; t_idx <= test_case; ++t_idx) {
    
    cout << "Case #" << t_idx << ":" << endl;
    cin >> map_wid >> map_hei;
    InitMap();
    int tetro_num = 0;
    int is_over = false;
    cin >> tetro_num;
    // put tetro one by one
    for (int i = 0; i < tetro_num; ++i) {
      int type = 0;
      int rotate = 0;
      int loc_x = 0;
      cin >> type >> rotate >> loc_x;
      if (is_over) {
        continue;
      }
      Tetro tmp = std_tetro[type][rotate];
      tmp.loc_x = loc_x;

      if (PutTetro(tmp)) {
        // put tetro and clear row
        ClearRow();
      }
      else {
        is_over = true;  
      }
#ifdef _DEBUG
      PrintTetro(tmp);
      PrintMap();
#endif
    }
    if (!is_over) {
      PrintMap();
    } else {
      cout << "Game Over!" << endl;
    }
  }
  // Problem D
  return 0;
}