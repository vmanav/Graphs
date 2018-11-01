#include<iostream>
#include<list>
#include<vector>
using namespace std;
class adj_list
{
    private:
        int n;
        list<pair<int,int> > *adj;
    public:
        adj_list(int n)
        {
            this->n=n;
            adj=new list<pair<int,int> >[n];
        }
        void add_edge(int org,int dest,int de,int w=1)
        {
            if(org>n||dest>n||org<0||dest<0)
            {
                cout<<"Invalid edge!";
            }
            else
            {
                for(list<pair<int,int> >::adj[org])
                {
                    if(i.empty())
                    {
                        adj[org].push_back(make_pair(NULL,NULL));
                    }
                    adj[org].push_back(make_pair(dest,w));
                    if(de==0)
                    {
                        for(iterator i::adj[dest])
                        {
                            if(i.empty())
                            {
                                adj[dest].push_back(make_pair(NULL,NULL));
                            }
                        adj[dest].push_back(make_pair(org,w));
                        }
                    }
                }
            }
        }
        void display()
        {
            int i,j;
            for(i=0;i<=n;i++)
            {
                    for(pair<int,int> j::adj[i])
                    {
                        cout<<j.first<<","<<j.second<<" ";
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
    adj_list a(nodes);
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
        a.add_edge(origin,destin,de,w);
    }
    a.display();
    return 0;
}
