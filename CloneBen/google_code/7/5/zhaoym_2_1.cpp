// chess.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <utility>
using namespace std;

string getSourceStation(map<string,bool>& havePreStation)
{
	map<string,bool>::iterator havePreStationIter;
	havePreStationIter=havePreStation.begin();
	for (;havePreStationIter!=havePreStation.end();havePreStationIter++)
	{
		if (!(havePreStationIter->second))
		{
			return havePreStationIter->first;
		}
	}
	cout<<"no source!!"<<endl;
	getchar();
	return havePreStation.begin()->first;
}

int _tmain(int argc, _TCHAR* argv[])
{
	ifstream fin;
	fin.open("C-large.in");
	ofstream fout;
	fout.open("C-large.out");
	int caseNum;
	fin>>caseNum;
	for (int caseIndex=1;caseIndex<=caseNum;caseIndex++)
	{
		cout<<"case index="<<caseIndex<<endl;
		int ticketNum;
		fin>>ticketNum;
		map<string,string> nextStation;
		map<string,bool> havePreStation;
		map<string,bool> haveNextStation;
		for (int i=1;i<=ticketNum;i++)
		{
			string source, destination;
			fin>>source>>destination;
			nextStation[source]=destination;
			havePreStation[destination]=true;
			haveNextStation[source]=true;
			map<string,bool>::iterator findIter;
			findIter=haveNextStation.find(destination);
			if (findIter==haveNextStation.end())
			{
				haveNextStation[destination]=false;
			}
			findIter=havePreStation.find(source);
			if (findIter==havePreStation.end())
			{
				havePreStation[source]=false;
			}
		}
		//get source
		string currentSource=getSourceStation(havePreStation);
		fout<<"Case #"<<caseIndex<<":";
		while (haveNextStation[currentSource])
		{
			fout<<" "<<currentSource<<"-"<<nextStation[currentSource];
			currentSource=nextStation[currentSource];
		}
		fout<<endl;
	}
	return 0;
}

