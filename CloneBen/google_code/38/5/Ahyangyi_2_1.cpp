#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct route
{
    int start, end, st, dur;
};

inline int delay_time(route a, route b)
{
    return (b.st + 24 - (a.st + a.dur) % 24) % 24;
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
        vector<vector<int>> ins(c);
        vector<vector<int>> outs(c);
        int ans = 0;
        for (int i = 0; i < c * 2; ++i)
        {
            int start = i / 2;
            int end, st, dur;
            cin >> end >> st >> dur;
            end--;
            int r = routes.size();
            routes.push_back(route{start, end, st, dur});
            ans += dur;
            outs[start].push_back(r);
            ins[end].push_back(r);
        }
        int best_delay = -1;
        for (int z = 0; z <= 1; ++z)
        {
            vector<int> next(c * 2);
            vector<int> alt(c);
            vector<int> pick(c);
            int total_delay = 0;
            for (int i = 0; i < c; ++i)
            {
                int a, b, delay;
                if (i == 0)
                {
                    a = min(
                            delay_time(routes[ins[i][0]], routes[outs[i][0]]) + routes[outs[i][1]].st,
                            delay_time(routes[ins[i][1]], routes[outs[i][1]]) + routes[outs[i][0]].st
                        );
                    b = min(
                            delay_time(routes[ins[i][0]], routes[outs[i][1]]) + routes[outs[i][0]].st,
                            delay_time(routes[ins[i][1]], routes[outs[i][0]]) + routes[outs[i][1]].st
                        );
                    pick[i] = z;
                    if (z == 0)
                    {
                        delay = a;
                    }
                    else
                    {
                        delay = b;
                    }
                    alt[i] = 0;
                }
                else
                {
                    a = delay_time(routes[ins[i][0]], routes[outs[i][0]]) + delay_time(routes[ins[i][1]], routes[outs[i][1]]);
                    b = delay_time(routes[ins[i][0]], routes[outs[i][1]]) + delay_time(routes[ins[i][1]], routes[outs[i][0]]);
                    if (a < b)
                    {
                        pick[i] = 0;
                        delay = a;
                    }
                    else
                    {
                        pick[i] = 1;
                        delay = b;
                    }
                    alt[i] = (a == b);
                }

                if (pick[i] == 0)
                {
                    next[ins[i][0]] = outs[i][0];
                    next[ins[i][1]] = outs[i][1];
                }
                else
                {
                    next[ins[i][0]] = outs[i][1];
                    next[ins[i][1]] = outs[i][0];
                }

                total_delay += delay;
            }
            while (true)
            {
                vector<int> colors(c * 2);
                int tc = 0;
                for (int i = 0; i < c * 2; ++i)
                {
                    if (colors[i] == 0)
                    {
                        tc ++;
                        int j = i;
                        while (colors[j] == 0)
                        {
                            colors[j] = tc;
                            j = next[j];
                        }
                    }
                }
                if (tc > 1)
                {
                    bool changed = false;
                    for (int i = 0; i < c; ++i)
                        if (alt[i] && colors[ins[i][0]] != colors[ins[i][1]])
                        {
                            alt[i] = 0;
                            pick[i] = !pick[i];
                            if (pick[i] == 0)
                            {
                                next[ins[i][0]] = outs[i][0];
                                next[ins[i][1]] = outs[i][1];
                            }
                            else
                            {
                                next[ins[i][0]] = outs[i][1];
                                next[ins[i][1]] = outs[i][0];
                            }
                            changed = true;
                            break;
                        }
                    if (changed)
                    {
                        continue;
                    }
                    else
                    {
                        total_delay += (tc - 1) * 24;
                        break;
                    }
                }
                else
                {
                    break;
                }
            }
            if (best_delay == -1 || total_delay < best_delay)
            {
                best_delay = total_delay;
            }
        }
        ans += best_delay;
        cout << "Case #" << (ct + 1) << ": " << ans << endl;
    }
    return 0;
}
