#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

bool dfs(string be, unordered_map<string, int>& tMap, unordered_map<string, unordered_set<string>>& aMap)
{
    int target;
    if (tMap[be] == 1)
        target = 2;
    else
        target = 1;
    for (auto i :aMap[be])
    {
        if (tMap.count(i)!=0)
        {
            if (tMap[i] !=target)
                return false;
            continue;
        }
        tMap[i] = target;
        if (!dfs(i, tMap, aMap))
            return false;
    }

    return true;
}

bool solve(unordered_map<string, unordered_set<string>> aMap)
{
    unordered_map<string, int> tMap;
    //1->black 2->red
    for (auto i : aMap)
    {
        if (tMap.count(i.first)==0)
        {
            tMap[i.first] = 1;
            if (!dfs(i.first, tMap, aMap))
                return false;
        }
    }
    return true;
}

int main()
{
    freopen("input.in", "r", stdin);
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        int N;
        cin >> N;

        unordered_map<string, unordered_set<string>> tmp;
        string n1, n2;
        for (int j = 0; j < N; j++)
        {
            cin >> n1 >> n2;
            tmp[n1].insert(n2);
            tmp[n2].insert(n1);
        }


        if (solve(tmp))
            cout << "Case #" << i+1 << ": "<< "Yes" << endl;
        else
            cout << "Case #" << i+1 << ": " << "No" << endl;
    }
    return 0;
}
