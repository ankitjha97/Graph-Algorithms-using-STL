#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<list>
#include<limits>
int vertices,edges;
using namespace std;
vector< pair< int,pair< int,int > > > data;

class disjoint_data_structure{
	private:
		int *rank;
		int *parent;
		int ver;
	public:
		disjoint_data_structure(int vertices);		
		void MakeSet();
		void UNION(int u,int v);
		int FindSet(int u);
		~disjoint_data_structure(){
			delete[] rank;
			delete[] parent;
		}
};

disjoint_data_structure::disjoint_data_structure(int vertices){
	ver=vertices+1;
	rank=new int[ver];
	parent=new int[ver];
	
}
void disjoint_data_structure::MakeSet(){
	for(int i=0;i<ver;i++){
				rank[i]=0;
				parent[i]=i;
			}
}
int disjoint_data_structure::FindSet(int u){
	if(parent[u]!=u){
		FindSet(parent[u]);
	return(parent[u]);
	}
}

void disjoint_data_structure::UNION(int u,int v){
	int xroot=FindSet(u);
	int yroot=FindSet(v);
	if(rank[xroot]>rank[yroot]){
		yroot[parent]=xroot;
	}
	else if(rank[xroot]<rank[yroot]){
		parent[xroot]=yroot;
	}
	else{
		parent[yroot]=xroot;
		rank[xroot]++;		
	}
}

int kruskal(){
	int sum_weight=0;
	sort(data.begin(),data.end());
	disjoint_data_structure ds(vertices);
	ds.MakeSet();
	vector<pair<int,pair<int,int> > >::iterator itr;
	for(itr=data.begin();itr!=data.end();itr++){
		int u=itr->second.first;
		int v=itr->second.second;
		ds.MakeSet();
		int set1=ds.FindSet(u);
		int set2=ds.FindSet(v);
		if(set1!=set2){
			ds.UNION(set1,set2);
			cout<<u<<"   "<<v;
			sum_weight+=itr->first;
		}
	}
	cout<<"\nThe min weight fo the graph is :"<<sum_weight;
	return sum_weight;
}

int main(){
	int weight,v1,v2;
	cout<<"\nEnter the no of vertices,edges\n";
	cin>>vertices>>edges;
	
	for(int i=0;i<edges;i++){
		cout<<"\nEnter edges from v1 and v2 with the weight\n";
		cin>>v1>>v2>>weight;
		data.push_back(make_pair(weight,make_pair(v1,v2)));
	}

	kruskal();



	return 0;
}