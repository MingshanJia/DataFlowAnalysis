#include<iostream>
#include<queue>
#include<vector>
#include<map>
#include <hash_map>
#include <string>
using namespace std;
//#define TEST_SMALL
#define TEST_BIG
int main(){

#ifndef TEST_SMALL
	freopen("C-small-1-attempt0.in", "r", stdin);
	freopen("Cs.out", "w", stdout);
#endif
#ifndef TEST_BIG
	freopen("B-large-practice.in", "r", stdin);
	freopen("Bl.out", "w", stdout);
#endif	
	int cas;
	int n;
	vector < string > cards;
	scanf("%d", &cas);
	for(int t = 1; t <= cas; t++){
		cards.clear();
		scanf("%d", &n);
		char name[1000];
		gets(name);
		for(int i = 0; i < n; i++){
			gets(name);
			cards.push_back(name);
		}
		int ans = 0;
		bool change = false;
		while(true){
			change = false;
			for(int i = 1; i < n; i++){
				if (cards[i] < cards[i - 1]){
					change = true;
					ans++;
					for(int j = 0; j < i; j++){
						if (cards[i] < cards[j]){
							string temp = cards[i];
							for(int k = i; k > j; k--)
								cards[k] = cards[k - 1];
							cards[j] = temp;
							break;
						}
					}
				}
			}
			if (!change)
				break;
		}
		printf("Case #%d: %d\n", t, ans);
	
	
	}
}