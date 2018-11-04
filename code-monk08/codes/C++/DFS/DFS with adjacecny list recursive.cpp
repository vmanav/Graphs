#include<iostream>
#include<vector>
#include<iterator>
using namespace std;

void addedge(vector<int> alist[], int f, int s)
{
    alist[f].push_back(s);
    alist[s].push_back(f);
}


void DFS(vector<int> alist[], int n, int sv, vector<bool> &visited)
{
    cout<<sv<<" ";
    visited[sv] = true;
    vector<int>::iterator i1;
    for(i1 = alist[sv].begin(); i1!=alist[sv].end(); i1++)
    {
        if(!visited[*i1])
            DFS(alist,n,*i1,visited);
    }
}

int main()
{
    int n,f,s,e;
    cin>>n;
    cin>>e;
    vector<int> alist[n];
    for(int i =0; i < e; i++)
    {
        cin>>f>>s;
        addedge(alist, f, s);
    }
    vector<bool> visited(n, false);
    cout<<endl;
    DFS(alist,n,0,visited);
    return 0;
}
