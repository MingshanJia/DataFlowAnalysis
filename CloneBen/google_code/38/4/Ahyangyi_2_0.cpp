#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct route
{
    int start, end, st, dur;
};

int dfs(int state, int cur, const vector<route>& routes, 
        map<pair<int, int>, int>& memoir)
{
    if (memoir.find(make_pair(state, cur)) != memoir.end())
    {
        return memoir[make_pair(state, cur)];
    }
    if (state == 0)
    {
        return 0;
    }
    int ans = -1;
    for (size_t i = 0; i < routes.size(); ++i)
        if ((state & (1 << i)) && (routes[i].end == cur))
        {
            int time = dfs(state &~ (1 << i), routes[i].start, routes, memoir);
            if (time == -1)
            {
                continue;
            }
            int new_ans = time + (24 + routes[i].st - time % 24) % 24 + routes[i].dur;
            if (ans == -1 || new_ans < ans)
            {
                ans = new_ans;
            }
        }
    memoir[make_pair(state, cur)] = ans;
    return ans;
}

int main()
{
    int T;

    cin >> T;
    for (int ct = 0; ct < T; ++ct)
    {
        int c;
        cin >> c;
        vector<route> routes;
        map<pair<int, int>, int> memoir;
        for (int i = 0; i < c * 2; ++i)
        {
            int start = i / 2;
            int end, st, dur;
            cin >> end >> st >> dur;
            end--;
            routes.push_back(route{start, end, st, dur});
        }
        cout << "Case #" << (ct + 1) << ": " << dfs((1 << (c * 2)) - 1, 0, routes, memoir) << endl;
    }
    return 0;
}
