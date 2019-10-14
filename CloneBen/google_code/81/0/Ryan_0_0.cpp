#include <iostream>

using namespace std;

bool simple(int percentage_today,int percentage_overall,int most);

int main(){
  int t;
  cin>>t;
  for(int i=0;i<t;i++){
    int percentage_today,percentage_overall,most;
    cin>>most>>percentage_today>>percentage_overall;
    bool possible=simple(percentage_today,percentage_overall,most);
    if(possible)
      cout<<"Case #"<<i+1<<": Possible\n";
    else
      cout<<"Case #"<<i+1<<": Broken\n";
  }
}

bool simple(int percentage_today,int percentage_overall,int most){
  for(int today=1;today<=most;today++)
    for(int wins_today=0;wins_today<=today;wins_today++){
      if(wins_today*100==percentage_today*today);
      else continue;
      int losses_today=today-wins_today;
      if(wins_today>0 && percentage_overall==0)
        continue;
      if(losses_today>0 && percentage_overall==100)
        continue;

      return true;
      for(int overall=today;overall<=most;overall++)
        for(int wins_overall=wins_today;wins_overall<=overall-losses_today;wins_overall++)
          if(wins_overall*100==percentage_overall*today)
            return true;
    }
  return false;
}
