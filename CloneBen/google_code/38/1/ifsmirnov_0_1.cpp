#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define fore(i, b, e) for (int i = (int)(b); i <= (int)(e); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long i64;
typedef unsigned long long u64;
typedef long double ld;
typedef long long ll;
#define CLR(x) memset(x, 0, sizeof x)
#define cout _mycout_

#define PROD 1

int f(int x) {
    int s = 1;
    forn(i, x) s *= i+1;
    return s;
}


int poly(string s) {
    int cnt[20];
    memset(cnt, 0, sizeof cnt);
    for (char c: s) ++cnt[c-'0'];
    int res = f(s.size());
    forn(i, 10) res /= f(cnt[i]);
    return res;
}

struct Solver {
    int caseno;
    ostream& cout;

    Solver(int caseno, ostream& cout) : caseno(caseno), cout(cout) {}

    int n;
    string s;

    void read() {
        cin >> s;
        n = s.size();
    }

    string gen(string s) {
        string t;
        forn(i, s.size()) {
            forn(j, s[i]-'0') {
                t += '0'+i+1;
            }
        }
        if (t.empty() || t.size() > s.size()) return "";
        t = string(s.size()-t.size(), '0') + t;
//         cerr << t << endl;
        return t;
    }

    void solve() {
        int ss = 0;
        forn(i, n) ss += s[i]-'0';
        if (ss > n) {
            cout << "Case #" << caseno+1 << ": 1\n";
            return;
        }
        set<string> used{s};
        vector<string> q{s};
        int res = 0;
        forn(i, q.size()) {
            string s = q[i];
//             cerr << s << endl;
            string t = gen(s);
            if (t.empty()) continue;
            assert(is_sorted(all(t)));
            assert(count(all(t), '0') < (int)t.size());
            int ss = 0;
            forn(i, n) ss += t[i]-'0';
            if (ss > n) {
                if (used.count(t)) continue;
                used.insert(t);
                res += poly(t);
                continue;
            }
            do {
                if (!used.count(t)) {
//                     cerr << " " << t << endl;
                    used.insert(t);
                    q.pb(t);
                }
            } while (next_permutation(all(t)));
        }
        cout << "Case #" << caseno+1 << ": ";
        cout << res+q.size() << endl;
    }
};

#undef cout

struct ThreadPool {
    int threadNo;
    int taskNo;
    int nextTask;
    int maxTime;
    std::vector<std::string> output;

    std::mutex mutex;
    std::chrono::time_point<std::chrono::steady_clock> start;

    static constexpr const char* GREEN = "\033[32;3m";
    static constexpr const char* YELLOW = "\033[33;3m";
    static constexpr const char* NONE = "\033[0;m";

    ThreadPool(int threadNo, int taskNo, int maxTime) :
            threadNo(threadNo),
            taskNo(taskNo),
            nextTask(0),
            maxTime(maxTime),
            output(taskNo)
    {
    }

    int duration() {
        return (std::chrono::steady_clock::now() - start).count() / 1000000;
    }

    void payload(int id) {
        while (true) {
            int start = duration();

            mutex.lock();

            if (nextTask >= taskNo) {
                mutex.unlock();
                return;
            }
            int taskId = nextTask++;
            std::ostringstream stream;
            Solver *s = new Solver(taskId, stream);
            s->read();

            std::cerr << YELLOW << "Running task " <<
                taskId+1 << "/" << taskNo <<
                " on thread " << id << NONE << std::endl;

            mutex.unlock();

            s->solve();
            delete s;
            output[taskId] = stream.str();

            mutex.lock();
            int dur = duration();
            std::cerr << GREEN <<  "Task " << taskId+1 << ": " <<
                dur - start << " ms, overall " <<
                dur/1000 << "." << std::setw(3) << std::setfill('0') <<
                dur%1000 << "/" << maxTime << " s" <<
                NONE << std::endl;
            std::cerr << stream.str();
            mutex.unlock();
        }
    }

    void run() {
        start = std::chrono::steady_clock::now();

        std::vector<std::thread> threads;
        for (int i = 0; i < threadNo; ++i) {
            threads.emplace_back([this, i]() { payload(i); });
        }
        for (auto& t: threads) {
            t.join();
        }

        int dur = duration();
        std::cerr << GREEN << "Run " << taskNo << " tasks in " <<
                dur/1000 << "." << std::setw(3) << std::setfill('0') <<
                dur%1000 << " seconds" <<
                NONE << std::endl;
        std::cerr << std::endl;

        for (const auto& s: output) {
            std::cout << s;
        }
    }
};

int main() {
#ifdef LOCAL
#if !PROD
    freopen("a.in", "r", stdin);
#endif
#endif

    const int THREADS = thread::hardware_concurrency();
    const int TIME = 60 * 6;
    (void)(THREADS + TIME);

    int n;
    cin >> n;
    string tmp;
    getline(cin, tmp);

#if PROD
    ThreadPool tp(THREADS, n, TIME);
    tp.run();
#else
    forn(i, n) {
        Solver *s = new Solver(i, cout);
        s->read();
        s->solve();
    }
#endif

#ifdef LOCAL
#if !PROD
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
#endif
    return 0;
}
