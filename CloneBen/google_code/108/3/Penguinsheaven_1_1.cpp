#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

#define DIM 110

using namespace std;


int main() {
    
    int testsCount;
    cin >> testsCount;
    
    for(int test = 1; test <= testsCount; test++) {
    
        int n; 
        cin >> n;
        
        vector<double> probs(2 * n);
        for(auto &prob : probs)
            cin >> prob;
        sort(begin(probs), end(probs));
        
        double ans = 1.0;
        for(int i = 0; i < n; ++i) {
            ans *= 1 - probs[i] * probs[2 * n - i - 1];
        }
        cout << fixed << setprecision(12);
        cout << "Case #" << test << ": " << ans << "\n";
        
    }
    
    
    return 0;
    
}