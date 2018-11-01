#include<iostream>
#include<cstdlib>
using namespace std;
class adj_mat
{
    private:
        int n;
        int **adj;
    public:
        adj_mat(int n)
        {
            this->n=n;
            adj=new int*[n];
            for(int i=0;i<n;i++)
            {
                adj[i]=new int[n];
                for(int j=0;j<n;j++)
                {
                    adj[i][j]=0;
                }
            }
        }
        void add_edge(int org,int dest,int de,int w=1)
        {
            if(org>n||dest>n||org<0||dest<0)
            {
                cout<<"Invalid edge!";
            }
            else
            {
                adj[org-1][dest-1]=w;
                if(de==0)
                {
                    adj[dest-1][org-1]=w;
                }
            }
        }
        void display()
        {
            int i,j;
            for(i=0;i<n;i++)
            {
                for(j=0;j<n;j++)
                {
                    cout<<adj[i][j]<<" ";
                }
                cout<<endl;
            }
        }
};
int main()
{
    int nodes,max_edges;
    cout<<"Enter number of nodes:-";
    cin>>nodes;
    cout<<"\nEnter 1 if graph is directed else 0:- ";
    int de;
    cin>>de;
    cout<<"\nEnter 1 if graph is weighted else 0:- ";
    int wc;
    cin>>wc;
    int w=1;
    adj_mat a(nodes);
    max_edges=nodes*(nodes-1);
    int origin,destin;
    for (int i = 0; i < max_edges; i++)
    {
        cout<<"Enter edge (-1 -1 to exit): ";
        cin>>origin>>destin;
        if((origin == -1) && (destin == -1))
            break;
        if(wc==1)
        {
            cout<<"Enter the weight of the edge";
            cin>>w;
        }
        a.add_edge(origin, destin,de,w);
    }
    a.display();
    return 0;
}
