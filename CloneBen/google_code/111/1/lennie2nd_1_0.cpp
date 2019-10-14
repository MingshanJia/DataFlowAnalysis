#include<cstdio>
#include<vector>
#include<cmath>
using namespace std;
int tc;
int totalA, totalB, a, b, years;

int main() {
  scanf("%d", &tc);
  for (int t = 0; t < tc; t++) {
    scanf("%d %d %d %d %d", &totalA, &totalB, &a, &b, &years);
    vector<int> A;
    vector<int> B;
    int dieA;
    int dieB;

    A.push_back(totalA);
    B.push_back(totalB);

    for (int y = 1; y <= years; y++) {
       dieA = (floor(A[y-1] / 100));
       dieB = (floor(B[y-1] / 100));

       int babies = floor(2 / double(100) * min(A[y-1], B[y-1]));
       int offspringA = floor((a / (double) 100 * babies));
       int offspringB = floor((b / (double) 100 * babies));
       if (babies != offspringA + offspringB) {
         int rest = babies - offspringA - offspringB;
         offspringA += rest / 2;
         offspringB += (rest - rest / 2);
       }
       A.push_back(A[y-1] + offspringA - dieA);  
       B.push_back(B[y-1] + offspringB - dieB);  
    }
    printf("Case #%d: %d %d\n", t+1, A[years], B[years]);    
  }
}
