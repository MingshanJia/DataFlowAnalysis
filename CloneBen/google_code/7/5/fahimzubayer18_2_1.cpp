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

map<string,ll>M;
map<ll,string>N;

ll in[20004];
ll v[20004];

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
	    cout<<"Case #"<<t<<":";
	    //cout<<endl;

	    cin>>z;

	    M.clear();
	    N.clear();

	    ll n=0;

	    for(a=0;a<=2*z;a++){ v[a]=0; in[a]=0; }

	    string sr,ds;

	    for(a=0;a<z;a++)
	    {
	        cin>>sr;
	        cin>>ds;
	        if(!M[sr])
	        {
	            ++n;
	            M[sr]=n;
	            N[n]=sr;
	        }
	        if(!M[ds])
	        {
	            ++n;
	            M[ds]=n;
	            N[n]=ds;
	        }
	        x=M[sr];
	        y=M[ds];

	        v[x]=y;
	        in[y]++;
	    }
	    for(a=1;a<=n;a++)
	    {
	        if(!in[a])
	        {
	            x=a;
	            break;
	        }
	    }
	    //cout<<N[x]<<endl;
	    while(1)
	    {
	        if(!v[x])
	        {
	            cout<<endl;
	            break;
	        }
	        cout<<" "<<N[x]<<"-"<<N[ v[x] ];
	        x=v[x];
	    }
	}


    return 0;
}
