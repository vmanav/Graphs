#include<iostream>
#include<list>
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
};

int main(){
    graph g(10);
    g.addedge(0,1);
    g.addedge(0,2);
    g.addedge(0,3);
    g.addedge(2,3);
    g.addedge(1,2);
    g.addedge(1,3);

    g.printadjlist();
    return 0;
}
