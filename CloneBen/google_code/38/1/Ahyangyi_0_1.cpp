#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

map<string, long long> memory;

long long dfs(string s);
long long enumerate(string& s, string& t, size_t total)
{
    if (t.size() == s.size())
    {
        return dfs(t);
    }

    long long ret = 0;
    for (size_t i = 0; i <= s.size(); ++i)
    {
        if (i == 0 && t.size() + total + 1 > s.size())
            continue;
        if (i > 0 && s[i - 1] == '0')
            continue;
        if (i > 0) s[i - 1] --;
        t.push_back('0' + i);
        ret += enumerate(s, t, total - (i > 0));
        if (i > 0) s[i - 1] ++;
        t.pop_back();
    }

    return ret;
}

long long dfs(string s)
{
    if (memory.find(s) != memory.end())
    {
        return memory[s];
    }

    memory[s] = 0;
    size_t total = 0, total_2 = 0;
    for (size_t i = 0; i < s.size(); ++i)
    {
        total += s[i] - '0';
        total_2 += (i + 1) * (s[i] - '0');
    }
    if (total > s.size())
    {
        return (memory[s] = 1);
    }
    if (total_2 > s.size())
    {
        // 3
        // 2 0 1 -> perm(1 1 3) -> 3
        // 1 0 1 -> perm(0 1 3) -> 6
        long long ret = 1;
        for (size_t i = 1; i <= s.size(); ++i)
        {
            ret *= i;
        }
        for (size_t i = 0; i < s.size(); ++i)
            for (int j = 1; j <= s[i] - '0'; ++j)
                ret /= j;
        for (int j = 1; j <= (int)s.size() - (int)total; ++j)
            ret /= j;
        return (memory[s] = ret + 1);
    }

    string t = "";
    memory[s] = 1 + enumerate(s, t, total);
    return memory[s];
}

int main()
{
    int T;

    cin >> T;
    for (int ct = 0; ct < T; ++ct)
    {
        string s;
        cin >> s;
        cout << "Case #" << (ct + 1) << ": " << dfs(s) << endl;
    }
    return 0;
}
