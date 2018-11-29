
#include <iostream>
#include <vector>
#include <iterator>
#include <stack>
using namespace std;

void addedge(vector<int> *array, int f, int s)
{
    array[f].push_back(s);
    array[s].push_back(f);
}

void DFS(vector<int> alist[], int n, int sv)
{
    stack<int> S;
    vector<bool> visited(n, false);
    vector<int> :: iterator it;
    S.push(sv);
    while(!S.empty())
    {
        int currentVertex = S.top();
        S.pop();
        if(!visited[currentVertex])
        {
            cout<< currentVertex << " ";
            visited[currentVertex] = true;
        }
        for(it = alist[currentVertex].begin(); it!=alist[currentVertex].end(); it++)
        {
            if(!visited[*it])
                {
                    S.push(*it);
                } 
        }
    }
}

void input(vector<int> *array, int n, int e)
{
    int f, s;
    for (int i = 0; i < e; i++)
    {
        cin >> f >> s;
        addedge(array, f, s);
    }
}

int main()
{
    int n; //vertices
    cin >> n;
    int e;
    cin >> e; //edges
    vector<int> alist[n];
    input(alist, n, e);
    DFS(alist, n,0);
}
