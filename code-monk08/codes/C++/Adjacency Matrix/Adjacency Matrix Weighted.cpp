//work on deletion from adjacency matrix
#include <iostream>
#include <vector>
using namespace std;

void print(vector< vector<int> > &matrix,int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void addedge(vector< vector<int> > &matrix, int f, int s, int w)
{
        matrix[f][s] = w;
        matrix[s][f] = w;
}

void input(vector< vector<int> > &matrix, int e)
{
    int f,s,w;
    for(int i =0 ; i < e; i++)
    {
        cin>>f>>s>>w;
        addedge(matrix,f,s,w);
    }
}

int main()
{
    int n; 
    int e;
    cin >>n;
    cin>>e;
    //vector< vector<int> > matrix(n, vector<int>(n, 0));
    vector< vector<int> > matrix(n, vector<int>(n,0));
    input(matrix,e);    
    print(matrix,n);
    return 0;
}