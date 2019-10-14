#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <map>
#include <cmath>

using namespace std;

int main()
{
  int cases;

  cin >> cases;

  int N = 0;
  while(N < cases)
  {
    N++;

    int M;
    cin >> M;
    string empty;
    getline(cin, empty);

    vector<string> names;
    for (int i = 0; i < M; i++)
    {
      string name;
      getline(cin, name);
      names.push_back(name);
      //cout << "get " << name << "\n";
    }

    if (M == 1)
    {
      cout << "Case #" << N  << ": " << 0 << "\n";
      continue;
    }

    int cnt = 0;
    string max_name = names[0];
    for (int i = 1; i < M; i++)
    {
      //cout << "i " << names[i] << "\n";
      //cout << "i+1 " << names[i + 1] << "\n";
      if (names[i] < max_name)
      {
        cnt++;
      }
      else if (names[i] > max_name)
      {
        max_name = names[i];
      }
    }
    cout << "Case #" << N  << ": " << cnt << "\n";
  }

  return 0;
}
