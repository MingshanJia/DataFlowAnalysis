#include <iostream>
#include <vector>
using namespace std;
int cards[80][3];
bool hand[80];
int tmp[80];
int turns, score;
int deck, tot;
void play(int x) {
    hand[x]=false;
    for (int i=0; i<cards[x][0] && deck<tot; i++) {
        hand[deck++]=true;
    }
    score += cards[x][1];
    turns += cards[x][2];
    turns--;
}
int main() {
    int T; scanf("%d",&T); for (int t=1; t<=T; t++) {
        int N; scanf("%d",&N);
        for (int i=0; i<N; i++)
        for (int j=0; j<3; j++) scanf("%d",&cards[i][j]);
        int M; scanf("%d",&M);
        for (int i=0; i<M; i++) 
        for (int j=0; j<3; j++) scanf("%d",&cards[N+i][j]);
        
        tot = M+N;
        
        deck = N;
        
        memset(hand,0,80*sizeof(bool));
        for (int j=0; j<N; j++) hand[j]=true;
        int handsize = N;
        
        int best = 0;
        turns = 1;
        score = 0;
        
        while (turns && handsize>0) {
            bool found = false;
            for (int i=0; i<tot; i++) {
                if (hand[i] && cards[i][2]) {
                    play(i);
                    found = true;
                    break;
                }
            }
            if (found) continue;
            // no cards with extra turns available. two cases: play highest 'turns' scores left is case one
            
            int tmpct = 0;
            for (int i=0; i<tot; i++) {
                if (hand[i]) tmp[tmpct++]=cards[i][1];
            }
            sort(tmp,tmp+tmpct);
            int tothere = 0;
            for (int i=0; i<turns && i<tmpct; i++) {
                tothere += tmp[tmpct-1-i];
            }
            best>?=score + tothere;
            
            // case two: play highest scoring card with an extra draw
            
            int bestfound = -1;
            for (int i=0; i<tot; i++) {
                if (hand[i] && cards[i][0]>0 && (bestfound==-1 || cards[i][1]>cards[bestfound][1])) {
                    bestfound = i;
                }
            }
            if (bestfound!=-1) {
                play(bestfound);
                continue;
            }
            
            break;
        }
        printf("Case #%d: %d\n",t,max(best,score));
    }
}
