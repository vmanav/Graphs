#include <iostream>
using namespace std;

class graph
{   private:
        int v; //vertices
        bool **adj;
    public:
        graph(int vert)
        {   int i,j;
            this->v=vert;
            adj= new bool*[vert];
            for(i=0;i<vert;i++)
            {   adj[i]=new bool[vert];
                for(j=0;j<vert;j++)
                {   adj[i][j]= 0;
                }
            }
        }

        void add_edge(int x, int y)
        {   if( x<0 || y<0 || x>(v-1) || y>(v-1) )
            {   cout<<"\nInvalid edge";
            }
            else
            {   adj[x][y]=1; // naming of edges also start from '0'
                adj[y][x]=1;
            }
        }
        void remove_edge(int x, int y)
        {   if( x<0 || y<0 || x>(v-1) || y>(v-1) )
            {   cout<<"\nInvalid edge";
            }
            else
            {   adj[x][y]=0;    // naming of edges also start from '0'
                adj[y][x]=0;
            }
        }

        int edge_P(int x , int y) //edge present ?
        {   return adj[x][y]==1 ? 1:0;
        }

        void display()
        {   int i,j;
            for(i=0;i<v;i++)
            {   cout<<i<<" ";
            }
            cout<<"\n";
            for(i=0;i<v;i++)
            {   cout<<i<<"  ";
                for(j=0;j<v;j++)
                {   cout<<adj[i][j]<<" ";
                }
            cout<<"\n";
            }

        }

        ~graph()     //Destructor
        {   delete[] adj; // Deleting 2d Dynamic Array
        }
};


int main()
{   int x,y,ch,VERT,max_edge,edge_count,ans;
    cout<<"Enter The Number of Vertices";
    cin>>VERT;
    graph g(VERT);
    max_edge=(VERT*(VERT-1))/2;
    cout<<"\n1 add edge";
    cout<<"\n2 delete edge";
    cout<<"\n3 edge present ?";
    cout<<"\n4 display adjacency matrix"<<"\n";
    char Y;
    do
    {   cout<<"\nEnter choice ";
        cin>>ch;
        switch(ch)
        {   case 1: cout<<"\nEnter edge coordinates";
                    cin>>x>>y;
                    g.add_edge(x,y);
                    break;

            case 2: cout<<"\nEnter edge coordinates";
                    cin>>x>>y;
                    g.remove_edge(x,y);
                    break;

            case 3: cout<<"\nEnter edge coordinates";
                    cin>>x>>y;
                    ans = g.edge_P(x,y);
                    if (ans==1)
                        cout<<"\nEdge Present";
                    else
                        cout<<"\nNo Edge";
                    break;

            case 4: g.display();
                    break;

        }
        cout<<"\nenter 'Y' to continue";
        cin>>Y;
    }while(Y=='Y');
    return 0;
}
