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
        
        string sex, mother, father;
        
        int mother_in, father_in, tmp;
        
        cin >> sex >> mother >> father;
        
        
        int ft,in;
        ft=mother.find("'");
        in=mother.find("\"");
        
        istringstream (mother.substr(0,ft)) >> tmp;
        mother_in = tmp * 12;
        istringstream (mother.substr(ft+1,in-ft)) >> tmp;
        mother_in += tmp;
        
        istringstream (father.substr(0,ft)) >> tmp;
        father_in = tmp * 12;
        istringstream (father.substr(ft+1,in-ft)) >> tmp;
        father_in += tmp;
        
        double total_in = father_in + mother_in;
        if (sex.compare("B")==0)
            total_in += 5;
        else total_in -= 5;
        
        total_in /= 2;
        
        double low_in, high_in;
        low_in = ceil(total_in - 4.0);
        high_in = floor(total_in + 4.0);
        
        int low_ft, high_ft;
        low_ft = floor(low_in / 12.0);
        high_ft = floor(high_in / 12.0);
        
        low_in -= low_ft*12;
        high_in -= high_ft*12;
        
        cout << "Case #" << times << ": " 
             << low_ft<<"'"<<low_in<<"\""
             << " to "
             << high_ft<<"'"<<high_in<<"\"";
             
        
        
        //cout<<setprecision(50)<<res;
        
        cout << endl;
    }
    
    return 0;
}
