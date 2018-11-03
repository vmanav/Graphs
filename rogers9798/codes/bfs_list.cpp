#include <iostream>
#include <list>
#include<iterator>
 
using namespace std;
 
class graph
{
int V;
    list<int> *adjLists;
    bool* visited;
 public:
    graph(int vertices);  
 void addEdge(int src,int dest); 
    void bfs(int startVertex);
};
 
graph::graph(int vertices)
{
    V = vertices;
    adjLists = new list<int>[vertices];
}
 
 void graph::addEdge(int src, int dest)
{
    adjLists[src].push_back(dest);
    adjLists[dest].push_back(src);
             }
 
   void graph::bfs(int startVertex)
{
    visited = new bool[V];
    for(int i = 0; i < V; i++)
        visited[i] = false;
  list<int> queue;
 
    visited[startVertex] = true;
queue.push_back(startVertex);
 
 list<int>::iterator i;
 
    while(!queue.empty())
    {
        int curr = queue.front();
        cout <<curr<<" ";
        queue.pop_front();
 
        for(i = adjLists[curr].begin(); i != adjLists[curr].end(); ++i)
        {
            int adj_V = *i;
 if(!visited[adj_V])
 { visited[adj_V] = true;
                queue.push_back(adj_V);
            }
        }
    }
}
 
int main()
{

    int V,e,f,s,i,x;
cout<<"enter no. of vertices ";
cin>>V;
cout<<"enter no. of edges ";
cin>>e;

    graph g(V);
cout<<"enter from and to :\n";
     for (i=1;i<=e;i++)
    {   cout<<"enter "<<i<<" edge :";
        cin>>f;cin>>s;
        g.addEdge(f,s);
    }
    cout << "enter vertex for traversal \n";cin>>x;cout<<"bfs-trav is :\n";

    g.bfs(x);
 
    return 0;
}