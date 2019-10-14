#include <bits/stdc++.h>
#define ll long long
#define eps 1e-9
using namespace std;

int bs(int *st,int *en,int val,char c)
{
    int k;
    //first element not less than val,else returns last
    if(c=='l') k=lower_bound(st,en,val)-st;
    //first element greater than val,else returns last
    if(c=='u') k=upper_bound(st,en,val)-st;
    return k;
}

void ai(int *p,int l)
{
    for(int a=0;a<l;a++) scanf("%d",&p[a]);
}
void al(int *p,int l)
{
    for(int a=0;a<l;a++) cin>>p[a];
}

int prime[78500];
int sieve()
{
    int a,b,c;
    c=0; prime[c]=2;
    bool *m=(bool *)calloc(1000006,sizeof(bool));
    for(a=3;a<=1000000;a=a+2)
    {
        if(!m[a])
        {
            prime[++c]=a;
            for(b=2*a;b<=1000000;b=b+a) m[b]=true;
        }
    }
    free(m);
    return c;
}

int hor[]={1,0,-1,0};
int ver[]={0,1,0,-1};

int ar[1003][1003];

int pos[1003*1003][2];

int dp[1003*1003];
bool bi[1003][1003];

int main()
{

    freopen("0.in","r",stdin);
    freopen("0.out","w",stdout);


    //cout << fixed << setprecision(4);
    std::ios::sync_with_stdio(false);




	ll a,b,c,d,e,x,y,z;

	ll te,t;

	cin>>te;

	for(t=1;t<=te;t++)
	{
	    cout<<"Case #"<<t<<": ";
	    //cout<<endl;

	    ll n;

	    cin>>n;

	    for(a=0;a<n;a++) for(b=0;b<n;b++)
	    { bi[a][b]=0;  cin>>ar[a][b]; pos[ ar[a][b] ][0]=a; pos[ ar[a][b] ][1]=b; }
	    for(a=0;a<=n*n;a++) dp[a]=0;

	    ll per,num;
	    num=0;

	    for(a=n*n;a>=1;a--)
	    {
	        x=pos[a][0];
	        y=pos[a][1];
	        dp[a]=1;
	        for(b=0;b<4;b++)
	        {
	            int i=x+ver[b];
	            int j=y+hor[b];
	            if(i<0 || j<0  || i>=n || j>=n) continue;
	            if(ar[i][j]==a+1)
	            {
	                dp[a]=dp[a]+dp[a+1];
	                break;
	            }
	        }
	        if(dp[a]>=num)
	        {
	            num=dp[a];
	            per=a;
	        }
	    }
	    cout<<per<<" "<<num<<endl;



	}


    return 0;
}
