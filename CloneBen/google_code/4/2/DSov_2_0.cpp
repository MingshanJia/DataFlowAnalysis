#include<bits/stdc++.h>
#define M 1000000007
#define maxl 20
using namespace std;
int s,v,t;
int main()
{
	cin>>t;
	long long int cnt[10000];
	map<vector<int>,int > vocab;
	string tmp;
	vector<string> sents;
	string sent; 
	int cas =1;
	while(t--)
	{
		cin>>v>>s;
		sents = vector<string>(s);
		vocab = map<vector<int>,int >();
		for(int i=0;i<v;i++)
		{
			cin>>tmp;
			vector<int> chars(26,0);
			for(int i=0;i<tmp.size();i++)
			{
				chars[tmp[i]-'a']++;
			}
			if(vocab.find(chars)==vocab.end())
			{
				vocab[chars] = 1;
			}
			else
			{
				vocab[chars]++;
			}
		}
		for(int i=0;i<s;i++)
		{
			cin>>sents[i];
		}
		cout<<"Case #"<<cas<<": ";
		for(int i=0;i<s;i++)
		{
			cnt[0] = 1;
			for(int j=1;j<=sents[i].size();j++)
			{
				cnt[j]=0;
				vector<int> chars(26,0);
				for(int l=1;l<=maxl,l<=j;l++)
				{
					chars[sents[i][j-l]-'a']++;
					// for(int x=0;x<26;x++)
					// {
					// 	cout<<chars[x]<<" ";
					// }
					// cout<<endl;
					if(vocab.find(chars)!=vocab.end())
					{
						if(cnt[j-l]!=0)
						{
							//cout<<"here"<<endl;
							cnt[j] = (cnt[j]+(cnt[j-l]*vocab[chars])%M)%M;
						}
					}
				}
			}
			cout<<cnt[sents[i].size()]<<" ";
		}
		cout<<endl;
		cas++;
	}
	return 0;
}