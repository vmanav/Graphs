
#include<iostream>
#include<list>
 
using namespace std;
 
class Graph
{list<int> *adj;
    int V;    
    
    void util(int v,bool visit[]);  
public:
    Graph(int V);  
void addEdge(int s,int d);   
void dfs_trav(int v);   
};
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
 
void Graph::addEdge(int s,int d)
{
    adj[s].push_back(d); 
}
 
void Graph::util(int v,bool visit[])
{list<int>::iterator i;
    
    visit[v]=true;
    cout<<v<<endl;
 
    
    
    for (i=adj[v].begin(); i!= adj[v].end();i++)
      {if (!visit[*i])
            util(*i,visit);}  
}
 

void Graph::dfs_trav(int v)
{
    
 bool *visit = new bool[V];
    for (int i = 0; i < V; i++)
       {visit[i] = false;
}  
    
    util(v,visit);
}
 
int main()
{
    
  
   int V,e,f,s,i,x;
cout<<"enter no. of vertices ";
cin>>V;
cout<<"enter no. of edges ";
cin>>e;

    Graph g(V);
cout<<"enter from and to :\n";
     for (i=1;i<=e;i++)
    {   cout<<"enter "<<i<<" edge :";
        cin>>f;cin>>s;
        g.addEdge(f,s);
    }
 
    cout << "enter vertex for Depth First Traversal \n";cin>>x;cout<<"dfs-trav is :\n";
    g.dfs_trav(x);
 
    return 0;
}