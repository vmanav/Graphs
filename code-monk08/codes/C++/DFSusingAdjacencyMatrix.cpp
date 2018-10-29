//n verticles - -- - - - -  [0 to n-1]
//undirected tree

#include <iostream>
using namespace std;

void print(int **edge, int n, int sv, bool *visited)
{
    cout << sv << endl;
    visited[sv] = true;
    for (int i = 0; i < n; i++)
    {
        if (i == sv)
            continue;
        if (edge[sv][i] == 1)
        {
            if (visited[i])
                continue;
            print(edge, n, i, visited);
        }
    }
}

int main()
{
    int n, e; // n = number of vertices, e = number of edges
    cin >> n >> e;
    int **edge = new int *[n];
    for (int i = 0; i < n; i++)
    {
        edge[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            edge[i][j] = 0;
        }
    }
    int f, l;
    for (int i = 0; i < e; i++)
    {
        cin >> f >> l;
        edge[f][l] = 1;
        edge[l][f] = 1;
    }
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    print(edge, n, 0, visited);
    return 0;
}

/*
Sample Output for tree: https://www.google.com/url?sa=i&rct=j&q=&esrc=s&source=images&cd=&cad=rja&uact=8&ved=2ahUKEwj8rpbLsKzeAhVKfX0KHUQ1A7wQjRx6BAgBEAU&url=http%3A%2F%2Fwww.mathcs.emory.edu%2F~cheung%2FCourses%2F171%2FSyllabus%2F11-Graph%2Fdata-stru.html&psig=AOvVaw08-cdTWwldLRFF5yYsmoKr&ust=1540926929094091
9
10
0 1
0 3
0 8
1 7
2 3
2 7
3 4
4 8
5 2
5 6
0
1
7
2
3
4
8
5
6
*/