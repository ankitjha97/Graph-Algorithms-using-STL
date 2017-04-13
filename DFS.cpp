#include<iostream>
#include<vector>
#include<list>
#include<stack>
using namespace std;
int vertices,edges;
void DFS_VISIT(int num,vector<list<int> > adjacency_list);
void display(vector<list<int> > adjacency_list){
	list<int>::iterator itr;
	
	for(int i=1;i<adjacency_list.size();i++){
		cout<<i;
		for(itr=adjacency_list[i].begin();itr!=adjacency_list[i].end();itr++){
			cout<<"   - >  "<<*itr;
			}
			cout<<endl;
		}
}
int *dist;

int *finish;

int *color;

int *pred;

int t;
void dfs(vector<list<int> > adjacency_list){
	
	for(int i=0;i<=vertices;i++){
		color[i]=0;
		pred[i]=-1;
		}
	for(int i=1;i<adjacency_list.size();i++){
		if(color[i]==0){
			DFS_VISIT(i,adjacency_list);
			}
		}
}


void DFS_VISIT(int num,vector<list<int> > adjacency_list){
	color[num]=1;
	t+=1;
	dist[num]=t;
	list<int>::iterator itr;
	for(itr=adjacency_list[num].begin();itr!=adjacency_list[num].end();itr++){
		if(color[*itr]==0){
			pred[*itr]=num;
			DFS_VISIT(*itr,adjacency_list);
			}
		}
		t+=1;
		finish[num]=t;
		color[num]=2;
}
	
	
	
int main(){
	cout<<"\nEnter vertices and edges\n";
	cin>>vertices>>edges;
	dist=new int[vertices+1];
	finish=new int[vertices+1];
	color=new int[vertices+1];
	pred=new int[vertices+1];
	t=0;
	int v1,v2;
	vector<list<int> > adjacency_list(vertices+1);
	while(edges--){
	cout<<"\nEnter edge v1 to v2\n";
	cin>>v1>>v2; 
	adjacency_list[v1].push_back(v2);
	}
	display(adjacency_list);
	cout<<"\n\tThe DFS of the graph\n";
	dfs(adjacency_list);
	for(int i=1;i<=vertices;i++){
			cout<<"\nCOLOR of i is           :"<<color[i]<<endl;
			cout<<"\nDIST of i is            :"<<dist[i]<<endl;
			cout<<"\nPREDECESSOR of i is     :"<<pred[i]<<endl;
			cout<<"\nFINISH TIME of i is     :"<<finish[i]<<endl;
		}
	delete[] color;
	delete[] dist;
	delete[] pred;
	delete[] finish;

	return 0;
}
