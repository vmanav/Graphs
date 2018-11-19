#include<iostream>
#include<map>
#include<string>
#include<list>
using namespace std;

template<typename T>
class graph{

    map<T, list<T>> adjlist;
public:
    graph(){
    }

    void addedge(T u, T v, bool bidir = true){
        adjlist[u].push_back(v);
        if(bidir){
            adjlist[v].push_back(u);
        }
    }

    void printadjlist(){
        for(auto row: adjlist){
            T key = row.first;
            cout<<key<<"->";
            for(auto value: row.second){
                cout<<value<<",";
            }
            cout<<endl;
        }
    }
};

int main(){
    graph<string> g;
    g.addedge("delhi","lucknow");
    g.addedge("delhi","faridabad");
    g.addedge("delhi","bombay");
    g.addedge("delhi","chennai");
    g.addedge("faridabad","lucknow");
    g.addedge("lucknow","bombay");
    g.addedge("bombay","chennai");
    g.addedge("chennai","lucknow");
    g.addedge("varanasi","lucknow");

    g.printadjlist();
    return 0;
}
