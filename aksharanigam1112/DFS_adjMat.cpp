#include <iostream>
#include<vector>

using namespace std;

class Graph
{
private:
      bool** adjMatrix;
      int Vertices;
public:
      Graph(int nv)
      {
            this->Vertices = nv;
            adjMatrix = new bool*[nv];
            for (int i = 0; i < nv; i++)
            {
                  adjMatrix[i] = new bool[nv];
                  for (int j = 0; j < nv; j++)
                        adjMatrix[i][j] = false;
            }
    }

      void addEdge(int i, int j)
      {
          adjMatrix[i-1][j-1] = true;
    }

      void removeEdge(int i, int j)
      {
          adjMatrix[i-1][j-1] = false;
        }

    void display()
    {
        int i;
        cout<<"    ";
        for(i=0;i<Vertices;i++)
            cout << i+1 << " ";
        cout<<endl;
        for (i = 0; i < Vertices; i++)
        {
            cout << i+1 << " : ";
            for (int j = 0; j < Vertices; j++)
            {
                cout<<adjMatrix[i][j] << " ";
            }
            cout << "\n";
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

    void DFS(int beg , vector<int>visited)
    {
        if(!find(beg , visited))
            {
                 cout<<beg<<"\t";
                visited.push_back(beg);
            }

            for(int j=0;j<Vertices ;j++)
            {
                if(adjMatrix[beg-1][j] == true && j!=beg-1 && (!find(j+1,visited) ))
                {
                     DFS(j+1 , visited);
                }
            }

    }

};


int main()
{
    int n , ch,i,j;
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
                vector<int> v;
                cout<<"\nEnter the vertex to start DFS with :- ";
                cin>>x;
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
        cin>>n;
    }while(n==1);
    return 0;
}

