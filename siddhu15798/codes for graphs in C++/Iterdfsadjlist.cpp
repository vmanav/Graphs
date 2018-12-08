#include<iostream>
#include<list>
#include<stack>
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

    void dfs(int src){
        stack<int> s;
        bool *visited = new bool[V]{0};

        s.push(src);
        while(!s.empty()){
            int node = s.top();
            s.pop();
            if(!visited[node]){
                cout<<node<<" ";
                visited[node] = true;
            }

            for(int neighbour: adjlist[node]){
                if(!visited[neighbour]){
                    s.push(neighbour);
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

    g.dfs(0);
    return 0;
}


