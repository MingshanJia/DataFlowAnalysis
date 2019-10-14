#include<stdio.h>
#include<iostream>

using namespace std;
string s;
int tc;

int main() {
  scanf("%d\n", &tc);
  for (int t = 0; t < tc; t++) {
    getline(cin, s);
    printf("Case #%d:\n", t+1);
    printf("+-");
    for (int i = 0; i < s.length(); i++) {
      printf("-");
    }
    printf("-+\n");
    printf("| ");
    cout << s;
    printf(" |\n");
    printf("+-");
    for (int i = 0; i < s.length(); i++) {
      printf("-");
    }
    printf("-+\n");
  }
}
