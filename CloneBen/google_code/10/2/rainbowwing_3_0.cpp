#include<iostream>
#include<vector>
#include<string>
#include <fstream>
#include <iterator>
#include<string.h>
#include<algorithm>
using namespace std;
FILE *fin=fopen("D-small-attempt1.in","r");
FILE *fout = fopen("CutTiles.out","w");
class CTiles
{
  int ctiles;
  vector<int> tiles;
  
  int getMaxK(int e)
  {
    int k = 0;
    while (e > 1) {
      e>>= 1;
      ++k;
    }
    return k;
  }

  void includTiles(int numa, int numb, vector<int>& tiles)
  {
    if (numa > numb)
		swap(numa, numb);
    //printf("%d,%d",numa,numb);
    if (numa == 0) return ;
    if (numa == 1) 
	{
      tiles[0] += numb;
      return;
    }
    int ak = getMaxK(numa), sa = 1 << ak;
    tiles[ak] += 1;
    includTiles(numb - sa, numa, tiles);
    includTiles(numa - sa, sa, tiles);
  }
  
public:
  CTiles(int other) {
    ctiles = other;
    tiles.resize(32);
    includTiles(ctiles, ctiles, tiles);
  }

  bool Add(int num) {
    for (int i = num; i < 32; ++i) {
      if (tiles[i] > 0) {
        -- tiles[i];
        includTiles((1<<i)-(1<<num), 1<<i, tiles);
        includTiles(1<<num, (1<<i)-(1<<num), tiles);
        return true;
      }
    }
    return false;
  }
};

int CutTiles()
{
	int n,m;
	fscanf(fin,"%d%d",&n,&m);
	//printf("\n%d %d\n",n,m);getchar();
    vector<int> sn(n);
    for (int i=0;i<n;i++) {
		int t ;
		fscanf(fin,"%d",&t);
		sn[i]=t;
		//printf("%d<<",sn[i]);
    }
    vector<CTiles> ans;
    sort(sn.begin(), sn.end());
    //for (vector<int>::iterator itr = sn.rbegin(); itr != sn.rend(); ++itr)
	for(int itr = sn.size()-1;itr>=0;itr--)
	{
	//	printf("%d..",itr);
      bool added = false;
	  for(int i=0;i<ans.size();i++)
		  if( ans[i].Add(sn[itr]))
		  {
			  added = true;
			  break;
		  }
      if (!added) {
        ans.push_back(CTiles(m));
        ans.back().Add(sn[itr]);
      }
    }
	return ans.size();
}
void CutTilesMain()
{
	int cases;
	fscanf(fin,"%d",&cases);
	//printf("%d",cases);printf("\n");
	for(int i=1;i<=cases;i++)
	{
		fprintf(fout,"Case #%d: %d\n",i,CutTiles());
		//printf("%d,%d\n",i,CutTiles());
	}
	return ;
}
int main()
{
	CutTilesMain();
	fclose(fin);
	fclose(fout);
	return 0;
}
