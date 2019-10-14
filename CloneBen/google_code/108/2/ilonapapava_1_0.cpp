//
//  main.cpp
//  GCJ
//
//  Created by Ilona Papava on 3/11/17.
//  Copyright © 2017 Ilona Papava. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    freopen ("input.txt","r",stdin);
    freopen ("output.txt","w",stdout);
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    cin >> t;
    for (int kkk = 0; kkk < t; ++kkk) {
        int n;
        cin >> n;
        vector<double> prob(2*n);
        for (int i = 0; i < 2*n; ++i) {
            cin >> prob[i];
        }
        sort(prob.begin(), prob.end());
        double res = 1.0;
        for (int i = 0; i < n; ++i) {
            res *= (1.0 - prob[i] * prob[2*n - i - 1]);
        }
        std::cout.precision(6);
        cout << "Case #" << kkk +1 << ": " << fixed << res << endl;
    }
    return 0;
}
