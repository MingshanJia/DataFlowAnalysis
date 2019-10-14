#include <vector>
#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;
typedef pair<double,double> pii;
bool sl(pii a,pii b)
{
	//return (a.second)/(a.first) < (b.second/b.first);
	if (a.first<0)
		return a.second * b.first < b.second * a.first;
	return a.second * b.first > b.second * a.first;
}
double operator*(pii &a, pii &b)
{
	return a.first * b.first + a.second * b.second;
}
bool near(double a,double b)
{
	if (abs(a-b)<1E-06) return true;
	if (abs(min(a,b)/max(a,b))<1E-06) return true;
	return false;
}
bool bigger(double a,double b)
{
	return a>b;
}
int main()
{
	//freopen("b-ex.txt","r",stdin);
	int T;
	scanf("%d",&T);
	for (int kase=1;kase<=T;++kase)
	{
		int n,r,target;
		scanf("%d %d %d",&n,&r,&target);
		vector<pii> data;
		for (int q=0;q<n;++q)
		{
			int u,v;
			scanf("%d %d",&u,&v);
			data.push_back(pii(u,v));
		}
		sort(data.begin(),data.end());
		double totP=0,totH=0;
		for (int q=0;q<n;++q)
		{
			double low = 0, high = data[q].second;
			for (int t=0;t<50;++t)
			{
				double h = (low+high)/2.;
				pii left(-r-data[q].first,-h), right(r-data[q].first,-h);
				for (int w=0;w<n;++w)
				{
					if (q==w) continue;
					pii tar(data[w].first-data[q].first,data[w].second-h);
					if (w<q && sl(tar,left)) left = tar;
					if (w>q && sl(tar,right)) right = tar;
				}
				pii a(data[q].first,h);
				//printf("%lf %lf %lf %lf\n",left.first,left.second,right.first,right.second);
				//solve left
				double leftAngle,rightAngle;
				{
					double A = left * left;
					double B = a * left;
					double C = a * a - r * r;
					double K = -B+sqrt(B*B-A*C);
					K/=A;
					pii mat( a.first + K * left.first , a.second + K * left.second );
					leftAngle = atan2(mat.second,mat.first);
					//printf("to %lf %lf %lf (%lf)\n",mat.first,mat.second,mat*mat,leftAngle);
				}
				{
					double A = right * right;
					double B = a * right;
					double C = a * a - r * r;
					double K = -B+sqrt(B*B-A*C);
					K/=A;
					pii mat( a.first + K * right.first , a.second + K * right.second );
					rightAngle = atan2(mat.second,mat.first);
					//printf("from %lf %lf %lf (%lf)\n",mat.first,mat.second,mat*mat,rightAngle);
				}
				double PI = 2*acos(0.);
				if (leftAngle<0) leftAngle = 0;
				if (rightAngle<0) rightAngle = PI;
				double mm = leftAngle-rightAngle;
				double nn = PI * target / 12;
				if (near(mm,nn) || bigger(mm,nn))
					high = h;
				else 
					low = h;
			}
			totH+=data[q].second - (low+high)/2;
			totP+=data[q].second;
			//printf("at %d, at least height = %lf,%lf\n",q,low,high);
		}
		printf("Case #%d: %.8lf\n",kase,totH/totP);
	}
	return 0;
}