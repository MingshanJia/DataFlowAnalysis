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
        int d, n;
        cin >> d >> n;
        d = 15;
        vector<vector<char>> vec(15, vector<char>(15));
        for (int i = 0; i < d; ++i) {
            char a, b;
            if (i % 2 == 0) {
                a = 'I';
                b = 'O';
            } else {
                a = 'O';
                b = 'I';
            }
            for (int j = 0; j < d; ++j) {
                if (j % 4 == 0) {
                    vec[i][j] = a;
                } else if (j % 4 == 2) {
                    vec[i][j] = b;
                } else {
                    vec[i][j] = '/';
                }
            }
        }
        int current = 287;
        int curi = 1, curj = 1;
        while (curi < d - 1 && current >= n + 3) {
            vec[curi][curj] = 'O';
            curj += 2;
            if (curj >= d) {
                curj = 1;
                curi++;
            }
            current -= 3;
        }
        int difference = current - n;
        curj = 1;
        for (int i = 0; i < difference; ++i) {
            vec[0][curj] = 'O';
            curj += 2;
            if (curj > d) {
                break;
            }
            current--;
        }
        difference = current - n;
        curj = 1;
        for (int i = 0; i < difference; ++i) {
            vec[d - 1][curj] = 'O';
            curj += 2;
            if (curj > d) {
                break;
            }
            current--;
        }
        cout << "Case #" << kkk +1 << ": " << endl;
        for (int i = 0; i < d; ++i) {
            for (int j = 0; j < d; ++j) {
                cout << vec[i][j];
            }
            cout << endl;
        }
    }
    return 0;
}
