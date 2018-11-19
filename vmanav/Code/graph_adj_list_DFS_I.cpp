#include<iostream>
#include<vector>
#include<stack>
#include<list>
using namespace std;

class graph
{   private:
        int v;  //  VERTICES
        list<int> *adj;
    public:
        graph(int V)
        {   this->v=V;
            adj = new list<int> [V]; // @vmanav refer geeks for declaration
        }

        void add_edge(int s , int e)
        {   adj[s].push_back(e);
            adj[e].push_back(s);
        }

        void remove_edge(int s , int e)
        {   adj[s].remove(e);
            adj[s].remove(e);
        }

        void DFS(int V);

        void display()
        {   int i;
            for(i=0;i<v;i++)
            {   list<int>::iterator I= adj[i].begin();
                cout<<" "<<i<<" - ";
                while(I!= adj[i].end())
                {   cout<<" "<<*I;
                    I++;
                }
                cout<<"\n";
            }
        }
};

int main()
{   graph g(8);

        g.add_edge(0, 1);

        g.add_edge(1, 2);

        g.add_edge(2, 3);

        g.add_edge(1, 7);

        g.add_edge(2, 4);

        g.add_edge(4, 5);

        g.add_edge(4, 6);

        g.add_edge(4, 7);



        // print the adjacency list representation of the above graph

        g.display();


            cout << "Following is Depth First Traversal"
            " (starting from vertex 0) \n";
    g.DFS(0);


   return 0;
}





void graph::DFS(int V)
{   vector<bool> visited(v, false); // ALL MARKED TO ZERO

    stack<int> ST;
