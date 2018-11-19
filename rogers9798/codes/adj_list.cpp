#include <iostream>
#include <list>
#include <iterator>
using namespace std;
 
class graph
{   public:
    int v;
    list<int> *adj_list;
    list<int>::iterator it;

    graph(int vert);
    void add_edge(int src, int dest,int v);
    void print(list<int>*adj_list,int v)
    {
        for (int i = 0; i < v; i++)
        {
            list<int>::iterator i1;
            cout << i << "-->"
                 << " ";
            for (i1 = adj_list[i].begin(); i1 != adj_list[i].end(); i1++)
            {
                cout << *i1 << " ";
            }
            cout << endl;
        }
    }
};
 
graph::graph(int vert)
{
    v = vert;
    adj_list = new list<int>[vert];
}
 
void graph::add_edge(int src,int dest,int v)
{
    adj_list[src].push_front(dest);
    print(adj_list,v);
}
 
 
 
int main()
{   int V,e,f,s,i;
cout<<"enter no. of vertices ";
cin>>V;
cout<<"enter no. of edges ";
cin>>e;

    graph g(V);
cout<<"enter from and to :\n";
     for (i=0;i<e;i++)
    {   cout<<"enter "<<i<<" edge :";
        cin>>f;cin>>s;
        g.add_edge(f,s,V);
    }

 
    return 0;
}