//MADE BY lordmonsoon A.I.
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>
#include<set>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<sstream>
#include<iostream>
#include<utility>
#include<bitset>

using namespace std;

#define pi pair<int,int>
#define vi vector<int>
#define vpi vector<pi>
#define fst first
#define snd second
#define pb push_back
#define SIZE(a) (int)(a.size())
#define LENGTH(a) (int)(a.length())
#define REP(i,n) for(int i=0;i<(n);i++)
#define REPD(i,n) for(int i=(n);i>=0;i--)
#define FOR(i,n,m) for(int i=(n);i<=(m);i++)
#define FORD(i,n,m) for(int i=(n);i>=(m);i--)
#define MIN(a,b) ((a)<(b) ? (a) : (b))
#define MAX(a,b) ((a)<(b) ? (b) : (a))
#define ABS(a) ( (a)<0 ? -(a) : (a))
#define STRUMIEN(A,B) istringstream A(B)
#define SORT(A) sort(A.begin(),A.end())


////////////////////////////////////////////////////////////////////////////////

int n,p,q;
char P[20000],R[20000];
char W[17];

void oblicz(int &r,int &c,int &w)
{
      int xm = 0, xx = 0,x = 0,y = 1, yy = 0;
      int vx = 0, vy = -1;
      REP(i,p)
      {
            if(P[i] == 'W') {x+=vx,y+=vy;}
            else if(P[i] == 'L')
            {
                  int tmp = vy;
                  vy = vx;
                  vx = -tmp;
            }
            else //P[i]=='R'
            {
                  int  tmp = vx;
                  vx = vy;
                  vy = -tmp;
            }
            if(i<p-1) {xm<?=x;xx>?=x,yy<?=y;} 
      }      
      vx = -vx;
      vy = -vy;
      REP(i,q)
      {
            if(R[i] == 'W') {x+=vx,y+=vy;}
            else if(R[i] == 'L')
            {
                  int tmp = vy;
                  vy = vx;
                  vx = -tmp;
            }
            else //P[i]=='R'
            {
                  int  tmp = vx;
                  vx = vy;
                  vy = -tmp;
            }
            if(i<q-1) {xm<?=x;xx>?=x,yy<?=y;} 
      }
      r = -yy+1;
      c = xx - xm + 1;
      w = -xm;
}

void wypisz(int r,int c,int s)
{
      int M[r][c];
      REP(i,r) REP(j,c) M[i][j] = 0;
      int x = s, y = 1;
      int vx = 0,vy = -1;
      REP(i,p)
      {
            if(P[i] == 'W') 
            {
                  int t = 0, e = 0;
                  if(vx == 1) t = 3,e = 2;
                  else if(vx==-1) t = 2,e = 3;
                  else if(vy==1) t = 0,e = 1;
                  else t = 1,e = 0;
                  if(i>0) M[-y][x] |= 1<<t;

                  x+=vx,y+=vy;

                  if(i<p-1) M[-y][x] |= 1<<e;
            }
            else if(P[i] == 'L')
            {
                  int tmp = vy;
                  vy = vx;
                  vx = -tmp;
            }
            else //P[i]=='R'
            {
                  int  tmp = vx;
                  vx = vy;
                  vy = -tmp;
            }
      }      
      vx = -vx;
      vy = -vy;
      REP(i,q)
      {
            if(R[i] == 'W') 
            {
                  int t = 0, e = 0;
                  if(vx == 1) t = 3,e = 2;
                  else if(vx==-1) t = 2,e = 3;
                  else if(vy==1) t = 0,e = 1;
                  else t = 1,e = 0;
                  if(i>0) M[-y][x] |= 1<<t;
                  x+=vx,y+=vy;
                  if(i<q-1) M[-y][x] |= 1<<e;
            }
            else if(R[i] == 'L')
            {
                  int tmp = vy;
                  vy = vx;
                  vx = -tmp;
            }
            else //P[i]=='R'
            {
                  int  tmp = vx;
                  vx = vy;
                  vy = -tmp;
            }
      }      
      
      REP(i,r)
      {
            REP(j,c) printf("%c",W[M[i][j]]);
            printf("\n");
      }
}

int main()
{
      REP(i,10) W[i] = '0' + i;
      REP(i,6) W[i+10] = 'a' + i;
      scanf("%d",&n);
      REP(i,n)
      {
            scanf("%s %s",P,R);
            p = strlen(P);
            q = strlen(R);
            int r,c,x;
            oblicz(r,c,x);
            printf("Case #%d:\n",i+1);
            wypisz(r,c,x);
      }
      return 0;
}
