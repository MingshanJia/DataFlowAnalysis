#include <iostream>
#include <vector>
#include <map>

using namespace std;

void dfs(vector<int>& orientation,
         const vector<pair<int,int>>& edges,
         const vector<vector<int>>& ins,
         const vector<vector<int>>& outs,
         vector<bool>& visited,
         int cur)
{
    if (visited[cur])
    {
        return;
    }
    
    visited[cur] = true;
    for (const auto& e : outs[cur])
    {
        int next = edges[e].second;
        if (!visited[next])
        {
            orientation[e] = 1;
            dfs(orientation, edges, ins, outs, visited, next);
        }
        else if (orientation[e] == 0)
        {
            orientation[e] = 1;
        }
    }
    for (const auto& e : ins[cur])
    {
        int next = edges[e].first;
        if (!visited[next])
        {
            orientation[e] = -1;
            dfs(orientation, edges, ins, outs, visited, next);
        }
        else if (orientation[e] == 0)
        {
            orientation[e] = -1;
        }
    }
}

bool circle_aug(vector<int>& score,
                const vector<int>& orientation,
                const vector<pair<int,int>>& edges,
                const vector<vector<int>>& ins,
                const vector<vector<int>>& outs,
                vector<bool>& visited,
                int start, int cur)
{
    if (start == cur)
    {
        return true;
    }
    if (visited[cur])
    {
        return false;
    }
    
    visited[cur] = true;
    for (const auto& e : outs[cur])
        if (orientation[e] == 1)
        {
            int next = edges[e].second;
            if (!visited[next] && circle_aug(score, orientation, edges, ins, outs, visited, start, next))
            {
                score[e] ++;
                return true;
            }
        }
    for (const auto& e : ins[cur])
        if (orientation[e] == -1)
        {
            int next = edges[e].first;
            if (!visited[next] && circle_aug(score, orientation, edges, ins, outs, visited, start, next))
            {
                score[e] --;
                return true;
            }
        }
    return false;
}

int main()
{
    int T;

    cin >> T;
    for (int ct = 0; ct < T; ++ct)
    {
        int f, p;
        cin >> f >> p;
        vector<vector<int>> outs(f), ins(f);
        vector<pair<int,int>> edges;
        vector<int> orientation(p);
        vector<int> scores(p);
        bool fail = false;
        for (int i = 0; i < p; ++i)
        {
            int a, b;
            cin >> a >> b;
            a --;
            b --;
            int e = (int)edges.size();
            edges.push_back(make_pair(a, b));
            outs[a].push_back(e);
            ins[b].push_back(e);
        }

        {
            vector<bool> visited(f);
            for (int i = 0; i < f; ++i)
            {
                if (!visited[i])
                {
                    dfs(orientation, edges, ins, outs, visited, i);
                }
            }
        }
        for (int i = 0; i < p; ++i)
            if (orientation[i] == 0)
            {
                fail = true;
            }

        for (int i = 0; i < p && !fail; ++i)
            if (scores[i] == 0)
            {
                vector<bool> visited(f);
                int start, end;
                if (orientation[i] == 1)
                {
                    start = edges[i].first;
                    end = edges[i].second;
                }
                else
                {
                    start = edges[i].second;
                    end = edges[i].first;
                }
                if (circle_aug(scores, orientation, edges, ins, outs, visited, start, end))
                {
                    scores[i] += orientation[i];
                }
                else
                {
                    fail = true;
                }
            }
        if (fail)
        {
            cout << "Case #" << (ct + 1) << ": IMPOSSIBLE" << endl;
        }
        else
        {
            cout << "Case #" << (ct + 1) << ":";
            for (size_t i = 0; i < scores.size(); ++i)
            {
                if (scores[i] == 0 || scores[i] > f * f || scores[i] < -f * f)
                {
                    cerr << "Ouch! " << scores[i] << endl;
                }
                cout << " " << scores[i];
            }
            cout << endl;
        }
    }
    return 0;
}
