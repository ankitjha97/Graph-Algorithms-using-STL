#include<iostream>
#include<algorithm>
#include<vector>
#include<list>
#include<queue>
#include<limits>
using namespace std;
int vertices,edges;

void display(vector<list<pair<int,int> > > adjacency_list){
	list<pair<int,int> >::iterator itr;
	for(int i=1;i<=vertices;i++){
		cout<<i;
		for(itr=adjacency_list[i].begin();itr!=adjacency_list[i].end();itr++){
			cout<<itr->first<<"   "<<itr->second<<"\t"	;
		}
		cout<<endl;
	}



}

int *dist;
int *parent;

void initialise(int source){
	dist=new int[vertices+1];
	parent=new int[vertices+1];
	for(int i=0;i<=vertices;i++){
		dist[i]=numeric_limits<int>::max();
		parent[i]=i;
	}
	dist[source]=0;

}

void Prim(vector<list<pair<int,int> > > adjacency_list){
	cout<<"\nEnter the source\n";
	int source;
	bool flag=true;
	cin>>source;
	list<pair<int,int> >::iterator itr;
	initialise(source);
	for(int i=1;i<=vertices-1;i++){
		for(itr=adjacency_list[i].begin();itr!=adjacency_list[i].end();itr++){
			if((dist[itr->first])>(dist[i]+itr->second)){
				parent[itr->first]=i;
				dist[itr->first]=dist[i]+itr->second;
			}
		}
	}
	list<pair<int,int> >::iterator itr1;
	for(int i=1;i<=vertices;i++){
		for(itr1=adjacency_list[i].begin();itr1!=adjacency_list[i].end();itr1++){
			if((dist[itr1->first])>(dist[i]+itr1->second)){
				cout<<"Presence of negative weight cycle\n";
				flag=false;
			}
		}
	}
	if(flag==true){
		for(int i=1;i<=vertices;i++){
			cout<<"dist of  "<<i<<dist[i]<<endl;
			cout<<"Parent of i  "<<parent[i]<<endl;
		}
	}
}


int main(){
	cout<<"\nEnter vertices and edges\n";
	cin>>vertices>>edges;
	int v1,v2,weight;
	vector<list<pair<int,int> > > adjacency_list(vertices+1);
	for(int i=0;i<edges;i++){
		cin>>v1>>v2>>weight;
		adjacency_list[v1].push_back(make_pair(v2,weight));
	}
	display(adjacency_list);
	Prim(adjacency_list);


	return 0;
}