#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>

using namespace std;

typedef pair<int,int> pii;

long long calc() {
    int P, Q;
    cin >> P >> Q;
    vector<int> v(Q);
    for (int i = 0; i < Q; i++) cin >> v[i];
    sort(v.begin(), v.end());
    long long res = 1000000000;
    // only small
    do {
        vector<pair<int,int> > vInt;
        vInt.push_back(pii(1, P));
        long long now = 0;
        for (int i = 0; i < Q; i++) {
            for (int j = 0; j < vInt.size(); j++) {
                if (vInt[j].first <= v[i] && v[i] <= vInt[j].second) {
                    now += vInt[j].second - vInt[j].first;
                    vInt.push_back(pii(v[i] + 1, vInt[j].second));   
                    vInt[j] = pii(vInt[j].first, v[i] - 1);
                    break;                              
                }    
            }
        }
        if (now < res) res = now;
    } while(next_permutation(v.begin(), v.end()));
    
    return res;
}

int main() {
    int T;
    cin >> T >> ws;
    for (int i = 1; i <= T; i++) {
        cout << "Case #" << i << ": " << calc() << endl;
    }
}
