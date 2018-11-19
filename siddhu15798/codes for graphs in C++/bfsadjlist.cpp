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

    void addedge(int u, int v, bool bidir = true){
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

    void bfs(int src){
        queue<int> q;
        bool *visited = new bool[V]{0};

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
                }
            }
        }
    }
};

int main(){
    graph g(6);
    g.addedge(0,1);
    g.addedge(1,2);
    g.addedge(0,4);
    g.addedge(2,3);
    g.addedge(2,4);
    g.addedge(3,4);
    g.addedge(3,5);

    //g.printadjlist();
    g.bfs(0);
    return 0;
}
