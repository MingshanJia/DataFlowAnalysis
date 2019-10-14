#include<iostream>
#include<vector>
#include<string>
#include <fstream>
#include <iterator>
#include<string.h>
using namespace std;
//ifstream fin("supre2048.in");
//ofstream fout("A-large-practice.out");
FILE *fin=fopen("B-small-attempt3.in","r");
FILE *fout = fopen("supre2048.out","w");

vector<int>  handL(vector<int> &numbers)
{
	vector<int>  result;
	vector<bool> flag;
	if( numbers.size()==0) return result;
	//if(numbers[0]>0)result.push_back(numbers[0]);////can not be zero...
	//flag.push_back(false);
	for(int i=0;i<numbers.size();i++)
	{
		if( numbers[i] == 0) continue;
		if( result.size() == 0){
			result.push_back( numbers[i] );
			flag.push_back(false);
			continue;
		}
		if(numbers[i] == result.back() && flag.back()==false)
		{
			result[ result.size()-1] = 2*numbers[i];
			flag[flag.size()-1] = true;
		}
		else {
			result.push_back( numbers[i] );
			flag.push_back(false);
		}
	}
	while(result.size()<numbers.size()) result.push_back(0);
	return result;///////
}
void Super2048()
{
	int N;
	char direction[10];
	fscanf(fin,"%d",&N);
//	printf("%d\t",N);
	fscanf(fin,"%s",direction);
//	printf("%s\t",direction);
	vector<vector<int>> matrix(N+1, vector<int>(N+1));
	vector<vector<int>> result(N+1, vector<int>(N+1));
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
		{
			int t ;
			fscanf(fin,"%d",&t);
			matrix[i][j]=t;
		}/////input over

		if( strcmp(direction,"left")==0){
		//printf("left");
		for(int i=0;i<N;i++)/////every row...
		{
			vector<int> temp;
			for(int j=0;j<N;j++)
				temp.push_back( matrix[i][j]);
			vector<int> leftResult(handL( temp));
			///////
			for(int j=0;j<N;j++)
				result[i][j]=leftResult[j];/////
		}///
		}//////////////////////////////left condition...
		else if( strcmp(direction,"right")==0){
		//	printf("right");
		for(int i=0;i<N;i++)/////every row...
		{
			vector<int> temp;
			for(int j=N-1;j>=0;j--)
				temp.push_back( matrix[i][j]);
			vector<int> rightResult(handL( temp));
			///////
			for(int j=0;j<N;j++)
				result[i][N-j-1]=rightResult[j];/////
		}///
		}///////////////////////////////right condition
		else if( strcmp(direction,"up")==0){
		//	printf("up");
		for(int j=0;j<N;j++)/////every col
		{
			vector<int> temp;
			for(int i=0;i<N;i++)
				temp.push_back( matrix[i][j]);
			vector<int> upResult(handL( temp));
			///////
			for(int i=0;i<N;i++)
				result[i][j]=upResult[i];
		}///
		}//////////////////////////////up condition
		else {
		//	printf("down");
			for(int j=0;j<N;j++)/////every col
			{
			vector<int> temp;
			for(int i=N-1;i>=0;i--)
				temp.push_back( matrix[i][j]);
			vector<int> upResult(handL( temp));
			///////
			for(int i=0;i<N;i++)
				result[N-i-1][j]=upResult[i];
		}///
		}//////////////////////down condition



		for(int i=0;i<N;i++)
		{
			fprintf(fout,"%d",result[i][0]);
			for(int j=1;j<N;j++)
				fprintf(fout," %d",result[i][j]);
			fprintf(fout,"\n");
		}//getchar();
	return ;
}
void Super2048Main()
{
	int cases;
	fscanf(fin,"%d",&cases);
	
	for(int i=1;i<=cases;i++)
	{
		fprintf(fout,"Case #%d:\n",i);
		Super2048();
	}
	return ;
}
int main()
{
	Super2048Main();
	getchar();
	return 0;
}