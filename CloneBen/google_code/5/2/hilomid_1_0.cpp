//#include "TC.cpp"
#include <iostream>
#include <sstream>
#include <fstream>
#include <cmath>
#include <ctime>
#include <cstring>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <bitset>
#include <utility>
#include <algorithm>
#include <unordered_map>
using namespace std;

const double EPS=1e-8;
const double PI=3.1415926;
int T,V,D;
double calc(double lo,double hi,double val){
	lo=lo/90*PI/2; hi=hi/90*PI/2;
	double mid,last=-1;
	for(int i=0;i<100;i++){
		mid=(lo+hi)/2;
		if(sin(mid)*cos(mid)<=val) lo=mid;
		else hi=mid;
		if(abs(mid-last)<=EPS) return mid;
		last=mid;
	}
	return 100;
}
int main()
{
	freopen("B-small-attempt0.in","r",stdin);
	freopen("Ans.out","w",stdout);
	//ifstream fin("dict.out");
	//ofstream fout("Ans.out");
	//FILE *fin=fopen("table.txt","r");
	//FILE *fout=fopen("Ans.out","w");
	cin>>T;
	for(int cas=1;cas<=T;cas++){
		cin>>V>>D;
		double val=9.8*D/(2*V*V);
		double deg=calc(0,45,val);
		deg=min(deg,calc(45,90,val));
		deg=deg/PI*180;
		printf("Case #%d: %.7lf\n",cas,deg);
	}
	
	return 0;
}