#include<iostream>
#include<algorithm>
#include<vector>
#include<list>
#include<queue>
int vertices;
int edges;
using namespace std;
void display(vector<list<int> > adjacency_list){
	for(int i=1;i<adjacency_list.size();i++){
	cout<<i<<"  - >  ";
		list<int>::iterator itr=adjacency_list[i].begin();
		while(itr!=adjacency_list[i].end()){
			cout<<*itr<<"  - >  ";
			itr++;
		}
		cout<<endl;
	}
	}
void bfs(vector<list<int> > adjacency_list){
	queue<int> q;
	bool *status;
	status=new bool[vertices+1];
	int *level;
	level=new int[vertices+1];
	for(int i=0;i<=vertices;i++){
		status[i]=false;
		}
	for(int i=0;i<=vertices;i++){
		level[i]=1;
		}
	int source;
	cout<<"Enter the source vertex :  ";
	cin>>source;
	q.push(source);
	int temp;
	list<int>::iterator itr;
	while(!q.empty()){
		temp=q.front();
		q.pop();
		status[temp]=true;
		for(itr=adjacency_list[temp].begin();itr!=adjacency_list[temp].end();itr++){
			if(status[*itr]==0){
			
			q.push(*itr);
			level[*itr]=level[temp]+1;
			status[*itr]=true;
			cout<<*itr;
			}
			
			else{
			continue;
			}
			}
		}
}
		
		
	


int main(){
	
	cout<<"\nEnter the edges and vertices\n";
	cin>>edges>>vertices;
	int v1,v2;
	vector<list<int> > adjacency_list(vertices+1);
	for(int i=0;i<edges;i++){
		cout<<"\nEnter the edges v1->v2\n";
		cin>>v1>>v2;	
		adjacency_list[v1].push_back(v2);
		}
	
			
	cout<<endl;
	display(adjacency_list);
	bfs(adjacency_list);




	return 0;
}

