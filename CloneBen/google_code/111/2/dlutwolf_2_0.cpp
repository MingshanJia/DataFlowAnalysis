#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <stdio.h>
#include <iomanip>


using namespace std;

int f(int m){

    if(m ==1 || m == 2)
        return 1;
    else{
        int a = 1;
        for(int i = 1; i < m; i++){
            a = a*i;
        }
        a = a / 2;
       // cout << a << endl;
        return a;
    }
}

int ff(int a, int k, int m){
    int res = 1;
    for(int i = 0; i < a; i++){
        res = res * f(m + 1);
    }
    for(int i = 0; i < k - a; i++){
        res = res * f(m);
    }
    return res;
}


int c(int n, int m){
    int res = 1;
    for(int i= 0; i < m; i++){
        res = res *(n - i);
    }
    for(int i = 0; i < m; i++){
        res = res / (m - i);
    }
    return res;
}
int main()
{
    ifstream input;

    input.open("C-small-attempt0.in");
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
    int l = 0;
    int n, k;
    while(l < T){
        input >> n >> k;
        int a = n % k;
        int m = (n- a)/k;
        int div = 1;

        //cout << "c(" <<n << ", " << m+1 << ") :" << x << endl;
        //cout << "c(" <<n << ", " << m << ") :" << y << endl;
        for(int i = 0; i < a; i++){

            div = div * c(n, m+1);
            //cout << "c(" << n << ", " << m+1 << ") :" << c(n, m+1) << endl;
            n = n - (m+1);
        }
        for(int i = 0; i < k - a; i++)
        {
            div = div * c(n, m);
            //cout << "c(" << n << ", " << m << ") :" << c(n, m) << endl;
            n = n - m;
        }
        for(int i = 1; i <= a; i ++){
            div = div / i;
        }
        for(int i = 1; i <= k -a; i++){
            div = div / i;
        }
        cout << "div " << div << endl;
        cout  << "ff " << ff(a, k, m) << endl;
        int res = ff(a, k, m) * div;
        cout << "res " << res << endl;
        output << "Case #"<< l+1 <<": "<< res << endl;
        l++;
    }
    output.close();
    return 0;
}
