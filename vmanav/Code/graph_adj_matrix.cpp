#include<iostream>
using namespace std;

class graph
{   private:
    int v;
    int e;
    int **adj;
    public:
    
    
    graph(int vert)
    {   this->v=vert;
        adj = new int* [vert];
        int i,j;
        for(i=0;i<vert;i++)
        {   adj[i] = new int [vert];
        }
        for(i=0;i<vert;i++)
        {   for(j=0;j<vert;j++)
            {   adj[i][j] = 0;
                adj[j][i] = 0;
            }
        }
    }
    
    /*int EDGE()
    {   return this->e;
    }
    int VERTICE()
    {   return this->v;
    }*/
    void display()
    {   int i,j;
        for(i=0;i<v;i++)
        {   for(j=0;j<v;j++)
            {   cout<<adj[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    void add_edge(int x, int y)
    {   if( x<0 || y<0 || x>(v-1) || y>(v-1) )
        {   cout<<"\nInvalid edge";
        }
        else
        {   adj[x][y]=1;
            adj[y][x]=1;
        }
    }
    void remove_edge(int x, int y)
    {   if( x<0 || y<0 || x>(v-1) || y>(v-1) )
        {   cout<<"\nInvalid edge";
        }
        else
        {   adj[x][y]=0;
            adj[y][x]=0;
        }
    }

    bool edge_present(int x ,int y)
    {   return adj[x][y] == 1 ? 1: 0;
    }

};

int main()
{   int i,x,y,vert,edge;
    cout<<"\nEnter The Number of Vertices";
    cin>>vert;
    int k=vert*(vert-1)/2;
    graph grp(vert);    //declaring object and calling constructor 
    for(i=0;i<k;i++)
    {   cout<<"\nEnter Edge co-ordinates\n";
        cin>>x>>y;
        grp.add_edge(x,y);
    }
    grp.display();
    return 0;
}
