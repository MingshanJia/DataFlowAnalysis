#include "stdafx.h"

#include <cstdio>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <stack>
#include <queue>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <unordered_map>
#include <iomanip>
#include <functional>

#define INPUTFILE "test.in"
#define OUTPUTFILE "result.out"

using namespace std;

#define INF 0xffffffff

class MYWEIGHT
{
public:
	MYWEIGHT(){
		real = INF;
		img = 0;
		tag = -1;
	}
	int real;
	int img;
	int tag;
};

int myNum[110];
unordered_map<string, int> myNode;
unordered_map<string, int>::iterator nodeItor;
int* Edge[5000];
MYWEIGHT NodeWeight[5000];
int nodeSum;
int tagValue[5000];
bool isTagValue[5000];


void CalWeight(int root)
{
	queue<int> myQue;
	myQue.push(root);
	int tReal, tImg;
	while (!myQue.empty()){
		int n = myQue.front();
		myQue.pop();
		for (int i = 0; i < nodeSum; ++i){
			if (Edge[n][i] != -1){
				tReal = Edge[n][i] - 200000 - NodeWeight[n].real;
				tImg = -NodeWeight[n].img;
				if (NodeWeight[i].tag == -1){
					NodeWeight[i].tag = NodeWeight[n].tag;
					NodeWeight[i].real = tReal;
					NodeWeight[i].img = tImg;
					myQue.push(i);
				}
				else{
					if (tImg != NodeWeight[i].img){
						isTagValue[NodeWeight[i].tag] = true;
						tagValue[NodeWeight[i].tag] = (NodeWeight[i].real - tReal)
							/ (tImg - NodeWeight[i].img);
					}
				}
			}
		}
	}
	return;
}


int main()
{
	/*freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);*/

	fstream infile(INPUTFILE, ios::in);
	fstream outfile(OUTPUTFILE, ios::out);
		
	int testN, testCount;
	testCount = 1;
	infile >> testN;
	infile.get();
	int T,N,Q;

	
	for (int i = 0; i < 5000; ++i){
		Edge[i] = new int[5000];
	}
		
	while (testCount <= testN){
		infile >> N;
		infile.get();
		for (int i = 0; i < 5000; ++i){
			memset(Edge[i], -1, sizeof(int)* 5000);
		}
		memset(isTagValue, false, sizeof(bool)* 5000);
		for (int i = 0; i < 5000; ++i)
			NodeWeight[i].tag = -1;
		nodeSum = 0;
		myNode.clear();
		string str1, str2;
		int node1, node2;
		int weight;
		for (int i = 1; i <= N; ++i){
			getline(infile, str1, '+');
			getline(infile, str2, '=');
			infile >> weight;
			infile.get();
			nodeItor = myNode.find(str1);
			if (myNode.end() == nodeItor){
				node1 = nodeSum++;
				myNode.insert(make_pair(str1, node1));
			}else
				node1 = nodeItor->second;
			nodeItor = myNode.find(str2);
			if (myNode.end() == nodeItor){
				node2 = nodeSum++;
				myNode.insert(make_pair(str2, node2));
			}
			else
				node2 = nodeItor->second;
			Edge[node1][node2] = Edge[node2][node1] = weight + 200000;
		}
		//do sth
		int maketag = 0;
		for (int i = 0; i < nodeSum; ++i){
			if (NodeWeight[i].tag == -1){
				NodeWeight[i].tag = maketag++;
				NodeWeight[i].real = 0;
				NodeWeight[i].img = 1;
				CalWeight(i);
			}
		}

		outfile << "Case #" << testCount++ << ":\n";

		infile >> Q;
		infile.get();
		for (int i = 1; i <= Q; ++i){
			getline(infile, str1, '+');
			getline(infile, str2, '\n');
			nodeItor = myNode.find(str1);
			if (myNode.end() == nodeItor){
				continue;
			}
			else
				node1 = nodeItor->second;
			nodeItor = myNode.find(str2);
			if (myNode.end() == nodeItor){
				continue;
			}
			else
				node2 = nodeItor->second;
			
			//cout
			if (NodeWeight[node1].tag == NodeWeight[node2].tag){
				if ((NodeWeight[node1].img + NodeWeight[node2].img) != 0
					&& !isTagValue[NodeWeight[node1].tag])
					continue;
				outfile << str1 << "+" << str2 << "="
					<< NodeWeight[node1].real + NodeWeight[node2].real
					+ (NodeWeight[node1].img + NodeWeight[node2].img)*tagValue[NodeWeight[node1].tag] << endl;
			}
			else{
				if (!isTagValue[NodeWeight[node1].tag] || !isTagValue[NodeWeight[node2].tag])
					continue;
				outfile << str1 << "+" << str2 << "="
					<< NodeWeight[node1].real + NodeWeight[node2].real
					+ (NodeWeight[node1].img)*tagValue[NodeWeight[node1].tag] 
					+ (NodeWeight[node2].img)*tagValue[NodeWeight[node2].tag] << endl;
			}
		}
	}
	
	infile.close();
	outfile.close();
	return 0;
}


