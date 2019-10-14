#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<limits.h>
#include<iostream>
#include<iomanip>
#include<sstream>
#include<algorithm>
#include<functional>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<complex>
#define EPS (1e-10)
#define PI (3.141592653589793238)
#define MP make_pair
typedef long long ll;
using namespace std;

void xdraw(int x,vector<pair<int,pair<int,int> > > &hand,vector<pair<int,pair<int,int> > > &deck){
	int i;
	for(i=0;i<x;i++){
		if(deck.size()==0)break;
		hand.push_back(deck[deck.size()-1]);
		deck.pop_back();
	}
	return;
}

int main(void){
	int T;
	scanf("%d",&T);
	for(int casenum=1;casenum<=T;casenum++){
		int i,j,k;
		int n,m;
		vector<pair<int,pair<int,int> > > hand,deck;
		scanf("%d",&n);
		for(i=0;i<n;i++){
			int c,s,t;
			scanf("%d %d %d",&c,&s,&t);
			hand.push_back(MP(c,MP(s,t)));
		}
		scanf("%d",&m);
		for(i=0;i<m;i++){
			int c,s,t;
			scanf("%d %d %d",&c,&s,&t);
			deck.push_back(MP(c,MP(s,t)));
		}
		reverse(deck.begin(),deck.end());
		vector<pair<int,pair<int,int> > > hand_bak,deck_bak;
		hand_bak=hand;
		deck_bak=deck;
		int maxiscore=0;
		for(int draw=0;draw<=n+m;draw++){
			int left=1;
			int score=0;
			int dodraw=0;
			hand=hand_bak;
			deck=deck_bak;
			while(left>=1 && hand.size()>=1){

				/*printf("(%d)[maxi=%d][score=%d,left=%d,dodraw=%d] ",draw,maxiscore,score,left,dodraw);
				for(i=0;i<hand.size();i++)printf("(%d,%d,%d)",hand[i].first,hand[i].second.first,hand[i].second.second);
				puts("");*/

				bool end=false;
				for(i=0;i<hand.size();i++){
					if(hand[i].second.second>=1){
						xdraw(hand[i].first,hand,deck);
						dodraw+=hand[i].first;
						score+=hand[i].second.first;
						left+=hand[i].second.second;
						hand.erase(hand.begin()+i);
						left--;
						end=true;
					}
					if(end)break;
				}
				if(end)continue;

				int maxi=-1,maxipos=0;
				if(dodraw<draw){
					for(i=0;i<hand.size();i++){
						if(hand[i].first>=1){
							if(maxi<hand[i].second.first){
								maxi=hand[i].second.first;
								maxipos=i;
							}
						}
					}
				}else{
					for(i=0;i<hand.size();i++){
						if(maxi<hand[i].second.first){
							maxi=hand[i].second.first;
							maxipos=i;
						}
					}
				}
				xdraw(hand[maxipos].first,hand,deck);
				dodraw+=hand[maxipos].first;
				score+=hand[maxipos].second.first;
				left+=hand[maxipos].second.second;
				hand.erase(hand.begin()+maxipos);
				left--;
			}
			maxiscore=max(maxiscore,score);
		}
		printf("Case #%d: %d\n",casenum,maxiscore);
	}
	return 0;
}
