#include<iostream>
#include<list>
using namespace std;
class Graph
{
    int V;
    list<int> *adj;
    public:
        Graph(int V)
        {
            this->V = V;
            adj = new list<int>[V];
        }
        void addEdge(int v, int w)
        {
            adj[v].push_back(w);
        }

void DFS(int s)
{
    vector<bool> visited(V, false);
    stack<int> stack;
    stack.push(s);
    while (!stack.empty())
    {
        s = stack.top();
        stack.pop();
        if (!visited[s])
        {
            cout << s << " ";
            visited[s] = true;
        }
        for (auto i = adj[s].begin(); i != adj[s].end(); ++i)
            if (!visited[*i])
                stack.push(*i);
    }
}
};
int main()
{
     int V;
    cout<<"enter no. of nodes in graph:-";
    cin>>V;
    Graph g(V);
    int sc,ds,m;
    do
    {
    cout<<"enter source node and destination node";
    cin>>sc>>sc;
    g.addEdge(sc, ds);
    cout<<"dp you want to insert more connections? if yes enter 1 else 0:-";
    cin>>m;
    }while(m!=0);
    cout << "Following is Depth First Traversal (starting from vertex 2) \n";
    g.DFS(2);
    return 0;
}
