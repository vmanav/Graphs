#include <iostream>
#include <vector>
#include<stack>

using namespace std;

void DFS(vector< vector<int> > &matrix,int n, int sv)
{
    vector<bool> visited(n, false);
    stack<int> S;
    S.push(sv);
    while(!S.empty())
    {
        int cv = S.top();
        if(!visited[cv])
        {
            cout<<cv<<" ";
            visited[cv] = true;
        }
        S.pop();

        for(int i=0; i<n;i++)
        {
            if(matrix[cv][i] == 1 && !visited[i] && i!=cv)
                {
                    S.push(i);
                    break;
                }
        }
    }

}

void input(vector< vector<int> > &matrix, int e)
{
    int f,s;
    for(int i =0 ; i < e; i++)
    {
        cin>>f>>s;
        matrix[f][s] = 1;
        matrix[s][f] =1;
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
    DFS(matrix,n,0);
    return 0;
}

/*
//http://graphonline.ru/en/?graph=IicvyOEaqCBJIbxV
10
17
0 1
0 7
0 8
1 2
1 3
1 6
2 4
3 4
3 5
4 5
5 6
5 8
5 9
6 8
7 8
7 9
8 9
*/