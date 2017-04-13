#include<iostream>
#include<algorithm>
#include<vector>
#include<list>
#include<queue>
#include<limits>
#include<functional>
using namespace std;

int vertices,edges;
int *parent;
bool *status;
int *dist;
void initialise(){
	parent=new int[vertices+1];
	status=new bool[vertices+1];
	dist=new int[vertices+1];
	for(int i=0;i<=vertices;i++){
		dist[i]=numeric_limits<int>::max();
		parent[i]=-1;
		status[i]=false;
	}
}
void Prim(vector<list<pair<int,int> > > adjacency_list){
	initialise();
	int source;
	cout<<"\nEnter the source\n";
	cin>>source;
	list<pair<int,int> >::iterator itr;
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;
	pq.push(make_pair(source,0));
	while(!pq.empty()){
		status[source]=true;
		dist[source]=0;
		parent[source]=source;
		int u=pq.top().first;
		pq.pop();
		for(itr=adjacency_list[u].begin();itr!=adjacency_list[u].end();itr++){
			int v=(*itr).first;
			int weight=(*itr).second;
			
			if((dist[v]>dist[u]+weight)&&(status[v]==false)){
				dist[v]=dist[u]+weight;
				parent[v]=u;
				pq.push(make_pair(v,dist[v]));
				status[v]=true;
			}
		}
	}
	for(int i=1;i<=vertices;i++){
		cout<<dist[i]<<endl;
	}

}
int main(){
	int v1,v2,weight;
	cout<<"\nEnter the vertices and edges\n";
	cin>>vertices>>edges;
	vector<list<pair<int,int> > > adjacency_list(vertices+1);
	for(int i=1;i<=edges;i++){
		cout<<"\nEnter the edge v1 to v2 with edge weight\n";
		cin>>v1>>v2>>weight;
		adjacency_list[v1].push_back(make_pair(v2,weight));
	}
	Prim(adjacency_list);



	return 0;
}