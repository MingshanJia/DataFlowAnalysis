#include <iostream>
#include <vector>
#include <cstring>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <map>
#include <math.h>

using namespace std;

int a[110];
int b[110];
int main() {
    freopen("../C-small-attempt0.in", "r", stdin);
    freopen("../out.txt", "w", stdout);
   
    int T;
    cin >> T;
    int C = 1;
    while (T --) {
        int n;
        scanf("%d", &n);
        vector<string> vec;
        for (int i = 0; i < 3; i ++) {
            string tmp;
            cin >> tmp;
            vec.push_back(tmp);
        }
        map<string,int> mp;
        vector<string> all={"012", "021", "102"};
        vector<string> rev_all = {"ABC", "ACB", "BAC"};
        for (int i = 0; i < all.size(); i ++) {
            vector<string> new_vec;
            for (int j = 0;j < 3; j ++) {
                string cur = vec[j];
                for (int k = 0;k < n; k ++) {
                    cur[k] = all[i][cur[k] - 'A'];
                }
                new_vec.push_back(cur);
            }
            sort(new_vec.begin(), new_vec.end());
            string mid = new_vec[1];
            for (int j = 0;j < n;j ++) {
                mid[j] = rev_all[i][mid[j] - '0'];
            }
            mp[mid] = 1;
        }
        printf("Case #%d:", C++);
        for (int i = 0;i < 3; i ++) {
            if (mp[vec[i]] == 1) {
                printf(" YES");
            }
            else {
                printf(" NO");
            }
        }
        puts("");
    }
}