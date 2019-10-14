#include <vector>
#include <map>
#include <set>
#include <iostream>
#include <fstream>
#include <string>
#include <deque>
using namespace std;
class GNode{
public:
	string name;
	int color;
	set<GNode *> links;
	GNode(const string &str):name(str),color(0){}
};

bool do_case(ifstream &fin,ofstream &fout,int casenum){
	int k;
	fin>>k;
	map<string,GNode*> vertices;
	string name1,name2;
	for(int i=0;i<k;i++){
		fin>>name1>>name2;
		if(vertices.find(name1)==vertices.end()){
			vertices[name1]=new GNode(name1);
		}
		if(vertices.find(name2)==vertices.end()){
			vertices[name2]=new GNode(name2);
		}
		vertices[name1]->links.insert(vertices[name2]);
		vertices[name2]->links.insert(vertices[name1]);
	}
	deque<GNode *> bfs;
	GNode * temp;
	while(!vertices.empty()){
	(*vertices.begin()).second->color=1;
	bfs.push_back((*vertices.begin()).second);
	while(!bfs.empty()){
		temp=bfs.front();
		if(vertices.find(temp->name)!=vertices.end()){
			vertices.erase(temp->name);
		}
		bfs.pop_front();
		for(set<GNode *>::iterator it=temp->links.begin();
			it!=temp->links.end(); ++it){
				

				if((*it)->color==temp->color){
					fout<<"Case #"<<casenum<<": No"<<endl;
					return false;
				}else if((*it)->color==0){
					(*it)->color=(-1)*temp->color;
					bfs.push_back(*it);
				}
		}
	}
	}
	fout<<"Case #"<<casenum<<": Yes"<<endl;
					return true;

}


int main(){
	ifstream fin("A-small-1-attempt0.in");
	ofstream fout("output.txt");
	int n;
	fin>>n;
	for(int i=0;i<n;i++){
		do_case(fin,fout,i+1);
	}
	fin.close();
	fout.close();
	return 0;
}
