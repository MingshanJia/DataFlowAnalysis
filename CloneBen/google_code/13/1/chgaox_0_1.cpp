#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <map>

using namespace std;

int main()
{
  int cases;

  cin >> cases;
  
  int N = 0;
  while (N < cases)
  {
    int M;
    cin >> M;

    int id = 0;
    map<string, int> ids;
    map<int, vector<int> > graph;
    map<int, int> color;

    for (int i = 0; i < M; i++)
    {
      string s1, s2;
      cin >> s1 >> s2;
      if (!ids.count(s1))
      {
        ids[s1] = id++;
        graph[ids[s1]] = vector<int>();
      }
      if (!ids.count(s2))
      {
        ids[s2] = id++;
        graph[ids[s2]] = vector<int>();
      }
      graph[ids[s1]].push_back(ids[s2]);
      graph[ids[s2]].push_back(ids[s1]);
    }

    bool ok = true;
    queue<int> qu;
    color[0] = 0;
    qu.push(0);

    while (qu.size() > 0)
    {
      int cur = qu.front();
      qu.pop();
      int cur_color = color[cur];
      vector<int> nei = graph[cur];
      for (int i = 0; i < nei.size(); i++)
      {
        if (!color.count(nei[i]))
        {
          color[nei[i]] = cur_color ^ 1;
          qu.push(nei[i]);
        }
        else if (color[nei[i]] == cur_color)
        {
          ok = false;
          break;
        }
      }
    }

    if (ok)
    {
      cout << "Case #" << N + 1 << ": " << "Yes\n";
    }
    else
    {
      cout << "Case #" << N + 1 << ": " << "No\n";
    }
    N++;
  }
  return 0;
}
