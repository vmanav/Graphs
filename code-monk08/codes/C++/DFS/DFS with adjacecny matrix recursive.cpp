#include<iostream>
using namespace std;

void DFS(int **edge, int n, int sv, bool *visited)
{
    cout<<sv<<endl;
    visited[sv] = true;

    for(int i=0; i < n; i++)
    {
        if(i == sv)
            continue;
        if(edge[sv][i] == 1)
            {
                if(visited[i])
                    continue;
                DFS(edge, n, i, visited);
            }
    }
}


int main()
{
    int n; //number of vertices
    int e; //number of edges

    cin>>n>>e;

    int **edge = new int*[n];
    for(int i =0; i < n; i++)
    {
        edge[i] = new int[n];
        for(int j=0; j<n; j++)
        {
            edge[i][j] = 0;
        }
    }
    int f; //stores the information of first node in consideration
    int s; //stores the information of second node in consideration
    for(int i=0; i<e; i++)
    {
        cin>>f>>s;
        edge[f][s] = 1;
        edge[s][f] = 1;
    }

    bool *visited = new bool[n];
    for(int i=0; i < n; i++)
    {
        visited[i] = false;
    }
    DFS(edge, n, 0, visited);
    return 0;
}