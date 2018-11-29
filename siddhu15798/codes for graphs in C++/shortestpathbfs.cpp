#include<iostream>
#include<list>
#include<queue>
using namespace std;

class graph{
	int V;
    list<int> *adjlist;

public:
    graph(int v){
        V = v;
     	adjlist = new list<int>[V];
    }

    void addedge(int u,int v,bool bidir=true){
        adjlist[u].push_back(v);
     	if(bidir){
     		adjlist[v].push_back(u);
     	}
    }

    void printadjlist(){
        for(int i=0;i<V;i++){
     		cout<<i<<"->";
     		for(int node:adjlist[i]){
     			cout<<node<<",";
     		}
     		cout<<endl;
     	}
    }

    void bfs(int src,int dest){
     	queue<int> q;
     	bool *visited = new bool[V]{0};
     	int *dist = new int[V]{0};
     	int *parent = new int[V];

     	for(int i=0;i<V;i++){
     		parent[i] = -1;
     	}

     	q.push(src);
     	visited[src] = true;

     	while(!q.empty()){
     		int node = q.front();
     		cout<<node<<" ";
     		q.pop();

     		for(int neighbour: adjlist[node]){
                if(!visited[neighbour]){
     				q.push(neighbour);
     				visited[neighbour] = true;
     				dist[neighbour] = dist[node]  + 1;
     				parent[neighbour] = node;
     			}
     		}
     	}
     	cout<<endl;
     	cout<<"Shortest dist is "<<dist[dest]<<endl;
     	cout<<"Shortest path is ";

     	int temp = dest;
     	while(temp!=-1){
     		cout<<temp<<"<--";
     		temp = parent[temp];
     	}
    }
};

int main(){
	graph g(6);
	g.addedge(0,1);
	g.addedge(1,2);
	g.addedge(0,4);
	g.addedge(2,4);
	g.addedge(3,2);
	g.addedge(3,5);
	g.addedge(3,4);
	g.bfs(0,5);
	return 0;
}
