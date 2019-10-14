#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <stdio.h>
#include <iomanip>


using namespace std;

int main()
{
    ifstream input;

    input.open("B-small-attempt0.in");
    //input.open("input.txt");
    ofstream output;
    output.open("output.txt", ios::out | ios::app);
    if(input == NULL)
    {
        cerr << "cannot open file" << endl;
    }
    if(output == NULL){
        cerr << "cannot create output file" << endl;
    }
    int T;
    input >> T;
    int n = 0;
    int a, b, alpha, beta, y;
    while(n < T){
        input >> a >> b >> alpha >>beta >>y;
        int k;
        for(int i = 0 ; i < y; i++){
            if(a > b){
                k = b;
            }else{
                k = a;
            }
            k = k * 2 / 100;
            int alphaBaby = k * alpha / 100;
            int betaBaby = k * beta /100;
            int half = (k-alphaBaby - betaBaby)/2;
            int da = a /100;
            int db = b /100;
            a = a + half + alphaBaby;
            b = b + (k-alphaBaby - betaBaby -half) + betaBaby;
            a = a - da;
            b = b- db;

        }
        cout << a << " " << b << endl;
        output << "Case #"<< n+1 <<": "<< a << " " <<b << endl;
        n++;
    }
    output.close();
    return 0;
}
