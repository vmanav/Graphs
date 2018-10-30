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
          int flag=0;
          for(int k=0;k<Vertices;k++)
          {
              if (adjMatrix[i-1][k] == false && k!=j-1)
                flag++;
          }
          if (flag == Vertices-1)
            cout<<"\nCannot be removed";
          else
            adjMatrix[i-1][j-1] = false;
        }

      bool isEdge(int i, int j)
      {
        return adjMatrix[i-1][j-1];
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

    bool visited(int ele , vector<int>v)
    {
        for(int i=0;i<v.size();i++)
        {
            if(ele==v[i])
                return true;
        }
        return false;
    }

    void BFS(int n)
    {
        vector<int>visit;
        for(int i=0;i<n;i++)
        {
            if(!visited(i,visit))
                {
                        cout<<" "<<i+1;
                        visit.push_back(i);
                }
            for(int j=0;j<n;j++)
            {
                if(isEdge(i+1,j+1))
                {
                    if(!visited(j,visit))
                    {
                        cout<<" "<<j+1;
                        visit.push_back(j);
                    }
                }
            }
        }
    }

    ~Graph()
    {
             delete[] adjMatrix;
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
        cout<<"\n1.. Add Edges \n2.. Remove Edges \n3.. BFS \n4.. Display"<<endl;
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
                cout<<"\nBFS";
                obj.BFS(n);
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

