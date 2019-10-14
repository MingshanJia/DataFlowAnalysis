//
//  main.cpp
//  GG_onsite
//
//  Created by 祝风翔 on 15/8/14.
//  Copyright (c) 2015年 祝风翔. All rights reserved.
//

#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <string>
#include <time.h>
#include <vector>
#include <unordered_map>
#include <queue>
#include <map>
using namespace std;



vector<string>E;
int main(){
    freopen("C-small-1-attempt1.in","r",stdin);
    freopen("C-small-1-attempt1.out","w",stdout);
    int T,cas = 0;
    scanf("%d",&T);
    while(T--) {
        E.clear();
        int n;
        scanf("%d",&n);
        getchar();
        for(int i = 0;i < n;i++) {
            char str[100 + 5];
            gets(str);
            string tmp;
            for(int j = 0;j < strlen(str);j++)
                tmp += str[j];
            E.push_back(tmp);
        }
        int cost = 0;
        for(int i = 0;i < E.size();i++) {
            if(i > 0 && E[i] < E[i-1]) {
                cost++;
                int cur = i - 1;
                while(cur >= 0 && E[cur] > E[cur + 1]) {
                    swap(E[cur],E[cur+1]);
                    cur--;
                }
            }
        }
        printf("Case #%d: %d\n",++cas,cost);
    }
    return 0;
}