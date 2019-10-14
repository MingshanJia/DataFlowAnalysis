#include <iostream>
#include <vector>
using namespace std;
int SORTER;
typedef struct Word {
    char w[11];
    int states[26];
    int len;
    int orderval;
    int setcount;
    int newsetcount;
    int origsetcount;
    int val;
    bool operator<(const Word& w) const {
        if (SORTER==-1) return len<w.len;
        else {
            if (setcount!=w.setcount) return setcount<w.setcount;
            else return states[SORTER]<w.states[SORTER];
        }
    }
};
bool exist[10000];
Word words[10000];
char order[27];
int main() {
    int T; scanf("%d",&T); for (int t=1; t<=T; t++) {
        printf("Case #%d:",t);        
        int N,M; scanf("%d %d",&N,&M);
        for (int i=0; i<N; i++) {
            scanf("%s",words[i].w);
            for (int j=0; j<26; j++) {
                words[i].states[j]=0;
                words[i].len=0;
            }
            for (int j=0; words[i].w[j]; j++) {
                words[i].states[words[i].w[j]-'a']|=1<<j;
                words[i].len++;
            }
            words[i].orderval=i;
        }
        
        SORTER=-1;
        int setcount = -1;

        sort(words,words+N);
        for (int i=0; i<N; i++) {
            if (i==0 || words[i].len!=words[i-1].len) setcount++;
            words[i].origsetcount = words[i].setcount = setcount;

        }

        int origsetcount = setcount;
        
//        for (int i=0; i<N; i++) printf("%s %d\n",words[i].w,words[i].setcount);
        
        for (int m=0; m<M; m++) {
            setcount= origsetcount;
            for (int i=0; i<N; i++) {
                words[i].setcount = words[i].origsetcount;
                words[i].val=0;
            }
            
            scanf("%s",order);
            
            for (int i=0; i<26; i++) {
                SORTER = order[i]-'a';                
                for (int j=0; j<=setcount; j++) exist[j]=false;
                // does there exist an order[i] in each set
                for (int j=0; j<N; j++) {
                 //   printf("words[%d].states[%d] = %d\n",j,order[i]-'a'
                    if (words[j].states[SORTER]!=0) exist[words[j].setcount]=1;
                }
                //for (int j=0; j<=setcount; j++) printf("%d: %d\n",j,exist[j]);

                sort(words,words+N);
                
                setcount = -1;
                for (int j=0; j<N; j++) {
                    if (j==0 || words[j].setcount!=words[j-1].setcount || words[j].states[SORTER]!=words[j-1].states[SORTER]) setcount++;
                    if (exist[words[j].setcount] && words[j].states[SORTER]==0) words[j].val++;
                    words[j].newsetcount = setcount;
                }
                for (int j=0; j<N; j++) words[j].setcount = words[j].newsetcount;
//                printf("After sort %d\n",i);
//                for (int j=0; j<N; j++) printf("%s %d %d\n",words[j].w,words[j].setcount,words[j].val);
            }
            
            Word *best = NULL;
            for (int i=0; i<N; i++) {
                if (best==NULL || words[i].val>best->val || words[i].val==best->val && words[i].orderval<best->orderval) best=&words[i];
            }
            printf(" %s",best->w);
//            for (int i=0; i<N; i++) printf("\n%s: %d\n",words[i].w,words[i].val);
        }
        
        printf("\n");
    }
}
