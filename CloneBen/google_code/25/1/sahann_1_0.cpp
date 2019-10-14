#include <vector>
#include <list>
#include <set>
#include <map>
#include <algorithm>
#include<fstream>
//#include <iostream>
using namespace std;

ifstream cin("B-small-attempt1.in");
ofstream cout("B.out");
int global = -1;





template <class C> struct DFSGraph{
	struct DFSGraphEdge{
		int org;
		int dest;
		double weight;
	};
	struct DFSGraphNode{
		C ID;
		int DFSParent;
		int DFSColor;
		int disctime;
		int finishtime;
		int compID;
		bool active ;
		list <int> out_edges;
		list <int> in_edges;

		DFSGraphNode(){
			DFSParent = -1;
			DFSColor  = 0;
			disctime = -1;
			finishtime = -1;
			compID = -1;
			active = false;
		};
		
	};
	//member variables of the DFSGraph class
	int maxnodes;
	int maxedges;

	vector <DFSGraphNode> Nodes;
	vector <DFSGraphEdge> Edges;
	list <int> available;
	list <int> e_available;
	map <C,int> IndexByID;
	bool reachedOrigin;


	DFSGraph(int nnodes, int nedges){

		maxnodes = nnodes;
		maxedges = nedges;
		Nodes.resize(maxnodes);
		Edges.resize(maxedges);
		for(size_t i=0;i<Nodes.size();i++)
			available.push_back(i);
		for(size_t j=0;j<Edges.size();j++)
			e_available.push_back(j);
		reachedOrigin = false;
	}
	int DFS(){//returns the number of components in the graph
		int sum=0;
		int timestamp =0;
		int aux;
		typename map<C,int>::iterator mpi;
		for(mpi = IndexByID.begin();mpi!=IndexByID.end();mpi++){
			aux = (*mpi).second;
			Nodes[aux].DFSColor = 0;
			Nodes[aux].DFSParent = -1;
			Nodes[aux].compID = -1;
		}

		for(mpi = IndexByID.begin();mpi!=IndexByID.end();mpi++){
			if(Nodes[(*mpi).second].DFSColor == 0){
				DFSVisit((*mpi).second,timestamp,sum);
				sum++;
			}
			
		}
		return sum;
	}
	void DFSVisit2(C id,int& timestamp,int compID){
		int index = IndexByID[id];
		DFSVisit(index,timestamp,compID);
	};
	void DFSVisit(int u,int& timestamp,int compID){
		Nodes[u].DFSColor = 1;
		Nodes[u].compID = compID;
		timestamp++;
		Nodes[u].disctime = timestamp;
		list <int>::iterator li;
		int v;
		for (li=Nodes[u].out_edges.begin();li!=Nodes[u].out_edges.end();li++){
			v = Edges[*li].dest;
			if(Nodes[v].DFSColor==0){
				Nodes[v].DFSParent = u;
				DFSVisit(v,timestamp,compID);
			}
			else if(Nodes[v].DFSParent == -1) reachedOrigin = true;
		}
		Nodes[u].DFSColor = 2;
		timestamp++;
		Nodes[u].finishtime = timestamp;
	}
	DFSGraphNode& operator [](C id){
		return Nodes[IndexByID[id]];
	}	
	int AddNode(C id){
		if (IndexByID.find(id)==IndexByID.end()){
			int temp=available.front();
			IndexByID[id]=temp;
			Nodes[temp].ID = id;
			Nodes[temp].active = true;
			available.pop_front();
			return 1;
		}
		return 0;
	};
	void AddDirEdge(C id1,C id2,double w){
		int index1,index2;
		index1 = IndexByID[id1];
		index2 = IndexByID[id2];
		int e_index = e_available.front();
		Edges[e_index].org = index1;
		Edges[e_index].dest = index2;
		Edges[e_index].weight = w;
		Nodes[index1].out_edges.push_back(e_index);
		Nodes[index2].in_edges.push_back(e_index);
		e_available.pop_front();
	};
	void AddUndirEdge(C id1,C id2,double w){
		AddDirEdge(id1,id2,w);
		AddDirEdge(id2,id1,w);
	};

};



int main(){
	
	int T = 0;
	cin >> T;

	for(int i=0;i<T;i++){
		int N;
		cin >> N;
		int R;
		cin >> R;
		map <int, int> node_degrees;
		DFSGraph<int> dfsg(N,4*R+10);
		for(int j=0;j<R;j++){
			int org,dest;
			cin >> org >> dest;
			dfsg.AddNode(org);
			dfsg.AddNode(dest);
			if (node_degrees.count(org)==0){
				node_degrees[org]= 1;
			}
			else node_degrees[org] = node_degrees[org] + 1;
			if (node_degrees.count(dest)==0){
				node_degrees[dest]= 1;
			}
			else node_degrees[dest] = node_degrees[dest] + 1;
			
			dfsg.AddUndirEdge(org,dest,1);
		}
		int ncomps = dfsg.DFS();
		//Now we have only have to determine how many nodes of odd degree in each component.
		map <int,int> oddnodesincomp;
		map <int,int>::iterator it;
		int nodd=0;
		for(it = node_degrees.begin();it!=node_degrees.end();it++){
			if(it->second%2==1){
				nodd++;
				int temp = dfsg[it->first].compID;
				if(oddnodesincomp.count(temp)==0)
					oddnodesincomp[temp] = 1;
				else oddnodesincomp[temp] = oddnodesincomp[temp]+1;
			}
		}
		int nres = 0;
		//OK so first we link the odd components among one another, and this consumes
		//ncomp edges and 2*ncomp odd degrees
		// for the remaining odd degrees within the components we have to consume
		//remaining/2 odd degrees
		//for the remaining components (the even one + the even one coming from the odd one)
		//we have to add their number to the number of required edges.
		int oddcomp=(oddnodesincomp.size()>0)?1:0;
		if(oddnodesincomp.size()>0){
			nres+=oddnodesincomp.size();
			nodd-=2*oddnodesincomp.size();	
			
		}
		nres+=nodd/2;
		int nremcomps = ncomps - oddnodesincomp.size() ;
		if(ncomps!=1) nres+=ncomps-oddnodesincomp.size();
		if((ncomps ==1)&&(oddnodesincomp.size()==0))
			nres = 0;
		cout << "Case #" << i+1 << ": " << nres << endl;
	}	
	return 0;
}
