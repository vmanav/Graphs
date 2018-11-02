#include<iostream>
#include<queue>
using namespace std;

void BFS(int **edges, int n, int sv, bool *visited)
{
    queue<int> Q;
    Q.push(sv);
    visited[sv] = true;
    while(!Q.empty())
    {
        int current = Q.front();
        Q.pop();
        cout<<current<<" ";
        for(int i=0; i<n; i++)
        {
            if(i==current)
                continue;
            if((edges[current][i] == 1) && (!visited[i]))
            {
                Q.push(i);
                visited[i] = true;
            }
        }
    }
}

int main()
{
    int n,e; 
    cin>>n;//vertices
    cin>>e;//edges
    int **edges = new int*[n];
    for(int i=0; i<n; i++)
    {
        edges[i] = new int[n];
        for(int j=0; j<n; j++)
        {
            edges[i][j] = 0;
        }
    }
    int f, s;
    for(int i=0; i <e; i++)
    {
        cin>>f>>s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }
    bool *visited = new bool[n];
    for(int i=0; i<n; i++)
    {
        visited[i] = false;
    }
    int sv;
    cout<<"enter starting vertex for BFS traversal"<<endl;
    cin>>sv;
    BFS(edges, n, sv, visited);
    //handling deletion
    delete [] visited;
    for(int i=0; i<n; i++)
    {
        delete [] edges[i];
    }
    delete [] edges;
    return 0;
}