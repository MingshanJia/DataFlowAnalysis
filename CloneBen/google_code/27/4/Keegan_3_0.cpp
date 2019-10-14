#include <algorithm>
#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

int T, N, M;

enum State {
    UNDECIDED,
    TRUTH,
    LIAR,
    UNKNOWN,
} people[10];

struct Rule {
    int i, j, k;
    char r;
} rules[500];

bool state[10];


bool next(int i) {
    if (i == N)
        return false;
    state[i] = !state[i];
    if (!state[i])
        return next(i + 1);
    else
        return true;
}

bool consistent() {
    for (int m = 0; m < M; m++) {
        int i = rules[m].i - 1;
        int j = rules[m].j - 1;
        int k = rules[m].k - 1;
        char r = rules[m].r;

        switch(r) {
        case 'T': if (!(state[i] == state[j])) return false;
            break;
        case 'L': if (!(state[i] != state[j])) return false;
            break;
        case 'S': if (!(state[i] == (state[j] == state[k]))) return false;
            break;
        case 'D': if (!(state[i] == (state[j] != state[k]))) return false;
            break;
        default:
            assert(false);
        }
    }
    return true;
}

int main() {
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cin >> N >> M;

        fill(state, state + N, false);
        fill(people, people + N, UNDECIDED);

        for (int m = 0; m < M; m++) {
            cin >> rules[m].i >> rules[m].r >> rules[m].j;
            if (rules[m].r == 'S' || rules[m].r == 'D')
                cin >> rules[m].k;
        }

        do {
            if (!consistent())
                continue;

            for (int n = 0; n < N; n++) {
                if (people[n] == UNDECIDED) {
                    people[n] = state[n] ? TRUTH : LIAR;
                } else if (state[n] && people[n] != TRUTH) {
                    people[n] = UNKNOWN;
                } else if (!state[n] && people[n] != LIAR) {
                    people[n] = UNKNOWN;
                }
            }
        } while(next(0));

        cout << "Case #" << t << ":";
        for (int n = 0; n < N; n++) {
            cout << ' ';
            if (people[n] == TRUTH)
                cout << 'T';
            else if (people[n] == LIAR)
                cout << 'L';
            else
                cout << '-';
        }
        cout << '\n';
    }
}
