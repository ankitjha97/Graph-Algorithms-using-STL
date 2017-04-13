    #include<iostream>
#include<algorithm>
#include<vector>
#include<functional>
#include<queue>
#include<list>
#include<set>
#include<limits>
using namespace std;
int vertices,edges;
set<int> U;
set<int> V;
int *dist;
int *parent;

void initialise(){
    dist=new int[vertices+1];
    parent=new int[vertices+1];
    for(int i=0;i<vertices+1;i++){
        dist[i]=numeric_limits<int>::max();
    }
    for(int i=0;i<vertices+1;i++){
        parent[i]=-1;
    }
    for(int i=1;i<=vertices;i++){
        V.insert(i);
    }

}

void display(vector<list<pair<int,int> > > adjacency_list){
    list<pair<int,int> >::iterator itr;
    for(int i=1;i<vertices;i++){
                cout<<i<<"\t";
                for(itr=adjacency_list[i].begin();itr!=adjacency_list[i].end();itr++){
                    cout<<"  - >  "<<itr->first<<"  "<<itr->second;
                }
                cout<<endl;
}
}



int RELAX(int u,int v,int weight){
    if(dist[v]>dist[u]+weight){
        dist[v]=dist[u]+weight;
    }
}
void dikstra(vector<list<pair<int,int> > > adjacency_list){
    initialise();
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;
    int source,destination;
    cout<<"\nEnter source and destination\n";
    cin>>source>>destination;
    list<pair<int,int> >::iterator itr;
    U.insert(source);
    V.erase(source);
    pq.push(make_pair(source,0));
    dist[source]=0;
    int u;
    while(!pq.empty()){
        u=pq.top().first;
        pq.pop();
        U.insert(u);
        V.erase(u);
        for(itr=adjacency_list[u].begin();itr!=adjacency_list[u].end();itr++){
            int v=(*itr).first;
            int weight=(*itr).second;
            RELAX(u,v,weight);
            pq.push(make_pair(v,weight));
        }



    }



}

void display_dist(){
    for(int i=1;i<=vertices;i++){

        cout<<dist[i]<<"\t";
    }


}


int main(){
    int v1,v2,weight;
    cout<<"\nEnter the no of vertices and edges\n";
    cin>>vertices>>edges;
    vector<list<pair<int,int> > > adjacency_list(vertices+1);
    for(int i=0;i<vertices;i++){
        cout<<"\nEnter edges v1 to v2 along with weight\n";
        cin>>v1>>v2>>weight;
        adjacency_list[v1].push_back(make_pair(v2,weight));
    }
    display(adjacency_list);
    dikstra(adjacency_list);
    display_dist();


    delete[] dist;
    delete[] parent;
    return 0;
}
