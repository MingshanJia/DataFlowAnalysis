#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

const int dy[4]={1, 0, -1, 0};
const int dx[4]={0, -1, 0, 1};

const int wf[4]={2, 4, 1, 8};
const int wb[4]={1, 8, 2, 4};

char p1[10008], p2[10008];

char getCode(char c);

int main() {
  int t, T;
  int i, j;
  int x, y, d;
  int min_x, min_y;
  int max_x, max_y;
  scanf("%d", &T);
  for (t=1; t<=T; t++) {
    scanf("%s %s", p1, p2);
    d=0;
    min_x=max_x=x=0;
    min_y=max_y=y=0;
    for (i=1; p1[i+1]; i++) {
      switch (p1[i]) {
        case 'W': x+=dx[d]; y+=dy[d]; break;
        case 'R': d=(d+1)%4; break;
        case 'L': d=(d+3)%4; break;
      }
      min_x=min(min_x, x); min_y=min(min_y, y);
      max_x=max(max_x, x); max_y=max(max_y, y);
    }
    d=(d+2)%4;
    for (i=1; p2[i+1]; i++) {
      switch (p2[i]) {
        case 'W': x+=dx[d]; y+=dy[d]; break;
        case 'R': d=(d+1)%4; break;
        case 'L': d=(d+3)%4; break;
      }
      min_x=min(min_x, x); min_y=min(min_y, y);
      max_x=max(max_x, x); max_y=max(max_y, y);
    }
    vector<string> fd(max_y-min_y+1, string(max_x-min_x+1, '\0'));
    d=0;
    x=-min_x;
    y=-min_y;
    fd[y][x]|=wb[d];
    for (i=1; p1[i+1]; i++)
      switch (p1[i]) {
        case 'W':
          fd[y][x]|=wf[d];
          x+=dx[d];
          y+=dy[d];
          fd[y][x]|=wb[d];
          break;
        case 'R': d=(d+1)%4; break;
        case 'L': d=(d+3)%4; break;
      }
    fd[y][x]|=wf[d];
    d=(d+2)%4;
    for (i=1; p2[i+1]; i++)
      switch (p2[i]) {
        case 'W':
          fd[y][x]|=wf[d];
          x+=dx[d];
          y+=dy[d];
          fd[y][x]|=wb[d];
          break;
        case 'R': d=(d+1)%4; break;
        case 'L': d=(d+3)%4; break;
      }
    for (i=0; i<fd.size(); i++)
      for (j=0; j<fd[i].length(); j++)
        fd[i][j]=getCode(fd[i][j]);
    printf("Case #%d:\n", t);
    for (i=0; i<fd.size(); i++)
      puts(fd[i].c_str());
  }
  return 0;
}

char getCode(char c) {
  return (c<10 ? '0'+c : 'a'+(c-10));
}
