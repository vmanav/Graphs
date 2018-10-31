
#include <iostream>

using namespace std;
#define max 20

class adjMat
{
    private:
        int n;
        int **adj;
        bool *vis;
    public:
        adjMat(int n)
        {
            this->n = n;
            vis = new bool [n];
            adj = new int* [n];
            for (int i = 0; i < n; i++)
            {
                adj[i] = new int [n];
                for(int j = 0; j < n; j++)
                {
                    adj[i][j] = 0;
                }
            }
        }
       
        void add_edge(int org, int dest)
        {
            if( org > n || dest > n || org < 0 || dest < 0)
            {   
                cout<<"invalid edge\n";
            }
            else
            {
                adj[org-1][dest-1]=1;
            }
        }
       
        void display()
        {
            int i,j;
            for(i = 0;i < n;i++)
            {
                for(j = 0; j < n; j++)
                    cout<<adj[i][j]<<"  ";
                cout<<endl;
            }
        }
};

int main()
{
    int nodes,max_edges,org,dest;
    cout<<"enter no. of nodes ";
    cin>>nodes;
    adjMat am(nodes);
    max_edges = nodes * (nodes - 1);
    for (int i = 0; i < max_edges; i++)
    {
        cout<<"enter edge  ";
        cin>>org>>dest;
        if((org == -1) && (dest == -1))
            break;
        am.add_edge(org, dest);
    }
    am.display();
    return 0;
}