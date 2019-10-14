#include <iostream>
#include <fstream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <cassert>

using namespace std;

int memo[1500][1500][2];

void do_case(const int cn) {
    int NA, NB;
    cin >> NA >> NB;
    const int NN = 1440;
    vector<int> data(NN, -1); //0 = A, 1 = B
    for(int i=0;i<NA;++i) {
        int start, finish;
        cin >> start >> finish;
        for(int j=start;j<finish;++j) {
            data[j] = 0;
        }
    }
    for(int i=0;i<NB;++i) {
        int start, finish;
        cin >> start >> finish;
        for(int j=start;j<finish;++j) {
            assert(data[j] != 0);
            data[j] = 1;
        }
    }
    int allout = 150000;
    for(int start_data=0;start_data<2;++start_data) {
    for(int end_data=0;end_data<2;++end_data) {
        int sure = (start_data != end_data);
        if(start_data == data[0]){continue;}
        if(end_data == data[NN-1]){continue;}
        memset(memo, 0x3f, sizeof(memo));
        memo[NN][0][0] = memo[NN][0][1] = 0;
        for(int at=NN-1;at>=0;--at) {
            for(int left=NN;left>=0;--left) {
                for(int last=0;last<2;++last) {
                    int out = 153153;
                    for(int touse=0;touse<2;++touse) {
                        if(touse == data[at]){continue;}
                        if(at==0 && touse != start_data){continue;}
                        if(at==NN-1 && touse != end_data){continue;}
                        int nleft = (touse==0)?(left-1):(left);
                        if(nleft >= 0) {
                            out = min(out, (touse != last) + memo[at+1][nleft][touse]);
                        }
                    }
                    memo[at][left][last] = out;
                }
            }
        }
        allout = min(allout, memo[0][720][end_data]);
    }
    }
    printf("Case #%d: %d\n", cn, allout);
}

int main(int argc, char **argv)
{
    int CASES;
    cin >> CASES;
    for(int cn=1;cn<=CASES;++cn) {
        do_case(cn);
    }

    return 0;
}
