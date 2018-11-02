#include<iostream>
#include<list>
#include<vector>
#include<stack>
using namespace std;

class Graph
{
private:
    int vertices;
    list<int> *adjlist;
public:
    Graph(int n)
    {
        this->vertices = n;
        adjlist = new list<int> [n];
    }

    void addEdge(int src, int dest)
    {
        adjlist[src-1].push_back(dest);
    }

     void removeEdge(int src, int dest)
    {
        adjlist[src-1].remove(dest);
    }
    void display()
    {
         int i;
         for (i = 0; i < vertices; i++)
            {
                list<int>::iterator it = adjlist[i].begin();
                cout<<"\n Adjacency list of vertex "<<i+1<<" is:- ";
                while(it != adjlist[i].end())
                {
                    cout<<"\t" << *it ;
                    it++;
                }
                cout<<endl;
            }
    }

    bool find(int ele , vector<int> v)
    {
        for(int i=0;i<v.size();i++)
        {
            if(v[i] == ele)
                return true;
        }
        return false;
    }

    void DFS(int beg , vector<int>visited )
    {
            if(!find(beg , visited))
                cout<<beg<<"\t";
            visited.push_back(beg);

            list<int>::iterator it = adjlist[beg-1].begin();
            while(it != adjlist[beg-1].end())
            {
                if(!find(*it , visited))
                {
                    DFS(*it , visited);
                }
                it++;
            }
        }

};


int main()
{
    int n , ch,i,j,k;
    cout<<"\nEnter the no. of vertices:- ";
    cin>>n;
    Graph obj(n);
    do
    {
        cout<<"\n1.. Add Edges \n2.. Remove Edges \n3.. DFS \n4.. Display"<<endl;
        cin>>ch;
        switch(ch)
        {
        case 1:
            {
                cout<<"\nEnter the nodes to add an edge:- ";
                cin>>i>>j;
                obj.addEdge(i,j);
                break;
            }
        case 2:
            {
                cout<<"\nEnter the nodes to remove an edge:- ";
                cin>>i>>j;
                obj.removeEdge(i,j);
                break;
            }
        case 3:
            {
                int x;
                cout<<"\nEnter the vertex to start DFS with:- ";
                cin>>x;
                vector<int>v;
                obj.DFS(x , v);
                break;
            }
        case 4:
            {
                obj.display();
                break;
            }
        }
        cout<<"\nPress 1 to continue:- ";
        cin>>k;
    }while(k==1);
    return 0;
}




