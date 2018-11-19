#include<iostream>
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
            adj[e].remove(s);
        }

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
{   graph g(5);

        g.add_edge(0, 1);

        g.add_edge(0, 4);

        g.add_edge(1, 2);

        g.add_edge(1, 3);

        g.add_edge(1, 4);

        g.add_edge(2, 3);

        g.add_edge(3, 4);

     

        // print the adjacency list representation of the above graph

        g.display();
    

        g.remove_edge(1, 3);

        cout<<"\nNow the edge (1,3) must be removed\n";
                g.display();
    
   return 0;
}
