#include <cstdlib>
#include <iostream>
#include <cmath>
#include <string>
#include <cctype>
#include <limits>
#include <algorithm>
#include <sstream>
#include <iterator>
#include <list>
#include <vector>
#include <map>
#include <iomanip>


using namespace std;

bool comp (int a, int b) {
    return a < b;
}

int main(int argc, char** argv) {

    int tmax;
    cin >> tmax;
    
    for (int times=1; times<=tmax; times++) {
        
        
        int N;
        double h[1000], avg;
        
        cin >> N;
        cin >> h[0];
        cin >> h[1];
        
        
        for (int n=2;n<N;n++) {
            cin >> h[n];
            avg = (h[n] + h[n-2]) / 2.0;
            if (avg < h[n-1]) h[n-1]=avg;
        }
        
        cout << "Case #" << times << ": ";
        
        cout<<setprecision(10)<<h[N-2];
        
        cout << endl;
    }
    
    return 0;
}
