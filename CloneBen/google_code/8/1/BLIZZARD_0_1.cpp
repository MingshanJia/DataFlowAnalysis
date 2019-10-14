// Problem A
// 
#include "iostream"
#include "fstream"
#include <vector>
#include "algorithm"
#include "queue"

using namespace std;

const int dx[] = { 0, 0, 1, 1, 1, -1, -1, -1 };// up down down  
const int dy[] = { 1, -1, -1, 0, 1, -1, 0, 1 };

char map[302][302];

struct Node
{
  int x, y;
  Node() {}
  Node(int a, int b){
    x = a;
    y = b;
  }
};

int n;

void bsf(int x, int y)
{
  queue<Node> q;
  q.push(Node(x, y));
  while (!q.empty())
  {
    Node tmp = q.front(), tmp1;

    if (map[tmp.x][tmp.y] == '0')
    {
      for (int i = 0; i < 8; i++)
      {
        tmp1.x = tmp.x + dx[i]; tmp1.y = tmp.y + dy[i];
        if (tmp1.x < 1 || tmp1.x > n || tmp1.y < 1 || tmp1.y > n || map[tmp1.x][tmp1.y] == '*') continue;
        q.push(tmp1);
      }
    }

    map[tmp.x][tmp.y] = '*';
    q.pop();
  }
  return;

}

int main(void)
{
  fstream ifile, ofile;

  int ntest;
  ifile.open("A-large.in", ios::in);
  ofile.open("A-large.out", ios::out);

  ifile >> ntest;

  for (int k = 0; k<ntest; k++)
  {
    ifile >> n;

    memset(map, '.', 302 * 302 * sizeof(char));


    for (int i = 1; i <= n; i++)
    {
      for (int j = 1; j <= n; j++)
      {
        ifile >> map[i][j];
      }
    }

    // calcalute 
    for (int i = 1; i <= n; i++)
    {
      for (int j = 1; j <= n; j++)
      {
        if (map[i][j] == '*')
          continue;

        int num = 0;

        for (int mm = 0; mm < 8; mm++)
        {
          int xx = i + dx[mm];
          int yy = j + dy[mm];
          if (xx >= 1 && xx <= n && yy >= 1 && yy <= n && map[xx][yy] == '*')
            num++;
        }

        map[i][j] = num + '0';
      }
    }

    int ans = 0;

    for (int i = 1; i <= n; i++)
    {
      for (int j = 1; j <= n; j++)
      {
        if (map[i][j] == '0')
        {
          bsf(i, j);
          ans++;
        }
      }
    }

    for (int i = 1; i <= n; i++)
    {
      for (int j = 1; j <= n; j++)
      {
        if (map[i][j] != '*')
        {
          ans++;
        }
      }
    }

    ofile << "Case #" << k + 1 << ": " << ans << endl;
  }


  if (ifile.is_open())
    ifile.close();

  if (ofile.is_open())
    ofile.close();

  return 0;
}

