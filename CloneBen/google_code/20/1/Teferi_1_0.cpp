#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


bool ValRange(const string& str, int i, int x)
{
	if(i>str.length())
		return x==0;
	else
	{
		if(str[i-1]=='?')
		{
			if(i==str.length() && str.length()>1 && x==0)
				return false;
			else
				return true;
		}
		else
			return str[i-1]==(x+'0');
	}	
}

struct Tri
{
	string a,b,c;
};
inline bool operator<(const Tri& x, const Tri& y)
{	return ((x.a<y.a) || (x.a==y.a && x.b<y.b) || (x.a==y.a && x.b==y.b && x.c<y.c));	}


void Update(Tri& cur, int x, int y, int z, Tri& pre)
{
	if(pre.a=="")
		return;

	Tri t;
	t.a=(char)(x+'0')+pre.a;
	t.b=(char)(y+'0')+pre.b;
	t.c=(char)(z+'0')+pre.c;
	if(cur.a=="")
		cur=t;
	else
		cur=min(cur,t);
}
void main()
{
	int t;
	cin>>t;

	for(int ii=0; ii<t; ii++)
	{
		string na,nb,nc;
		string oper,equ;
		cin>>na>>oper>>nb>>equ>>nc;

		reverse(na.begin(),na.end());
		reverse(nb.begin(),nb.end());
		reverse(nc.begin(),nc.end());
		int len=max(max(na.length(),nb.length()),nc.length());

		Tri sol[250][2];
		sol[0][0].a=sol[0][0].b=sol[0][0].c=" ";

		for(int i=1; i<=len; i++)
		{
			for(int x=9; x>=0; x--)
			{
				if(!ValRange(na,i,x))
					continue;
				for(int y=9; y>=0; y--)
				{
					if(!ValRange(nb,i,y))
						continue;

					for(int z=9; z>=0; z--)
					{
						if(!ValRange(nc,i,z))
							continue;

						if(oper=="+")
						{
							if(x+y==z)
								Update(sol[i][0],x,y,z,sol[i-1][0]);
							else if(x+y+1==z)
								Update(sol[i][0],x,y,z,sol[i-1][1]);
							else if(x+y==10+z)
								Update(sol[i][1],x,y,z,sol[i-1][0]);
							else if(x+y+1==10+z)
								Update(sol[i][1],x,y,z,sol[i-1][1]);
						}
						else if(oper=="-")
						{
							if(x-y==z)
								Update(sol[i][0],x,y,z,sol[i-1][0]);
							else if(x-y-1==z)
								Update(sol[i][0],x,y,z,sol[i-1][1]);
							else if(10+x-y==z)
								Update(sol[i][1],x,y,z,sol[i-1][0]);
							else if(10+x-y-1==z)
								Update(sol[i][1],x,y,z,sol[i-1][1]);
						}
					}
				}
			}
				
		}	
		cout<<"Case #"<<ii+1<<": ";
		cout<<sol[len][0].a.substr(len-na.length())<<oper<<" ";
		cout<<sol[len][0].b.substr(len-nb.length())<<"= ";
		cout<<sol[len][0].c.substr(len-nc.length())<<endl;
	}
}