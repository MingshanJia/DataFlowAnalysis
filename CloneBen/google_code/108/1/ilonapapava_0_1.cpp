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
        int f, s;
        cin >> f >> s;
        s+=2;
        vector<vector<int>> vec(s);
        for (int i = 0; i < s; ++i) {
            vec[i].resize(s);
        }
        for (int i= 0; i < f; ++i) {
            int a, b;
            cin >> a >> b;
            vec[a][b] = 1;
            vec[b][a] = 1;
        }
        
        int maxi = 0;
        for (int i = 0; i < s; ++i) {
            int cur = 0;
            for (int j = 0; j < s; ++j) {
                if (vec[i][j]) {
                    cur++;
                }
            }
            maxi = max(maxi, cur);
        }
        cout << "Case #" << kkk +1 << ": " << maxi << endl;
    }
    return 0;
}
